#ifndef SCENA_HH
#define SCENA_HH
#include <iostream>
#include <iomanip>
#include <memory>
#include <fstream>
#include <list>
#include "Plaskowyz.hh"
#include "Gran.hh"
#include "Gora.hh"
#include "Graniastoslup6.hh"
#include "lacze_do_gnuplota.hh"
#include "Dron.hh"
#include "Plaszczyzna.hh"
#include "Obiekt_Sceny.hh"

#define N 2

class Scena
{
    std::list<std::shared_ptr<Obiekt_Sceny>> Lista_elementow;
    PzG::LaczeDoGNUPlota Lacze;
    std::list<std::shared_ptr<Dron>> Lista_Dronow; /// element fazy3
    int nr_elem;
    int nr_drona;
    Plaszczyzna *dno;

public:
    Scena();
    void rysuj();
    bool interfejs();
    ~Scena();
};

#endif
