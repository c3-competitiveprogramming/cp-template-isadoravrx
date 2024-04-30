#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;

    cin >> s;

    int i = 0;

    while(i < s.size()){
        if(i!= s.size()-1 && s[i] == s[i+1]){
            int ini = i;
            int fim = i;

            int cont = 1;
            for(int j = 0; j < s.size(); j++){
                if(s[j] != s[ini]){
                    break;
                }
                fim++;
                cont++;
            }
            
            if(cont % 2 == 0){
                for(int j =  ini; j <= fim; j+=2){
                     if(j >= 0 && s[j-1] != 'c' && s[j+1] != 'c'){
                        s[j] = 'c';
                    }else if(j >= 0 && s[j-1] != 'a' && s[j+1] != 'a'){
                         s[j] = 'a';
                    }else if(j >= 0 && s[j-1] != 'b' && s[j+1] != 'b'){
                         s[j] = 'b';
                    }else if(j == 0){
                        if(s[j + 1] != 'a'){
                            s[j] = 'a';
                        }else{
                            s[j] = 'b';
                        }
                    }

                }
            }else{
                for(int j =  ini + 1; j <= fim; j+=2){
                    if(j >= 0 && s[j-1] != 'c' && s[j+1] != 'c'){
                        s[j] = 'c';
                    }else if(j >= 0 && s[j-1] != 'a' && s[j+1] != 'a'){
                         s[j] = 'a';
                    }else if(j >= 0 && s[j-1] != 'b' && s[j+1] != 'b'){
                         s[j] = 'b';
                    }else if(j == 0){
                        if(s[j + 1] != 'a'){
                            s[j] = 'a';
                        }else{
                            s[j] = 'b';
                        }
                    }
                } 
            }

            
            i = fim + 1;
        }
    }
    cout << s << endl;
}

