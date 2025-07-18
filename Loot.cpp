#include "Loot.h"
#include <iostream>
using namespace std;

struct NodeLoot 
{
    int score; // valor del Node
    NodeLoot* next; // puntero al siguiente Node
};

struct Loot 
{
    int amount; // cantidad de elementos
    NodeLoot* first; // puntero al primer Node
    NodeLoot* current; // puntero al Node actual (para recorridos)


};



// Agrega un elemento al principio de la loot.
void saveLoot(int n , Loot* lt)
{
    NodeLoot* nodo = new NodeLoot;
    
    nodo->score = n;
    nodo->next = lt ->first;
    lt-> first = nodo;
    lt->amount++; 
}

// muestra el loot en consola
void showLoot (Loot* lt)
{
    NodeLoot* current = lt ->first;

    cout << " {"; 
    while (current != NULL)
    {
        cout << " " << current->score;
        current = current -> next;
    }
    cout << " } ";
}


 // Crea una Loot vacía
Loot* emptyLoot()
{

    Loot* lt = new Loot;

    lt->amount = 0;
    lt->first = NULL;
    lt->current = NULL;

    return lt;
}

// Indica si la Loot está vacía.
bool isEmptyLoot(Loot* lt)
{
    return lt-> first == NULL;
}

// Devuelve el primer score del loot.
int headLoot(Loot* lt)
{
    return lt-> first->score;
}

// Quita el primer score del loot.
void tailLoot(Loot* lt)
{
    NodeLoot* ex = lt->first;

    lt -> first = lt -> first -> next;

    delete ex;
}

// libera memoria utilizada por la loot
void destroyLoot(Loot* lt)
{

    if (not isEmptyLoot(lt))
    {
        while (! isEmptyLoot(lt))
        {
         tailLoot(lt);
         delete lt;
        }
    }
    
    
}

// Devuelve la cantidad de scores.
int amountLoot(Loot* lt)
{
    return lt->amount;
}

// Apunta el recorrido al primer loot.
void initializeLoot(Loot* lt)
{
    lt->current = lt->first;
}

// Devuelve el elemento actual en el recorrido.
int currentLoot(Loot* lt)
{
    return lt ->current ->score;
}

// Pasa al siguiente elemento.
void nextLoot(Loot* lt)
{
    lt -> current = lt->current->next;
}

 // Indica si el recorrido ha terminado.
bool isFinishedLoot(Loot* lt)
{
    return lt->current == NULL;
}

// Reemplaza el elemento actual por otro elemento.
void setCurrentLoot(int n, Loot* lt)
{
    lt -> current ->score = n;
}

// Agrega un elemento al final del loot.
void snoc (int n , Loot* lt)
{
    NodeLoot* newNode = new NodeLoot;

    newNode->next = NULL;
    newNode->score = n;

    lt->amount++;

    if ( lt ->first == NULL)
    {
        lt->first = newNode;
    }
    else
    {
        NodeLoot* current = lt -> first;

        while (current -> next != NULL)
        {
            current = current->next;
        }

        current ->next = newNode;
    }
    
}


//  devuelve el score del  nodo
int scoreInNode(NodeLoot* nodo)
{
    return nodo->score;
}

// Denota true si son el mismo elemento
bool sameScore(int x , int y)
{
    return x == y;
}


// Indica si el elemento pertenece al Loot.
bool belongsLoot(int n, Loot* lt) 
{
    bool booleano = false;
    NodeLoot* current = lt->current;

    while (current != NULL)
    {
        if ( sameScore( scoreInNode(current), n ))
        {
            booleano = true;
        }

        current = current->next;
    }

    return booleano;
}

// devuelve el primer nodo del loot
NodeLoot* firstNode(Loot* lt)
{
    return lt->first;
}

