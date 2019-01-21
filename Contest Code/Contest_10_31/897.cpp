#include <iostream>
#include <algorithm>
#include <set>
#include <cmath>
#include <string>

using namespace std;

void perm(string n, set<string>& perms, string current);

int main(int argc, char *argv[]) {
    int n = 10000000;
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i] && (long long)i * i <= n) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    
    
    int num;
    cin >> num;
    while(num){
        bool found;
        for(auto i: primes){
            if(i<=num){
                continue;
            }
            if(i>num*10){
                break;
            }
            set<string> perms;
            found=false;
            perm(to_string(i), perms, "");
            bool notprime=false;
            for(auto it: perms){
                if(primes.count(stoi(it))==0){
                    notprime=true;
                    break;
                }
            }
            if(!notprime){
                cout << i << endl;
                found=true;
                break;
            }
        }
        if(!found){
            cout << 0 << endl;
        }
        cin >> num;
    }    
}

void perm(string n, set<string>& perms, string current){
    if(n.size()==0){
        perms.insert(current);
        return;
    }
    
    for(int i=0; i<n.size(); i++){
        string sendcurrent = current + n[i];
        string sendn = n.substr(0, i) + n.substr(i+1, n.size()-i-1);
        perm(sendn, perms, sendcurrent);
    }
}
    

    
    