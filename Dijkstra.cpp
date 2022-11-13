#include <iostream>
#include "Heap.h"
#include "Dijkstra.h"
#include "Aresta.h"
#include <limits>
using namespace std;
using std::cout;

Dijkstra::Dijkstra(){}

Dijkstra::Dijkstra(Grafo grafo){
  grafo = grafo;
}

Dijkstra::~Dijkstra(){
  for(int u = 0; u < antecessores.size(); u++)
    delete this->antecessores[ u ]; 
}

void Dijkstra::obterArvoreCMC(int raiz){
  
  int n = grafo.numVertices();
  vector<int*> vs;
  
  for(int u = 0; u < n; u++){
    antecessores.push_back(new int (-1));

    peso_vertice.push_back(new double (numeric_limits<double>::max()));

    vs.push_back(new int (u));
  }

  peso_vertice[raiz] = 0;

  Heap heap(peso_vertice, vs);
  heap.constroi();

  while(!heap.vazio()){
    int u = heap.retiraMin();
    if(!grafo.listaAdjVazia(u)){
      Aresta adj = grafo.primeiroListaAdj(u);
      while (adj != 0){
        int v = adj.getV2();
        if(peso_vertice[v] > (peso_vertice[u] + adj.getPeso())){
          *antecessores[v] = u;
          heap.diminuiChave(v, *peso_vertice[u] + adj.getPeso());          
        }
        adj = grafo.proxAdj(u);       
      }
    }
  }
}

int Dijkstra::antecessor(int u){
  return *antecessores[u];
}

double Dijkstra::peso(int u){
  return *peso_vertice[u];
}

void Dijkstra::imprimeCaminho(int origem, int v){
  if (origem == v) cout <<origem<< endl;
  else if (*antecessores[v] == -1)
    cout << "Não existe caminho de "<<origem<< " até "<<v<< endl;
  else{
    imprimeCaminho(origem, *antecessores[v]);
    cout <<v<< endl;
  }
}
