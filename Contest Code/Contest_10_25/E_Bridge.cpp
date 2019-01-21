#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int main(int argc, char *argv[]) {
    map<char, int> conv = {{'C', 100}, {'D', 200}, {'S', 300}, 
    {'H', 400}, {'2', 2}, {'3', 3}, {'4', 4}, {'5' , 5}, {'6' , 6}, {'7', 7}, {'8', 8}, {'9', 9}, {'T', 10}, {'J', 11}, {'Q', 12}, {'K', 13}, {'A', 14}};
    map<int, char> unconv = {{100, 'C'}, {200, 'D'}, {300, 'S'}, 
        {400, 'H'}, {2, '2'}, {3, '3'}, {4, '4'}, {5 , '5'}, {6 , '6'}, {7, '7'}, {8, '8'}, {9, '9'}, {10, 'T'}, {11, 'J'}, {12, 'Q'}, {13, 'K'}, {14, 'A'}};
    //hand is south west north east
    map<char, int> dir = {{'S', 0}, {'W', 1}, {'N', 2}, {'E', 3}};
    int dirs[4] = {'S', 'W', 'N', 'E'};
    char direction;
    string result;
    string s1, s2;
    while(cin >> direction){
        vector<vector<string> > hand(4);
        vector<vector<int> > nhand(4);
        vector<vector<string> > reshand(4);
        if(direction=='#'){
            break;
        }
        cin >> s1 >> s2;
        s1 = s1 + s2;
        for(int i=0; i<52; i++){
            hand[(1+i+dir[direction])%4].push_back(s1.substr(i*2, 2));
        }

        for(int i=0; i<4; i++){
            for(int j=0; j<13; j++){
                nhand[i].push_back(conv[hand[i][j][0]]+conv[hand[i][j][1]]);
            }
            sort(nhand[i].begin(), nhand[i].end());
        }
 
        for(int i=0; i<4; i++){
            for(int j=0; j<13; j++){
                result = unconv[(nhand[i][j]/100)*100];
                result += unconv[nhand[i][j]%100];
                reshand[i].push_back(result);
            }
        }
        for(int i=0; i<4; i++){
            cout << char(dirs[i]) << ":";
            for(int j=0; j<13; j++){
                cout << " " << reshand[i][j];
            }
            cout << endl;
        }
        
    }
    
    
}