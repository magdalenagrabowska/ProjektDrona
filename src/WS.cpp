#include "Wektor3D.cpp"
#include "Macierz3D.cpp"
#include "rozmiar.h"
using namespace std;

template class Wektor<double,ROZMIAR>;
template istream & operator>> (istream & strm, Wektor<double,ROZMIAR>&Wek);
template ostream & operator<< (ostream & strm,const Wektor<double,ROZMIAR>&Wek);
template Wektor<double, ROZMIAR> operator * (double l1, Wektor<double,ROZMIAR> W2);

template class MacierzKw3D<double,ROZMIAR>;
template istream & operator>>(istream & strm, MacierzKw3D<double,ROZMIAR> &Mac);
template ostream & operator<<(ostream & strm,const MacierzKw3D<double,ROZMIAR> &Mac);


