#include <iostream>
#include <stdlib.h>
#include "Ranked.h"
#include "Serie.h"
#include "DataBase.h"

using namespace std;


// Estructura de los nodos del ranked
struct NodeRanked
{
    Serie* serie; // Serie en el nodo
    int priority;        // prioridad del nodo
    struct NodeRanked *next; // siguiente nodo
};

// Estructura del ranked
struct Ranked
{
    NodeRanked *forward; // nodos siguientes
    NodeRanked *back  ; // nodos anteriores
};

// armar una ranked vacia
Ranked *makeNewRanked()
{
    Ranked* newRanked = new Ranked;

    newRanked->forward = NULL;
    newRanked->back = NULL;

    return newRanked;
}

// crea un nuevo nodo
NodeRanked *makeNode( Serie* s, int pr)
{
    NodeRanked*newNode = new NodeRanked;
    newNode->serie = s;
    newNode->priority = pr;
    return newNode;
};

// agrega la serie a la ranked
void addToRanked( Ranked* rk, Serie* s, int priori )
{
     
     NodeRanked *aux = makeNode(s, priori);
     aux->next = NULL;
     
     if( rk->forward == NULL)
         rk->forward = aux;   // encola el primero elemento
     else
         (rk->back)->next = aux;

     rk->back = aux;        // puntero que siempre apunta al ultimo elemento 
}

// devuelve el primero nodo de la ranked.
NodeRanked* firstNode(Ranked* rk)
{
    return rk->forward;
}

// devuelve true si el nodo no esta vacio.
bool isNotEmptyNode(NodeRanked* node)
{
    return node != NULL;
}

// devuelve la serie del nodo
Serie* nodeElement(NodeRanked* node)
{
    return node->serie;
}

// devuelve true si son la misma series
bool sameElement ( Serie* x , Serie* y)
{
    return x == y;
}

// devuelve la prioridad de un nodo
int priority(NodeRanked* n)
{
    return n->priority;
}

// devuelve el siguiente nodo
NodeRanked* nextNode(NodeRanked* n)
{
    return n->next;
}

// dado un name de una serie devuelve su prioridad
int priorityOf(Ranked* rk , Serie* s)
{
    int aux = 0; 
    NodeRanked* current = firstNode(rk);

    while(isNotEmptyNode(current) )
    {
        if(sameElement(nodeElement(current), s ))
        {
            aux = priority(current);
        }

        current = nextNode(current);
    }

    return aux;
}

// asignar el nodos a una ranked
void assignNode (Ranked* rk, NodeRanked* n1 , NodeRanked* n2)
{
    rk->forward = n1;
    rk->back = n2;
}



// muestra la ranked en consola
void showRanked( Ranked* rk )
{
    NodeRanked *aux;
     
     aux = rk->forward;
       
     while( aux != NULL )
     {
            cout<<"    "<< name(aux->serie) << "     ->   " << aux->priority << endl;
            aux = aux->next;
     }    
}

// indica true si la ranked no esta vacio.
bool rankedNotIsEmpty(Ranked* rk)
{
    return isNotEmptyNode(firstNode(rk));
}


// dado una ranked y una serie devuelve true si tal serie esta en la ranked
bool belongs (Ranked* rk , Serie* s)
{
    bool aux = false;
    NodeRanked * current = firstNode(rk);

    while (isNotEmptyNode (current))
    {
        if (sameElement(nodeElement(current), s ))
        {
            aux = true;
        }
        
        current = nextNode(current);
    }
    
    return aux;
}


// ordena la ranked de menor a mayor
void sort( Ranked* rk )
{
     NodeRanked *aux1, *aux2;
     int p_aux;
     Serie* c_aux;
     
     aux1 = rk->forward;
     
     while( aux1->next != NULL)
     {
            aux2 = aux1->next;
            
            while( aux2 != NULL)
            {
                   if( aux1->priority >= aux2->priority )
                   {
                       p_aux = aux1->priority;
                       c_aux = aux1->serie;
                       
                       aux1->priority = aux2->priority;
                       aux1->serie   = aux2->serie;
                       
                       aux2->priority = p_aux;
                       aux2->serie   = c_aux;
                   }
                   
                   aux2 = aux2->next;
            }
            
            aux1 = aux1->next;
     }
}


// rankea una serie en la ranked
void rankear( Ranked* rk, Serie* s, int pr )
{

    if (not belongs(rk, s))
    {
     addToRanked( rk, s, pr ); 
     sort( rk ); 
    }
    else
    {
        unrankear(rk, s);
        addToRanked( rk, s, pr );
        sort( rk ); 
    }
         
}




// borra todos los nodos de una ranked
void deleteAllNode(Ranked* rk)
{
    NodeRanked* current = firstNode(rk);

    while (isNotEmptyNode(current))
    {
        delete current;
        current = nextNode(current);
    }

    assignNode(rk, NULL, NULL);
}



// dada una name de una serie lo borra de la ranked
void removeToRanked (Ranked* rk, Serie* s )
{
    Ranked * temp = makeNewRanked();

    NodeRanked* current = firstNode(rk);

    while (isNotEmptyNode (current))
    {
        if ( not sameElement(nodeElement(current), s) )
        {
            addToRanked(temp, nodeElement(current) , priorityOf(rk, nodeElement(current)));
        }
        
        current = nextNode(current);
      
    }

    deleteAllNode(rk);

    assignNode(rk, temp->forward, temp->back );

    
}

// unrakea una serie de la ranked
void unrankear(Ranked*rk, Serie* s)
{
    if (belongs(rk, s))
    {
        removeToRanked(rk , s);
        sort(rk);
    }
    
}

// devuelve el nodo con mayor prioridad.
NodeRanked* getMaxPriority(Ranked* rk)
{
    NodeRanked* current = rk->forward;
    NodeRanked* max = current;

    while (isNotEmptyNode(current))
    {
        if (current->priority > max->priority)
        {
            max = current;
        }
        
        current = nextNode(current);
    }

    return max;

}



// devuelve el/las serie/s con mayor score de la ranked. 
DataBase* getLeaders(Ranked* rk)
{
    DataBase* leaders = nil();

    NodeRanked* current = rk->forward;

    NodeRanked* max = getMaxPriority(rk);

    while (isNotEmptyNode(current))
    {
        if (current->priority == priority(max)  )
        {
            saveDB(current->serie, leaders);
        }
        
        current = nextNode(current);
    }
    
    return leaders;

}

