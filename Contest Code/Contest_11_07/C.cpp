#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
    long s;
    cin >> s;
    for(int i=0; i<s; i++){
        vector<long long> numv;
        long nums; 
        cin >> nums;
        cin >> nums;
        for(int j=0; j<nums; j++){
            long temp;
            cin >> temp;
            numv.push_back(temp);
        }
        long count = 0;
        long pre = -1;
        while(true){
            int min = 0;
            for(int j=0; j<numv.size();j++){
                if(numv[j] < numv[min]){
                    min = j;
                }
            }
            if(numv[min] == 1E12){
                break;
            }
            if(min > pre){
                pre = min;
                numv[min] = 1E12;
                count++;
            }else{
                break;
            }
        }
        cout << i+1 << " " << nums - count << endl;
    }
}