#include <iostream>
#include <vector>
using namespace std;

bool calcular2(vector<int>v, vector<int>v2, int n, int m){
    int j = (n-m)-1;
    int i =j+1;
    for(int k = 0; k < m; k++){
        if(j >= 0){
            if(v[i] + v[j] != v2[k]){
                return false;
            }
        }else if(v[i] != v2[k]){
            return false;
        }
        i++;
        j--;
    }

    return true;
}

bool calcular1(vector<int>v, vector<int>v2, int n, int m){
    int i = (n-m)-1;
    int j = i+1;
    for(int k = m-1; k >= 0; k--){
        if(j < n){
            if(v[i] + v[j] != v2[k]){
                return false;
            }
        }else if(v[i] != v2[k]){
            return false;
        }
        i--;
        j++;
    }

    return true;
}

int main(){
    int n;
    while(cin >> n){

        vector<int>v(n);
        for(int i = 0; i < n; i++){
            cin >> v[i];
        }

        int m;
        cin >> m;
        vector<int>v2(m);
        for(int i = 0; i < m ; i++){
            cin >> v2[i];
        }

        if(n%2==0 && m<n/2){
            cout << "N" << endl;
            continue;
        }else if(n%2==1 && m<=n/2){
            cout << "N" << endl;
            continue;
        }

        if(calcular1(v,v2,n,m) || calcular2(v,v2,n,m)){
            cout << "S" << endl;
        }else{
            cout << "N" << endl;
        }
    }

    return 0;
}