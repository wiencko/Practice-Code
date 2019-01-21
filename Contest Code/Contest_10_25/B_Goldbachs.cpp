#include <iostream>
#include <set>
#include <cmath>

using namespace std;
int main(int argc, char *argv[]) {
    set<int> primes;
    int topbound;
    primes.insert(2);
    primes.insert(3);
    primes.insert(5);
    for(int i=7;i<1000000;i+=2){
        topbound = sqrt(i) + 1;
        for(auto it: primes){
            if(it>topbound){
                primes.insert(i);
                break;
            }
            if(i%it==0){
                break;
            }
        }
    }
    
    int number, num1, num2;
    cin >> number;
    while(number!=0){
        for(auto it: primes){
            if(primes.count(number-it)!=0){
                num1 = it;
                num2 = number-it;
                break;
            }
        }
        cout << number << " = " << num1 << " + " << num2 << endl;
        cin >> number;
    }
}