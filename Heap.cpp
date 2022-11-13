#include <iostream>
#include "Heap.h"
using namespace std;
using std::cout;

Heap::Heap(){
  
}

Heap::Heap(vector<double*> peso, vector<int*> vertice){
  
  peso = peso;
  fp = vertice;
  n = fp.size()-1;
  
  for(int u = 0; u < fp.size()-1; u++)
    pos.push_back(new int (u+1));
}

Heap::~Heap(){

  for(int u = 0; u < pos.size(); u++)
    delete this->pos[ u ]; 

  for(int u = 0; u < peso.size(); u++)
    delete this->peso[ u ]; 

  for(int u = 0; u < fp.size(); u++)
    delete this->peso[ u ]; 
}

void Heap::refaz(int esq, int dir){
  int j = esq*2;
  int x = *fp[esq];

  while(j <= dir){
    if((j < dir)&&(*peso[*fp[j]] > *peso[*fp[j+1]]))j++;
    if(*peso[x] <= *peso[*fp[j]])break;
    fp[esq] = fp[j];
    *pos[*fp[j]] = esq;
    esq = j;
    j = esq*2;    
  }

  *fp[esq] = x;
  *pos[x] = esq;  
}

void Heap::constroi(){
  int esq = n/2 +1;
  while(esq > 1){
    esq--;
    refaz(esq, n);
  }
}

int Heap::retiraMin(){
  
  int minimo;
  
  if(n < 1) cout << "Heap vazio."<< endl;
  else{
    
    minimo = *fp[1];
    fp[1] = fp[n];
    *pos[*fp[n--]] = 1;
    refaz(1, n);
    
  }
  
  return minimo;
}

void Heap::diminuiChave(int i, double chaveNova){
  
  i = *pos[i];
  int x = *fp[i];
  
  if (chaveNova < 0) cout << "Chave inválida."<< endl;

  else{
    *peso[x] = chaveNova;
    while((i > 1) && (peso[x] <= peso[*fp[i/2]])){
      fp[i] = fp[i/2];
      *pos[*fp[i/2]] = i;
      i/=2;    
    }
    *fp[i] = x;
    *pos[x] = i;
  }  
}

bool Heap::vazio(){
  return n == 0;
}
