#include <iostream>
#include <vector>
#include <string>
using namespace std;
int lcs(string X, string Y, int m, int n,
        vector<vector<int> >&dp)
{
    if (m == 0 || n == 0)
        return 0;
    if (X[m - 1] == Y[n - 1])
        return dp[m][n] = 1 + lcs(X, Y, m - 1, n - 1, dp);

    if (dp[m][n] != -1) {
        return dp[m][n];
    }
    return dp[m][n] = max(lcs(X, Y, m, n - 1, dp),
                          lcs(X, Y, m - 1, n, dp));
}


int main()
{   
    string s1,s2;
    int t = 1;
    while(getline(cin,s1)){
        if(s1 == "#"){
            break;
        }

        getline(cin,s2);
        int m = s1.size();
        int n = s2.size();
        vector<vector<int> > dp(m + 1, vector<int>(n + 1, -1));
        int ans = lcs(s1, s2, m, n, dp);
        printf("Case #%d: you can visit at most %d cities.\n", t, ans);
        t++;
    }

    return 0;
}