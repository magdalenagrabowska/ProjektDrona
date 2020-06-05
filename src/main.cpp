#include"pow_morza.hh"
#include "dron.hh"
#include <iostream>
#include <vector>
#include <fstream>
#include "Dr3D_gnuplot_api.hh"
#include "Wektor3D.hh"
#include<fstream>
#include "interfejs_przeszkody.hh"
#include <math.h>
#include "Wektor3D.hh"

using std::cout;
using std::endl;
using std::cin;
using std::cerr;
using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;

//modyfikacja modułu na tydzień 2

int Wektor3D::ile_jest_w;
int Wektor3D::ile_powstalo_w;
int bryla::ile_jest_o;
int bryla::ile_utworzono_o;

void pokazwektory(){
  cout<<"powstalo wektorow "<<Wektor3D::zwroc_utworzone<<endl;
  cout<<"jest wektorow "<<Wektor3D::zwroc_istniejace<<endl;
}


int main(){
  drawNS::APIGnuPlot3D *api=new drawNS::APIGnuPlot3D(-20,20,-20,20,-20,20,0);
  Wektor3D translacja;
  MacierzOb ori;
  Wektor3D pow[4];
  Wektor3D wej[8];
  Wektor3D wirnikl[12];
  Wektor3D trans=Wektor3D(10,11,-5); 
  Wektor3D tran=Wektor3D(10,15,-10);
  Wektor3D tansik=Wektor3D(-9,-5,12);
 vector<std::shared_ptr<przeszkodapscian>> kolekcja_przeszkod{
    std::make_shared<przeszkodapscian>(api,translacja,wej,ori), 
    std::make_shared<przeszkodapscian>(api,tran,wej,ori),
    std::make_shared<przeszkodapscian>(api,tansik,wej,ori)
  };
  vector<std::shared_ptr<in_dron>> kolekcja_Dronow;
    std::shared_ptr<dron> dronik1=std::make_shared<dron>(api,translacja,wej,wirnikl,wirnikl,ori);
    kolekcja_Dronow.push_back(dronik1);
    std:shared_ptr<dron> dronik2=std::make_shared<dron>(api,trans,wej,wirnikl,wirnikl,ori);
    kolekcja_Dronow.push_back(dronik2);
  pow_dna dno(api,translacja,pow,ori);
  pow_morza powi(api,translacja,pow,ori);
  double a=0;
  int nr=0;
  cout<<"powstalo obiektow "<<bryla::zwroc_utworzone<<endl;
  cout<<"jest obiektow"<<bryla::zwroc_istniejace<<endl;
  char wybor[2] = " ";
  cout<<"Menu"<<endl;
  cout<<"podaj numer drona. Dostępny jest 0 albo 1"<<endl;
  cin>>nr;
  if(nr<0 || nr>1)
  cin.fail();
  if(cin.fail()){
       cout<<"Blad.Nie ma takiego drona"<<endl;
       cin.clear();
       cin.ignore(1000, '\n');
  }
  while (wybor[0]!='0'){
  cout<<"Menu"<<endl;
  cout<<"1-zmien drona"<<endl;
  cout<<"2-przemieść drona w przod"<<endl;
  cout<<"3-przemiesc drona w górę o kat"<<endl;
  cout<<"4-obrot drona"<<endl;
  cout<<"0-koniec programu"<<endl;

  cout<<"Twoj wybor"<<endl;

  cin>>wybor;

  switch(wybor[0]){
   case '1':{
     pokazwektory();
     cout<<"nastąpi zmiana dronow do kierowania"<<endl;
     if(nr==0)
     nr=1;
     else nr=0;
     if(cin.fail()){
       cout<<"Blad. Program wroci sie do menu"<<endl;
       cin.clear();
       cin.ignore(1000, '\n');
    } 
    break;
  }
  case '2':{
    pokazwektory();
    cout<<"podaj o ile chcesz przemieścić w przod.Uwaga:podanie dodatniej wartosci spowoduje przesuniecie w tyl, a ujemnej w przod"<<endl;
    cin>>a;
    if(cin.fail()){
       cout<<"Blad. Program wroci sie do menu"<<endl;
       cin.clear();
       cin.ignore(1000, '\n');
    } 
    for(int i=0;i<abs(a);i++){
    if(a>0)
    kolekcja_Dronow[nr]->przesuneciedronaprzod(1);
    else kolekcja_Dronow[nr]->przesuneciedronaprzod(-1);
    for(int j=0;j<kolekcja_przeszkod.size();++j){
    bool podroz=kolekcja_przeszkod[j]->czy_kolizja(kolekcja_Dronow[nr]);
    if(podroz==false)
    {
      cerr<<"kolizja drona"<<endl;
      exit(1);
    }
    }
    }
    break;
  }
  
  case '3':{cout<<"podaj kat, pod jakim dron ma plynac w gore"<<endl; 
    int kat=0;
    cin>>kat;
    pokazwektory();
     if(cin.fail()){
       cout<<"Blad. Program wroci sie do menu"<<endl;
       cin.clear();
       cin.ignore(1000, '\n');
    } 
    kolekcja_Dronow[nr]->obrotx(kat);
    cout<<"podaj o ile chcesz przemieścić w gore.Uwaga:podanie dodatniej wartosci spowoduje przesuniecie w gore, a ujemnej w dol"<<endl;
    cin>>a;
    if(cin.fail()){
       cout<<"Blad. Program wroci sie do menu"<<endl;
       cin.clear();
       cin.ignore(1000, '\n');
    } 
    for(int i=0;i<abs(a);i++){
    if(a>0)
    kolekcja_Dronow[nr]->przesuneciedronaprzod(1);
    else kolekcja_Dronow[nr]->przesuneciedronaprzod(-1);
    for(int j=0;j<kolekcja_przeszkod.size();++j){
    bool podrozek=kolekcja_przeszkod[j]->czy_kolizja(kolekcja_Dronow[nr]);
    if(podrozek==false)
    {
      cerr<<"kolizja drona"<<endl;
      exit(1);
    }
    }
    bool podroz=dno.czy_kolizja(kolekcja_Dronow[nr]);
    if(podroz==false)
    {
      cerr<<"kolizja drona"<<endl;
      exit(1);
    }
    podroz=powi.czy_kolizja(kolekcja_Dronow[nr]);
    if(podroz==false)
    {
      cerr<<"kolizja drona"<<endl;
      exit(1);
    }
    }
    break;}
  
  case '4':{

    cout<<"podaj o ile chcesz obrocic drona. Uwaga:kat jest podawany w stopniach"<<endl;
    cin>>a;
    if(cin.fail()){
       cout<<"Blad. Program wroci sie do menu"<<endl;
       cin.clear();
       cin.ignore(1000, '\n');
    } 
   else kolekcja_Dronow[nr]->obrotz(a);
   pokazwektory();
    break;}
  
  case '0':{
  pokazwektory();
    cout<<"koniec dzialania programu"<<endl;break;
  }
  default:{
    cerr<<"Nierozpoznana opcja. Sprobuj ponownie albo uruchom program od poczatku"<<endl;
    }
   } //koniec switch
 } //koniec while
}


