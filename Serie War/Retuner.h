#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Loot.h"
#include "Serie.h"


struct Retuner;

Retuner* makeNewRetuner();
void addScore(Serie* s, Retuner* rt);
void reset(Loot* lt );
void assignNewLoot(Retuner* rt, Loot* lt);
Loot* getLoot(Retuner* rt);