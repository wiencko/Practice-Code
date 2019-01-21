#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

using namespace std;

int score(int judgeRatings[], int J);
string best(string countries[], int C, int scores[]);

int main(int argc, char* argv[]){
    int C, J;
    ifstream s(argv[1]);
    s >> C >> J;
    string* countries = new string[C];
    int** ratings = new int*[C];
    for(int i=0; i<C; i++){
        ratings[i] = new int[J];
        s >> countries[i];
        for(int j=0; j<J; j++){
            s >> ratings[i][j];
        }
    }
    
    cout << C << endl;
    for(int i=0; i<C; i++){
        int max = ratings[i][0], min = ratings[i][0], total=0;
        for(int j=0; j<J; j++){
            total += ratings[i][j];
            if(max < ratings[i][j]){
                max = ratings[i][j];
            }
            if(min > ratings[i][j]){
                min = ratings[i][j];
            }
        }
        total = round((total-max-min)/(J-2.0));
        cout << countries[i] << " " << total << endl;
    }
}