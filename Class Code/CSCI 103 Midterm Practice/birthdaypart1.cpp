#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    int bd[366] = {0};
    int temp, examined = 0;
    cin >> temp;
    while(!cin.fail()){
        examined++;
        bd[temp] += 1;
        if(bd[temp] == atoi(argv[1])){
            cout << examined << " birthdays examined to find " << atoi(argv[1]) << " occurrences of " << temp << endl;
            break;
        }
        
        cin >> temp;
        
        if(cin.fail()){
            cout << "No birthday occurs " << atoi(argv[1]) << " times" << endl;
        }
    }
}