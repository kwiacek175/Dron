#ifndef OBIEKT_SCENY_HH
#define OBIEKT_SCENY_HH
#include  <string>
#include <memory>


class Obiekt_Sceny
{

public:

virtual bool czy_kolizja(shared_ptr <Obiekt_Sceny> ob)=0;
virtual std::string get_nazwa() const=0;
virtual void zapisz()=0;
virtual Wektor3D get_srodek() const=0;
virtual double promien()=0;
};





#endif
