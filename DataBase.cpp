#include "DataBase.h"
#include "Serie.h"
#include <iostream>
using namespace std;

struct NodeDB 
{
    Serie* serie; // valor del nodo
    NodeDB* next; // puntero al siguiente nodo
};

struct DataBase 
{
    int amount; // cantidad de elementos
    NodeDB* first; // puntero al primer nodo
    NodeDB* current; // puntero al nodo actual (para recorridos)
};

// devuelve la cantidad de Serie que tiene inscriptas la datdbase
int amountDB(DataBase* db)
{
    return db->amount;
}
// Agrega un elemento al principio de la lista.
void saveDB(Serie* s ,DataBase* db)
{
    
    NodeDB* nodo = new NodeDB;
    
    nodo->serie = s;
    nodo->next = db ->first;
    db-> first = nodo;
    db->amount++; 
}

// muestra la data base en consola.
void showDB (DataBase* db)
{
    NodeDB* current = db ->first;

    cout << " {"; 
    while (current != NULL)
    {
        cout << " " << name(current->serie);
        current = current -> next;
    }
    cout << " } ";
}



// Crea una DataBase vacía
DataBase* nil()
{
    DataBase* db = new DataBase;

    db->amount = 0;
    db->first = NULL;
    db->current = NULL;

    return db;
}

 // Indica si la DataBase está vacía.
bool isEmptyDB(DataBase* db)
{
    return db-> first == NULL;
}

// Devuelve el primer elemento de la DataBase
Serie* headDB(DataBase* db)
{
    return db-> first->serie;
}


 // Quita el primer elemento de la DataBase
void tailDB(DataBase* db)
{
    NodeDB* ex = db->first;

    db -> first = db -> first -> next;

    delete ex;
}

// libera memoria utilizada por la DataBase
void destroyDB(DataBase* db)
{

    while (! isEmptyDB(db))
    {
        tailDB(db);
    }

    delete db;
}

// Devuelve la cantidad de elementos de la DataBase.
int lengthDB(DataBase* db)
{
    return db->amount;
}

 // Apunta el recorrido al primer elemento de la DataBase.
void initializeDB(DataBase* db)
{
     db->current = db->first;
    
}

// Devuelve el elemento actual en el recorrido de la DataBase.
Serie* currentDB(DataBase* db)
{
    return db ->current ->serie;
}

// Pasa al siguiente elemento de la DataBase
void nextDB(DataBase* db)
{
    db -> current = db->current->next;
}

// Indica si el recorrido ha terminado. de la DataBase.
bool isFinishedDB(DataBase* db)
{
    return db->current == NULL;
}

// Reemplaza el elemento actual por otro elemento de la DataBase.
void setCurrentDB(Serie* s, DataBase* db)
{
    db -> current ->serie = s;
}

 // Agrega un elemento al final de la lista.
void snocDB (Serie* s , DataBase* db)
{
    NodeDB* newNode = new NodeDB;

    newNode->next = NULL;
    newNode->serie = s;

    db->amount++;

    if ( db ->first == NULL)
    {
        db->first = newNode;
    }
    else
    {
        NodeDB* current = db -> first;

        while (current -> next != NULL)
        {
            current = current->next;
        }

        current ->next = newNode;
    }
    
}



// indica true si la serie existe en la database
bool belongsDB(Serie* s, DataBase* db)
{
    bool booleano = false;
    NodeDB* current = db->first;

    while (current != NULL)
    {
        if(current->serie == s)
        {
            booleano = true;
        }

        current = current->next;
    }

    return booleano;
}
