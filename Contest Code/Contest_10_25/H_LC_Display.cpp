#include <iostream>
#include <vector>
#include <string>

using namespace std;
int main(int argc, char *argv[]) {
    int size;
    cin >> size;
    while(size!=0){
        string num;
        cin >> num;
        vector<string> fin(2*size+3);
        for(int i=0; i<fin.size(); i++){
            fin[i] = "";
        }
        for(int i=0; i<num.size(); i++){
            if(num[i] == '1' || num[i] == '4'){
                for(int j=0; j<2+size; j++){
                    fin[0] += " ";
                }
            }else{
                fin[0] += " ";
                for(int j=0; j<size; j++){
                    fin[0] += "-";
                }
                fin[0] += " ";
            }
            
            if(num[i] == '6' || num[i] == '5'){
                for(int j=0; j<size; j++){
                    fin[j+1] += "|";
                    for(int k=0; k<size+1; k++){
                        fin[j+1] += " ";
                    }
                }
            }else if(num[i] == '1' || num[i] == '2' || num[i] == '3' || num[i] == '7'){
                for(int j=0; j<size; j++){
                    for(int k=0; k<size+1; k++){
                        fin[j+1] += " ";
                    }
                    fin[j+1] += "|";
                }
            }else{
                for(int j=0; j<size; j++){
                    fin[j+1] += "|";
                    for(int k=0; k<size; k++){
                        fin[j+1] += " ";
                    }
                    fin[j+1] += "|";
                }
            }
            if(num[i] == '1' || num[i] == '7' || num[i] == '0'){
                for(int j=0; j<2+size; j++){
                    fin[1+size] += " ";
                }
            }else{
                fin[1+size] += " ";
                for(int j=0; j<size; j++){
                    fin[1+size] += "-";
                }
                fin[1+size] += " ";
            }
            if(num[i] == '2'){
                for(int j=0; j<size; j++){
                    fin[j+2+size] += "|";
                    for(int k=0; k<size+1; k++){
                        fin[j+2+size] += " ";
                    }
                }
            }else if(num[i] == '3' || num[i] == '4' || num[i] == '5' || num[i] == '7' || num[i] == '9' || num[i] == '1'){
                for(int j=0; j<size; j++){
                    for(int k=0; k<size+1; k++){
                        fin[j+2+size] += " ";
                    }
                    fin[j+2+size] += "|";
                }
            }else{
                for(int j=0; j<size; j++){
                    fin[j+2+size] += "|";
                    for(int k=0; k<size; k++){
                        fin[j+2+size] += " ";
                    }
                    fin[j+2+size] += "|";
                }
            }
            if(num[i] == '1' || num[i] == '4' || num[i] == '7'){
                for(int j=0; j<2+size; j++){
                    fin[2+size*2] += " ";
                }
            }else{
                fin[2+size*2] += " ";
                for(int j=0; j<size; j++){
                    fin[2+size*2] += "-";
                }
                fin[2+size*2] += " ";
            }
            
            if(i!=(num.size()-1)){
                for(int j=0; j<fin.size(); j++){
                    fin[j] += " ";
                }
            }
        }

        for(int i=0; i<fin.size();i++){
            cout << fin[i] << endl;
        }
        cout << endl;
        cin >> size;
    }
}