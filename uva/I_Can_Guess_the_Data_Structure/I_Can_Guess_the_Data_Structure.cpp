#include <iostream>
#include <vector>
#include <deque>
#include <set>
using namespace std;

int main(){
    int n;

    while(cin >> n){

        deque<int>stack;
        vector<int>queue;
        multiset<int>st;

        bool pilha = true;
        bool fila  = true;
        bool priorfila = true;

        for(int i = 0; i < n; i++){
            int a,b;
            cin >> a >> b;
            if(a == 1){
                stack.push_front(b);
                queue.push_back(b);
                st.insert(b);
            }else{
                if(stack.size() == 0 || (*stack.begin()) != b ){
                    pilha = false;
                }else{
                    stack.erase(stack.begin());
                }
                if(  queue.size() == 0 || queue[0] != b){
                    fila = false;
                }else{
                    queue.erase(queue.begin());
                }
                if(st.size() == 0 || (*(--st.end())) != b){
                    priorfila = false;
                }else{
                    st.erase(--st.end());
                }
            }
        }

        if((pilha && fila && priorfila) || (!pilha && fila && priorfila) || (pilha && !fila && priorfila)|| (pilha && fila && !priorfila)){
            cout << "not sure" << endl;
        }else if(!pilha && !fila && !priorfila){
            cout << "impossible" << endl;
        }else if(pilha && !fila && !priorfila){
            cout << "stack" << endl;
        }else if(!pilha && fila && !priorfila){
            cout << "queue" << endl;
        }else{
            cout << "priority queue" << endl;
        }
    }
}
