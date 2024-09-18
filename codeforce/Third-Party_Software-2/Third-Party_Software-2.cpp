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

    int func = 1;

    sort(v.begin(), v.end());
    vector<int>ans(n + 1);
    int anssize = 0;
    int cont = 0;
    
    for(int i = 0; i < n; i++){
        int mxright;
        int mxversao;
        cont = 0;
        int j;
        for(j = i ; j < n; j++ ){
            if(v[j][0] <= func){
                if(v[j][1] >= func){
                    if(cont == 0){
                        mxright = v[j][1];
                        mxversao = v[j][2];
                    }else{
                        if(mxright < v[j][1]){
                            mxright = v[j][1];
                            mxversao = v[j][2];
                        }
                    }
                    cont = 1;

                }
            }else{
                break;
            }
        }
        
        if(cont == 0){
            break;
        }

        i = j-1;
        func = mxright + 1;

        if(ans[mxversao] == 0){
            ans[mxversao]++;
            anssize++;
        }
    }

    if(func <= m){
        cout << "NO" << endl;
        return 0;
    }
    
    cout << "YES" << endl;
    cout << anssize << endl;
    cont = 0;
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
