#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int>v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    int i = 0;
    int j = v.size() - 1;   
    long long saldo = 0;
    int donosaldo = 0;

    while(i <= j){
        if(i == j){
            j++;
            break;
        }

        if(saldo > 0){
            if(donosaldo == 0){
                if(v[i] <= saldo){
                    i++;
                }else{
                    v[i] = v[i] - saldo;
                }
            }else{
                if(v[j] <= saldo){
                    j--;
                }else{
                    v[j] = v[j] - saldo;
                }
            }
        }

        if(v[i] < v[j]){
            saldo += v[j] - v[i];
            donosaldo = 0;
        }else if(v[j] < v[i] ){
            saldo += v[i] - v[j];
            donosaldo = 1;
        }
        i++;
        j--;
    }

    cout << i+1 << " " << v.size() - j << endl;
}
