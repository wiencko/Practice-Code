#include <iostream>
#include <vector>
#include <queue>

int mod[9][2] = {{1,1},{1,0},{1,-1},{0,1},{0,-1},{-1,1},{-1,0},{-1,-1}};

using namespace std;
int main(int argc, char *argv[]) {
    int m, n;
    cin >> m >> n;
    while(m!=0){
        vector<vector<char> > g(m, vector<char> (n));

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
        cout << total << endl;
        cin >> m >> n;
    }
}