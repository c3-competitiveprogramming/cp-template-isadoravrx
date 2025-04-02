#include <iostream>
#include <vector>
#include <string>
#include <map>
typedef long long ll;
using namespace std;
map<string,vector<int> >mppi;

template<typename T> vector<int> pi(T s) {
	vector<int> p(s.size());
	for (int i = 1, j = 0; i < s.size(); i++) {
		while (j and s[j] != s[i]) j = p[j-1];
		if (s[j] == s[i]) j++;
		p[i] = j;
	}
	return p;
}

template<typename T> vector<int> matching(T& s, T& t) {
	vector<int>match,p;
    if(mppi.find(s) != mppi.end()){
        p = mppi[s];
    }else{
        p = pi(s);
        mppi[s] = p;
    }

	for (int i = 0, j = 0; i < t.size(); i++) {
		while (j and s[j] != t[i]) j = p[j-1];
		if (s[j] == t[i]) j++;
		if (j == s.size()) match.push_back(i-j+1), j = p[j-1];
	}
	return match;
}


int main(){
    string s;
    while(cin >> s){
        ll sum = 0;
        string temp2, auxtemp2;
        map<string,int>freq;
        map<string,int>ans;
        for(int i = 0; i < s.size(); i++){
            string temp = "";
            if(i == 0){
                temp2 = s.substr(i+1, s.size() - i + 1);
                auxtemp2 = temp2;
            }else{
                auxtemp2.erase(auxtemp2.begin());
                temp2 = auxtemp2;
            }

            for(int j= i; j < s.size() && temp2.size() >= temp.size(); j++){
                temp += s[j];

                while(temp.size() + temp2.size() > s.size()){
                    temp2.erase(temp2.begin());
                }

                if(freq.find(temp) != freq.end()){
                    sum += (ans[temp]-freq[temp]) * temp.size();
                    freq[temp]++;
                }else{
                    int vsize = matching(temp,temp2).size();   
                    freq[temp]++;
                    ans[temp] =  vsize;
                    sum +=  vsize * temp.size();
                }
            }
        }

        cout << sum << endl;
    }
}