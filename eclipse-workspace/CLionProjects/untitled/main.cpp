//THis program is written by Professor
#include <iostream>// to use input & output header file
#include <iomanip>// to use fixed, set precision header file
#include <cmath>

using namespace std; // to use standard c++ symbols
int main () {
// declare variables and their data types
// output what this program does and your name
    const double PI = 3.14159;
    double rad1, rad2, rad3;
    cout << "Please Enter First Radius: ";
    cin >> rad1;
    cout << "Please Enter Second Radius: ";
    cin >> rad2;
    cout << "Please Enter Second Radius: ";
    cin >> rad3;

    cout << fixed << setprecision(3);

    cout << "The area and circumference of the first circle are " << rad1 * rad1 * PI << ", and " << PI * 2* rad1 << ", respectively" <<endl;
    cout << "The area and circumference of the second circle are " << rad2 * rad2 * PI << ", and " << PI * 2* rad2 << ", respectively" <<endl;
    cout << "The area and circumference of the third circle are " << rad3 * rad3 * PI << ", and " << PI * 2* rad3 << ", respectively" <<endl;
    // Ask user for three different radius
    // Calculate C and A from R for each one
    // Return answers to use with 3 decimal places
    return 0;
}