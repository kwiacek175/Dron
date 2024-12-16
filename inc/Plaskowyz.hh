#ifndef PLASKOWYZ_HH
#define PLASKOWYZ_HH

#include "Bryla.hh"

class Plaskowyz : public Bryla
{

public:

Plaskowyz(Wektor3D srodek=Wektor3D(), double x=50,double y=50, double z=50,std::string nazwa="dat/Plaskowyz.dat");
Plaskowyz( Plaskowyz& pr );
 
};







#endif 