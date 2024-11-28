#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;

    while(getline(cin,s)){
        string temp = "";

        for(int i = 0; i < s.size(); i++){
            temp += char(int(s[i]) - 7);
        }

        cout << temp << endl;
    }
}
