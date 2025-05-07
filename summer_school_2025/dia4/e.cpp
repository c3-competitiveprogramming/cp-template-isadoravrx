#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main(){

    int n;
    cin >> n;

    vector<int>v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    
    vector<int>v2;
    int g;

    int cont = 0;
    int a;
    int firsta, seconda;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            a = lcm(v[i], v[j]);
            cont++;
            if(cont == 1){
                firsta = a;
            }else if(cont == 2){
                seconda = a;
                g = gcd(firsta, seconda);
            }else{
                g = gcd(g, a);
            }
        }
    }

    g = gcd(g, a);
    
    cout << g << endl;
}