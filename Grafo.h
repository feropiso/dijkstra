#ifndef GRAFO_H
#define GRAFO_H
#include "Aresta.h"

class Grafo{
  
  public:
    Grafo();
    ~Grafo();
    int numVertices();
    bool listaAdjVazia(int);
    Aresta primeiroListaAdj(int);
    Aresta proxAdj(int);
   

  private:
  Aresta aresta;   

};

#endif //GRAFO_H
