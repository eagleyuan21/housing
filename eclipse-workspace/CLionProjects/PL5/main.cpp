#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
//Import all packages needed

int main() {
    //Welcome
    cout << "Hello, user! Welcome to Eagle Yuan's Molecular weight and average weight program" << endl;
    //Constant of weights of each element
    const double Oweight = 15.9994;
    const double Cweight = 12.011;
    const double Nweight = 14.00674;
    const double Sweight = 32.066;
    const double Hweight = 1.00794;

    //initialize count of each element in amino acid
    double O, C, N, S, H;
    //set decimal precision to 3
    cout << fixed << setprecision(3);

    //Ask the amount of elements in each amino acid
    cout << "How many oxygen atoms are there? ";
    cin >> O;
    cout << "How many carbon atoms are there? ";
    cin >> C;
    cout << "How many nitrogen atoms are there? ";
    cin >> N;
    cout << "How many sulfer atoms are there? ";
    cin >> S;
    cout << "How many hydrogen atoms are there? ";
    cin >> H;

    //calculate both weight of amino acid and average weight per atom
    double weight = Oweight * O + Cweight * C + Nweight * N + Sweight * S + Hweight * H;
    double average_weightatom = weight / (O + C + N + S + H);

    //output weight of amino acid and average weight per atom
    cout << "The molecular weight of the amino acid is " << weight << " amu, and the average weight per atome is " << average_weightatom << " amu/atom";
    return 0;
}