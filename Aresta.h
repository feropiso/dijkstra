#ifndef ARESTA_H
#define ARESTA_H

class Aresta{
  
  public:
   Aresta();
   Aresta(int, int, int);
   int getV1();
   int getV2();
   int getPeso();

  private:
   int v1;
   int v2;
   int peso;
    
};

#endif //ARESTA_H
