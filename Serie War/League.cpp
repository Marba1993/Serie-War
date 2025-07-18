#include "League.h"
#include "Serie.h"
#include "DataBase.h"
#include "Ranked.h"
#include "Retuner.h"
#include "Loot.h"
#include <iostream>


using namespace std;

// g++ -o app league.cpp serie.cpp ranked.cpp retuner.cpp loot.cpp database.cpp

struct League
{
    int quantity; // cantidad de series
    DataBase* series; // fila de peliculas inscriptas en la league
    Ranked* rank; //  ranked 
    Retuner* retuner; //retuner
};

// arma nuevo league
League* makeNewLeague()
{
    League* newL = new League;

    newL->quantity = 0;
    newL->series = nil();
    newL->rank = makeNewRanked();
    newL->retuner = makeNewRetuner();

    return newL;
}


// Devuelve las series inscriptas en la league
DataBase* inscribedSeries (League* l)
{
    return l->series;
}

// devuelve true si la league no tiene serie inscriptas
bool leagueEmpty(League* l)
{
    return isEmptyDB(inscribedSeries(l));
}

// devuelve la ranked de la league
Ranked* getRanked(League* l)
{
    return l->rank;
}

// devuelve el retuner de la league.
Retuner* getRetuner(League* l)
{
    return l->retuner;
}


// rankea una serie en la league
void rankearLeague(Serie* s , League* l)
{
    Ranked* rk = getRanked(l);
    Retuner* rt = getRetuner(l);

   
    addScore(s, rt);
    rankear(rk,s, score(s));
}


// registra una nueva serie en la league,
void registerSerie(League* l , Serie* s)
{

    DataBase* db = inscribedSeries(l);

    saveDB(s,db);

    Ranked* rk = getRanked(l);

    rankear(rk, s , 0);

    l->quantity = l->quantity +1;

    
}


// reproduce una partida de la league
void playLeague(League* l)
{
    DataBase* db = inscribedSeries(l);
    initializeDB(db);
    

    while (! isFinishedDB(db))
    {
        rankearLeague(currentDB (db),l);
        nextDB(db);
        
    }
    
} 

// juega una nueva ronda entre los lideres de la league
void playOff(League*l)
{
    Ranked* rk = getRanked(l);
    DataBase* db = getLeaders(rk);
    initializeDB(db);

    while (! isFinishedDB(db))
    {
        rankearLeague(currentDB(db), l);
        nextDB(db);
    }
    
}


