#ifndef WIRNIKI_HH
#define WIRNIKI_HH

#include "pscian6.hh"
#include"Wektor3D.hh"
#include "Macierz3D.hh"

//modul na tydzien 2

class wirnik:public pscian6{
protected:

public:
wirnik(drawNS::APIGnuPlot3D *Api, Wektor3D &transformacja,Wektor3D wej[12], MacierzOb &orientacja):pscian6(Api,transformacja,wej,orientacja){
}
void ciaglyobr(){
    zmienkatz(45);
    /*api->erase_shape(wir);
    wir=rysuj();*/
}
};
class wirnik_lewy:public wirnik{
public:
Wektor3D przesunl=Wektor3D(-3,1,0);
int wirl=-1;
wirnik_lewy(drawNS::APIGnuPlot3D *Api, Wektor3D &transformacja,Wektor3D wej[12], MacierzOb &orientacja):wirnik(Api,transformacja,wej,orientacja){
   wierzchy[0]=Wektor3D(-3,0,1.5);
   wierzchy[1]=Wektor3D(-2.5,0,2) ;
   wierzchy[2]=Wektor3D(-1.5,0,2);
   wierzchy[3]=Wektor3D(-1,0,1.5) ;
   wierzchy[4]=Wektor3D(-1.5,0,1);
   wierzchy[5]=Wektor3D(-2.5,0,1) ;
   wierzchy[6]=Wektor3D(-3,-2,1.5);
   wierzchy[7]=Wektor3D(-2.5,-2,2) ;
   wierzchy[8]=Wektor3D(-1.5,-2,2);
   wierzchy[9]=Wektor3D(-1,-2,1.5) ;
   wierzchy[10]=Wektor3D(-1.5,-2,1);
   wierzchy[11]=Wektor3D(-2.5,-2,1) ;
}
};

class wirnik_prawy:public wirnik{
Wektor3D przesunpr=Wektor3D(-3,-1,0);
int wirpr=-1;
public:
wirnik_prawy(drawNS::APIGnuPlot3D *Api, Wektor3D &transformacja,Wektor3D wej[12], MacierzOb &orientacja):wirnik(Api,transformacja,wej,orientacja){
  
   wierzchy[0]=Wektor3D(-1,0,1.5);
   wierzchy[1]=Wektor3D(-0.5,0,2) ;
   wierzchy[2]=Wektor3D(0.5,0,2);
   wierzchy[3]=Wektor3D(1,0,1.5) ;
   wierzchy[4]=Wektor3D(0.5,0,1);
   wierzchy[5]=Wektor3D(-0.5,0,1) ;
   wierzchy[6]=Wektor3D(-1,-2,1.5);
   wierzchy[7]=Wektor3D(-0.5,-2,2) ;
   wierzchy[8]=Wektor3D(0.5,-2,2);
   wierzchy[9]=Wektor3D(1,-2,1.5) ;
   wierzchy[10]=Wektor3D(0.5,-2,1);
   wierzchy[11]=Wektor3D(-0.5,-2,1) ;
}
};




#endif