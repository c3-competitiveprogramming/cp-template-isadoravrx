#include <iostream>
#include <vector>
#include <bitset>
#include <cmath>
using namespace std;

int main(){
    int n,l,r,x;
    cin >> n >> l >> r >> x;

    int cont = 0;
    vector<int>v;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        v.push_back(num);
    }
    for(int i = 0; i < 1 << n; i++){
        bitset<15>bt(i);

        int contAtLeastTwo = 0;
        int difTotal = 0;
        int hard = 0 , easy = 0;
        int jaentrou = false;
        for( int j = 0; j < n; j++){
            if(bt[j]){
                if(jaentrou == false){
                    easy = v[j];
                    hard = v[j];
                    jaentrou = true;
                }
                contAtLeastTwo++;
                difTotal += v[j];
                hard = max(hard,v[j]);
                easy = min(easy,v[j]);
            }
        }
        if(contAtLeastTwo >= 2 && difTotal >= l && difTotal <= r && (hard - easy) >= x){
            cont++;
        }
    }

    cout << cont << endl;
}

