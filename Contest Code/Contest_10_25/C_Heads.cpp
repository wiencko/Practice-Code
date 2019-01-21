#include <iostream>
#include <iomanip>

using namespace std;
int main(int argc, char *argv[]) {
    int nums;
    cin >> nums;
    int num;
    while(nums--){
        int decimals=0;
        long double total = 1;
        cin >> num;
        cout << "2^-" << num << " = ";
        while(num--){
            total/=2;
            if(total<1){
                total*=10;
                decimals++;
            }
        }
        cout << setprecision(3) << fixed << total << "E-" << decimals << endl;
    }
}