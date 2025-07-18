#include <iostream>
#include "Serie.h"
using namespace std;


struct DataBase;

DataBase* nil();

bool isEmptyDB(DataBase* db);

Serie* headDB(DataBase* db);

void saveDB(Serie* s, DataBase* db);

void tailDB(DataBase* db);

int lengthDB(DataBase* db);

void initializeDB(DataBase* db);

Serie* currentDB(DataBase* db);

void setCurrentDB(Serie se, DataBase* db);

void nextDB(DataBase* db);

bool isFinishedDB(DataBase* db);

void destroyDB(DataBase* db);

void showDB (DataBase* db);

bool belongsDB(Serie* s, DataBase* db);

int amountDB(DataBase* db);
