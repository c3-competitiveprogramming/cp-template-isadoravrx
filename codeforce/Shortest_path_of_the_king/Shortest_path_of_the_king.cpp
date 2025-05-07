#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <set>
using namespace std;
int ldestino,cdestino;
vector<string>ans;
int dist[18][18];

void djk(int xinicial, int yinicial){
    set<pair<pair<int,vector<string> >,pair<int,int> > >st;
    st.insert(make_pair(make_pair(0,ans),make_pair(xinicial,yinicial)));
    dist[xinicial][yinicial] = 0;

    
    while(!st.empty()){
        int x = (*st.begin()).second.first;
        int y = (*st.begin()).second.second;
        vector<string>temp = (*st.begin()).first.second;
        int cost = (*st.begin()).first.first;
        

        st.erase(st.begin());

        if(x == ldestino && y == cdestino){
            if(ans.size() > temp.size() || ans.size() == 0){
                ans = temp;
            }
        }

        if(x > 0 && cost < dist[x-1][y]){//cima
            dist[x-1][y] = cost + 1;
            temp.push_back("U");
            st.insert(make_pair(make_pair(cost+1,temp), make_pair(x-1,y)));
            temp.pop_back();
        }

        if(x > 0 && y > 0 && cost < dist[x-1][y-1]){//esquerda cima
            dist[x-1][y-1] = cost + 1;
            temp.push_back("LU");
            st.insert(make_pair(make_pair(cost+1,temp),make_pair(x-1,y-1)));
            temp.pop_back();
        }   
        
        if(y > 0 && cost < dist[x][y-1]){//esquerda
            dist[x][y-1] = cost;
            temp.push_back("L");
            st.insert(make_pair(make_pair(cost+1,temp), make_pair(x,y-1)));
            temp.pop_back();
        }

        if(x < 7 && y > 0 && cost < dist[x+1][y-1]){//esquerda baixo
            dist[x+1][y-1] = cost;
            temp.push_back("LD");
            st.insert(make_pair(make_pair(cost+1,temp),make_pair(x+1,y-1)));
            temp.pop_back();
        }

        if(x < 7 && cost < dist[x+1][y]){//baixo
            dist[x+1][y] = cost;
            temp.push_back("D");
            st.insert(make_pair(make_pair(cost+1,temp),make_pair(x+1,y)));
            temp.pop_back();
        }
        
        if(x < 7 && y < 7 && cost < dist[x+1][y+1]){//direita baixo
            dist[x+1][y+1] = cost;
            temp.push_back("RD");
            st.insert(make_pair(make_pair(cost+1,temp),make_pair(x+1,y+1)));
            temp.pop_back();
        }

        if(y < 7 && cost < dist[x][y+1]){//direita
            dist[x][y+1] = cost;
            temp.push_back("R");
            st.insert(make_pair(make_pair(cost+1,temp),make_pair(x,y+1)));
            temp.pop_back();
        }

        if(x > 0 && y < 7 && cost < dist[x-1][y+1]){//direita cima
            dist[x-1][y+1] = cost;
            temp.push_back("RU");
            st.insert(make_pair(make_pair(cost+1,temp),make_pair(x-1,y+1)));
            temp.pop_back();
        }

    }
    
}
int main(){
    string s;
    cin >> s;

    int cking = s[0] - 'a';
    int lking = s[1] - '0';

    lking = 8 - lking;

    cin >> s;

    cdestino = s[0] - 'a';
    ldestino = s[1] - '0';

    ldestino = 8 - ldestino;

    memset(dist, 1000000, sizeof(dist));
    djk(lking,cking);

    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << endl;
    }
}