#include <iostream>
#include <set>
#include <string>
#include <map>

using namespace std;
int main(int argc, char *argv[]) {
    map<char, char> m = {{'A','2'},{'B','2'},{'C','2'},{'D','3'},{'E','3'},{'F','3'},{'G','4'},{'H','4'},{'I','4'},{'J','5'},{'K','5'},{'L','5'},{'M','6'},{'N','6'},{'O','6'},{'P','7'},{'R','7'},{'S','7'},{'T','8'},{'U','8'},{'V','8'},{'W','9'},{'X','9'},{'Y','9'},{'0','0'},{'1','1'},{'2','2'},{'3','3'},{'4','4'},{'5','5'},{'6','6'},{'7','7'},{'8','8'},{'9','9'}};

    int ds;
    cin >> ds;
    while(ds--){
        set<string> ss;
        multiset<string> times;
        int nums;
        cin >>nums;
        while(nums--){
            string line,temp="";
            cin >> line;
            for(auto it:line){
                if(it!='-'){
                    temp+=m[it];
                }
            }
            ss.insert(temp);
            times.insert(temp);
        }
        bool dupe=false;
        for(auto it: ss){
            if(times.count(it)>1){
                dupe=true;
            }
        }
        if(dupe){
            for(auto it: ss){
                if(times.count(it)>1){
                    cout << it.substr(0,3) << "-" << it.substr(3,4) << " " << times.count(it) << endl;
                }
            }
        }else{
            cout << "No duplicates." << endl;
        }
        if(ds!=0){
            cout << endl;
        }
    }
}