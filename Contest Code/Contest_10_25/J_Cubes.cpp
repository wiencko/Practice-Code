#include <iostream>
#include <algorithm>
using namespace std;

class R{
    public:
        long long x, y, z, x2, y2, z2;
        R(long long a, long long b, long long c, long long d){
            x=a;
            y=b;
            z=c;
            x2=a+d;
            y2=b+d;
            z2=c+d;
        }
        int size(){
            return (x2-x)*(y2-y)*(z2-z);
        }
};
            

int main(int argc, char *argv[]) {
    int cubes;
    cin >> cubes;
    while(cubes!=0){
        long long tx, ty, tz, td;
        cin >> tx >> ty >> tz >> td;
        R ans(tx, ty, tz, td);
        cubes--;
        while(cubes--){
            cin >> tx >> ty >> tz >> td;
            R inter(tx, ty, tz, td);
            ans.x = max(inter.x, ans.x);
            ans.x2 = min(inter.x2, ans.x2);
            ans.y = max(inter.y, ans.y);
            ans.y2 = min(inter.y2, ans.y2);
            ans.z = max(inter.z, ans.z);
            ans.z2 = min(inter.z2, ans.z2);
        }
        int answer = ans.size();
        if(answer<0){
            cout << 0;
        }else{
            cout << answer;
        }
        cout << endl;
        cin >> cubes;
    }
}