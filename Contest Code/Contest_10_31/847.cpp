#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    long num;
    while(cin>>num){
        double n = num/18.0;
        while(n>1){
            n/=18.0;
        }
        if(n>.5){
            cout << "Ollie wins.";
        }else{
            cout << "Stan wins.";
        }
        cout << endl;
    }
        
}