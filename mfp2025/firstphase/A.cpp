#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;


    vector<int>prefix(m+2);
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;

        if(x+1 <= m){
            prefix[x+1] -= 1;
        }
       
    }


    int sum = n;
    for(int i = 1; i <= m; i++){
        sum += prefix[i];
        if(i == m){
            cout << sum << endl;
            return 0;
        }
        cout << sum << " ";
    }

}