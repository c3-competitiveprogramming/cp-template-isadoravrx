#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    long long n;
    cin >> n;
    
    vector<vector<long long>>v(n);
    for(long long i = 0; i < n; i++){
        long long a,b,c;
        cin >> a >> b >> c;
        v[i].push_back(a);
        v[i].push_back(b);
        v[i].push_back(c);
        v[i].push_back(a + b + c);
        sort(v[i].begin(), v[i].end());
    }

    
    long long q = 0;
    for(long long i = 0; i < n; i++){
        q = 0;
        for(long long j = 0; j < n; j++){
            if(j == i){
                continue;
            }
            
            if(v[i][3] >= v[j][0] + 1 + v[j][1] + 1){
                q++;
            }

        }


        if(i == n - 1){
            cout << q << endl;
        }else{
            cout << q << " ";
        }
    }
}
