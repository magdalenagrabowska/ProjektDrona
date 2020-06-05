#include "Wektor3D.hh"
using std::endl;
using std::cerr;


/*
int Wektor3D::ile_jest_w=0;
int Wektor3D::ile_utworzono_w=0;
*/

template<typename STyp, int SWymiar>
 STyp & Wektor<STyp, SWymiar>::operator[] (unsigned int index) { 
    if (index < 0 || index >= SWymiar) {
      cerr << "poza zakresem" << endl;
      exit(1);
    }
    return _tab[index];     
  }

template<typename STyp, int SWymiar>
const STyp & Wektor<STyp, SWymiar>::operator[] (unsigned int index) const{
  if (index < 0 || index >= SWymiar) {
      cerr << "poza zakresem" << endl;
      exit(1);
    }
     return _tab[index];
}
template<typename STyp, int SWymiar>
std::istream &operator>>(std::istream &strm, Wektor<STyp, SWymiar>  &Wek){
for(int i=0;i<SWymiar;i++){
  strm>>Wek[i];
if(strm.fail())
strm.setstate(std::ios::failbit);
}
return strm;
}
template<typename STyp, int SWymiar>
std::ostream& operator <<(std::ostream &strm, const Wektor<STyp, SWymiar> &Wek){
for(int i=0;i<SWymiar;i++){
strm<<Wek[i]<<" ";
if(strm.fail())
strm.setstate(std::ios::failbit);
 } 
return strm;
}

template<typename STyp, int SWymiar>
Wektor<STyp, SWymiar> Wektor<STyp, SWymiar>::operator + (const Wektor<STyp, SWymiar> & W2) const{
Wektor<STyp, SWymiar> Suma;
for(int ind=0;ind<SWymiar;ind++){
  Suma._tab[ind]=_tab[ind]+W2._tab[ind];
}
return Suma;
}

template<typename STyp, int SWymiar>
Wektor<STyp, SWymiar> Wektor<STyp, SWymiar>::operator - (const  Wektor<STyp, SWymiar>& W2) const{
Wektor<STyp, SWymiar> Suma;
for(int ind=0;ind<SWymiar;ind++){
  Suma._tab[ind]=_tab[ind]-W2._tab[ind];
}
return Suma;
  }

template<typename STyp, int SWymiar>
STyp Wektor<STyp, SWymiar>::operator * (const Wektor<STyp, SWymiar> & W2) const{
STyp Suma;
Suma=0; //iloczyn skalarny
STyp mnoznik;
mnoznik=0;
for(int ind=0;ind<SWymiar;ind++){
  mnoznik=_tab[ind]*W2._tab[ind];
  Suma+=mnoznik;
}
return Suma;
}
template<typename STyp, int SWymiar>
Wektor<STyp, SWymiar> Wektor<STyp, SWymiar>::operator * (double li)const{
Wektor<STyp, SWymiar> W2;
 for(int ind=0;ind<SWymiar;ind++){
  W2._tab[ind]=_tab[ind]*li;
 }
return W2;
  }

template<typename STyp, int SWymiar>  
Wektor<STyp, SWymiar> operator * (double l1, Wektor<STyp, SWymiar> W2){
  for(int ind=0;ind<SWymiar;ind++){
  W2[ind]=W2[ind]*l1;
}
return W2;
}
