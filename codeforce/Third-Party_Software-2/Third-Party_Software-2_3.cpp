#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;

    vector<vector<int>>v(n,vector<int>(3));
    for(int i = 0; i < n; i++){
        int a,b;
        cin >> a >> b;
        v[i] = {a,b,i+1};
    }

    int version = 0;
    int func = 1;

    sort(v.begin(), v.end());
    vector<int>ans(n + 1);
    int anssize = 0;

    while(version < n && func <= m){
        int mxright;
        int mxversao;
        int cont = 0;
        int i;
        for(i = version ; i < n; i++ ){
            if(v[i][0] <= func){
                if(v[i][1] >= func){
                    if(cont == 0){
                        mxright = v[i][1];
                        mxversao = v[i][2];
                    }else{
                        if(mxright < v[i][1]){
                            mxright = v[i][1];
                            mxversao = v[i][2];
                        }
                    }
                    cont = 1;

                }
            }else{
                break;
            }
        }
        func = mxright + 1;
        version = i;
        if(ans[mxversao] == 0){
            anssize++;
        }
        ans[mxversao]++;
    }

    if(func <= m){
        cout << "NO" << endl;
        return 0;
    }
    
    cout << "YES" << endl;
    cout << anssize << endl;
    int cont = 0;
    for(int i = 1; i <= n; i++){
        if(ans[i] == 1){
            if(cont != 0){
                cout << " ";
            }
            cout << i;
            cont = 1;
        }
    }
    cout << endl;
}
