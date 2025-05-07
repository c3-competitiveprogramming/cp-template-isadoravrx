#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int lcs(vector<int>s1 ,vector<int> s2){
    int n = s1.size();
    int m = s2.size();
    vector<vector<int> >dp(n+1, vector<int>(m+1,0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(s1[i] == s2[j]){
                dp[i+1][j+1] = max(dp[i][j]+1, max(dp[i+1][j], dp[i][j+1]));
            }else{
                dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
    }

    return dp[n][m];
}

int main(){
    int n, m;
    cin >> n >> m;

    vector<int>s1(n),s2(m);

    for(int i = 0; i < n; i++){
        cin >> s1[i];
    }

    for(int i = 0; i < m; i++){
        cin >> s2[i];
    }

    int subslenght = lcs(s1,s2);
    cout <<  n - subslenght << " " << m - subslenght  << endl;
}