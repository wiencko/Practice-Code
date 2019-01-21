#include <iostream>
#include <map>
#include <cmath>
#include <set>
#include <vector>

using namespace std;

int gcd(int x, int y){
    return x==0 ? y : gcd(y % x, x);
}

int main(int argc, char *argv[]) {
    int n;
    while(cin >> n){
        int count1 = 0, count2 = 0;
        for(int z=3; z<=n; z++){
            for(int y=2; y<z; y++){
                for(int x=1; x<y; x++){
                    cout << x << " " << y << " " << z << endl;
                    if((x*x + y*y) == z*z){
                        
                        if(1 != gcd(gcd(x*x, y*y), z*z)){
                            count1++;
                        }
                    }
                }
            }
        }
        cout << count1 << " " << count2 << endl;
    }
}

