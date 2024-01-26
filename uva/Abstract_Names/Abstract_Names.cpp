#include <iostream>
#include <string>
using namespace std;

int main(){
    int n;
    cin >> n;

    while(n--){
        string s1, s2;
        cin >> s1 >> s2;
    
        bool b = true;
        if(s1.size() == s2.size()){
            for(int i = 0; i < s1.size(); i++){
                if(s1[i] == 'a'|| s1[i] == 'e'||s1[i] == 'i'||s1[i] == 'o'||s1[i] == 'u'){
                    if(s2[i] == 'a'|| s2[i] == 'e'||s2[i] == 'i'||s2[i] == 'o'||s2[i] == 'u'){
                        continue;
                    }else{
                        b = false;
                        break;
                    }
            
                }else{
                    if(s2[i] == 'a'|| s2[i] == 'e'||s2[i] == 'i'||s2[i] == 'o'||s2[i] == 'u'){
                        b = false;
                        break;
                    }else{
                        if(s1[i] != s2[i]){
                            b = false;
                            break;
                        }
                    }
                }
            }
            if(b){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;    
            }
        }else{
            cout << "No" << endl;        
        }
    }
}
