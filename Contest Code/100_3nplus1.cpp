#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;


int cycle_length(map<int,int> &memo, int num);


int main(int argc, char *argv[]) {
    int a, b, c, d;
    map<int,int> memo;
    memo[1] = 1;
    while(scanf("%d %d", &c, &d)==2){
        a = c;
        b = d;
        if(a>b) swap(a,b);
        int maxnum = 0;
        for(int i=a; i<=b; i++)
            maxnum = max(maxnum, cycle_length(memo, i));
        printf("%d %d %d\n", c, d, maxnum);
    }
}

int cycle_length(map<int,int> &memo, int num){
    int total;
    if(memo.count(num) > 0){
        return memo[num];
    }else{
        if(num % 2 == 1){
            total = 1 + cycle_length(memo, 3*num+1);
        }else{
            total = 1 + cycle_length(memo, num/2);
        }
        memo[num] = total;
        return total;
    }
}
    
        

    
    