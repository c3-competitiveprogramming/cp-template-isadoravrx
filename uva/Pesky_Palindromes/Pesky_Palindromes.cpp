#include <iostream>
#include <string>
#include <bitset>
#include <vector>
using namespace std;

bool isPalindrome(string s){
    int v = s.size() - 1;
    for (int i = 0; i <= s.size()/2; i++) {
        if(s[i] != s[v]){
            return false;
        }
        v--;
    }
    return true;
}

int main(){
    string s;
    while(cin >> s){
        int contPalindromo = 0;
        bitset<26>bt(0);
        for (int i = 0; i < s.size(); i++) {
            bt[s[i] - 'a'] = 1;
        }

        for(int i = 0; i < 26; i++){
            if(bt[i] == 1){
                contPalindromo++;
            }    
        }

        vector<string>v;
        for(int i = 0; i < s.size(); i++){
            string sConcat = "";
            sConcat += s[i];
            for(int j = i + 1; j < s.size(); j++){
                 sConcat = sConcat + s[j];
                    bool var = isPalindrome(sConcat);
                    if(var){
                        bool jacolocou = false;
                        for(int i = 0; i < v.size(); i++){
                            if(v[i] == sConcat){
                                jacolocou = true;
                            }
                        }
                        if(jacolocou == false){
                            contPalindromo++;
                            v.push_back(sConcat);
                        }
                    }
            }
        }
            cout << "The string '"<< s << "' contains "<< contPalindromo << " palindromes." << endl;


    }
}

