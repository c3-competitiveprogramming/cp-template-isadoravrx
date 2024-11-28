#include <iostream>
#include <string>
using namespace std;

int main(){
    int n;
    string gabarito;
    string resposta;
    cin >> n;
    int counter = 0;
    
    cin >> gabarito;
    cin >> resposta;
    
    for(int i = 0; i < n; i++){
        if(gabarito[i] == resposta[i]){
            counter++;
        }
    } 

    cout << counter << endl;
    return 0;
}