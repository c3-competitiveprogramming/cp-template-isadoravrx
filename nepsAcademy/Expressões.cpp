#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        string  s;
        cin >> s;
        bool hascomplemente = true;
        deque<char>open;
        
        for(int j = 0; j < s.size(); j++){
            if(s[j] == '{' || s[j] == '[' || s[j] == '('){
                open.push_front(s[j]);
            }else{
                if(!open.empty()){
                    char aberto = open[0];
                    open.pop_front();
                    if(s[j] == ')'){
                        if(aberto != '('){
                            hascomplemente = false;
                        }
                    }else if(s[j] == ']'){
                        if(aberto != '['){
                            hascomplemente = false;
                        }
                    }else{
                        if(aberto != '{'){
                            hascomplemente = false;
                        }
                    }
                }else{
                    hascomplemente = false;
                }
            }
        }

        if(hascomplemente == false || !open.empty()){
            cout << "N" << endl;
        }else{
            cout << "S" << endl;
        }
    }
}
