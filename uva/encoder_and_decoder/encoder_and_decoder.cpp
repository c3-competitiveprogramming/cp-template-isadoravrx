#include<iostream>
#include<string>
using namespace std;

int main(){

    string s;
    while(getline(cin,s)){
        if(s[0]>='0' && s[0]<='9'){
            int i=s.size()-1;
            while(i>=0){
                string num="";
                if(s[i]=='1'){
                    num+=s[i];
                    i--;
                    num+=s[i];
                    i--;
                    num+=s[i];
                    i--;
                }else{
                    num+=s[i];
                    i--;
                    num+=s[i];
                    i--;
                }

                int valor=stoi(num);
                printf("%c",valor);
            }
        }else{
            string printar="";
            for(int i=s.size()-1;i>=0;i--){
                printar=to_string(int(s[i]));
                for(int i=printar.size()-1;i>=0;i--){
                    printf("%c",printar[i]);
                }
            }
        }
        printf("\n");
    }

    return 0;
}