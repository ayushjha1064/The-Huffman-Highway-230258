// QUESTION-2 //
#include <iostream>
#include <cmath> // For trigonometric functions (sin, cos, etc.)

using namespace std;

// Function to perform addition
float add(float a, float b) {
    return a + b;
}

// Function to perform subtraction
float subtract(float a, float b) {
    return a - b;
}

// Function to perform multiplication
float multiply(float a, float b) {
    return a * b;
}

// Function to perform division
float divide(float a, float b) {
    if (b != 0) {
        return a / b;
    } else {
        cout << "Error: Division by zero!" << endl;
        return 0; 
    }
}

// Function to calculate the natural logarithm (ln)
float naturalLog(float x) {
    return log(x);
}

// Function to calculate sine (sin)
float sine(float x) {
    return sin(x);
}

// Function to calculate the remainder (mod)
float mod(float a, float b) {
    if (b != 0) {
        return fmod(a, b);
    } else {
        cout << "Error: Division by zero in mod operation!!" << endl;
        return 0; 
    }
}

int main() {
    char op;
    float num1, num2;

    cout << "Enter operator (+, -, *, /, ln (only l), sin (only s), mod (only m)): ";
    cin >> op;

    if (op == '+' || op == '-' || op == '*' || op == '/'|| op== 'm') {
        cout << "Enter two operands: ";
        cin >> num1 >> num2;

        switch (op) {
            case '+':
                cout << "Result: " << add(num1, num2) << endl;
                break;
            case '-':
                cout << "Result: " << subtract(num1, num2) << endl;
                break;
            case '*':
                cout << "Result: " << multiply(num1, num2) << endl;
                break;
            case '/':
                cout << "Result: " << divide(num1, num2) << endl;
                break;
            case 'm':
                cout << "Remainder (mod) of " << num1 << " = " << mod(num1, num2) << endl;
                break;
        }
    } else if (op == 'l' || op == 's') {
        cout << "Enter a value: ";
        cin >> num1;

        switch (op) {
            case 'l':
                cout << "Natural logarithm (ln) of " << num1 << " = " << naturalLog(num1) << endl;
                break;
            case 's':
                cout << "Sine (sin) of " << num1 << " = " << sine(num1) << endl;
                break;
            
        }
    } else {
        cout << "Error: Invalid operator!" << endl;
    }

    return 0;
}