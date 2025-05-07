#include <iostream>
#include <map>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    map<int,int>linha;
    map<int,int>col;
    int mx = 0;

    for(int i = 0; i < n; i++){
        for(int j =0 ; j < m; j++){
            int num;
            cin >> num;
            if(j == 0){
                linha[i] = 0;
            }

            if(i == 0){
                col[j] = 0;
            }

            linha[i] += num;
            col[j] += num;

        }

        mx = max(mx, linha[i]);
    }

    for(int i = 0; i < m; i++){
        mx = max(mx, col[i]);
    }

    cout << mx << endl;
}