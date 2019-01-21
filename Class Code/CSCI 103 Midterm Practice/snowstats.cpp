#include <iostream>

using namespace std;



int main(int argc, char *argv[]) {
    int t, coldest = 200, days = 0;
    double s, total = 0;
    cin >> s >> t;
    while(!cin.fail()){
        days++;
        total += s;
        if(t < coldest){
            coldest = t;
        }
        cin >> s >> t;
    }

    cout << "Number of days: " << days << endl;;
    cout << "Total snow: " << total << endl;
    cout << "Coldest temperature: " << coldest << endl;
}