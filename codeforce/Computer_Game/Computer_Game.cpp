#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long k, n, a, b;


int main(){
    long long q;
    cin >> q;

    while(q--){
        cin >> k >> n >> a >> b;
        
        long long low = 0;
        long long high = n;
        long long mid = (low + high)/2;
        long long maxmin = -1;
        if((k - (n * a)) > 0){ //já achou a resposta
            cout << n << endl;
        }else{
            while(low <= high){
                if((k -(mid * a)) > 0){
                    if(mid >= n){
                        maxmin = max(maxmin, mid);
                        low = mid + 1;
                    }else{
                        long long resto = (k -(mid * a));
                        long long rodadasFaltam = n - mid;
                        if((resto - (rodadasFaltam * b))> 0){
                            maxmin = max(maxmin, mid);
                            low = mid + 1;
                        }else{
                            high = mid - 1;
                        }
                    }
                }else{
                    high = mid - 1;
                }

                mid = (low + high)/2;
            }

            cout << maxmin << endl;
        }

    }
}
