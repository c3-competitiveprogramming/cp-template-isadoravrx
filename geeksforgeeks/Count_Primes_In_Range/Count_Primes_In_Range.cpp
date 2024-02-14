#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int l,r;
	cin >> l >> r;
	
	int cont = 0;
	for(int i = l; i <= r; i++){
		bool b = true;
		
		for(int j = 2; j <= sqrt(i); j++){
			if(i % j == 0){
				b = false;
				break;
			}
		}
	
		if(b){
			cont++;	
		}
	}

	cout << cont << endl;
}
