#include<iostream>
#include<string>
using namespace std;

bool ehVogal(char c){
    if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
        return true;
    }

    return false;
}

int main(){

    string s;
    cin>>s;
    int i=0, j=s.size()-1;
    bool eh=true;
    while(i<j){
        if(ehVogal(s[i]) && ehVogal(s[j])){
            if(s[i]!=s[j]){
                cout<<"N\n";
                return 0;
            }
            
        }else if(ehVogal(s[i])){
            i--;
        }else if(ehVogal(s[j])){
            j++;
        }
        i++;j--;
    }

    cout<<"S\n";

    return 0;
}