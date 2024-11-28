#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        int v[n];
        memset(v,0,sizeof(v));

        int ball = 1;
        int ans = 0;

        while(true){
            bool entrou = false;

            for(int i = 0; i < n; i++){
                if(v[i] == 0){
                    v[i] = ball;
                    ans++;
                    ball++;
                    entrou = true;
                    break;
                }else{
                    int raiz = sqrt(v[i] + ball);
                    if((raiz * raiz) == (v[i] + ball)){
                        v[i] = ball;
                        ans++;
                        ball++;
                        entrou = true;
                        break;
                    }
                }
            }

            if(!entrou){
               break;
            }
        }

        cout << ans << endl;
    }
}