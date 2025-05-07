#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;
int n;
int a,b,c;
int memo[12002][12002];

int dp(int sum, int cont){
    if(memo[sum][cont] != -1){
        return memo[sum][cont];
    }
    if(sum == n){
        return cont;
    }

    if(sum > n){
        return 0;
    }

    return memo[sum][cont] = max(dp(sum+a, cont+1), max(dp(sum+b, cont+1), dp(sum+c,cont+1)));
}

int main(){
    
    memset(memo, -1 ,sizeof(memo));
    cin >> n >> a >> b >> c;

    cout << dp(0,0) << endl;
}