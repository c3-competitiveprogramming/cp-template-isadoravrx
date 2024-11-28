#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    vector<int>nums;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        nums.push_back(num);
    }

    long long k;
    cin >> k;
    
   
    int house1,house2;
    
    int fixIndice = 0;
    int low = 1, high = nums.size() - 1 , mid; 

    while(true){
        mid = (low + high) / 2;
        

        if(nums[fixIndice] + nums[mid] == k){
            house1 = nums[fixIndice];
            house2 = nums[mid];
            break;
        }

        if(low > high){
            fixIndice++;
            low = 1;
            high = nums.size() - 1;
        }else if(nums[fixIndice] + nums[mid] > k){
            high = mid - 1;
        }else{
            low = mid + 1;
        }

    }

    if(house1 < house2){
        printf("%d %d\n", house1, house2);
    }else{
        printf("%d %d\n", house2, house1);
    }

    return 0;

}
