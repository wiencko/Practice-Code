#include <iostream>

using namespace std;

bool isD(int r[], int length){
    bool d = true;
    for(int i=1; i<=length; i++){
        if(i==r[i-1]){
            d = false;
        }
    }
    return d;
}

int main(int argc, char *argv[]) {
    int hats, ds = 0;
    cin >> hats;
    int hattemp[100], first[100];
    while(true){
        for(int i=0; i<hats; i++){
            cin >> hattemp[i];
            if(cin.fail()){
                break;
            }
        }
        if(cin.fail()){
            break;
        }
        
        if(isD(hattemp, hats)){
            if(!ds){
                for(int i=0; i<hats; i++){
                    first[i] = hattemp[i];
                }
            }
            ds++;
        }
    }
    if(ds){
        cout << "First derangement:";
        for(int i=0; i<hats; i++){
            cout << " " << first[i];
        }
        cout << endl;
    }
    cout << "Number of derangements: " << ds << endl;   
}