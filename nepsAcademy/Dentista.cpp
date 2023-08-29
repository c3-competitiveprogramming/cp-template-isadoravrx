#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    int cont = 0;
    vector<int>ini;
    vector<int>f;
    for(int i = 0; i < n; i++){
        int x,y;
        cin >> x >> y;
        bool isvalid = true;
        
        for(int i = 0; i < f.size(); i++){
            if((x >= ini[i] && x < f[i]) ||(y > ini[i] && y <= f[i])){
                isvalid = false;
            }    
        }

        if(isvalid){
            cont++;
            ini.push_back(x);
            f.push_back(y);
        }
    }

    cout << cont << endl;
}
