#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
    int sets;
    cin >> sets;
    for(int z=1; z<=sets; z++){
        cout << z << " ";
        string num;
        cin >> num >> num;
        long long answer = 0;
        long long place = 1;
        for(int i=num.size()-1; i>=0; i--){
            if(num[i] - '0' > 7){
                answer = 0;
                break;
            }
            answer += ((long long)(num[i]-'0'))*place;
            place *= 8;
        }
        cout << answer << " " << num << " ";
        
        answer = 0;
        place = 1;
        for(int i=num.size()-1; i>=0; i--){
            answer += ((long long)(num[i]-'0'))*place;
            place *= 16;
        }
        cout << answer << endl;
    }
}