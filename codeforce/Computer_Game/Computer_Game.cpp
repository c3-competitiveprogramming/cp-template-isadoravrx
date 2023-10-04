#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int k, n, a, b;

int validate(int mid){
    int cont = 0;
    int bateria = k;
    int max = 0;
    while(true){
        if(cont == n){
            return max;
        }

        if(max == mid){
            break;
        }
        if(bateria  > a){
            cont++;
            bateria -= a;
            max++;
        }else{
            break;
        }
    }

    while(true){
        if(cont == n){
            return max;
        }

        bateria -= b;
        if(bateria <= 0){
            return -1;
        }else{
            cont++;
        }
    }
}


int main(){
    int q;
    cin >> q;

    while(q--){
        cin >> k >> n >> a >> b;
        
        int low = 0;
        int high = k -1;
        int mid = (low + high)/2;
        int maxmin = -1;
        while(low <= high){
            int qrodadasA = validate(mid);
            if(qrodadasA != -1){
                maxmin = max(maxmin,qrodadasA);
                low = mid + 1;
            }else{
                high = mid - 1;
            }
            
            mid = (low + high)/2;
        }

       cout << maxmin << endl; 
    }
}
