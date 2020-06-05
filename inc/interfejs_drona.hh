#ifndef INTERFEJS_DRONA_HH
#define INTERFEJS_DRONA_HH

#include "Dr3D_gnuplot_api.hh"
#include "Draw3D_api_interface.hh"
#include "pscian.hh"
#include "Wektor3D.hh"
#include "Macierz3D.hh"


class in_dron{
public:
virtual float zwroc_srednice()=0;
virtual Wektor3D zwroc_translacje()=0;
virtual void przesuneciedronaprzod(double a)=0;
virtual void obrotz(double kat)=0;
virtual void obrotx(double kat)=0;
};




#endif