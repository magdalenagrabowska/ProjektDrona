#ifndef POWIERZCHNIA_HH
#define POWIERZCHNIA_HH

#include "bryla.hh"
#include"Wektor3D.hh"
#include "Macierz3D.hh"
#include "Dr3D_gnuplot_api.hh"
#include "Draw3D_api_interface.hh"

//moduł na tydzień 2

class powierzchnia:public obiekt{
protected:
Wektor3D punkt[9];
public:
int powi;
powierzchnia(drawNS::APIGnuPlot3D *Api, Wektor3D &transformacja,Wektor3D *wej, MacierzOb &orientacja):obiekt(Api,transformacja,orientacja){
for(int i=0;i<9;i++){
    punkt[i]=wej[i];
}
powi=rysuj();
}
int rysuj();

};

int powierzchnia::rysuj(){
    powierzchnia pow(*this);
for(unsigned int Ind=0; Ind<9;++Ind){
    pow.punkt[Ind]=punkt[Ind];
}
powi=api->draw_surface(vector<vector<drawNS::Point3D>> {{
    pow.punkt[0].zwrocpunkt(), pow.punkt[1].zwrocpunkt(),pow.punkt[2].zwrocpunkt()
},{ pow.punkt[3].zwrocpunkt(),pow.punkt[4].zwrocpunkt(),pow.punkt[5].zwrocpunkt()
},{pow.punkt[6].zwrocpunkt(),pow.punkt[7].zwrocpunkt(),pow.punkt[8].zwrocpunkt()}}, "blue");

return powi;
}

#endif