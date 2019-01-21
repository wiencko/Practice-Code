#include <iostream>
#include <string>
#include <set>
#include <sstream>

using namespace std;
int main(int argc, char *argv[]) {
    string word,line;
    cin >> word;
    set<string> dict;
    int matches[27] = {0};
    while(word != "#"){
        dict.insert(word);
        cin >> word;
    }
    getline(cin, word);
    getline(cin, line);
    for(int i=0;i<27;i++){
        string templine="";
        for(int j=0; j<line.size();j++){
            if(line[j]==' '){
                line[j] = char('A' + 26);
            }
            templine += char((((line[j] - 'A')+i)%27)+'A');
            if(templine[j]==('A' + 26)){
                templine[j] = ' ';
            }
        }
        stringstream s(templine);
        while(s >> word){
            for(auto it: dict){
                if(it == word){
                    matches[i]++;
                }
            }
        }
    }
    int maxshift=0;
    for(int i=0; i<27; i++){
        if(matches[i] > matches[maxshift]){
            maxshift = i;
        }
    }
    string templine="";
    for(int j=0; j<line.size();j++){
        if(line[j]==' '){
            line[j] = char('A' + 26);
        }
        templine += char((((line[j] - 'A')+maxshift)%27)+'A');
        if(templine[j]==('A' + 26)){
            templine[j] = ' ';
        }
    }
    stringstream s(templine);
    int count=0;
    while(s >> word){
        if(count==0){
            cout << word;
            count+=word.size();
        }else if((count+word.size())<=60){
            if(1+count+word.size()<=60){
                cout << " ";
                count++;
            }
            count+=word.size();
            cout << word;
        }else{
            cout << endl;
            count=1+word.size();
            cout << word;
            
        }
        
    }
    cout << endl;
}