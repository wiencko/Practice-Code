#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

void read(const char filename[], int* n, double numbers[], string items[]);

int main(int argc, char *argv[]) {
    double numbers[100];
    string items[100];
    int n;
    read(argv[2], &n, numbers, items);

    for(int i=0; i<n; i++){
        cout << numbers[i]*atoi(argv[1]) << " " << items[i] << endl;
    }
    
    
}

void read(const char filename[], int* n, double numbers[], string items[]){
    freopen(filename,"r", stdin);
    double num;
    string item;
    cin >> num >> item;
    int count = 0;
    while(!cin.fail()){
        count++;
        numbers[count-1] = num;
        items[count-1] = item;
        cin >> num >> item;
    }
    *n = count;
}
        