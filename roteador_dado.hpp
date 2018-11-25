// TRABALHO FINAL DE AED
// PROTOCOLO DE ROTEAMENTO
// Funcionalidade: Roteador e Dado
// Arquivo que contem as classes do Roteador e do Dado que ser� transmitido
// Responsavel: Arthur Madero

#ifndef DADO    
#define DADO
#include <iostream>
#include <time.h>
#include <string>
#include <vector>
using namespace std;

class Dado{
  public:
    // ATRIBUTOS
    int codigo; // identificador do Dado
    int caminho; // diz o custo do caminho m�nimo	
	// CONSTRUTOR
    Dado(int id){
        if (id != 0)
    		codigo = (time(NULL) % 1000 + 1)*id; // fun��o hash implementada aqui
        else
    		codigo = (time(NULL) % 1000 + 1); // fun��o hash implementada aqui

	}
};

class Roteador{
  public:
    // ATRIBUTOS
    vector <Dado> dados; // tabela inteligente do roteador
};

#endif
