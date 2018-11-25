// TRABALHO FINAL DE AED
// PROTOCOLO DE ROTEAMENTO
// Funcionalidade: Menu
// Responsavel: Daniel Gobbi e Arthur Madero

#include <iostream>
#include <string>
#include <vector>
#include "roteador_dado.hpp"
#include "grafo.hpp" 
using namespace std;

int main(){
    int opcao = 1;
    bool montado = false; // auxiliar para checar se foi montado um grafo ou nao
    int auxi; // inteiro auxiliar
    Grafo *g = NULL;

    cout << "Bem vindo a simulador de rede!\n";
    cout << "Selecione uma das opcoes a seguir:\n";
    while (opcao > 0 && opcao < 5){
        cout << "1) Iniciar uma nova rede\n";
        cout << "2) Criar enlace entre dispositivos\n";
        cout << "3) Enviar pacote\n";
        cout << "4) Consultar tabela de roteador\n";
        cout << "5) Sair\n";
        cin >> opcao;

        switch(opcao){
            case 1:
                g = NULL;
                cout << "Quantos dispositivos terao na sua rede?\n";
                cin >> auxi;
                g = new Grafo(auxi);
                cout << endl;
                break;
            case 2:
                if (g != NULL){
                    g->Monta_grafo(auxi);
                    montado = true;
                }
                else
                    cout << "É necessario criar uma rede primeiro!\n";
                cout << endl;
                break;
            case 3:
                if (g == NULL)
                    cout << "É necessario criar uma rede primeiro!\n";
                else if (montado == false)
                    cout << "É necessario criar enlaces entre os roteadores primeiro!\n";
                else{
                    g->envia_pacote();
                }
                cout << endl;
                break;
            case 4:
                if (g == NULL)
                    cout << "É necessario criar uma rede primeiro!\n";
                else{
                    g->mostrar_tabela();
                }
                cout << endl;
                break;
        }
    }

    delete[] g;
    return 0;
}
