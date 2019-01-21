#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int f1(int x, int y)
{
return (double) (x/y);
}
int main()
{
int x = 10, y=4, a = 11, b = 8;
double z = 12.5;
cout << 19 % 5 << endl;
cout << 5 / 2 << endl; //_________________
cout << 5 + 3 % 2 * x / 4 << endl;// _________________
cout << (a++ + b) << endl; //_________________
cout << (++a - b) << endl; //_________________
cout << boolalpha << (x && (y || y/x)) << endl;// _________________
cout << pow(2, y) << endl; //_________________
cout << min(max(min(x,y),x-1),(int)z) << endl;// _________________
cout << f1(12,b) << endl;// _________________
//return 0;

char data[3] = {'h','t','\0'};
cout << data << endl;
int data2[3] = {1,2,3};
cout << data2 << endl;


cout << strlen("hi") << endl;


return 0;
}