#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int n;
vector<int>v;
int best = 2000000;
int i = 0;
void dp(int pego){
    if(pego == 1){
        
    }
}
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        v.push_back(num);
    }
    
    dp(0);
    dp(1);

    cout << best << endl;
}
