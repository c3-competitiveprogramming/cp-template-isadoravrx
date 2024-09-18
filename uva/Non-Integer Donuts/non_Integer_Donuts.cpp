#include<iostream>
#include<string>
using namespace std;

int main(){

    int n, cents, c,qtd=0;
    cin>>n;
    string s;
    cin>>s;

    //cout<<n<<" "<<s<<endl;
    cents=(s[s.size()-1]-'0')+((s[s.size()-2]-'0')*10);
    //cout<<cents<<" "<<s<<endl;
    for(int i=0;i<n;i++){
        cin>>s;
        cents+=(s[s.size()-1]-'0')+((s[s.size()-2]-'0')*10);
        if(cents%100!=0){
            qtd++;
        }
    }

    cout<<qtd<<endl;

    return 0;
}