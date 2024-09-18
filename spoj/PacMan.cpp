#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<char>>v(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            char c;
            cin >> c;
            v[i].push_back(c);
        }
    }
    
    int sum = 0;
    vector<int>sums;
    
    int i = 0;
    int j = 0;
    int start = 0; // 0 comeca da esquerda
    while(true){
        if(i == n){
            if(sum != 0){
                sums.push_back(sum);
            }
            break;
        }
        if(v[i][j] == 'o'){
            sum++;
        }else if(v[i][j] == 'A'){
            sums.push_back(sum);
            sum = 0;
        }
        
        if(start == 0){
            j++;
        }else{
            j--;    
        }
        if(j == n || j == -1){
            i++;
            if(start == 0){
                j = n - 1;
                start = 1;
            }else{
                j = 0;
                start = 0;
            }
        }

    }
    
    int mx = 0;
    for(int i = 0; i < sums.size(); i++){
        mx = max(mx,sums[i]);
    }

    cout << mx << endl;
}
