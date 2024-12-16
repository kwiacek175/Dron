#ifndef GORA_HH
#define GORA_HH

#include "Bryla.hh"

class Gora : public Bryla
{

public:
  double promien(){return (*wymiary)[2];}
Gora(Wektor3D srodek=Wektor3D(), double x=50,double y=50, double z=50,std::string nazwa="dat/Gora.dat");
Gora( Gora& pr );

};







#endif 