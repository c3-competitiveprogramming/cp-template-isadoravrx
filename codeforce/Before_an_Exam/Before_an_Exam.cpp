#include <iostream>
using namespace std;

int main(){
    
    int d, sumtime;
    cin >> d >> sumtime;
    
    int minimos[d];
    int maximos[d];
    
    int summin = 0;
    int summax = 0;
    for(int i = 0; i < d; i++){
        int mn, mx;
        cin >> mn >> mx;
        summin += mn;
        summax += mx;
        minimos[i] = mn;
        maximos[i] = mx;
    }
    
    if(summin > sumtime){
        cout << "NO";
    }else if(summin == sumtime){
        cout << "YES" << endl;
        for(int i = 0; i < d; i++){
            cout << minimos[i] << " ";
        }
    }else{
        if(sumtime <= summax){
            cout << "YES" << endl;
            int dif = sumtime - summin;
            for(int i = 0; i < d; i++){
                if(dif > 0){
                    if(maximos[i] - minimos[i] <= dif){
                        dif -= (maximos[i] - minimos[i]);
                        cout << maximos[i] << " ";
                    }else{
                        cout << minimos[i] + dif << " ";
                        dif = 0;
                    }
                }else{
                    cout << minimos[i] << " ";
                }
            }
        }else{
            cout << "NO";
        }    
    }

    cout << endl;
}
