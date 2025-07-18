#include <iostream>
#include <stdlib.h>
#include "DataBase.h"
#include "Serie.h"

using namespace std;

struct Ranked;


void showRanked( Ranked *rk );
void rankear( Ranked *rk, Serie* c, int pr );
void unrankear(Ranked*rk, Serie* s);
Ranked *makeNewRanked();
DataBase* getLeaders(Ranked* rk);
Serie* getMaxScore(Ranked* rk);
bool rankedNotIsEmpty(Ranked* rk);