#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    vector<vector<int>>v(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int num; 
            cin >> num;
            v[i].push_back(num);
        }
    }
    
    int l;
    int j = 0;
    int times = 0;
    for(int k = 0; k < (n + (n - 1)); k++){
        if(k >= n ){
            l = n - 1;
        }else{
            l = k;
        }
        
        if(k < n){
            times++;
        }else{
            times--;
        }
    
        if(k >= n){
            j++;
        }else{
           j = 0; 
        }

        int cont = 0;
        for(int i = 0; i < times; i++)  {
            if(k == n + (n - 1) - 1){
                cout << v[l][j + cont] << endl;
            }else{
                cout << v[l][j + cont] << " ";
            }
            cont++;
            l--;
        }
    }

}
