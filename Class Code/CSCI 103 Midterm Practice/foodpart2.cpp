#include <iostream>
#include <string>

using namespace std;

string best(string countries[], int scores[], int C);

int main(int argc, char *argv[]) {
    int C;
    cin >> C;
    string* countries = new string[C];
    int* scores = new int[C];
    
    for(int i=0; i<C; i++){
        cin >> countries[i] >> scores[i];
    }
    
    for(int i=1; i<=atoi(argv[1]); i++){
        cout << "Rank " << i << ": " << best(countries, scores, C) << endl;
    }
}

string best(string countries[], int scores[], int C){
    int max = 0;
    for(int i=0; i<C; i++){
        if(scores[max] < scores[i]){
            max = i;
        }
    }
    scores[max] = 0;
    return countries[max];
}
        
        