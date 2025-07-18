#include "Retuner.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Loot.h"
#include "Serie.h"



using namespace std;

struct Retuner
{
    Loot* loot; // loot del retuner
};

// arma un nuevo retuner
Retuner* makeNewRetuner()
{

    Loot* newLoot = emptyLoot();
    Retuner* rt = new Retuner;

    reset(newLoot);

    rt->loot = newLoot;

    return rt;
};

// devuelve el loot del retuner
Loot* getLoot(Retuner* rt)
{
    return rt->loot;
}

// devuelve la puntuacion actual del loot del retuner.
int currentScore(Retuner* rt)
{
    Loot* lt = getLoot(rt);

    return headLoot(lt);

}

// indica so el retuner no tiene score disponibles
bool emptyRetuner(Retuner* rt)
{
  Loot* lt = getLoot(rt);

  return isFinishedLoot(lt);
}


// pasar al siguiente loot
void nextScore(Retuner* rt)
{
  Loot* newLt = getLoot(rt);

  tailLoot(newLt);

  assignNewLoot(rt, newLt);

}



// agregar una puntuacion a la serie.
void addScore(Serie* s, Retuner* rt)
{
  receiveScore(currentScore(rt), s);

  nextScore(rt);
}

// asigna un nuevo loot a un retuner
void assignNewLoot(Retuner* rt, Loot* lt)
{
  rt->loot = lt;

}


//  destruye el retuner liberando la memoria usada
void destroyRetuner(Retuner* rt)
{
    Loot* xLt = getLoot(rt);

    destroyLoot(xLt);

    delete rt;
}

// reinicia el loot del retuner.
void reset(Loot* lt )
{

const int PopulationSize = 50; // maximo  score dispónible.
const int ArraySize = 50; // cantidad de score disponibles

 int population[ PopulationSize ]; // crea un array de 20 espacios
  for ( int i=0; i < PopulationSize; i++ )
    population[ i ] = i+1; // a cada elemento del array se sumo 1.
 
   int arreglo[ ArraySize ]; // crea un array de 19 espacios
 
   srand(time(0));
 
   for(int i = 0; i < PopulationSize; i++)
   {
     int j = rand() % PopulationSize;
 
     if ( i == j )
       j = ( i + 1 ) % PopulationSize;
 
     std::swap( population[i], population[j]);
   }
 

   for ( int i = 0; i < ArraySize; ++i )
   {
     arreglo[ i ] = population[ i ];
     saveLoot(arreglo[ i ],lt);
   }

}

