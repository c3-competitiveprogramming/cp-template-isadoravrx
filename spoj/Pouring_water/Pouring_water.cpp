#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int a,b,c;
        cin >> a >> b >> c;

        if(a < c && b < c){
            cout << -1 << endl;
            continue;
        }

        if(c == 0){
            cout << 0 << endl;
            continue;
        }



        int cont1 = 0;
        int tempa = 0;
        int tempb = 0;
        bool impos1 = false;
        while(true){
            if(tempa == c || tempb == c){
                break;
            }

            if(tempa == a && tempb == b){
                impos1 = true;
                break;
            }
            if(tempa == 0){
                tempa = a;
            }else if(tempb == b){
                tempb = 0;
            }else{
                int tirardea = min(tempa,b-tempb);
                tempa -= tirardea;
                tempb += tirardea;
            }

            cont1++;
        }

        int cont2 = 0;
        tempa = 0;
        tempb = 0;
        bool impos2 = false;
        while(true){
            if(tempb == c || tempa == c){
                break;
            }
            if(tempa == a && tempb == b){
                impos2 = true;
                break;
            }
            if(tempb == 0){
                tempb = b;
            }else if(tempa == a){
                tempa = 0;
            }else{
                int tirardeb = min(tempb,a-tempa);
                tempb -= tirardeb;
                tempa += tirardeb;
            }

            cont2++;
        }

        if(impos1 && impos2){
            cout << -1 << endl;
        }else{
            cout << min(cont1,cont2) << endl;
        }
    }
}
