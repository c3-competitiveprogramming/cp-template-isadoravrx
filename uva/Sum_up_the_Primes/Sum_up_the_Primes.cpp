#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

int main(){
    long long n,qtd;
    long long primos[] = {2 ,3 , 3 ,5 ,5 ,7 ,7,11,11,13,13 ,17,17 ,19,19, 23,23 ,29,29 ,31,31 ,37,37 ,41,41 ,43,43, 47,47, 53 ,53,59  , 59,61 ,61,67 ,67,71,71, 73 ,73,79,79, 83,83 ,89,89, 97,97, 101,101 ,103,103 ,107,107 ,109,109 ,113,113 ,127,127 ,131,131 ,137,137, 139,139, 149,149 ,151,151, 157,157, 163,163 ,167,167 ,173,173, 179,179 ,181,181, 191,191 ,193,193 ,197,197, 199,199 ,211,211 ,223,223, 227,227 ,229,229 ,233,233, 239,239, 241,241, 251,251 ,257,257 ,263,263 ,269,269 ,271,271 ,277,277 ,281,281 ,283,283 ,293,293};
    int test = 1;
    while(cin >> n >> qtd){
        printf("CASE %d:", test);
        if(n == 0 && qtd == 0){
            break;
        }

        bool b = false;
        for(int k = 0; k <= 124; k++){
            bitset<124>bt(k);
            
            long long sum = 0;
            long long cont = 0;
            for(int i = 0; i <= 124; i++){
                if(bt[i] == 1){
                    if(bt[i] > n){
                        b = true;
                        break;
                    }else if((sum + primos[i] == n) && (cont+1 == qtd)){
                        for(int j = 0; j <= i ; j++){
                            if(j != 0){
                                cout << "+";
                            }
                            cout << primos[i];
                        }
                    }else if(cont >= qtd || sum + primos[i] > n){
                        break;
                    }else if(sum + primos[i] < n){
                        sum += primos[i];
                        cont++;
                    }
                }
            }
        }
        
        test++;
        if(b){
            cout << "No Solution." << endl;
        }else{
            cout << endl;
        }
    }
}