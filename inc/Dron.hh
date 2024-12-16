#ifndef DRON_HH
#define DRON_HH

#include "Prostopadloscian.hh"
#include "Graniastoslup6.hh"
#include "lacze_do_gnuplota.hh"
#include "Obiekt_Sceny.hh"
#include <unistd.h> // biblioteka dla usleep
#define CZAS 20000

class Dron :public Obiekt_Sceny, public std::enable_shared_from_this< Dron >
{
    double promien_;
    std::vector<Wektor3D> droga_drona;
    PzG::LaczeDoGNUPlota &Lacze;
    Prostopadloscian orginal;
    Prostopadloscian kopia;
    Graniastoslup6 org_wir[4];
    Graniastoslup6 kopia_wir[4];
    Macierz3x3 obr;
    Wektor3D droga;
    double kat;
    int id; 
public:
double promien(){return kopia.promien();}
Wektor3D get_srodek() const;
 bool czy_kolizja(shared_ptr <Obiekt_Sceny> ob);
  void usun();
  std::string get_nazwa()const{return "dron";}
  int get_id(){return id; }
  Dron(int id,PzG::LaczeDoGNUPlota &Lacze,Wektor3D pozycja);
  void unoszenie(double droga);
  void przesun(double droga);
  void obrot(double kat); // kont podajemy w stopniach
  void obrot_rotrow(); // kont podajemy w stopniach
  void zapisz();
  void sterowanie(std::list<std::shared_ptr<Obiekt_Sceny>> &Lista_elementow);
  void okresl_droge(double droga);
};

#endif
