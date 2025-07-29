#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int memo[100002];
int n,k;
int heights[100002];

int dp(int i){
    if(i == 0){
        return 0;
    }
    if(memo[i] != -1){
        return memo[i];
    }

    int mn = 1e9+7;
    for(int j = i-1; j >= max(0,i-k); j--){
        mn = min(mn,dp(j) + abs(heights[i] - heights[j]));
    }

    return memo[i] = mn;
}


int main(){
   
    cin >> n >> k;

    
    for(int i = 0; i < n; i++){
        int h;
        cin >> h;
        heights[i] = h;
    }
    memset(memo, -1, sizeof(memo));
    cout << dp(n-1) << endl;
}