// TRABALHO FINAL DE AED
// PROTOCOLO DE ROTEAMENTO
// Funcionalidade: Grafo
// Responsavel: Thiago alves
// Implementacao da classe do grafo

#include<iostream>
#include<list>
#include<cmath>
#include<queue>

using namespace std;

class Grafo
{
	  public:
	  	int NO;
	  	list<pair<int, int> >* adjacente; //lista de adjacencia - par de inteiros, onde o primeiro é o numero do nó adjacente e o segundo é o custo do enlace
	  									  //qual nó se liga a qual e com o custo
	//construtor da classe
	Grafo(int NO)
	{
		this->NO = NO; //numero de nós
		adjacente = new list<pair<int, int> >[NO]; //lista de adjacencia dos nós com o nó vizinho e o custo
		
	} 
	
	//adiciona os enlaces do grafo, o nó1 recebe um nó2 adjacente com um custo
	void Enlaces(int NO_1, int NO_2, int custo)
	{
		adjacente[NO_1].push_back(make_pair(NO_2, custo));
	}
	
	int Dijkstra(int NO_origem, int NO_destino)
	{
		int distancia[NO]; //distancia do nó de referencia para os outros nós
		
	  int visitados[NO]; //nós já expandidos
		
		priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > x; //alteração na função para lista de prioridade minima
	
		for(int i=0; i< NO; i++)
		{
			distancia[i] = INFINITY;
			visitados[i] = false;
		}
		
		distancia[NO_origem]=0;
		
		x.push(make_pair(distancia[NO_origem],NO_origem));//inserindo na fila de prioridades
		
		while(!x.empty())//enqunato a lista de prioridade for diferente de vazia
		{
			pair<int, int> k = x.top();//pega o par(distancia e nó) do top da fila 
			int no = k.second; //obtem o nó do par// second pq o nó é o segundo no par
			x.pop(); // remove da fila de prioridade
			
			if(visitados[no] == false)
			{
				// marca o nó como visitado
				visitados[no] = true;

				list<pair<int, int> >::iterator it;

				// percorre os nós "n" adjacentes de "no"
				for(it = adjacente[no].begin(); it != adjacente[no].end(); it++)
				{
					// obtém o nó adjacente e o custo do enlace
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
		//distancia mininma, resultado do algoritmo de dijkstra
		return distancia[NO_destino];
	}
	
	void Monta_grafo(Grafo grafo, int no_origem, int no_destino)
	{
		int no_inicio, no_final, custo;
		string sair;
		
		cout<<"Insira os nos da rede com os custos associados para montar o grafo"<<endl;
		while(sair!="x")
		{
			cout<<"Insira o no de origem"<<endl;
			cin>>no_inicio;
			cout<<"Insira o no de destino"<<endl;
			cin>>no_final;
			cout<<"Insira o custo do enlace"<<endl;
			cin>>custo;
			grafo.Enlaces(no_inicio, no_final, custo);
			cout<<"Para sair digite 'x' "<<endl;
			cin>>sair;
		}
		cout<<" custo do no "<<no_origem<<" ate o no "<<no_destino<<" = "<<grafo.Dijkstra(no_origem, no_destino);
	}

};



int main()
{
	int numero_nos,numero_enlaces, no_origem, no_destino;
/*	
	cout<<"Insira o numero de nos da redes"<<endl;
	cin>>numero_nos;
	cout<<"Insira o no de origem da rede"<<endl;
	cin>>no_origem;
	cout<<"Insira o no de destino da rede"<<endl;
	cin>>no_destino;
	
	system("cls");
//	cout<<"Insira o numero de enlaces"<<endl;
//	cin>>numero_enlaces;
	
	Grafo grafo(numero_nos);
	
	grafo.Monta_grafo(grafo,no_origem, no_destino);
*/
	Grafo grafo(5);
	
	grafo.Enlaces(0, 1, 1);
	grafo.Enlaces(0, 3, 3);
	grafo.Enlaces(0, 4, 10);
	grafo.Enlaces(1, 2, 5);
	grafo.Enlaces(3, 2, 2);
	grafo.Enlaces(2, 4, 1);
	grafo.Enlaces(3, 4, 6);
	
	cout << grafo.Dijkstra(0, 4) << endl;
	
	return 0;
}
