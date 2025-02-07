#include <iostream>
#include <vector>

using namespace std;

class ListaSequencial {
private:
    vector<int> lista;
    size_t capacidade;

public:
    
    ListaSequencial(size_t cap = 100) : capacidade(cap) {}

  
    bool estaVazia() const {
        return lista.empty();
    }

    
    bool estaCheia() const {
        return lista.size() >= capacidade;
    }

    
    size_t tamanho() const {
        return lista.size();
    }

    
    int obterElemento(size_t pos) const {
        if (pos >= lista.size()) {
            cerr << "Erro: Posição inválida!" << endl;
            exit(EXIT_FAILURE);
        }
        return lista[pos];
    }

    void modificarElemento(size_t pos, int valor) {
        if (pos >= lista.size()) {
            cerr << "Erro: Posição inválida!" << endl;
            exit(EXIT_FAILURE);
        }
        lista[pos] = valor;
    }

    
    void inserirElemento(size_t pos, int valor) {
        if (estaCheia()) {
            cerr << "Erro: Lista cheia!" << endl;
            return;
        }
        if (pos > lista.size()) {
            cerr << "Erro: Posição inválida!" << endl;
            return;
        }
        lista.insert(lista.begin() + pos, valor);
    }

    
    void removerElemento(size_t pos) {
        if (pos >= lista.size()) {
            cerr << "Erro: Posição inválida!" << endl;
            return;
        }
        lista.erase(lista.begin() + pos);
    }

    
    void exibirLista() const {
        cout << "Lista: ";
        for (int num : lista) {
            cout << num << " ";
        }
        cout << endl;
    }
};

int main() {
    ListaSequencial lista(10);
    
    lista.inserirElemento(0, 5);
    lista.inserirElemento(1, 10);
    lista.inserirElemento(2, 15);
    lista.exibirLista();

    cout << "Elemento na posição 1: " << lista.obterElemento(1) << endl;
    lista.modificarElemento(1, 20);
    lista.exibirLista();

    lista.removerElemento(1);
    lista.exibirLista();

    cout << "Lista está vazia? " << (lista.estaVazia() ? "Sim" : "Não") << endl;
    cout << "Lista está cheia? " << (lista.estaCheia() ? "Sim" : "Não") << endl;
    cout << "Tamanho da lista: " << lista.tamanho() << endl;
    
    return 0;
}
