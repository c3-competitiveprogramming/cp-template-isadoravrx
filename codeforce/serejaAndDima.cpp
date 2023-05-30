#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    
    vector<int>nums;
    for(int i = 0; i < n; i++ ){
        int num;
        cin >> num;
        nums.push_back(num);
    }

    int s = 1; //indica quando e a vez de sereja
    int sereja = 0,dima = 0;
    while(!nums.empty()){  
        if(s == 1){
            if(nums[nums.begin()] > num[nums.end()]){
                sereja += nums[nums.begin()];
                nums.erase(nums.begin());
            }else{
                sereja += nums[nums.end()];
                nums.erase(nums.end());
            }

            s = 0; 
        }else{
            if(nums[nums.begin()] > num[nums.end()]){
                dima += nums[nums.begin()];
                nums.erase(nums.begin());
            }else{
                dima += nums[nums.end()];
                nums.erase(nums.end());
            }

            s = 1;
        }
    }

    printf("%d %d\n", sereja, dima);
}
