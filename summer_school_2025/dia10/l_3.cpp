#include <iostream>
#include <vector>
using namespace std;
const int MAX = 200005;

int n, subsize[MAX];
vector<int> g[MAX];

void dfs(int k, int p=-1) {
	subsize[k] = 1;
	for (int i : g[k]) if (i != p) {
		dfs(i, k);
		subsize[k] += subsize[i];
	}
}

int centroid(int k, int p=-1, int size=-1) {
	if (size == -1) size = subsize[k];
	for (int i : g[k]) if (i != p) if (subsize[i] > size/2)
		return centroid(i, k, size);
	return k;
}

pair<int, int> centroids(int k=1) {
	dfs(k);
	int i = centroid(k), i2 = i;
	for (int j : g[i]) if (2*subsize[j] == subsize[k]) i2 = j;
	return make_pair(i, i2);
}

int main(){
    cin >> n;

    for(int i = 0; i < n-1; i++){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    pair<int, int> ans = centroids();
    cout << ans.first << endl;
}