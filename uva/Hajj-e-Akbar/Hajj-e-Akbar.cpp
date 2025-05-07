#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    int cont = 1;
    while(true){
        cin >> s;

        if(s == "*"){
            break;
        }
        
        cout << "Case " << cont << ": ";
        if(s == "Hajj"){
            cout << "Hajj-e-Akbar" << endl;
        }else{
            cout << "Hajj-e-Asghar" << endl;
        }

        cont++;
    }
}
