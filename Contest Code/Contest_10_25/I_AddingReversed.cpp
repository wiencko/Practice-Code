#include <iostream>
#include <string>

using namespace std;
int main(int argc, char *argv[]) {
    int numsets;
    cin >> numsets;
    string num1, num2, res;
    while(numsets--){
        cin >> num1 >> num2;
        res = "";
        int size1 = num1.size();
        int size2 = num2.size();
        if(size1 > size2){
            for(int i=size2; i<size1; i++){
                num2+='0';
            }
        }else if(size1 < size2){
            for(int i=size1; i<size2; i++){
                num1+='0';
            }
        }
        bool carry = 0;
        int temp;
        for(int i=0; i<num1.size(); i++){
            temp = (num1[i] - '0') + (num2[i] - '0');
            res += to_string((carry + temp) % 10);
            carry = (temp+carry)/10;
        }
        if(carry){
            res+='1';
        }
        while(res[0]=='0'){
            res = res.substr(1,res.size()-1);
        }

        cout << res << endl;
    }
}