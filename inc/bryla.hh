#ifndef BRYLA_HH
#define BRYLA_HH

#include "Wektor3D.hh"
#include "Macierz3D.hh"
#include "Dr3D_gnuplot_api.hh"
#include "Draw3D_api_interface.hh"


using drawNS::Point3D;
using drawNS::APIGnuPlot3D;

class obiekt{
protected:
MacierzOb orientacja;
Wektor3D translacja;
std::shared_ptr<drawNS::Draw3DAPI> api;
public:
static int ile_jest_o;
static int ile_utworzono_o;
obiekt(drawNS::Draw3DAPI *Api, Wektor3D trans, MacierzOb ori): api(Api), translacja(trans), orientacja(ori){
   ++ile_jest_o;
    ++ile_utworzono_o;
}

obiekt(const obiekt &b){
    ++ile_jest_o;
    ++ile_utworzono_o;
}

static int zwroc_istniejace(){
  return ile_jest_o;
}
static int zwroc_utworzone(){
  return ile_utworzono_o;
}

~obiekt(){
ile_jest_o--;
}
};

class bryla:public obiekt{
protected:
int id=-1;
public:
bryla(drawNS::Draw3DAPI *Api, Wektor3D trans, MacierzOb ori):obiekt(Api,trans,ori){
   
}
virtual int rysuj()=0;

void zmienp(const Wektor3D &M){
    Wektor3D tmp=orientacja*M;
     translacja=translacja+tmp;
}
void zmienkatx(double KatOstr){
    MacierzOb obrot;
    obrot.macobrx(KatOstr);
    orientacja=orientacja*obrot;
}
void zmienkatz(double KatOstr){
    MacierzOb obrot; 
    obrot.macobrz(KatOstr);
    orientacja=orientacja*obrot;
}
};

#endif