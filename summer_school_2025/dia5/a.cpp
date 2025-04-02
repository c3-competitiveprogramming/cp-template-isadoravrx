#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
typedef long long ll;
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<pair<int,int> >mns(n);
    vector<pair<int,int> >mxs(n);
    vector<vector<int> >v(n, vector<int>(n));

    for(int i = 0; i < n; i++){
        int mn = 2505;
        for(int j = 0; j < n; j++){
            int num;
            cin >> num;
            v[i][j] = num;

            if(num < mn){
                mn = num;
                mns[i] = make_pair(num,j);
            }    

            if(num > mxs[j].first){
                mxs[j] = make_pair(num,i);
            }
            
        }
    }

    sort(mns.begin(),mns.end());
    sort(mxs.begin(), mxs.end());

    int linha = mxs[0].second;
    int coluna = mns[n-1].second;

    cout << v[linha][coluna] << endl;
}