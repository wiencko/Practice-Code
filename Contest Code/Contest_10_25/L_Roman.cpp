#include <iostream>
#include <map>
#include <string>

using namespace std;
int main(int argc, char *argv[]) {
    map<char, int> r = {{'I', 1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
    map<char, int> c = {{'I', 0},{'V',0},{'X',0},{'L',0},{'C',0},{'D',0},{'M',0}};
    string line;
    while(cin>>line){
        int minval;
        bool valid=true;
        int total=0;
        minval = r[line[line.size()]];
        for(int i=line.size()-1;i>=0;i--){
            c[line[i]]++;
            if(r[line[i]]<minval){
                if(line[i]!='I'&&line[i]!='X'&&line[i]!='C'){
                    valid=false;
                }
                if(r[line[i+1]]!=minval){
                    valid=false;
                }else{
                    total-=r[line[i]];
                }
            }else{
                total+=r[line[i]];
                minval=r[line[i]];
            }
        }
        if(c['I']>4||c['V']>1||c['X']>4||c['L']>1||c['C']>4||c['D']>1){
            valid=false;
        }
        
        if(valid){
            cout << total << endl;
        }else{
            cout << "This is not a valid number" << endl;
        }
    }
}