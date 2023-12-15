#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main(){

    int c, s;
    while(cin>> c >> s){
        vector<int> massas (s);
        int somasMassas = 0;
        for(int i = 0; i < s; i++){
            cin >> massas[i];
            somasMassas += massas[i]; // soma total dos chambers
        }
        int AM = somasMassas / c;
        //int cont = 0;
        int IMB = 0;
        for(int i = 0; i < s - 1; i+=2){
            if(i+1 < massas.size()){
                IMB += abs((massas[i] + massas[i + 1]) - AM);
            }else{
                IMB += abs((massas[i]) - AM);
            }
        }
        cout <<IMB << endl;


    }

    return 0;
}
