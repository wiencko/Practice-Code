#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
    vector<char> primes(100000001, true);
    primes[0] = false;
    primes[1] = false;
    for(int i=4; i<primes.size(); i+=2){
        primes[i] = false;
    }
    for(int i=3; i*i<primes.size(); i+=2){
        if(primes[i]){
            for(int j=i*2; j<primes.size(); j+=i){
                primes[j] = false;
            }
        }
    }
    
        
    
}