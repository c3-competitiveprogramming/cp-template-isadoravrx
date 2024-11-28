#include <iostream>
using namespace std;

int main(){
    int n,c,s;
    cin >> n >> c >> s;

    int local = 1;
    int ans = 0;

    if(local == s){
        ans++;
    }
    for(int i = 0; i < c; i++){
        int direc;
        cin >> direc;

        local += direc;
        if(local == 0){
            local = n;
        }

        if(local == n + 1){ 
            local = 1;
        }

        if(local == s){
            ans++;
        }
    }

    cout << ans << endl;
}