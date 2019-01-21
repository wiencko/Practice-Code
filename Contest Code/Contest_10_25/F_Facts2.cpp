#include <iostream>
#include <iomanip>

using namespace std;
int main(int argc, char *argv[]) {
    int num;
    unsigned long long current;
    while(cin >> num){
        current = 1;
        for(int i=1; i<=num; i++){
            current *= i;
            while(current%10==0){
                current/=10;
            }
            current = current%10000000000000;
        }
        current = current%10;
        cout << setw(5) << num << " -> " << setw(1) << current << endl;
    }
}
        
            
            
            