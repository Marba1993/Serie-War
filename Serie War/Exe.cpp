#include "Exe.h"
#include "League.h"
#include "Ranked.h"
#include "Retuner.h"
#include "Serie.h"
#include "Loot.h"
#include "DataBase.h"
#include <iostream>
using namespace std;

struct Exe
{
    League* league; // league del exe

};

// g++ -o app exe.cpp league.cpp ranked.cpp retuner.cpp serie.cpp loot.cpp database.cpp

// arma nueva exe.
Exe* makeNewExe()
{
    Exe* newExe = new Exe;

    newExe->league = makeNewLeague();

    return newExe;
}

// devuelve la league del exe
League* getLeague(Exe* e)
{
    return e->league;
}

// registra un serie en el exe
void registerSeriesInExe(string s , Exe* e)
{
    Serie* newSerie = makeSerie(s);
    League* lg = getLeague(e);

    registerSerie(lg , newSerie);

}

// Auto registra la series en la exe.
void autoRegister(Exe* e)
{
    registerSeriesInExe("BreakingBad", e);
    registerSeriesInExe("Dark", e);
    registerSeriesInExe("MrRobot", e);
    registerSeriesInExe("BlackMirror", e);
    registerSeriesInExe("Vikings", e);
    registerSeriesInExe("Dahmer", e);
    registerSeriesInExe("BetterCallSaul", e);
    registerSeriesInExe("BlackSummer", e);
    registerSeriesInExe("Halo", e);
    registerSeriesInExe("GameOfThrones", e);
    registerSeriesInExe("Yu-Gi-Oh", e);

}

// muestra las series inscriptas en la league de la exe.
DataBase* showRegisteredSeries(Exe* e)
{
    League* lg = getLeague(e);

    return inscribedSeries(lg);
}


// indica true si la league de la exe no esta vacia.
bool leagueInExeNotEmpty(Exe* e )
{
    League* lg = getLeague(e);

    return not leagueEmpty(lg);

}

// muestra en consola las series incriptas en la league del exe
void showSeriesIncribed(Exe* e)
{
    League* lg = getLeague(e);

    showDB(inscribedSeries(lg));
}

// reproduce un ronda en la league.
void playLeagueInExe(Exe* e)
{
    League* lg = getLeague(e);

    playLeague(lg);

}

// devuelve true si la ranked tiene series inscriptas
bool rankedNotEmptyInLeague(Exe* e)
{
    League* lg = getLeague(e);
    Ranked* rk = getRanked(lg);

    return rankedNotIsEmpty(rk);
    
    
}

// muestra en consola la ranked de la exe
void showRankedInLeague(Exe* e)
{
    League* lg = getLeague(e);
    Ranked* rk = getRanked(lg);

    showRanked(rk);
}


// indica true si hay un playOff en la Ranked de la league
bool havePlayOff(Exe* e)
{
    League* lg = getLeague(e);
    Ranked* rk = getRanked(lg);

    return amountDB(getLeaders(rk)) > 1;
}

// realiza un desempate entre los lideres de la league
void playOffInRanked(Exe* e)
{
    League* lg = getLeague(e);

    playOff(lg);
}

/*                        Menu de opciones     
------------------------------------------------------------------------*/
void menu()
{
    cout<<"\n\t .: SerieWar  :. \n\n";

    cout<<"  [ 1 ] .: Iniciar SerieWar :.                          "<<endl;
    cout<<"  [ 2 ] .: Mostrar series inscriptas :.                          "<<endl;
    cout<<"  [ 3 ] .: Play league :.                          "<<endl;
    cout<<"  [ 4 ] .: Mostrar ranked :.                         "<<endl;
    cout<<"  [ 5 ] .: PlayOff :.                         "<<endl;
    cout<<"  [ 6 ] .: Salir :.                            "<<endl;

    cout<<"\n Ingrese Opcion: ";
}


/*                        Funcion Principal        
------------------------------------------------------------------------*/

int main()
{
    League* l = makeNewLeague();
    Ranked* rk = getRanked(l);

    Exe* newExe = makeNewExe();

    string s ; // serie a agregar
    int pr; //  prioridad del caracter
    int op; // opcion del menu
    int x; // numero que devuelve la funcon pop

    do
    {
        menu();  cin>> op;

        switch(op)
        {
            case 1:

                 autoRegister(newExe);
                 
                 cout<<"\n\n\t\t Serie War Iniciada...\n\n";
            break; 
                  
            case 2:

                 cout << "\n\n Mostrando Series inscriptas \n\n";
                 
                 if(leagueInExeNotEmpty(newExe))
                 {
                     showSeriesIncribed(newExe);
                 }
                     
                 else
                 {
                     cout<<"\n\n\t La league no tiene series inscriptas actualmente ...!"<<endl;
                 }   
            break;

            case 3:
                if (leagueInExeNotEmpty(newExe))
                {
                    playLeagueInExe(newExe);
                    cout << "\n\n League Rankeado...";
                }
                else
                {
                    cout<<"\n\n\t La league no tiene series inscriptas actualmente ...!"<<endl;
                }
                break;

            case 4:
                if (rankedNotEmptyInLeague(newExe))
                {
                    showRankedInLeague(newExe);
                }
                else
                {
                     cout<<"\n\n\t La Ranked no tiene actualmente ningun Serie Rankeado ...!"<<endl;
                }
                break;

            case 5: 
                if (havePlayOff(newExe))
                {
                    cout<<"\n\n\t Actualizando Ranked luego del Playoff entre los lideres"<<endl;

                    playOffInRanked(newExe);
                    showRankedInLeague(newExe);
                }
                else
                {
                    cout<<"\n\n\t No es necesario hacer un playOff por que hay un solo lider ...!"<<endl;
                }
                break;
            case 6:
                system("pause");  system("cls");
                break;

                
                

            default:
                    cout<<"\n\tOpcion incorecta..!"<<endl;
                    system("pause");
                    exit(0);
         }

        cout<<endl<<endl;
        system("pause");  system("cls");

    }while(op!=6);
    
    return 0;
    




}
