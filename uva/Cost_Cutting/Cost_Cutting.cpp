#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
    
    int test = 1;
    while(t--){
        vector<int>v;
        for(int i = 0; i < 3; i++){    
            int num;
            cin >> num;
            v.push_back(num);
        }
        
        sort(v.begin(),v.end());
        
        printf("Case %d: ",test);
        cout << v[1] << endl;
        test++;
    }
}   
