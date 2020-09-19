#include <iostream>
using namespace std;

int main() {
    char output = 'Y';
    while(output == 'Y') {
        cout << "Hello, welcome to Eagle's simple calculator!" << endl;
        double first, second, answer;
        char operation;
        cout << "Enter an operator (+, -, *, /): ";
        cin >> operation;
        cout << "Enter your first number: ";
        cin >> first;
        cout << "Enter your second number: ";
        cin >> second;
        if (operation == '+') {
            answer = first + second;
            cout << first << operation << second << "=" << answer << endl;
        } else if (operation == '-') {
            answer = first - second;
            cout << first << operation << second << "=" << answer << endl;
        } else if (operation == '*') {
            answer = first * second;
            cout << first << operation << second << "=" << answer << endl;
        } else if (operation == '/') {
            answer = first / second;
            cout << first << operation << second << "=" << answer << endl;
        } else {
            cout << "Error! Operator is not correct" << endl;
        }

        cout << "Do you want to try another calculation? (Y/N): ";
        cin >> output;
        cout << "*************************" << endl;
    }
}