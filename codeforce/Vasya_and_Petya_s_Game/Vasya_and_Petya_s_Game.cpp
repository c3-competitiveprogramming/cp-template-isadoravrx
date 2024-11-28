#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    int cont = 0;
    vector<int>v;
    for(int i = 2; i <= n; i++){
        bool isprime = true;

        for(int j = 2; j <= sqrt(i); j++){
            if(i % j == 0){
                isprime = false;
            }
        }
        if(isprime){
            for(int x = 1; pow(i,x) <= n; x++){
                if(pow(i,x) <= n){
                    v.push_back(pow(i,x));
                    cont++;
                }
            }        
        }
    }

    cout << cont << endl;
    for(int i = 0; i < v.size(); i++){
        if(i == v.size() - 1){
            cout << v[i] << endl;
            break;
        }

        cout << v[i] << " ";
    }
}
