#include<iostream>
using namespace std;
class constructor{
	int m,n;
	public:
		constructor(void){
			m=12;
			n=20;
			cout<<"Value of m is :" <<m <<endl<< "Value of n is :"<<n<<endl;
		}
		
};
int main(){
	constructor a;
;}
