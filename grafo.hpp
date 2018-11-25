// TRABALHO FINAL DE AED
// PROTOCOLO DE ROTEAMENTO
// Funcionalidade: Grafo
// Responsavel: Thiago alves e Daniel Gobbi
// Implementacao da classe do grafo

#ifndef GRAFO
#define GRAFO
#include <iostream>
#include <list>
#include <queue>
#include <vector>
#include "roteador_dado.hpp"
#define INFINITY 999

using namespace std;

class Grafo
{
  public:
  	int NO; // somente auxiliar
    Roteador *roteadores; 
  	list<pair<int, int> >* adjacente; //lista de adjacencia - par de inteiros, onde o primeiro é o numero do no adjacente e o segundo é o custo do enlace
	  									  //qual no se liga a qual e com o custo
	// CONSTRUTOR
	Grafo(int NO)
	{
		this->NO = NO; //numero de nos
        roteadores = new Roteador[NO];
		adjacente = new list<pair<int, int> >[NO]; //lista de adjacencia dos nos com o no vizinho e o custo
		
	} 
	
    // METODOS
	//adiciona os enlaces do grafo, o no1 recebe um no2 adjacente com um custo
	void Enlaces(int NO_1, int NO_2, int custo)
	{
		adjacente[NO_1].push_back(make_pair(NO_2, custo));
	}
	
	int Dijkstra(int NO_origem, int NO_destino)
	{
		int distancia[NO]; //distancia do no de referencia para os outros nos
		
	    int visitados[NO]; //nos ja expandidos
		
		priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > x; //alteraçao na funçao para lista de prioridade minima
	
		for(int i=0; i< NO; i++)
		{
			distancia[i] = INFINITY;
			visitados[i] = false;
		}
		
		distancia[NO_origem]=0;
		
		x.push(make_pair(distancia[NO_origem],NO_origem));//inserindo na fila de prioridades
		
		while(!x.empty())//enquanto a lista de prioridade for diferente de vazia
		{
			pair<int, int> k = x.top();//pega o par(distancia e no) do top da fila 
			int no = k.second; //obtem o no do par// second pq o no é o segundo no par
			x.pop(); // remove da fila de prioridade
			
			if(visitados[no] == false)
			{
				// marca o no como visitado
				visitados[no] = true;

				list<pair<int, int> >::iterator it;

				// percorre os nos "n" adjacentes de "no"
				for(it = adjacente[no].begin(); it != adjacente[no].end(); it++)
				{
					// obtém o no adjacente e o custo do enlace
					int n = it->first;
					int custo_enlace = it->second;

					// relaxamento (no, n)
					if(distancia[n] > (distancia[no] + custo_enlace))
					{
						// atualiza a distância de "n" e insere na fila
						distancia[n] = distancia[no] + custo_enlace;
						x.push(make_pair(distancia[n], n));
					}
				}
			}
		}
		//distancia minima, resultado do algoritmo de dijkstra
		return distancia[NO_destino];
	}
	
    void envia_pacote(){
        int aux, aux2;
        Dado *d; // somente auxiliar
        cout << "Qual o roteador de origem do pacote?\n";
        cin >> aux2;
        cout << "Qual o roteador de destino do pacote?\n";
        cin >> aux;
        if ((aux >= 0 && aux < NO) && (aux2 >= 0 && aux2 < NO)){ // checa se é um número valido de roteador
            d = new Dado(aux);
            d->caminho = Dijkstra(aux2, aux);
            if (d->caminho == 999){
                cout << "Nao existe enlace de " << aux2 << " para " << aux << "!\n";
            }else{
                roteadores[aux].dados.push_back(*d);
            }
        }
        else
            cout << "Voce digitou um número invalido para o roteador\n";
        delete[] d;
    }

    void mostrar_tabela(){ // metodo para mostrar tabela logica do roteador
        int aux, i = 0;
        vector<Dado>::iterator it;
        cout << "Voce gostaria de consultar a tabela de qual roteador?\n";
        cin >> aux;
        if (aux >= 0 && aux < NO){
            if (roteadores[aux].dados.empty())
                cout << "O roteador " << aux << " ainda nao recebeu nenhum pacote!\n";
            else{
                cout << "Tabela do roteador " << aux << ":\n";
                it = roteadores[aux].dados.begin();
                do {
                    cout << "DADO " << i + 1 << ":\n";
                    cout << "Codigo: " << it->codigo << "\n";
                    cout << "Custo de caminho minimo: " << it->caminho << "\n";
                    cout << endl;
                    ++i;
                    ++it;
                } while (it != roteadores[aux].dados.end());
                    
            }
        }else{
            cout << "Voce digitou um ID invalido de roteador\n";
        }
    }

	void Monta_grafo(int NO)
	{
		int no_inicio, no_final, custo;
		string sair;
		
		cout<<"Insira os nos da rede com os custos associados para montar o grafo"<<endl;
		while(sair!="x")
		{
			cout<<"Insira o ID do no de origem"<<endl;
			cin>>no_inicio;
			cout<<"Insira o ID do no de destino"<<endl;
			cin>>no_final;
            if ((no_inicio >= 0 && no_inicio < NO) && (no_final >= 0 && no_final < NO)){
				cout<<"Insira o custo do enlace entre os nos"<<endl;
				cin>>custo;
		        Enlaces(no_inicio, no_final, custo);
				cout<<"Para sair digite 'x' "<<endl;
				cin>>sair;
            }else{
                cout << "Voce digitou um numero invalido de roteador!\n";
            }
		}
	}

};

#endif
