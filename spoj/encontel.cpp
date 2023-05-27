#include <iostream>
#include <string>
using namespace std;
char number(char c){
    if(c == 'A' || c == 'B' || c == 'C'){
        return '2';
    }else if(c == 'D' || c == 'E' || c == 'F'){
        return '3';
    }else if(c == 'G' || c == 'H' || c == 'I'){
        return '4';
    }else if(c == 'J' || c == 'K' || c == 'L'){
        return '5';
    }else if(c == 'M' || c == 'N' || c == 'O'){
        return '6';
    }else if(c == 'P' || c == 'Q' || c == 'R'  || c == 'S'){
        return '7';
    }else if(c == 'T' || c == 'U' || c == 'V'){
        return '8';
    }else if(c == 'W' || c == 'X' || c == 'Y' || c == 'Z'){
        return '9';
    }

    return '0';
}
int main(){
    string s;
    while(cin >> s){

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '-' || s[i] == '1' || s[i] == '2'){
                continue;
            }

            s[i] = number(s[i]);
        }

        for(int i = 0; i < s.size(); i++){
            cout << s[i];
            if(i == s.size() - 1){
                cout << endl;
            }
        }

    }
    return 0;
}
