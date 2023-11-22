#include <iostream>
#include <algorithm>
#include <bitset>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
long long n;

int main(){
    cin >> n;
    vector<long long> lower;
    vector<long long> higher;

    long long ans = 0;
    int cont = 0;
    for(long long i  = 0; i < n; i++){
        long long len;
        cin >> len;

        long long last;
        long long mx = 0;
        long long mn = 1000000;
        bool isascedente = false;
        long long num;

        bool entrou = false;
        for(long long j = 0; j < len; j++){
            cin >> num;
            if(j != 0){
                if(last < num){
                    isascedente = true;
                    if(!entrou){
                        ans += n + (n -1); //quando se é ascedente, pode formar essa quantidade de pares com eles
                        entrou = true;
                        if(cont == 1){
                            ans -= cont;
                        }
                    }
                    cont++;
                }
            }

            mx = max(mx,num);
            mn= min(mn,num);
            last = num;
        }
        if(!isascedente){
            higher.push_back(mx);
            lower.push_back(mn);
        }

    }

    sort(lower.begin(),lower.end());
    sort(higher.begin(),higher.end());

    for(long long i = 0; i < lower.size(); i++){
            long long ind = (upper_bound(higher.begin(),higher.end(),lower[i]) - higher.begin()); //ponteiro do higher - ponteiro do achado, vai dar o index
            ans += lower.size() - ind;
    }

    cout << ans  << endl;
}
