#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int main()
{
    /*Write content to file*/
    string A = "I am write this to file using file handling";
    string B;
   
    ofstream in("34.File Handle.txt");
    in << A;
    in.close();


    ifstream out("34.File Handle.txt");
     getline(out,B);
    cout<<B;
    out.close();



}