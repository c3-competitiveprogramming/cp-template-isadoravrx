#include <iostream>
#include <bitset>
using namespace std;

int main(){
    int n;
    cin >> n;
    bitset<200001>bt(0);

    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        bt[num] = 1;
    }

    int mis;
    for(int i = 1; i <= n; i++){
        if(bt[i] == 0){
            mis = i;
            break;
        }
    }

    cout << mis << endl;
}
