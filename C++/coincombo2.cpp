#include <iostream>

using namespace std;

int pennycombos(int pennies){
    
    long long total = 0;
    
    // finds number of dime combos
    long num = (pennies/10) + 1;
    
    // finds the average combos in a dime combo
    long num2 = (pennies/5 + 3)/2;
    
    total = num*num2;
    
    cout << total << " ";
    return total;

}   

int main(){
    
    cout << "How may dollars: ";
    int dollars;
    cin >> dollars;
    
    int quarters =(4*dollars);
    
    int pennies = 0;
    long long combos = 1;
    int temp = 0, temp2 = 0;
    
    while(pennies != (dollars*100)){
        
        if(quarters != 0){
            quarters--;
            pennies += 25;
            temp2 = temp;
            temp = pennycombos(pennies);
            combos += temp;
            cout << temp-temp2 << " ";
            cout << combos << " " << quarters << endl;
            //cout << combos << endl;
        }
    }
    cout << combos << endl;
    
    return 0;
}