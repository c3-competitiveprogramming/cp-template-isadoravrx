#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    int c, n, q, p, lucro = 0;
    char evento;
    
    while (cin >> c) {
        map<int, bool> estacionado;
        map<int, pair<int, int> > pos; // pos final - inicio 
        vector<int> vagas(c);
        cin >> n;
        lucro = 0;
        while (n--) {
            cin >> evento;
            if (evento == 'C') {
                cin >> p >> q;
                bool procura_vaga = true;
                int i = 0, inicio_vaga = -1;
                if (c >= q) {
                    while (procura_vaga) {
                        while (i < vagas.size() && vagas[i] != 0) {
                            i++;
                        }
                        inicio_vaga = i - 1;
                        while (i < vagas.size() && vagas[i] == 0 && i - inicio_vaga < q) {
                            i++;
                        }
                        if (i - inicio_vaga == q) {
                            for (int j = inicio_vaga; j < i && j < vagas.size(); j++) {
                                vagas[j] = 1;
                                procura_vaga = false;
                            }
                            c -= q;
                            estacionado[p] = true;
                            if(pos.find(p) == pos.end()){
                                pos[p] = make_pair(i, inicio_vaga);
                            }else{
                                pos[p].first = i;
                                pos[p].second = inicio_vaga;
                            }
                            lucro += 10;
                        } else {
                            inicio_vaga = -1;
                        }
                        if (i == vagas.size()) {
                            break;
                        }
                    }
                }
            } else {
                cin >> p;
                if (estacionado.find(p) != estacionado.end() && estacionado[p] == true) {
                    int pos_final = pos[p].first;
                    int pos_inicial = pos[p].second;
                    for (int indice = pos_inicial; indice < pos_final && indice < vagas.size(); indice++) {
                        vagas[indice] = 0;
                    }
                    c += pos_final - pos_inicial;
                    estacionado[p] = false;
                }
            }
        }
        cout << lucro + 10 << endl;
    }

    return 0;
}