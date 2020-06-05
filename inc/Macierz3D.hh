#ifndef MACIERZ_HH
#define MACIERZ_HH

#include <iostream>
#include "Wektor3D.hh"
#include <string.h>
#include <math.h>
using std::cerr;
using std::endl;

template<typename STyp, int SWymiar>
class MacierzKw3D{
 protected:
  Wektor<STyp, SWymiar> Wiersz [SWymiar]; // 3 wektory skladajace sie na macierz, bedace wierszami owej macierzy
  public:
  MacierzKw3D(){ 
    for(int i=0;i<SWymiar;i++){
     for(int j=0;j<SWymiar;j++){
      Wiersz[i][j]=0; 
    }
  }
  }
  void transpozycja(); 
  void odwrotnosc(); 
  STyp wyznacznikGauss()const; 
  /*MacierzKw3D<STyp,SWymiar-1> minor(int i, int j)const;*/
  MacierzKw3D<STyp, SWymiar> operator + (const MacierzKw3D<STyp, SWymiar> & M)const;
  MacierzKw3D<STyp, SWymiar> operator - (const MacierzKw3D<STyp, SWymiar> & M)const;
  
  MacierzKw3D<STyp, SWymiar> operator * (const MacierzKw3D<STyp,SWymiar> & M)const;
  MacierzKw3D<STyp, SWymiar>  operator * (double l)const;
  Wektor<STyp, SWymiar> operator * (const Wektor<STyp,SWymiar> & W)const;

  const Wektor<STyp, SWymiar> & operator[] (unsigned int Wie) const;
  Wektor<STyp, SWymiar> & operator[] (unsigned int Wie);

  const STyp & operator() (unsigned int Wie, unsigned int Kol) const;
  STyp & operator() (unsigned int Wie,unsigned int Kol);

 Wektor<STyp, SWymiar> zwroc_kolumne(int ind)const; 
 void zmien_kolumne(Wektor<STyp,SWymiar> W, int i); 
};

/*
  *  Przeciazenie strumienia wejsciowego.Funkcja wczytuje podana wartosc od
  *  uzytkownika.
  * 
  *  Opis poszczegolnych parametrow wywolania funkcji:
  *   istream &strm  - odwolanie do sturmienia poprzez referencje,
  *   Macierz &Mac  - wartosc,ktora powinna zostac wczytana i zapisana
  *   w strukturze Macierz
  *   
  *   
  *  Warunki wstepne:
  *   strm musi byc strumieniem wejsciowym, by mozna bylo wczytac wartosci,
  *   podane watosci musza byc podane w odpowiedniej formie (tutaj za pomoca tablic)
  *
  *  Warunki koncowe:
  *   wszystko musi byc poprawnie wczytane, w przeciwnym wypadku strumien jest bledny
  *
  *  Funkcja wczytuje i zapisuje do tablic wartosci macierzy
  */
template<typename STyp, int SWymiar>
std::istream& operator>>(std::istream &strm, MacierzKw3D<STyp, SWymiar> &Mac);

/*
  *  Przeciazenie strumienia wyjsciowego.Funkcja wyswietla dla uzytkownika
  *  podana wartosc.
  * 
  *  Opis poszczegolnych parametrow wywolania funkcji:
  *   ostream &strm  - odwolanie do sturmienia poprzez referencje,
  *   const Macierz &Mac  - wartosc,ktora powinna zostac wyswietlona,
  *   bez jej zmiany, w dodatku odwolujac sie do oryginalu
  *   
  *  Warunki wstepne:
  *   strm musi byc strumieniem wyjsciowym, by mozna bylo wyswietlic wartosci,
  *   watosci musza byc podane w odpowiedniej formie (tutaj za pomoca tablicy)
  *
  *  Warunki koncowe:
  *   brak
  *
  *  Funkcja wyswietla na wyjsciu standardowym wartosci macierzy.
  */
template<typename STyp, int SWymiar>
std::ostream& operator<<(std::ostream &strm, const MacierzKw3D<STyp, SWymiar> &Mac);

class MacierzOb:public MacierzKw3D<double,3>{
     
    public:
    MacierzOb(const MacierzKw3D<double,3>&M):MacierzKw3D<double,3>(M){ 
    if(abs(wyznacznikGauss()-1)>0.001){
       cerr<<"to nie jest macierz obrotowa"<<endl;
      }

 }
   MacierzOb(){
     if(abs(wyznacznikGauss()-1)>0.001){
       cerr<<"to nie jest macierz obrotowa"<<endl;
      }
      Wiersz[0][0]=1;
      Wiersz[0][1]=0;
      Wiersz[1][0]=0;
      Wiersz[1][1]=1;
      Wiersz[2][2]=1;
}
 
void macobrz(double KatOstr){
   double radian=(KatOstr*3.1419592)/180;
      Wiersz[0][0]=cos(radian);
      Wiersz[0][1]=-sin(radian);
      Wiersz[1][0]=sin(radian);
      Wiersz[1][1]=cos(radian);
      Wiersz[2][2]=1;
}
void macobrx(double KatOstr){
   double radian=(KatOstr*3.1419592)/180;
      Wiersz[1][1]=cos(radian);
      Wiersz[2][1]=sin(radian);
      Wiersz[1][2]=-sin(radian);
      Wiersz[2][2]=cos(radian);
      Wiersz[0][0]=1; 
}
};
#endif
