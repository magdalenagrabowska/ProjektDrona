#ifndef PROSTOPADLOSCIAN_HH
#define PROSTOPADLOSCIAN_HH

#include <vector>
#include "bryla.hh"
#include "Wektor3D.hh"
#include "Macierz3D.hh"
#include <fstream>
#include "Dr3D_gnuplot_api.hh"
#include "Draw3D_api_interface.hh"


class pscian:public bryla{
  protected:
  Wektor3D _Wierz_lok[8];
  Wektor3D _Wierz_glob[8];
  int id=-1;
  public:
  pscian(drawNS::APIGnuPlot3D *Api, Wektor3D &transformacja,Wektor3D wej[8], MacierzOb &orientacja):bryla(Api,transformacja,orientacja){
   for(int i=0;i<8;i++){
     _Wierz_lok[i]=wej[i];
   }  
  }
  int rysuj()override;
};
#endif