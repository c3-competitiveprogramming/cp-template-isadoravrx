#include <iostream>
#include <cmath>
using namespace std;
int v[200002];
int main(){
	
	int cont = 0;
	for(int i = 2; i <= 200000; i++){
                bool b = true;
        
                for(int j = 2; j <= sqrt(i); j++){
                    if(i % j == 0){
                        b = false;
                        break;
                    }       
                }

                if(b && i != 1){  
                    cont++;
                }
        
                v[i] = cont;
            
                
         }

	
	int l,r;
	while(cin >> l >> r){
		cout << (v[r] - v[l-1]) << endl;
	}
            
}
