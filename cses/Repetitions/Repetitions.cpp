#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    cin >> s;

    int i = 0;
    int j = 1;
    int cont = 1;
    int bestcont = 1;
    while(true){
        if(j == s.size()){
            break;
        }

        if(s[i] == s[j]){
            cont++;
        }else{
            cont = 1;
            i = j;
        }
        j++;
        bestcont = max(bestcont,cont);
    }
    cout << bestcont << endl;
}