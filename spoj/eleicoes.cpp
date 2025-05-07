#include <iostream>
#include <map>
#include <cmath>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    map<int, int>mp;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        mp[num]++;
    }

    int highcont = 0;
    int highvalue = 0;
        
    for(auto i : mp){
        if(i.second > highcont){
            highcont = i.second;
            highvalue = i.first;
        }
    }

    cout << highvalue << endl;
}
