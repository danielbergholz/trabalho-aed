# Trabalho Final - Algoritmo e Estrutura de Dados

## Integrantes da equipe:
* Daniel Gobbi Bergholz 16/0004551
* Arthur Madero 16/0113113
* Thiago alves 16/0146348 

Git do trabalho final da disciplina de AED na UnB 02/2018.

### Updates semanais:
* **19/11**: Discussão bem inicial do projeto. O que decidimos: 
  * Utilizar a estrutura de matriz (e não de lista de vetores) no grafo;
  * O usuário que irá decidir todos os aspectos da rede que será simulada:
    * "Quantos dispositivos estão conectados na rede?";
    * "Quem está conectado em quem?";
    * "Qual o custo dos caminhos de cada roteador para o outro roteador no qual ele está conectado?";
  * Delegamos as tarefas da semana:
    * Daniel: Menu e organização da equipe (distribuição de tarefas e gestão do Git);
    * Thiago: Grafo e caminho mínimo;
    * Arthur: Tabela Hash;
* **21/11**: Ainda algumas discussões. Começamos a programar efetivamente hoje. O que ficou decidido:
  * Utilização de arquivos .hpp
    * Antes, iríamos fazer um monte de .cpp e unir em um só codigo main, agora ficou mais organizado;
    * Um arquivo .hpp que conterá as classes do Roteador e do Dado
  * A equipe se familiarizou mais com os comandos do GitHub
* **24/11 - 25/11**: Finalização do trabalho
  * Thiago Alves: Fez Sketch praticamente pronto do grafo.hpp
  * Arthur Madero: Fez as classes do dado e do roteador e começou a escrever o main.cpp
  * Daniel Gobbi: Concluiu o grafo.hpp e o main.cpp
  * Agora em termos mais técnicos:
    * Thiago: Escreveu a maior parte do grafo.hpp. Foi o responsável por todo o algoritmo de Dijkstra
    * Arthur: Criou as classes do dado e do roteador, inventou a função hash para cada dado, e fez um sketch inicial do main
    * Daniel: Terminou de unir tudo. Escreveu mais métodos (que estavam faltando) no grafo.hpp, e os implementou corretamente no main
