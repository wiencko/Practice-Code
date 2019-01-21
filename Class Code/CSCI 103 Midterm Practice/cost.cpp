#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

void read(const char filename[], int* n, double numbers[], string items[]);

int main(int argc, char *argv[]) {
    double itemnums[100], prices[100];
    string itemnames[100], pricenames[100];
    int numitems, numstoreitems;
    read(argv[1], &numitems, itemnums, itemnames);
    cin.clear();
    read(argv[2], &numstoreitems, prices, pricenames);
    double price=0;
    bool missing=false;
    for(int i=0; i<numitems; i++){
        bool found=false;
        for(int j=0; j<numstoreitems; j++){
            if(itemnames[i]==pricenames[j]){
                price += itemnums[i]*prices[j];
                found=true;
                break;
            }
        }
        if(!found){
            missing=true;
        }
    }
    if(!missing){
        cout << price << endl;
    }else{
        cout << "impossible" << endl;
    }
    return 0;
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
        