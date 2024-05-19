// AYUSH JHA //

// QUESTION-1 //
// #include<iostream>
// using namespace std;
// int main(){
//     int n;
//     cin>>n;
//     int k=1;
//     for(int i=1;i<=n;i++){
//         k=1;
//         while(k<=n){
//             if(k%2==1){
//                 for(int j=1;j<=i;j++){
//                     cout<<j;
//                 }
//                 for(int j=1;j<=2*(n-i);j++){
//                     cout<<" ";
//                 }
//             }
//             else{
//                 for(int j=i;j>=1;j--){
//                 cout<<j;
//                 }
//             }
            
            
            
//             k++;
//         }
//         cout<<endl;
//     }
// }


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













// QUESTION-3 //
// #include<iostream>

// using namespace std;
// double avg;
// int above;
// int equal_avg;
// void Average(int* arr){
//     double sum=0;
//     for(int i=0;i<10;i++){
//         sum+=arr[i];
//     }
//     avg= sum/10;
//     cout<<"Average:"<<sum/10<<endl;
//     return;
// }
// void Highest(int *arr){
//     int max= INT_MIN;
//     for(int i=0;i<10;i++){
//         if(arr[i]>max) max=arr[i];
//     }
//     cout<<"Highest: "<< max<<endl;
// }
// void Lowest(int *arr){
//     int min= INT_MAX;
//     for(int i=0;i<10;i++){
//         if(arr[i]<min) min=arr[i];
//     }
//     cout<<"Lowest: "<< min<<endl;
// }

// void aboveavg(int* arr){
//     int cnt=0;
//     int cnt2=0;
//     for(int i=0;i<10;i++){
//         if(arr[i]>avg){
//             cnt++;
//         }
//         if(arr[i]==avg){
//             cnt2++;
//         }
//     }
//     above=cnt;
//     equal_avg=cnt2;
//     cout<<"above_avg: "<<cnt<<endl;
// }
// void belowavg(int* arr){
//     cout<<"below_avg: "<<10-above-equal_avg<<endl;
// }

// int main(){
//     int arr[10];
//     for(int i=0;i<10;i++){
//         cin>>arr[i];
//     }
//     Average(arr);
//     Highest(arr);
//     Lowest(arr);
//     aboveavg(arr);
//     belowavg(arr);
// }






