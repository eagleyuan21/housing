#include <iostream> //import packages
#include <cmath>
using namespace std;

double inertia(char sha); //declare the function that calculates inertia

int main() {
    char again = 'Y'; //initial Yes variable to be repeated
    cout << "Welcome to the moment of inertia calculator by Eagle Yuan" << endl; //welcome
    while(again == 'Y') { //While yes, program repeats
        char shape = 'L';
        double answer = 0;
        cout << "What is the shape of the object? (Circle: C, Rectangle: R, Triangle: T): ";
        cin >> shape; //asks user for shape of object;

        while(!(shape == 'C' || shape == 'R' || shape == 'T'))
        {
            cout << "Invalid input. Try again: ";
            cin >> shape; //While loop makes sure shape is valid
        }

        answer = inertia(shape); //pass the calculation through the function
        cout << "The moment of inertia is " << answer << " mm^4" << endl; //output moment of inertia
        cout << "Would you like to calculate again? (Y/N): ";
        cin >> again; //asks for repeat again
        while(!(again == 'Y' || again == 'N'))
        {
            cout << "Invalid input. Try again: ";
            cin >> again; //makes sure input is either Y or N
        }
    }
    return 0;
}

double inertia(char sha)
{   //split the three characters, otherwise return 0
    if(sha == 'C') //Circle if statement
    {
        double radius = 0;
        cout << "What is the radius of your circle? (mm) ";
        cin >> radius; //ask for radius
        while (radius < 0)
        {
            cout << "Invalid input. Try again: ";
            cin >> radius; //makes sure radius input is valid
        }
        return M_PI * radius * radius * radius * radius / 4; //return calculated value
    }
    else if(sha == 'R') //Rectangle if statement
    {
        double height, base = 0;
        //asks for both height and base and makes sure they're valid inputs
        cout << "What is the base of your rectangle? (mm) ";
        cin >> base;
        while (base < 0)
        {
            cout << "Invalid input. Try again: ";
            cin >> base;
        }
        cout << "What is the height of your rectangle? (mm) ";
        cin >> height;
        while (height < 0)
        {
            cout << "Invalid input. Try again: ";
            cin >> height;
        }
        return base * height * height * height / 12; //calculate and return moment of inertia
    }
    else if(sha == 'T') //Triangle if statement
    {
        double height, base;
        //asks for both height and base and make sure they're valid
        cout << "What is the base of your triangle? (mm) ";
        cin >> base;
        while (base < 0)
        {
            cout << "Invalid input. Try again: ";
            cin >> base;
        }
        cout << "What is the height of your triangle? (mm) ";
        cin >> height;
        while (height < 0)
        {
            cout << "Invalid input. Try again: ";
            cin >> height;
        }
        return base * height * height * height / 12; //return triangle moment of inertia
    }
    else{ //Just in case return 0
        return 0;
    }
}
