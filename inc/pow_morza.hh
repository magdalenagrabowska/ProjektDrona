#ifndef POWIERZCHNIA_MORZA_HH
#define POWIERZCHNIA_MORZA_HH

#include"pow.hh"
#include"Wektor3D.hh"
#include "Macierz3D.hh"
#include "Dr3D_gnuplot_api.hh"
#include "Draw3D_api_interface.hh"
#include "interfejs_przeszkody.hh"
#include "interfejs_drona.hh"

//moduł na tydzień 2


class pow_dna:public powierzchnia,public przeszkoda{
uint denko;
public:
pow_dna(drawNS::APIGnuPlot3D *Api, Wektor3D &transformacja,Wektor3D wej[4], MacierzOb &orientacja):powierzchnia(Api,translacja,wej,orientacja){
    punkt[0]=Wektor3D(-19,-19,-19);
    punkt[1]=Wektor3D(-19,0,-19);
    punkt[2]=Wektor3D(-19,19,-19);
    punkt[3]=Wektor3D(0,-19,-19);
    punkt[4]=Wektor3D(0,0,-19);
    punkt[5]=Wektor3D(0,19,-19);
    punkt[6]=Wektor3D(19,-19,-19);
    punkt[7]=Wektor3D(19,0,-19);
    punkt[8]=Wektor3D(19,19,-19);
    wej=punkt;
    denko=rysuj();
}
bool czy_kolizja(std::shared_ptr<in_dron> dronus)override{
float r=dronus->zwroc_srednice();
Wektor3D wek=dronus->zwroc_translacje();
if(wek[2]<(-19+r))
return false;
else return true;
}
};


class pow_morza:public powierzchnia,public przeszkoda{
int powierz;
public:
pow_morza(drawNS::APIGnuPlot3D *Api, Wektor3D &transformacja,Wektor3D wej[4], MacierzOb &orientacja):powierzchnia(Api,translacja,wej,orientacja){
    punkt[0]=Wektor3D(-19,-19,16);
    punkt[1]=Wektor3D(-19,0,16);
    punkt[2]=Wektor3D(-19,19,16);
    punkt[3]=Wektor3D(0,-19,16);
    punkt[4]=Wektor3D(0,0,16);
    punkt[5]=Wektor3D(0,19,16);
    punkt[6]=Wektor3D(19,-19,16);
    punkt[7]=Wektor3D(19,0,16);
    punkt[8]=Wektor3D(19,19,16);
    wej=punkt;
    powierz=rysuj();
}
bool czy_kolizja(std::shared_ptr<in_dron> dronus)override{
Wektor3D wek=dronus->zwroc_translacje();
float r=dronus->zwroc_srednice();
if(wek[2]>16-(r/2))
return false;
else return true; 
}
};

#endif