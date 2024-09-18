#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int ini,fin;
    int cont = 0;
    while(cin >> ini >> fin){
        int n = ini;
        if(cont != 0){
            cout << endl;
            cont = 1;
        }
        while(n <= fin){
            int ite = 0;
            string s = to_string(n);
            int c = 0;
            while(s.size() != 1 || c == 0){
                c = 1;
                int soma = 0;
                for(int i = 0; i < s.size(); i++){
                    soma += pow((int)s[i],2);
                }
                s = to_string(soma);
                ite++;
            }
            c++;

            if(stoi(s) == 1){
                cout << n << " " << ite << endl;
            }
            
            n++;
        }
    }
}
