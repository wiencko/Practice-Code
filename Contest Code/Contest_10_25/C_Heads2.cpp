#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
int main(int argc, char *argv[]) {
    int nums, num;
    cin >> nums;
    while(nums--){
        cin >> num;
        cout << "2^-" << num << " = " << setprecision(3) << fixed << pow(10.0,-num*log10(2)-floor(-num*log10(2))) << "E" << int(floor(-num*log10(2))) << endl;
    }
}