#ifndef DRON_HH
#define DRON_HH

#include "interfejs_drona.hh"
#include "pscian.hh"
#include "wirniki.hh"
#include "Macierz3D.hh"
#include "interfejs_przeszkody.hh"

class dron:public in_dron,public pscian,public przeszkoda{
public:
wirnik_lewy prawus;
wirnik_prawy lewus;
int iden=-1;
float srednica=2.5;
dron(drawNS::APIGnuPlot3D *Api, Wektor3D &transformacja,Wektor3D wej[8],Wektor3D wirusl[12],Wektor3D wirusp[12],MacierzOb &orientacja):pscian(Api,transformacja,wej,orientacja),lewus(Api,transformacja,wirusl,orientacja),prawus(Api,transformacja,wirusp,orientacja){
_Wierz_lok[0]=Wektor3D(-3,0,0);  
_Wierz_lok[1]=Wektor3D(-3,2,0);  
_Wierz_lok[2]=Wektor3D(1,2,0);     
_Wierz_lok[3]=Wektor3D(1,0,0);     
_Wierz_lok[4]=Wektor3D(-3,0,3);   
_Wierz_lok[5]=Wektor3D(-3,2,3);    
_Wierz_lok[6]=Wektor3D(1,2,3);   
_Wierz_lok[7]=Wektor3D(1,0,3);
 iden=rysuj();
 if(transformacja!=translacja){
   translacja=transformacja;
 }
} 
void wait4key();
void przesuneciedronaprzod(double a)override;
void obrotz(double kat)override;
void obrotx(double kat)override;
bool czy_kolizja(std::shared_ptr<in_dron> dronus) override;
float zwroc_srednice()override{
float a=srednica;
 return a;
}
Wektor3D zwroc_translacje()override{
  return translacja;  
}
int rysuj();
};



#endif