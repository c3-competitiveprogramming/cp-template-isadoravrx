#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;

    cin >> s;

    int i = 0;

    while(i < s.size()){
        if(i != s.size()  && s[i] == s[i+1]){

            int ini = i;
            int fim = i;

            for(int j = i+1; j < s.size(); j++){
                if(s[i] == s[j]){
                    fim++;
                }else{
                    break;
                }
            }

            for(int j = ini+1; j <= fim; j+=2){
                if(j == 0 && j+1 < s.size()){
                    if(s[j+1] != 'a'){
                        s[j] = 'a';
                    }else{
                        s[j] = 'b';
                    }
                }else if(j == s.size()-1){
                    if(s[j-1] != 'a'){
                        s[j] = 'a';
                    }else{
                        s[j] = 'b';
                    }
                }else{
                    if(s[j+1] != 'a' && s[j-1] != 'a'){
                        s[j] = 'a';
                    }else if(s[j+1] != 'b' && s[j-1] != 'b'){
                            s[j] = 'b';
                    }else{
                            s[j] = 'c';
                    }
                }
            }

            i = fim + 1;
        }else{
            i++;
        }
    }
                            
    cout << s << endl;
                            
}

