#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int maxpacotes, macas;
int memo[105][100005]; // pos, custo

int dp (vector<int>&sacolas, int i, int custo, int maca_sum, int pacotes){
    if(memo[i][custo] != -1){
        return memo[i][custo];
    }

    if(i >= macas){
        if(maca_sum == macas){
            return custo;
        }else{
            return 100005;
        }
    }


    if(pacotes == maxpacotes){
        return 100005;
    }

    if(sacolas[i] != -1){
        memo[i][custo] = min(dp(sacolas, i+1, custo + sacolas[i], maca_sum + i + 1, pacotes + 1), dp(sacolas, i+1, custo, maca_sum, pacotes));
        memo[i][custo] = min(memo[i][custo] , dp(sacolas, i, custo + sacolas[i], maca_sum + i + 1, pacotes + 1));
    }else{
        memo[i][custo] = dp(sacolas, i+1, custo, maca_sum, pacotes);
    }

    return memo[i][custo];
}

int main(){
    int t;
    cin >> t;

    while(t--){
        
        memset(memo, -1,sizeof(memo));
        cin >> maxpacotes >> macas;
        vector<int>sacolas;
        for(int i = 0; i < macas; i++){
            int num;
            cin >> num;
            sacolas.push_back(num);
        }

        int ans = dp(sacolas, 0, 0, 0, 0);
        if(ans == 100005){
            cout << -1 << endl;
        }else{
            cout << ans << endl;
        }
    }
}