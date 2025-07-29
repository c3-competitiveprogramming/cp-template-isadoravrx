#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;

    while(n--){

        vector<int>v;
        for(int i = 0; i < 3; i++ ){
            int x;
            cin >> x;

            v.push_back(x);
        }   

        
        if(v[0] != v[1] && v[0] != v[2]){
            cout << v[0] << endl;
        }else if(v[1] != v[0] && v[1] != v[2]){
            cout << v[1] << endl;
        }else{
            cout << v[2] << endl;
        }
    }
}