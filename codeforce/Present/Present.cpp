#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
long long n, m, w;
long long v[100000];

bool validate(long long mid){
    long long sum = m * w;
    for(long long i = 0; i < n; i++){
        if(v[i] < mid){
            sum -= mid - v[i];
        }
        if(sum < 0){
            return false;
        }
    }
    return true;
}

int main(){
    cin >> n >> m >> w;

    long long mn = 10e9;
    long long mx = 0;
    for(long long i = 0; i < n; i++){
        long long num;
        cin >> num;
        v[i] = num;
        mn = min(mn,num);
        mx = max(mx,num);
    }

    long long low = mn;
    long long high = mx + (m * w);
    long long mid = (low + high)/2;

    long long ans = 0;
    while(low <= high){
        if(validate(mid)){
            low = mid + 1;
            ans = max(ans,mid);
        }else{
            high = mid - 1;
        }

        mid = (low + high)/2;
    }

    cout << mid << endl;
}