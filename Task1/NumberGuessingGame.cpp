#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int main(){
    srand((unsigned int) time(NULL));
    int number = (rand() % 100) + 1;
    int guess = 0;
    do{
        cout<<"Enter Your Guessing Number Between 1 to 100: ";
        cin>>guess;
        if (guess>number){
            cout<<"Guess a smaller number"<<endl;
        }else if(guess<number){
            cout<<"Guess a greater number"<<endl;
        }else{
            cout<<"You Won!"<<endl;
        }
    }while(guess != number);
    return 0;
}