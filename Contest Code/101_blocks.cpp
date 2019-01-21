#include <iostream>
#include <vector>

using namespace std;

void moveonto(vector<vector<int> > &nums, int a, int b);
void moveover(vector<vector<int> > &nums, int a, int b);
void pileonto(vector<vector<int> > &nums, int a, int b);
void pileover(vector<vector<int> > &nums, int a, int b);
void findnum(vector<vector<int> > &nums, int num, int* loc);

int main(int argc, char *argv[]) {
    vector<vector<int> > nums(10);
    for(int i=0; i<nums.size();i++){
        nums[i].push_back(i);
    }
    
    moveonto(nums, 4, 6);
    moveover(nums, 6, 5);
    
    for(int i=0; i<nums.size(); i++){
        cout << i << ": ";
        for(int j=0; j<nums[i].size(); j++){
            cout << nums[i][j] << " "; 
        }
        cout << endl;
    }
    
}

void findnum(vector<vector<int> > &nums, int num, int* loc){
    static int result[2];
    for(int i=0; i<nums.size(); i++){
        for(int j=0; j<nums[i].size(); j++){
            if(nums[i][j]==num){
                loc[0] = i;
                loc[1] = j;
            }
        }
    }
}




void moveonto(vector<vector<int> > &nums, int a, int b){
    int loc_a[2], loc_b[2];
    findnum(nums, a, loc_a);
    findnum(nums, b, loc_b);
    for(int i=loc_a[1]+1; i<nums[loc_a[0]].size(); i++){
        nums[nums[loc_a[0]][i]].push_back(nums[loc_a[0]][i]);
    }
    nums[loc_a[0]].resize(loc_a[1]);
    
    for(int i=loc_b[1]+1; i<nums[loc_b[0]].size(); i++){
        nums[nums[loc_b[0]][i]].push_back(nums[loc_b[0]][i]);
    }
    nums[loc_b[0]].resize(loc_b[1]+1);
    nums[loc_b[0]].push_back(a);
}

void moveover(vector<vector<int> > &nums, int a, int b){
    int loc_a[2], loc_b[2];
    findnum(nums, a, loc_a);
    findnum(nums, b, loc_b);
    for(int i=loc_a[1]+1; i<nums[loc_a[0]].size(); i++){
        nums[nums[loc_a[0]][i]].push_back(nums[loc_a[0]][i]);
    }
    nums[loc_a[0]].resize(loc_a[1]);
    nums[loc_b[0]].push_back(a);
}

void pileonto(vector<vector<int> > &nums, int a, int b){
    int loc_a[2], loc_b[2];
    findnum(nums, a, loc_a);
    findnum(nums, b, loc_b);
    for(int i=loc_b[1]+1; i<nums[loc_b[0]].size(); i++){
        nums[nums[loc_b[0]][i]].push_back(nums[loc_b[0]][i]);
    }
    nums[loc_b[0]].resize(loc_b[1]+1);
    
    
    
    
    