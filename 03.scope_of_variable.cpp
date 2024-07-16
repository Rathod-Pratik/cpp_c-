#include<iostream>
using namespace std;
char G[]="I am global variable";

int main(){
    char a[]="I am local variable";

    cout << a << endl;
    cout << G << endl;

    return 0;
}