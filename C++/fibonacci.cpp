#include <iostream>
#include <vector>

typedef long long ll;

ll fibonacci(ll n, std::vector<ll>& rem_fib);   

int main(int argc, char *argv[]) {
    ll num;
    std::cout << "Nth fibonacci number. Enter N\n";
    std::cin >> num;
    
    std::vector<ll> rem_fib(num + 1, 0);
    rem_fib[0] = 0;
    rem_fib[1] = 1;
    rem_fib[2] = 1;
    
    std::cout << fibonacci(num, rem_fib);
}

ll fibonacci(ll n, std::vector<ll>& rem_fib){
    if(rem_fib[n]!=0){
        return rem_fib[n];
    }else{
        ll value = fibonacci(n-1, rem_fib) + fibonacci(n-2, rem_fib);
        rem_fib[n] = value;
        return value;
    }
}
 