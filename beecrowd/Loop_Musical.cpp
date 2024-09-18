#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    while(true){
        int n;
        cin >> n;

        if(n == 0){
            break;
        }

        vector<int>v;

        for(int i = 0; i < n; i++){
            int num;
            cin >> num;
            v.push_back(num);
        }

        int cont = 0;

        for(int i = 0; i < n; i++){
            if(i == 0){
                if((v[n - 1] - v[i] > 0 && v[i + 1] - v[i]  > 0) || (v[n - 1] - v[i] < 0 && v[i + 1] - v[i]  < 0)){ //descendo e subindo ouu subindo e descendo
                    cont++;
                }
            }else if(i == n - 1){
                if((v[i - 1] - v[i] > 0 && v[0] - v[i]  > 0) || (v[i-1] - v[i] < 0 && v[0] - v[i]  < 0)){ //descendo e subindo ouu subindo e descendo
                    cont++;
                }
            }else{
                if((v[i - 1] - v[i] > 0 && v[i + 1] - v[i]  > 0) || (v[i-1] - v[i] < 0 && v[i + 1] - v[i]  < 0)){ //descendo e subindo ouu subindo e descendo
                    cont++;
                }
            }

        }

        cout << cont << endl;
    }
}