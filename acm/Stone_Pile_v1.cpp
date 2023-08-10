#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int n;
int sum = 0;
vector<int>v;
int ans;

void recursive(int i, int s){
    if(i == n){
        ans = min(ans, abs(2*s - sum));// ans sempre vai ser a menor diferenca possivel
        return;
    }

    recursive(i+1,s);
    recursive(i+1,s + v[i + 1]);
}

int main(){
    cin >> n;
    
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        v.push_back(num);
        sum+= num;
    }
    
    ans = sum;
    recursive(0,0);
    cout << ans << endl;
}
