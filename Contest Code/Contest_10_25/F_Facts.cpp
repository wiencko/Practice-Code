#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
    int num;
    int current;
    int inum;
    while(cin >> num){
        current = 1;
        for(int i=1; i<=num; i++){
            inum = i;
            while(true){
                if(inum==0){
                    inum = 1;
                    break;
                }
                if(inum%10!=0){
                    inum = inum%10;
                    break;
                }
                inum /= 10;
            }
            cout << inum << " ";
                
            if(current%10==0) current=(current/10)%10;
            if(inum!=0){
                current = current * inum;
                cout << current << " ";
                if(current%10==0){
                    current = (current/10);
                }                
                current = current%10;
                cout << current << " " << endl;
            }
        }
        //cout << current << endl;
    }
            
}