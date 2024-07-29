#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
int pos = 0;

string nextword(string s){
    string temp;

    while(s[pos] == ' '){
        pos++;
    }
    int i = pos;
    while(i < s.size() && s[i] != ' '){
        temp += s[i];
        i++;
    }
    
    pos = i;
    return temp;
    
}

int main(){
    string s;

    map<string,vector<string> > dependencies;
    map<string, int> installed;
    map<string,int>isdepence;
    vector<string>ordemdeinstalacao;
    while(getline(cin,s)){
        if(s == "END"){
            cout << "END" << endl;
            break;
        }

        pos = 0;
      
        string firstword  = nextword(s);
        if(firstword == "DEPEND"){
            cout << s << endl;

            string dependente = nextword(s);
            while(pos != s.size()){
                string temp = nextword(s);
                dependencies[dependente].push_back(temp);
                isdepence[temp]++;
            }
        }else if(firstword == "INSTALL"){
            cout << s << endl;

            string instalado = nextword(s);
            if(installed.find(instalado) != installed.end() && installed[instalado] == 1){
                printf("\t");   
                cout << instalado;
                printf(" is already installed.\n");
            }else{
                installed[instalado] = 1;
                
                for(int i = 0; i < dependencies[instalado].size(); i++){
                    if(installed.find(instalado) == installed.end() || installed[dependencies[instalado][i]] == 0){
                        installed[dependencies[instalado][i]] = 1;
                        printf("\t");   
                        cout << "Installing " << dependencies[instalado][i] << endl; 
                        ordemdeinstalacao.push_back(dependencies[instalado][i]);
                    } 
                }
                ordemdeinstalacao.push_back(instalado);
                printf("\t");   
                cout << "Installing " << instalado << endl; 
            }
            
        }else if(firstword == "REMOVE"){
            cout << s << endl;
            string vaiserremovido = nextword(s);
            if( installed.find(vaiserremovido) == installed.end() || installed[vaiserremovido] == 0){
                printf("\t");  
                cout << vaiserremovido; 
                printf(" is not installed.\n");
            }else if(isdepence[vaiserremovido] > 0){
                printf("\t");  
                cout << vaiserremovido; 
                printf(" is still needed.\n");
            }else{
                printf("\t");   
                printf("Removing ");
                cout << vaiserremovido << endl;

                for(int i = dependencies[vaiserremovido].size() -1; i >= 0 ; i--){
                    isdepence[dependencies[vaiserremovido][i]]--;
                    if(isdepence[dependencies[vaiserremovido][i]] == 0){
                        installed[dependencies[vaiserremovido][i]] = 0;
                        printf("\t");   
                        printf("Removing ");
                        cout << dependencies[vaiserremovido][i] << endl;
                    }
                }
            }

        }else{
            cout << s << endl;
            for(auto it : ordemdeinstalacao){
                if(installed[it] == 1){
                    printf("\t");   
                    cout << it << endl;
                }
            }
        }
        
    }
}