#include <sstream>
#include <vector>
#include <iostream>

using namespace std;

void Pegar(int val, string x[],int y[]){
    for(int i = 0; i < val; i++){
        string prod;
        int valor;

        cin >> prod >> valor;

        x[i] = prod;
        y[i] = valor;
    }
}

class Produto {
    private: string nomeProd;
    int precoProd;

    public:
    Produto(string ad, int bd) {
        nomeProd = ad;
        precoProd = bd;
    }

    bool operator<(const Produto & d){
        if(precoProd != d.precoProd) {
            return precoProd < d.precoProd;
        } else {
            return nomeProd < d.nomeProd;
        }
    }

    friend ostream& operator<<(ostream& osteam, const Produto& product);
};

ostream& operator<<(ostream& osteam, const Produto& product){
    osteam << "(" << product.nomeProd << "," << product.precoProd << ")";

    return osteam;
}

int main() {
    int N, M, P, Q;

    cin >> N >> M >> P >> Q;

    vector<string> resultProd;
    vector<int> resultPreco;
    string ListaProd1[N], ListaProd2[M];

    int ListaPreco1[N], ListaPreco2[M];

    Pegar(N,ListaProd1,ListaPreco1);

    for(int i = 0; i < (N-1);i++) {
        for(int j = (N-1); j > i; j--) {
            Produto prod1(ListaProd1[j-1], ListaPreco1[j-1]);
            Produto prod2(ListaProd1[j], ListaPreco1[j]);

            if(prod2 < prod1) {
                int cont1 = ListaPreco1 [j];
                string cont2 = ListaProd1 [j];
                ListaPreco1 [j] = ListaPreco1 [j-1];
                ListaProd1 [j] = ListaProd1 [j-1];
                ListaPreco1 [j-1] = cont1 ;
                ListaProd1 [j-1] = cont2 ;
            }
        }
    }

    for(int i = 0; i < P; i++) {
        resultProd.push_back(ListaProd1[i]);
        resultPreco.push_back(ListaPreco1[i]);
    }

    Pegar(M, ListaProd2, ListaPreco2);

    for(int i = 0; i < (M-1);i++) {
        for(int j = (M-1); j > i; j--) {
            Produto p1(ListaProd2[j-1], ListaPreco2[j-1]);
            Produto p2(ListaProd2[j], ListaPreco2[j]);

            if(p2 < p1) {
                int cont = ListaPreco2[ j ];
                string cont2 = ListaProd2[ j ];

                ListaPreco2[ j ] = ListaPreco2[j -1];
                ListaProd2[ j ] = ListaProd2[j -1];
                ListaPreco2[j -1] = cont ;
                ListaProd2[j -1] = cont2 ;
            }
        }
    }

    for(int i = 0; i < Q; i++) {
        resultProd.push_back(ListaProd2[i]);
        resultPreco.push_back(ListaPreco2[i]);
    }

    string resultadoProduto[resultProd.size()];
    int resultadoPreco[resultPreco.size()];

    for(int i = 0; i < int(resultProd.size()); i++) {
        resultadoProduto[i] = resultProd[i];
        resultadoPreco[i] = resultPreco[i];
    }

    for(int i = 0; i < (resultPreco.size()-1); i++) {
        for(int j = (resultPreco.size()-1); j > i; j--) {
            Produto prod1(resultadoProduto[j-1], resultadoPreco[j-1]);
            Produto prod2(resultadoProduto[j], resultadoPreco[j]);

            if(prod2 < prod1) {
                int cont = resultadoPreco[j];
                string cont2 = resultadoProduto[j];

                resultadoPreco[j] = resultadoPreco[j-1];
                resultadoProduto[j] = resultadoProduto[j-1];
                resultadoPreco[j-1] = cont ;
                resultadoProduto[j-1] = cont2 ;
            }
        }
    }

    resultPreco.clear();
    resultProd.clear();

    for(int i = 0; i < (sizeof resultadoPreco/sizeof resultadoPreco[0]); i++) {
        resultProd.push_back(resultadoProduto[i]);
        resultPreco.push_back(resultadoPreco[i]);
    }

    for(int i = 0; i < int(resultProd.size()); i++) {
        if(i != resultProd.size()-1) {
            cout << resultProd[i] << " ";
        } else {
            cout << resultProd[i] << endl;
        }
    }
}
