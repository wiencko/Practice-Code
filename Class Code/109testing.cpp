#include <iostream>

using namespace std;

void rectest(int x, int& count);
double matching(int bitmask);

int main(int argc, char *argv[]) {
    int count=0;
    int hi=0;
    rectest(10, count);
    cout << count << endl << (hi=count);
    
    
    
}

void rectest(int x, int& count){
    int i = 0;
    count++;
    while(i<x){
        i++;
        rectest(x-1, count);
    }
}

double matching(int bitmask){
    int hi;
    hi = 5;
    return hi = 6;
}