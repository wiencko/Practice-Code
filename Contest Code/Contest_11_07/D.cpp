#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
    map<char, int> value= {{'0',0},{'1',1},{'2',2},{'3',3},{'4',4},{'5',5},{'6',6},{'7',7},{'8',8},{'9',9},{'A',10},{'C',11},{'D',12},{'E',13},{'F',14},{'H',15},{'J',16},{'K',17},{'L',18},{'M',19},{'N',20},{'P',21},{'R',22},{'T',23},{'V',24},{'W',25},{'X',26}};
    map<char, char> replace = {{'B','8'},{'G','C'},{'I','1'},{'O','0'},{'Q','0'},{'S','5'},{'U','V'},{'Y','V'},{'Z','2'}};
    int P;
    cin >> P;
    for(int z=1; z<=P; z++){
        string line;
        cin >> line >> line;
        cout << z;
        for(int i=0; i<line.size(); i++){
            if(replace[line[i]] != 0){
                line[i] = replace[line[i]];
            }
        }
        unsigned long long answer = (2*value[line[0]] + 4*value[line[1]] + 5*value[line[2]] + 7*value[line[3]] + 8*value[line[4]] + 10*value[line[5]] + 11*value[line[6]] + 13*value[line[7]]);
        if(answer%27 == value[line[8]]){
            long long count = 1;
            answer = 0;
            for(int i=7; i>=0; i--){
                answer += value[line[i]]*count;
                count *= 27;
            }
            cout << " " << answer;
        }else{
            cout << " Invalid";
        }
        cout << endl;
        
        
        
    } 
    
    
}