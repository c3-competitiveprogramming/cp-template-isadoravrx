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
    
    bool achei = false;
    int house1,house2;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j){
                continue;
            }if(nums[i] + nums[j] > k){
                break;
            }if(nums[i] + nums[j] == k){
                achei = true;
                house1 = nums[i];
                house2 = nums[j];
                break;
            }
        }

        if(achei == true){
            break;
        }
    }

    if(house1 < house2){
        printf("%d %d\n", house1, house2);
    }else{
        printf("%d %d\n", house2, house1);
    }

    return 0;

}
