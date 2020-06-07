#include "dron.hh"
#include<vector>
#include "Dr3D_gnuplot_api.hh"
#include<cmath>
#include <chrono>
#include <thread>

using drawNS::Point3D;
using drawNS::APIGnuPlot3D;
using std::cout;
using std::endl;
using std::cerr;

//modyfikacja modułu na tydzień 2


/*!
   * \brief funkcja wait4key jest poleceniem dla gnuplota, żeby poczekał na wskazany przycisk wpisany
   * z klawiatury przez użytkownika, w tym wypadku jest to klawisz "w", po nim przechodzi do następnej akcji
   */ 


void dron::wait4key(){
  do {
    std::cout << "\n Press w to continue..." << std::endl;
  } while(std::cin.get() != 'w');
}


/*!
   * \brief medota klasy dron. Przesuwa drona w przód albo w tyl, czyli z założeń wzdłuż osi Y o zadaną wartość.
   * Wartość ujemna zakłada że dron przesuwa się w tył.
   */ 


void dron::przesuneciedronaprzod(double a){
  Wektor3D move;
  /*for(int i=0;i<abs(a);i++){*/
  if(a>0)move[1]=1;
  else move[1]=-1;
  zmienp(move);
  iden=rysuj();
 lewus.zmienp(move);
  prawus.zmienp(move);
  lewus.rysuj();
  prawus.rysuj();
  /*lewus.ciaglyobr();
  prawus.ciaglyobr();*/
  this_thread::sleep_for(chrono::milliseconds(10));
  /*}*/
}


bool dron::czy_kolizja(std::shared_ptr<in_dron> dronus){
Wektor3D sr=dronus->zwroc_translacje();
Wektor3D wsk=zwroc_translacje();
if(wsk==sr){
  return true;
} 
float r=dronus->zwroc_srednice();
int licz=0;
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


/*!
   * \brief medota klasy dron. Z zalozenia obraca dronem o zadany kat
   */
void dron::obrotz(double kat){
  for(int i=1;i<=kat;i++)
  {
  zmienkatz(1);
  lewus.zmienkatz(1);
  prawus.zmienkatz(1);
  iden=rysuj();
  lewus.rysuj();
  prawus.rysuj();
  /*lewus.ciaglyobr();
  prawus.ciaglyobr();*/
  this_thread::sleep_for(chrono::milliseconds(10));
  }
}

void dron::obrotx(double kat){
  for(int i=1;i<=kat;i++)
  {
  zmienkatx(1);
  lewus.zmienkatx(1);
  prawus.zmienkatx(1);
  iden=rysuj();
  lewus.rysuj();
  prawus.rysuj();
  /*lewus.ciaglyobr();
  prawus.ciaglyobr();*/
  this_thread::sleep_for(chrono::milliseconds(10));
  }
}
int dron::rysuj(){
  int p=pscian::rysuj();
 int w=lewus.rysuj();
 int wi=prawus.rysuj();
  iden=p+w+wi;
  return iden;
}
