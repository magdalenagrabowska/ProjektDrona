#ifndef INTERFEJS_PRZESZKODY_HH
#define INTERFEJS_PRZESZKODY_HH


#include <math.h>
#include<vector>
#include "interfejs_drona.hh"
#include "Macierz3D.hh"
#include "Wektor3D.hh"
#include "pscian.hh"
#include "Dr3D_gnuplot_api.hh"
#include "Draw3D_api_interface.hh"


class przeszkoda{
public:
virtual bool czy_kolizja(std::shared_ptr<in_dron> dronus)=0;
};

class przeszkodapscian:public przeszkoda,public pscian{
public:
przeszkodapscian(drawNS::APIGnuPlot3D *Api, Wektor3D &transformacja,Wektor3D wej[8], MacierzOb &orientacja):pscian(Api,transformacja,wej,orientacja){
_Wierz_lok[0]=Wektor3D(-10,-11,0);
_Wierz_lok[1]=Wektor3D(-10,-2,0);
_Wierz_lok[2]=Wektor3D(-8,-2,0);
_Wierz_lok[3]=Wektor3D(-8,-11,0);
_Wierz_lok[4]=Wektor3D(-10,-11,5);
_Wierz_lok[5]=Wektor3D(-10,-2,5);
_Wierz_lok[6]=Wektor3D(-8,-2,5);
_Wierz_lok[7]=Wektor3D(-8,-11,5);  
 int var1=rysuj();
 api->change_shape_color(var1,"black");
 if(transformacja!=translacja){
     translacja=transformacja;  
 }

}
int przesz=-1;
bool czy_kolizja(std::shared_ptr<in_dron> dronus) override{
float r=dronus->zwroc_srednice();
int licz=0;
Wektor3D sr=dronus->zwroc_translacje();
Wektor3D najmn_tmp=_Wierz_lok[0]+translacja;
Wektor3D najw_tmp=_Wierz_lok[6]+translacja;

for(int i=0;i<3;i++){
if(sr[i]>najmn_tmp[i]-2*r && sr[i]<najw_tmp[i]+2*r){
licz++;
}
else;
}
if(licz==3)return false;
else return true;
}
};

#endif