
#include "Serie.h"
#include "DataBase.h"
#include "Ranked.h"
#include "Retuner.h"
#include "Loot.h"
#include "iostream"

using namespace std;

struct League;

League* makeNewLeague();
void rankearLeague(Serie* s , League* l);
void registerSerie(League* l , Serie* s);
void playLeague(League* l);
void playOff(League*l);
Ranked* getRanked(League* l);
Retuner* getRetuner(League* l);
DataBase* inscribedSeries (League* l);
bool leagueEmpty(League* l);
