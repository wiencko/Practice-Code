#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <iomanip>
#include <algorithm>

class A{
    public:
        int team, ptime, problem, solved;
        A(int t, int p, int pt, int s){
            team=t;
            ptime=pt;
            problem=p;
            solved=s;
        }
};

class T{
    public:
        int tnum, ttime, tsolved;
        T(int a){
            tnum=a;
            ttime=0;
            tsolved=0;
        }
};

using namespace std;
int main(int argc, char *argv[]) {
    int sets;
    cin >> sets;
    string temp;
    getline(cin, temp);
    getline(cin, temp);
    while(sets--){
        string temp;
        vector<A> info;
        getline(cin, temp);
        set<int> teams, problems;
        vector<T> tstats;
        
        while(temp!=""){
            int modif=0;
            if(temp[1]!=' '){
                modif=1;
            }
            info.push_back(A(stoi(temp.substr(0,1+modif)), 1+temp[2+modif]-'A',
            (temp[4+modif]-'0')*60+stoi(temp.substr(6+modif,2)), int(temp[9+modif]=='Y')));
            getline(cin, temp);
        }
        for(auto it: info){
            teams.insert(it.team);
            problems.insert(it.problem);
        }
        
        for(int i=1; i<=*teams.rbegin(); i++){
            tstats.push_back(T(i));
        }
        for(auto& tn: tstats){
            for(auto ps: problems){
                int solved=0, tt=1E9, fc=1E9;
                for(auto it: info){
                    if((it.problem==ps) && (it.solved) && (tn.tnum==it.team)){
                        solved=1;
                        if(it.ptime<fc){
                            fc=it.ptime;
                        }
                    }
                }
                tt=fc;
                for(auto it: info){
                    if((it.problem==ps) && (it.ptime<=fc) && (!(it.solved)) && (tn.tnum==it.team)){
                        tt+=20;
                    }
                }
                if(solved){
                    tn.ttime+=tt;
                    tn.tsolved+=1;
                }
            }
        }
        sort(tstats.begin(), tstats.end(), 
        [](const T & a, const T & b){
            double aa=0,bb=0;
            aa+=a.tsolved*10000000 - a.ttime*100 - a.tnum;
            bb+=b.tsolved*10000000 - b.ttime*100 - b.tnum;
            return aa > bb;
        });
        
        cout << "RANK TEAM PRO/SOLVED TIME"<< endl;
        int rank=1;
        for(int i=0; i<tstats.size();i++){
            
            cout << setw(4) << rank << " " << setw(4) << tstats[i].tnum;
            if((tstats[i].tsolved)!=0){
                cout << " " << setw(4) << tstats[i].tsolved << "       "  << setw(4) << tstats[i].ttime;
            }
            if(i!=(tstats.size()-1)){
                if((tstats[i].ttime!=tstats[i+1].ttime)||tstats[i].tsolved!=tstats[i+1].tsolved){
                    rank=2+i;
                }
            }
            cout << endl;
        }
        if(sets!=0){
            cout << endl;
        }
    }
}
