#include"item.h"

typedef struct node *list;

list newList(void); //inizializza una lista

int empyList(list l);//verifica che la lista sia vuota o meno

list tailList(list l);//scorre la lista al nodo successivo

list consList(item val,list l);//scorre la lista e aggiunge un elemento

item getFirst(list l);//restituisce l'elemento in testa alla lista

list inputList(int n);//prende la taglia della lista e ne crea una ordinata(reversata)
void outputList(list l);//stampa la lista

list reverseList(list l);//reversa la lista

int posItem(list l,item val);//restituisce la posizione dell'elemento val

int sizeList(list l);//restituisce la size della lista

list insertList(list l,int pos,item val);//senza interferenze ma rimane elementi non accessibili

list insertList(list l,int pos,item val);//ottimizzata ma con intereferenza warning negli assegnamenti fra liste
