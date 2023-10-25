#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;
int n;
bitset<100000>bt(0);

int main(){
    cin >> n;
    int lower[n];
    int higher[n];
    for(int i  = 0; i < n; i++){
        int len;
        cin >> len;
        int last;
        int mx = 0;
        int mn = 1000000;
        for(int j = 0; j < len; j++){
            int num;
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

    long long cont = 0;
    for(int i = 0; i < n; i++){
        if(bt[i] == 1){
            cont += n;
            continue;
        }
        for(int j = 0; j < n; j++){
            if(bt[j] == 1 || lower[i] < higher[j]) {
                cont++;
            }
        }
    }

    cout << cont << endl;
}