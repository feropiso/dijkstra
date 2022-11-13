#ifndef DIJKSTRA_H
#define DIJKSTRA_H
#include "Grafo.h"
#include <vector>
using std::vector;

class Dijkstra{
  
  public:
    Dijkstra();
    Dijkstra(Grafo);
    ~Dijkstra();
    void obterArvoreCMC(int);
    int antecessor(int);
    double peso(int);
    void imprimeCaminho(int, int);

  private:
    Grafo grafo;
    vector<double*> peso_vertice;
    vector<int*> antecessores;
    
};

#endif //DIJKSTRA_H
