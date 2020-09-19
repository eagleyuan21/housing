/*
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handler(int signum)
{ //signal handler
	printf("Hello World!\n");
	exit(1); //exit after printing
}

int main(int argc, char * argv[])
{
	signal(SIGALRM,handler); //register handler to handle SIGALRM
	alarm(1); //Schedule a SIGALRM for 1 second
	while(5);

	printf("Turing was right!");

	return 0; //never reached
}*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netinet/in.h>
#include <netinet/ip.h> //ip hdeader library (must come before ip_icmp.h)
#include <netinet/ip_icmp.h> //icmp header
#include <arpa/inet.h> //internet address library
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>

#define BUFSIZE 1500 //1500 MTU (so within one frame in layer 2)
#define PROTO_ICMP 1

unsigned short checksum(unsigned short * data, int len);


int main(int argc, char * argv[]){
  char sendbuf[BUFSIZE], recvbuf[BUFSIZE], controlbuf[BUFSIZE];
  struct icmp * icmp;
  struct ip * ip;
  int sockfd;
  int packet_len, recv_len, ip_len, data_len;
  struct addrinfo * ai;
  struct iovec iov;
  struct msghdr msg;

  //process addr info
  getaddrinfo(argv[1], NULL, NULL, &ai);

  //process destination address
  printf("Dest: %s\n", ai->ai_canonname ? ai->ai_canonname : argv[1]);

  //Initialize the socket
  if((sockfd = socket(AF_INET, SOCK_RAW, PROTO_ICMP)) < 0){
    perror("socket"); //check for errors
    exit(1);
  }

  //initiate ICMP header
  icmp = (struct icmp *) sendbuf; //map to get proper layout
  icmp->icmp_type = ICMP_ECHO; //Do an echoreply
  icmp->icmp_code = 0;
  icmp->icmp_id = 42;
  icmp->icmp_seq= 0;
  icmp->icmp_cksum = 0;

  //compute checksum
  icmp->icmp_cksum = checksum((unsigned short *) icmp, sizeof(struct icmp));

  packet_len = sizeof(struct icmp);

  //send the packet
  if( sendto(sockfd, sendbuf, packet_len, 0, ai->ai_addr, ai->ai_addrlen) < 0){
    perror("sendto");//error check
    exit(1);
  }

  //built msgheader structure for receiving reply
  iov.iov_base = recvbuf;
  iov.iov_len = BUFSIZE;

  msg.msg_name = NULL;
  msg.msg_namelen = 0;
  msg.msg_iov = &iov;
  msg.msg_iovlen = 1;
  msg.msg_control=controlbuf;
  msg.msg_controllen=BUFSIZE;

  //recv the reply
  if((recv_len = recvmsg(sockfd, &msg, 0)) < 0){ //could get interupted ??
    perror("recvmsg");
    exit(1);
  }

  printf("%d\n",recv_len);

  ip = (struct ip*) recvbuf;
  ip_len = ip->ip_hl << 2; //length of ip header

  icmp = (struct icmp *) (recvbuf + ip_len);
  data_len = (recv_len - ip_len);

  printf("%d bytes from %s\n", data_len, inet_ntoa(ip->ip_src));

  return 0;
}

unsigned short checksum(unsigned short * data, int len){
  int i;
  unsigned int sum = 0;
  unsigned short * ptr;
  unsigned short chcksum;

  for(i=len, ptr=data; i > 1; i-=2){ //i-=2 for 2*8=16 bits at time
    sum += *ptr; //sum += 16 bit word at ptr
    ptr+=1;//move ptr to next 16 bit word
  }

  //check if we have an extra 8 bit word
  if (i == 1){
    sum += *((unsigned char*) ptr); //cast ptr to 8 bit unsigned char
  }

  //Fold the cary into the first 16 bits
  sum = (sum & 0xffff) + (sum >> 16);

  //Fold the last cary into the sum
  sum += (sum >> 16);

  // ~ compliments and return
  chcksum = ~sum;

  return chcksum;
}

/* Steps to getting this running
 * 1. Send an echo request with a packet, record time of send request,
 * and ask for an echo reply from IP address
 * 2. Record the time stamp when the reply is received, if a reply
 * is received at all
 * 3. Calculate the time it took between send and return, if no return
 * time then report that packet as loss
 * 4. Repeat step 1 after a pause time interval
 */
