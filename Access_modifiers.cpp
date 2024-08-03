#include<iostream>
using namespace std;
class myclass1{
	public:
		myfun(){
			cout << "This is public"<<endl;
		}
};

class myclass2{
	private:
	int radious;
	public:
	double area(){
	 return 3.14*radius*radius;
	} 
}

int main(){
	myclass1 obj;
	obj.myfun();

	myclass2 obj2;
	obj2.radious=15;

	cout << "Area is :"<< obj2.area<<endl;
}
