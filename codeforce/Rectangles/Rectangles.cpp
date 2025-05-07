#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>>v;

long long pot(int base, int exp){
    long long ans = 1;
    for(int i = 0; i < exp; i++){
        ans *= base;
    }
    return ans;
}

int main(){
    cin >> n >> m;
    
    v.resize(n);
    vector<int>q0linhas;
    q0linhas.assign(n,0);
    
    vector<int>q0colunas;
    q0colunas.assign(m,0);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int num;
            cin >> num;
            v[i].push_back(num);
            if(num == 0){
                q0linhas[i]++;
                q0colunas[j]++;
            }
        }
    }
    
    long long pos = 0;
    for(int i = 0; i < n; i++){
        pos += pot(2,q0linhas[i]) - 1;
        pos += pot(2, m - q0linhas[i]) - 1;
    }

    for(int i = 0; i < m; i++){
        pos += pot(2,q0colunas[i]) - 1 - q0colunas[i];
        pos += pot(2, n - q0colunas[i]) - 1 - (n - q0colunas[i]);
    }

    cout << pos << endl;
}
