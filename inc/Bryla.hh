#ifndef BRYLA_HH
#define BRYLA_HH

#include "Wektor3D.hh"
#include "Macierz3x3.hh"
#include <fstream>
#include <vector>
#include <memory>
#include "Obiekt_Sceny.hh"
class Bryla:public Obiekt_Sceny, public std::enable_shared_from_this< Bryla >
{
 protected:
 
  std::shared_ptr<Wektor3D> wymiary;
 std::vector<Wektor3D> wierz;
 Wektor3D srodek;
 std::string nazwa;
 public:
 bool czy_kolizja(shared_ptr <Obiekt_Sceny> ob);
  double promien(){return sqrt(pow(srodek[0]-wierz[0][0],2) + pow(srodek[1]-wierz[0][1],2)+pow(srodek[2]-wierz[0][2],2));}
  Wektor3D &operator[](int index);
  Wektor3D operator[](int index)const;

 void set_srodek(Wektor3D srodek);
 void set_nazwa(std::string nazwa);
 Wektor3D get_srodek() const;
 std::string get_nazwa() const;

 void przesun(Wektor3D przes);
 void translacja(Macierz3x3 obr);

 void zapisz();

};





#endif
