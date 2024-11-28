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
        
        sort(v.begin(), v.end());
        
        int maxmin = v[0];

        for(int i = 1; i < v.size(); i++){
            maxmin = max(maxmin,v[i] - v[i - 1]);
        }
        cout << maxmin << endl;
    }   
}
