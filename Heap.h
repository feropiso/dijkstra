#ifndef HEAP_H
#define HEAP_H
#include <vector>
using std::vector;

class Heap{
  
  public:
    Heap();
    Heap(vector<double*>, vector<int*>);
    ~Heap();
    void refaz(int, int);
    void constroi();
    int retiraMin();
    void diminuiChave(int, double);
    bool vazio();

  private:
    int n;
    vector<double*> peso;
    vector<int*> pos;
    vector<int*> fp;   

};


#endif //HEAP_H
