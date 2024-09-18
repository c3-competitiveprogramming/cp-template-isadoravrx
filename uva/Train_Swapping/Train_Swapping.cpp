#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;
        
        vector<int>v;
        for(int i = 0; i < n; i++ ){
            int num;
            cin >> num;
            v.push_back(num);
        }
        
        int cont = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n - 1; j++){
                if(v[j] > v[j + 1]){
                    swap(v[j],v[j+1]);
                    cont++;
                }
            }
        }

        printf("Optimal train swapping takes %d swaps.\n",cont);
    }
}

