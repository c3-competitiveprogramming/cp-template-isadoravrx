#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int m,n;
        cin >> m >> n;

        vector<vector<int> >ans(m,vector<int>(m));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < m; j++){
                int num;
                cin >> num;
                ans[i][j] = num;
            }
        }

        while(n--){
            for(int i = 0; i < m; i++){
                for(int j = 0; j < m; j++){
                    for(int k = 0; k < m; k++){
                        ans[i][j] += ((ans[i][k] % 1000000007) * (ans[k][j] % 1000000007)) % 1000000007;
                    }
                } 
                if(n == 0 && i == m-1){
                    cout << ans[i][j];
                    if(j == m-1){
                        cout << endl;
                    }else{
                        cout << " ";
                    }
                }

            }
        } 

    }
}
