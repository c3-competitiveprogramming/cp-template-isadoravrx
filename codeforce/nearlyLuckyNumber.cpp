#include <iostream>
#include <string>
using namespace std;

bool quantifyIsLucky(string contstring){
    for(int i = 0; i < contstring.size(); i++){
        if(contstring[i] != '4' && contstring[i] != '7'){
            return false;
        }
    }

    return true;
}

int main(){
    string num;
    cin >> num;

    long cont = 0;
    for(int i = 0; i < num.size(); i++){
        if(num[i] == '4' || num[i] == '7'){
            cont++;
        }
    }
    string numstring = to_string(cont);
    bool qIsLucky = quantifyIsLucky(numstring);

    if(qIsLucky == true){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

    return 0;
}