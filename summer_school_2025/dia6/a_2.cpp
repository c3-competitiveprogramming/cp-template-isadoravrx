#include <iostream>
#include <cmath>
#include <map>
using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    double angle, n;
    cin >> angle >> n;

    map<pair<double,double>, double >sombras;
    double sum = 0;
    double tanangle = sin((angle*3.14159265359)/180) / cos((angle*3.14159265359)/180);
    for(int i = 0; i < n; i++){
        double x, h;
        cin >> x >> h;
        double csombra = h/tanangle;
        auto result = sombras.insert(make_pair(make_pair(x, x + csombra), 1));
        auto it = result.first;
        auto it1 = it;
        auto it2 = it;
        bool b1 = false, b2 = false;
        
        if(it != sombras.begin()){
            it1--;
            b1 = true;
        }

        it2++;
        if(it2 != sombras.end()){
            b2 = true;
        }

        sum+= csombra; 
        if(b1 && b2) { 
            if(x < it1->first.second){
                sum -= it1->first.second - x;
            }

            if(x+csombra > it2->first.first){
                sum -= x+csombra - it2->first.first;
            }
        }else if(b1){
            if(x < it1->first.second){
                sum -= it1->first.second - x;
            }
        }else if(b2){ 
            if(x+csombra > it2->first.first){
                sum -= x+csombra - it2->first.first;
            }
        }
    }

    printf("%.5f\n", sum);
}
