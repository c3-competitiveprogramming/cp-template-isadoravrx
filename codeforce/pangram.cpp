#include <iostream>
#include <string>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int minusculo[26] = {0};
    int maiusculo[26] = {0};
    for(int i = 0 ; i < n; i++){ 
        if(s[i] + 0 >= 65 && s[i] + 0 <= 90){  //se for maiuscula, pois A vale 65 e e Z vale 90
            int index = s[i] - 'A';
            maiusculo[index]++;
            continue;
        }
        int index  = s[i] - 'a';
        minusculo[index]++;
    }
    
    bool pangram = true;
    for(int i = 0; i < 26; i++){
        if(minusculo[i] == 0 && maiusculo[i] == 0){
            pangram = false;
            break;
        }
    }

    if(pangram == true){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

}
