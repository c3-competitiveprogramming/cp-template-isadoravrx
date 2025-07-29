#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){ 

    vector<pair<int,int> >pontos;
    for(int i = 0; i < 4; i++){
        int x,y;
        cin >> x >> y;
        pontos.push_back(make_pair(x,y));
    }

    sort(pontos.begin(), pontos.end());
    cout << ((pontos[2].first - pontos[0].first) * (pontos[3].second - pontos[2].second)) << endl;
}