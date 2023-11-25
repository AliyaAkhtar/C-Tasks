#include<iostream>
#include<cmath>
using namespace std;

int main(){

    double num1,num2;
    char operat;

    cout<<"Enter the operator (+ - * / % ^): ";
    cin>>operat;
    cout<<"Enter first number: ";
    cin>>num1;
    cout<<"Enter second number: ";
    cin>>num2;
    
    switch(operat){
        case '+':
        cout<<"The addition of "<<num1<<" and "<<num2<<" is "<<num1+num2<<endl;
        break;

        case '-':
        cout<<"The subtraction of "<<num1<<" and "<<num2<<" is "<<num1-num2<<endl;
        break;

        case '*':
        cout<<"The multiplication of "<<num1<<" and "<<num2<<" is "<<num1*num2<<endl;
        break;

        case '/':
        if(num2==0.0){
            cout<<"Cannot be divided by 0!"<<endl;
        }else{
            cout<<"The division of "<<num1<<" and "<<num2<<" is "<<num1/num2<<endl;
        }
        break;

        case '%':
        cout<<"The modulus of "<<num1<<" and "<<num2<<" is "<<int(num1)%int(num2)<<endl;
        break;

        case '^':
        cout<<num1<<" raised to the power "<<num2<<" is "<<pow(num1, num2)<<endl;
        break;

        default:
        cout<<"Invalid Operator!"<<endl;
    }
    return 0;
}