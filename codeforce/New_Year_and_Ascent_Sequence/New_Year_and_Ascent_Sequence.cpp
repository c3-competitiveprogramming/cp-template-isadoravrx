#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;
long long n;
bitset<100000>bt(0); //1 quando é asc

int main(){
    cin >> n;
    long long lower[n];
    long long higher[n];
    for(int i  = 0; i < n; i++){
        long long len;
        cin >> len;
        long long last;
        long long mx = 0;
        long long mn = 1000000;
        for(int j = 0; j < len; j++){
            long long num;
            cin >> num;
            if(j != 0){
                if(last < num){
                    bt[i] = 1;
                }
            }
            mx = max(mx,num);
            mn= min(mn,num);
            last = num;
        }
        higher[i] = mx;
        lower[i] = mn;
    }

    long long desc = 0;
    for(int i = 0; i < n; i++){
        if(bt[i] == 0){ //primeiro desc
            for(int j = 0; j < n; j++){
                if(bt[j] == 0){ //segundo desc tbm
                    if(lower[i] >= higher[j]){ //ver se a combinacao deles tbm é no desc
                        desc++;
                    }
                }
            }
        }
    }

    cout << (n * n) - desc << endl;
}
