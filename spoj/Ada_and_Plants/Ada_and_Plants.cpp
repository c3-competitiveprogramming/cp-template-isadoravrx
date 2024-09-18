#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    long long t;
    cin >> t;

    while(t--){
        long long n,k;

        cin >> n >> k;
        vector<long long>v(n);
        for(long long i = 0; i < n; i++){
            cin >> v[i];
        }


        long long i = 0;
        long long j = min(k+1,(long long)v.size()-1);
        long long maxdif = 0;
        long long mn = 10e9;
        long long mx = 0;

        long long ind_mn = -1;
        long long ind_mx = -1;

        while(j < v.size()){
            if(ind_mx < i || ind_mx > j){
                long long maior = 0;
                long long ind_maior = 0;
                for(long long k = i ; k <= j; k++){
                    if(v[k] > maior){
                        maior = v[k];
                        ind_maior = k;
                    }
                }

                mx = maior;
                ind_mx = ind_maior;
            }

            if(ind_mn < i || ind_mn > j){
                long long menor = 10e9;
                long long ind_menor = 0;

                for(long long k = i; k <= j; k++){
                    if(v[k] < menor){
                        menor = v[k];
                        ind_menor = k;
                    }
                }

                mn = menor;
                ind_mn = ind_menor;
            }

            if(v[j] <= mn){
                mn = v[j];
                ind_mn = j;
            }

            if(v[j] >= mx){
                mx = v[j];
                ind_mx = j;
            }

            maxdif = max(maxdif,mx-mn);

            i++;
            j++;
        }

        cout << maxdif << endl;
    }
}
