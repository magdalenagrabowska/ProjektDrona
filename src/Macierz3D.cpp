#include "Macierz3D.hh"
using std::cerr;
using std::endl;
using std::cout;


template<typename STyp, int SWymiar>
const Wektor<STyp,SWymiar> & MacierzKw3D<STyp, SWymiar>::operator[] (unsigned int Wie) const{
    if (Wie < 0 || Wie >= SWymiar) {
      cerr << "poza zakresem" << endl;
      exit(1);
    }
    return Wiersz[Wie];
}
template<typename STyp, int SWymiar>
Wektor<STyp,SWymiar> & MacierzKw3D<STyp, SWymiar>::operator[] (unsigned int Wie){
       if (Wie < 0 || Wie >= SWymiar) {
      cerr << "poza zakresem" << endl;
      exit(1);
    }
    return Wiersz[Wie];
  }

template<typename STyp, int SWymiar>
 const STyp & MacierzKw3D<STyp,SWymiar>::operator() (unsigned int Wie,unsigned int Kol) const{
      if ((Wie < 0 || Wie >= SWymiar) && (Kol < 0 || Kol >= SWymiar)) {
      cerr << "poza zakresem" << endl;
      exit(1);
    }
    return Wiersz[Wie][Kol];
  }
template<typename STyp, int SWymiar>
 STyp & MacierzKw3D<STyp,SWymiar>::operator() (unsigned int Wie, unsigned int Kol){
     if ((Wie < 0 || Wie >= SWymiar) && (Kol < 0 || Kol >= SWymiar)) {
      cerr << "poza zakresem" << endl;
      exit(1);
    } 
    return Wiersz[Wie][Kol];
 }
template<typename STyp, int SWymiar>
Wektor<STyp,SWymiar> MacierzKw3D<STyp,SWymiar>::zwroc_kolumne(int ind)const{
  if (ind < 0 || ind >= SWymiar) {
      cerr << "poza zakresem" << endl;
      exit(1);
    } 
    Wektor<STyp,SWymiar> Kol;
    for(int i=0;i<SWymiar;i++){
      Kol[i]=Wiersz[i][ind];
    }
      
    return Kol;
  }
 
template<typename STyp, int SWymiar>
void MacierzKw3D<STyp,SWymiar>::zmien_kolumne(Wektor<STyp,SWymiar> W, int i){
 for(int j=0;j<SWymiar;j++)
 {
 Wiersz[j][i]=W[j];
 }
}

template<typename STyp, int SWymiar>
void MacierzKw3D<STyp,SWymiar>::transpozycja(){
 MacierzKw3D<STyp,SWymiar> M;
 Wektor<STyp,SWymiar> W;
 for(int i=0;i<SWymiar;i++){
   M.Wiersz[i]=Wiersz[i];
 }
 for(int i=0;i<SWymiar;i++){
   W=M.zwroc_kolumne(i);
   Wiersz[i]=W;
 }
}

template<typename STyp, int SWymiar>
STyp MacierzKw3D<STyp,SWymiar>::wyznacznikGauss()const{
  
  MacierzKw3D<STyp,SWymiar> M=(*this);
  
  STyp det;
  det=1;
  STyp mnoznik;
  mnoznik=0;
 for(int i=0;i<SWymiar-1;i++){
   for(int j=i+1;j<SWymiar;j++){
    mnoznik=M.Wiersz[j][i]/M.Wiersz[i][i];
    for(int k=i;k<SWymiar;k++)
    M.Wiersz[j][k]=M.Wiersz[j][k]-mnoznik*M.Wiersz[i][k];
    
   }
 }
 for(int z=0;z<SWymiar;z++){
   det=det*M.Wiersz[z][z];
   
 }
 return det;
}

template<typename STyp, int SWymiar>
MacierzKw3D<STyp,SWymiar> MacierzKw3D<STyp,SWymiar>::operator+ (const MacierzKw3D<STyp,SWymiar> & M)const{
  MacierzKw3D<STyp,SWymiar> Suma;
   for(int ind=0;ind<SWymiar;ind++){
  Suma.Wiersz[ind]=Wiersz[ind]+M.Wiersz[ind];
   }
  return Suma;
  }
template<typename STyp, int SWymiar>
MacierzKw3D<STyp,SWymiar> MacierzKw3D<STyp,SWymiar>::operator - (const MacierzKw3D<STyp,SWymiar> & M)const{
  MacierzKw3D<STyp,SWymiar> Suma;
   for(int ind=0;ind<SWymiar;ind++){
  Suma.Wiersz[ind]=Wiersz[ind]-M.Wiersz[ind];
   }
  return Suma;
  }
  
template<typename STyp, int SWymiar>
MacierzKw3D<STyp,SWymiar> MacierzKw3D<STyp,SWymiar>::operator * (const MacierzKw3D<STyp,SWymiar> & M)const{
  MacierzKw3D<STyp,SWymiar> Suma;
  MacierzKw3D<STyp,SWymiar> Mnoznik;
   for(int ind=0;ind<SWymiar;ind++){
  for(int j=0;j<SWymiar;j++){
  Wektor<STyp,SWymiar> Kolumna=M.zwroc_kolumne(j);
  for(int i=0;i<SWymiar;i++){
  Mnoznik.Wiersz[ind]=Wiersz[ind]*Kolumna[i];
  Suma[ind][j]+=Mnoznik[ind][i];
  }
  }
  }
  return Suma;
  } 

template<typename STyp, int SWymiar>
MacierzKw3D<STyp,SWymiar> MacierzKw3D<STyp,SWymiar>::operator * (double l)const{
   MacierzKw3D<STyp,SWymiar> M;
   for(int i=0;i<SWymiar;i++){
    M.Wiersz[i]=Wiersz[i]*l;
   }
   return M;
 }
 
template<typename STyp, int SWymiar>
Wektor<STyp,SWymiar> MacierzKw3D<STyp,SWymiar>::operator * (const Wektor<STyp,SWymiar> &W) const{
STyp Mnoznik;
Wektor<STyp,SWymiar> Wynik;  
for(int ind=0;ind<SWymiar;ind++){
for(int i=0;i<SWymiar;i++){
Mnoznik=Wiersz[ind][i]*W[i];
Wynik[ind]+=Mnoznik; 
}
}
return Wynik;
 }
 

template<typename STyp, int SWymiar>
std::istream& operator>>(std::istream &strm, MacierzKw3D<STyp,SWymiar> &Mac){
for(int i=0;i<SWymiar;i++){
for(int j=0;j<SWymiar;j++){
strm>>Mac(i,j);
if(strm.fail())
strm.setstate(std::ios::failbit);
}
} 
return strm;
  }

template<typename STyp, int SWymiar>
std::ostream& operator<<(std::ostream &strm, const MacierzKw3D<STyp,SWymiar> &Mac){
for(int i=0;i<SWymiar;i++){
for(int j=0;j<SWymiar;j++){
strm<<Mac(i,j);
 strm<<" ";
if(strm.fail())
strm.setstate(std::ios::failbit);
}
strm<<endl;
} 
return strm;
}



