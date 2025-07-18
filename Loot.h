#include <iostream>

using namespace std;

struct Loot;

Loot* emptyLoot();

bool isEmptyLoot(Loot* lt);

int headLoot(Loot* lt);

void saveLoot(int s, Loot* lt);

void tailLoot(Loot* lt);

int amountLoot(Loot* lt);

void initializeLoot(Loot* lt);

int currentLoot (Loot* lt);

void setCurrentLoot(int x, Loot ls);

void nextLoot(Loot* ls);

bool isFinishedLoot(Loot* lt);

void destroyLoot(Loot* lt);

void showLoot (Loot* lt);

bool belongsLoot(int n, Loot* lt); 
