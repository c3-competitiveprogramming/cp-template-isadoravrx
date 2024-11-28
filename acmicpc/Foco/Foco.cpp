#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    
    while(cin >> n){

        vector<pair<int,int> >v;
        for(int i = 0; i < n ; i++){
            int a,b;
            cin >> a >> b;
            v.push_back(make_pair(a,b));
        }

        sort(v.begin(), v.end());

        int oldini, oldfim;
        int cont = 1; 
        int moreoldfim;
        for(int i = 0; i < n ; i++){
            int x = v[i].first;
            int y = v[i].second;

            if(i == 0){
                oldini = x;
                oldfim = y;
                continue;
            }

            if(x == oldini && y > oldfim){
                oldfim = y;
            }else if(){

            }
            else if((x <= oldfim && y > oldfim) || (x > oldfim)){
                cont++;
                oldini = x;
                oldfim = y;
            }
            
        }

        cout << cont << endl;
    }
}