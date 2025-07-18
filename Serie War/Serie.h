

#include <iostream>
using namespace std;

struct Serie;


Serie* makeSerie(string name);
string name(Serie* s);
int score(Serie* s);
void showSerie(Serie* s);
void receiveScore(int score, Serie* s);