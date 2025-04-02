#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <queue>
using namespace std;

const int MAX = 5005;

namespace aho {
	map<char, int> to[MAX];
	int link[MAX], idx, term[MAX], exit[MAX], sobe[MAX];

	void insert(string& s) {
		int at = 0;
		for (char c : s) {
			auto it = to[at].find(c);
			if (it == to[at].end()) at = to[at][c] = ++idx;
			else at = it->second;
		}
		term[at]++, sobe[at]++;
	}
	void build() {
		queue<int> q;
		q.push(0);
		link[0] = exit[0] = -1;
		while (q.size()) {
			int i = q.front(); q.pop();
			for (auto [c, j] : to[i]) {
				int l = link[i];
				while (l != -1 and !to[l].count(c)) l = link[l];
				link[j] = l == -1 ? 0 : to[l][c];
				exit[j] = term[link[j]] ? link[j] : exit[link[j]];
				if (exit[j]+1) sobe[j] += sobe[exit[j]];
				q.push(j);
			}
		}
	}
	int query(string& s) {
		int at = 0, ans = 0;
		for (char c : s){
			while (at != -1 and !to[at].count(c)) at = link[at];
			at = at == -1 ? 0 : to[at][c];
			ans += sobe[at];
		}
		return ans;
	}
}

int main(){
        string s;

        while(cin >> s){
			aho::insert(s);
			aho :: build();
			cout << aho :: query(s) << endl;

        }
    }