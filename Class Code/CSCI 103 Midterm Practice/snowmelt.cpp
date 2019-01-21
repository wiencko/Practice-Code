#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

double meltage(double currSnow, int temp, int salt){
    return min(currSnow, pow((1 + currSnow), (temp-32+2*salt)/18.0));
}

void printArray(double arr[], double length){
    for(int i=0; i<length; i++){
        cout << setw(8) << setprecision(3) << arr[i];
    }
    cout << endl;
}

int main(int argc, char *argv[]) {
    int sets = argc - 1;
    double snowleft[100];
    while(true){
        double s;
        int t;
        cin >> s >> t;
        if(cin.fail()){
            return 0;
        }
        
        for(int i=0; i < sets; i++){
            snowleft[i] += s;
            snowleft[i] -= meltage(snowleft[i], t, atoi(argv[i+1]));
        }
        printArray(snowleft, sets);
    }

}