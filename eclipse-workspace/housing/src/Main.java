import java.util.List;
import java.util.ArrayList;
import java.util.Scanner;
import java.lang.Math; 


public class Main { 
	public static void main(String[] args)
  {
    List<int[]> dorms = new ArrayList<int[]>();
    int[] dummy = new int[4];
    int[] students = new int[9052];
    int var = 0;
    Scanner input = new Scanner(System.in);
    System.out.print("Enter your groups highest lottery number: ");
    int number = input.nextInt();
    int output = 0;
    int howmany = 10000;
    while(5000 > number || number > 9051)
    {
      System.out.print("Not a valid second year lottery number. Try again: ");
      number = input.nextInt();
    }
    int target = number;
    
    int average = 0;
    for(int n = 0; n < howmany; n++)
    {
      students = new int[9052];
      for(int i = 0; i < 9052; i++)
      {
        students[i] = (i + 1);
      }
      for(int j = 0; j < 5000; j++)
      {
        dummy = new int[4];
        if(students[j] != 0)
        {
          dummy[0] = students[j];
          students[j] = 0;
            
          for(int k = 1; k < 4; k++)
          {
            var = (int) (Math.random() * 5000);
            if(students[var] == 0 || students[var] == target)
            {
              k--;
            }
            else{
              dummy[k] = students[var];
              students[var] = 0;
            }
          }
          dorms.add(dummy);
        }
      }

      for(int a = 5000; a < 9052; a++)
      {
        dummy = new int[4];
        if(students[a] != 0)
        {
          dummy[0] = students[a];
          students[a] = 0;
            
          for(int k = 1; k < 4; k++)
          {
            var = (int) (Math.random() * 4052) + 5000;
            if(students[var] == 0 || students[var] == target)
            {
              k--;
            }
            else{
              dummy[k] = students[var];
              students[var] = 0;
            }
          }
          dorms.add(dummy);

        }
      }
    
      output = 0;
      for(int y = 0; y < dorms.size(); y++)
      {
        dummy = dorms.get(y);
        if(target == dummy[0])
        {
          output = y + 1;
          //System.out.println(output);
        }
      }
      average += output;

      dorms = new ArrayList<int[]>();
    }
    System.out.println("In only upperclassmen students, you will be about the " + Math.round(average / howmany) + " pick out of 2263 picks");
  } 
}