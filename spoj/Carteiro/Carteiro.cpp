#include <iostream>
#include <map>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    
    map<int,int>mp;
    int num;
    for(int i = 0; i < n; i++){
        cin >> num;
        mp[num] = i;
    }
    
    long long sum = 0;
    cin >> num;
    sum += mp[num];
    int ant = num;
    for(int i = 1; i < m; i++){
        cin >> num;
        sum += abs(mp[ant] - mp[num]);
        ant = num;
    }

    cout << sum << endl;
}
