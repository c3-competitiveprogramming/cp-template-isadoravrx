#include <iostream>
#include <string>
#include <cmath>
using namespace std;
string meses[] = {"January", "February", "March", "April", "May", "June", "July",
"August",  "September", "October", "November", "December"};

int main(){
    int test;
    cin >> test;
    int t = 1;
    while(test--){
        string m1,m2;
        int d1,a1;
        int d2,a2;
        char virg;

        cin >> m1 >> d1 >> virg >> a1;
        cin >> m2 >> d2 >> virg >> a2;
        
        int cont = 1;
        int mes1,mes2;
        for(string s : meses){
            if(m1 == s){
                mes1 = cont;
            }
            if(m2 == s){
                mes2 = cont;
            }

            cont++;
        }
                
        int qanosbisex = 0;
        for(int i = a1; i <= a2; i++){
            if(i % 4 == 0 && i % 100 != 0){
                qanosbisex++;
            }else if(i % 400 == 0){
                qanosbisex++;
            }
        }
    
        printf("Case %d: ",t);
        t++;
        if(((d1*pow(10,mes1)) <= (29 * pow(10,2))) && ((29 * pow(10,2)) <= d2*(pow(10,mes2)))){
            cout <<  qanosbisex << endl;
        }else{
            if(((d1*pow(10,mes1)) > (29 * pow(10,2))) && ((d2 * pow(10,mes2)) > (29 * pow(10,2)))){
                if(a1 % 4 == 0){
                    if(a2 % 4 == 0){
                        cout << qanosbisex - 2 << endl;
                    }else{
                        cout << qanosbisex - 1 << endl;
                    }
                }else{
                    cout << qanosbisex << endl;
                }
            }else{
                cout << 0 << endl;
            }
        }

        
    }
}
