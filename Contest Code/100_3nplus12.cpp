#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;


//int cycle_length(map<int,int> memo, int num, int count);


int main(int argc, char *argv[]) {
    int a, b, c, d;
    map<int,int> memo;
    while(scanf("%d %d", &c, &d)==2){
        a = c;
        b = d;
        if(a>b) swap(a,b);
        int maxnum = 0;
        for(int i=a; i<=b; i++){
            int cnt=1;
            int num=i;
            while(num!=1){
                cnt++;
                if(num%2 == 1){
                    num = 3*num+1;
                }else{
                    num = num/2;
                }
            }
            maxnum = max(maxnum, cnt);
        }
        printf("%d %d %d\n", c, d, maxnum);
    }
}

/*
int cycle_length(map<int,int> memo, int num, int count){
    int total;
    if(memo.count(num) > 0){
        return memo[num] + count;
    }else{
        if(num % 2 == 1){
            total = cycle_length(memo, 3*num+1, ++count);
        }else{
            total = cycle_length(memo, num/2, ++count);
        }
        memo[num] = total;
        return total;
    }
}
    */
        

    
    