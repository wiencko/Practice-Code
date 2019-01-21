#include <iostream>
#include <vector>

using namespace std;
const int N = 100000000;
int lp[N+1];
vector<int> primes;
void sieve(){
    lp[0] = lp[1] = -1; 
    for(int i=2; i<=N; ++i)
        lp[i] = i;
    for(int i=2; i<=N; ++i){
        if(lp[i] == i)
            primes.push_back(i);
        for(int j=0; j<(int)primes.size() && primes[j]<=lp[i] && i*primes[j]<=N; ++j)
            lp[i*primes[j]] = primes[j];
    }
}
#define isprime(i) (i==lp[i])

int main(int argc, char *argv[]) {
    sieve();
        
}