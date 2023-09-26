#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        
        vector<int>v;
        for(int i = 0; i < n; i++){
            int num;
            cin >> num;
            v.push_back(num);
        }
        
        int high = v[0];
        int min = v[0];
            
        sort(v.begin(), v.end());
    
        for(int i = 1; i < n; i++){
            
        }
    }
}
