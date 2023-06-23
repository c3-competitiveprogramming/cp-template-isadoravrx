#include <iostream>
#include <vector>
using namespace std;
long long n;
long long k;
vector<long long>heights;
long long bestValue = 0;

bool validate(long long mid){
    long long sum = 0;

    for(long long i = 0; i < n; i++){
        if(heights[i] - mid <= 0){
            continue;
        }else{
            sum+= heights[i] - mid;
        }
    }

    if(sum >= k){
        return true;
    }else{
        return false;
    }
}

long long binarysearch(long long low, long long high){
    long long mid = (low + high) /2 ;
    if(low > high){
        return bestValue;
    }

    if(validate(mid) == true){
        bestValue = mid;
        return binarysearch(mid + 1, high);
    }else{
        return binarysearch(low, mid - 1);
    }
}

int main(){
    
    cin >> n >> k;

    long long highHeight = 0;
    for(long long i = 0; i < n; i++ ){
        long long v;
        cin >> v;
        if(v > highHeight){
            highHeight = v;
        }
        heights.push_back(v);
    }

    long long low = 0; //pois o k pode ser no minimo 1
    long long high = highHeight + 1;
    long long answer = binarysearch(low,high);
    cout << answer << endl;
    return 0;
}