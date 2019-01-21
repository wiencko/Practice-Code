#include <iostream>

using namespace std;

bool f2(char s[], char c){
    int ii=0;
    while(s[ii] != 0){
        if(s[ii] == c){
            s[ii] = '-';
            return true;
        }
        ii++;
    }
    return false;
}

bool f1(char* s)
{
    while( f2(s, 'a')){
        if(! f2(s, 'b')){
            return false;
        }
    }
    return !f2(s, 'b');
}

int main(int argc, char *argv[]) {
    char s[] = "";
    char ss[] = "aaab";
    char sss[] = "baabba";
    
    cout << f1(s) << endl << f1(ss) << endl << f1(sss) << endl;
    cout << s << endl << ss << endl << sss << endl;
    
    
    int* pnt = NULL;
    cout << (bool)pnt; 
}