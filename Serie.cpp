#include "Serie.h"
#include <iostream>

using namespace std;

struct Serie
{
    string name;
    int score;
};

// Arma una serie nueva
Serie* makeSerie(string name)
{
    Serie* newS = new Serie;

    newS->name = name;
    newS->score = 0;
    

    return newS; 
}

// devuelve el nombre de una serie
string name(Serie* s)
{
    return s->name;
}


// devuelve el puntaje total de una serie
int score(Serie* s)
{
    return s->score;
}

// muestra la serie en consola
void showSerie(Serie* s)
{
    cout << "Serie " << endl;
    cout << ".: Nombre: " << name(s) << endl;
    cout << ".: Puntaje: " << score(s) << endl;
}

// agrega un score a una serie
void receiveScore(int sc, Serie* s)
{
    s->score = s->score + sc ;
}

