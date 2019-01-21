#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char *argv[]) {
    int size, temp;
    cin >> size;
    while(size!=0){
        vector<vector<int> > matrix;
        vector<int> empty;
        for(int i=0;i<size;i++){
            matrix.push_back(empty);
            for(int j=0;j<size;j++){
                cin >> temp;
                matrix[i].push_back(temp);
            }
        }
        vector<int> row;
        vector<int> column;
        for(int i=0;i<size;i++){
            temp=0;
            for(int j=0;j<size;j++){
                temp += matrix[i][j];
            }
            row.push_back(temp%2);
        }
        
        for(int i=0;i<size;i++){
            temp=0;
            for(int j=0;j<size;j++){
                temp += matrix[j][i];
            }
            column.push_back(temp%2);
        }
        
        int rowtotal=0, coltotal=0;
        for(int i=0; i<row.size();i++){
            rowtotal+=row[i];
        }
        for(int i=0; i<column.size();i++){
            coltotal+=column[i];
        }
        if(coltotal==0 && rowtotal==0){
            cout << "OK" << endl;
        }else if(coltotal==1 && rowtotal==1){
            int rowloc, colloc;
            for(int i=0; i<row.size();i++){
                if(row[i] == 1){
                    rowloc = i+1;
                }
            }
            for(int i=0; i<column.size();i++){
                if(column[i] == 1){
                    colloc = i+1;
                }
            }
            cout << "Change bit (" << rowloc << "," << colloc << ")\n";
        }else{
            cout << "Corrupt\n";
        }
        cin >> size;
    }
}