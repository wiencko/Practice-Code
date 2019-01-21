#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
#include <iomanip>

int mod[9][2] = {{1,1},{1,0},{1,-1},{0,1},{0,-1},{-1,1},{-1,0},{-1,-1}};

using namespace std;
int main(int argc, char *argv[]) {
    string temp;
    getline(cin, temp);
    while(temp!=""){
        vector<vector<char> > g;
        vector<vector<int> > ans;
        vector<int> w;
        
        if(temp=="%"){
            getline(cin, temp);
        }
        while(!(temp=="" || temp=="%")){
            g.push_back(vector<char> ());
            ans.push_back(vector<int> ());
            for(int i=0; i<temp.size(); i++){
                if(temp[i]!=' '){
                    g[g.size()-1].push_back(temp[i]);
                    ans[g.size()-1].push_back(0);
                }
            }
            getline(cin, temp);
        }
        int cnt = 0;
        int n, m;
        m = g.size();
        n = g[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(isalpha(g[i][j])){
                    cnt++;
                    ans[i][j] = cnt;
                    char tc = g[i][j];
                    g[i][j] = ' ';
                    queue<pair<int, int> > q;
                    q.push(std::make_pair(i,j));
                    while(!q.empty()){
                        pair<int, int> p = q.front();
                        int a=p.first, b=p.second;
                        q.pop();
                        for(int k=0; k<9; k++){
                            int x=a+mod[k][0];
                            int y=b+mod[k][1];
                            if(x<0 || y<0 || x>=m || y>=n){
                                continue;
                            }
                            if(g[x][y] == tc){
                                ans[x][y] = cnt;
                                g[x][y] = ' ';
                                q.push(std::make_pair(x,y));
                            }
                        }
                    }
                }
            }
        }
        for(int i=0; i<ans[0].size(); i++){
            int mx = 1;
            for(int j=0; j<ans.size(); j++){
                mx = max(mx, int (log10((double) ans[j][i])+1));
            }
            w.push_back(mx);
        }
                
                
        for(int i=0; i<ans.size(); i++){
            for(int j=0; j<ans[0].size(); j++){
                cout << setw(w[j]) << ans[i][j];
                if(j!=(ans[0].size()-1)){
                    cout << " ";
                }
            }
            cout << endl;
        }
        cout << "%" << endl;
    }
}

            /*
            
                    
                
            

            for(int i=0; i<m; i++){
                for(int j=0; j<n; j++){
                    cin >> g[i][j];
                }
            }
            int total=0;
            for(int i=0; i<m; i++){
                for(int j=0; j<n; j++){
                    if(g[i][j] == '@'){
                        g[i][j] = '*';
                        total++;
                        queue<pair<int, int> > q;
                        q.push(std::make_pair(i,j));
                        while(!q.empty()){
                            pair<int, int> p = q.front();
                            int a=p.first, b=p.second;
                            q.pop();
                            for(int k=0; k<9; k++){
                                int x=a+mod[k][0];
                                int y=b+mod[k][1];
                                if(x<0 || y<0 || x>=m || y>=n){
                                    continue;
                                }
                                if(g[x][y] == '@'){
                                    g[x][y] = '*';
                                    q.push(std::make_pair(x,y));
                                }
                            }
                        }
                    }
                }
            }
            */


        