#include<iostream>
#define PI 3.14
using namespace std;
int main()
{
int X,Y;
X = 2 * PI;
cout<<"enter the number :\n";
cin>>X;
Y=X%2;
if(Y==0)
cout<<"number is even\n";
else
cout<<"number is odd\n";
return 0;
}
