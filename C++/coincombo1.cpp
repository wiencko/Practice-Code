#include <iostream>

using namespace std;

int pennycombos(int pennies){
    
    long long total = 0;
    
    for(int dimes = 0; dimes <= pennies/10; dimes++){
        
        int rem_pennies = pennies - (dimes*10);
        
        total += rem_pennies/5 + 1;
        
        /*for(int nickles = 0; nickles <= rem_pennies/5; nickles++){
            
            total++;
        }
        */
    }
    
    cout << total << " " << pennies << " ";
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
        }
    }
    cout << combos << endl;
    
    return 0;
}