#include <iostream>

using namespace std;

int maxCycleLength(int arr[], int length){
    int max = 0;
    for(int i=0; i<length; i++){
        int count = 1;
        while((i+1)!=arr[i]){
            int temp = arr[arr[i]-1];
            arr[arr[i]-1] = arr[i];
            arr[i] = temp;
            count++;
        }
        if(count > max){
            max = count;
        }
    }
    return max;
}
        

int main(int argc, char *argv[]) {
    int hats, temphats[100], count=0, totalmax=0;
    cin >> hats;
    
    
    while(!cin.fail()){
        for(int i=0; i<hats; i++){
            cin >> temphats[i];
        }
        if(!cin.fail()){
            totalmax += maxCycleLength(temphats, hats);
            count++;
        }
    }
    cout << "Average max cycle length: " << double(totalmax)/count << endl;
}