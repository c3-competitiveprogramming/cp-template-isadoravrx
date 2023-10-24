#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int k, n, a, b;


int main(){
    int q;
    cin >> q;

    while(q--){
        cin >> k >> n >> a >> b;
        
        int low = 0;
        int high = n;
        int mid = (low + high)/2;
        int maxmin = -1;
        if((k - (n * a)) > 0){ //já achou a resposta
            cout << n << endl;
        }else{
            while(low <= high){
                if((k -(mid * a)) > 0){
                    if(mid >= n){
                        maxmin = max(maxmin, mid);
                        low = mid + 1;
                    }else{
                        int resto = (k -(mid * a));
                        int rodadasFaltam = n - mid;
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
