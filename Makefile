CPPFLAGS= -c -g -std=c++11 -iquote inc -Wall -pedantic

__start__: ./test_drona 
	./test_drona

obj:
	mkdir -p obj

./test_drona: obj obj/main.o obj/dron.o obj/Dr3D_gnuplot_api.o obj/WS.o obj/pscian.o
	g++ -o ./test_drona obj/main.o obj/dron.o obj/Dr3D_gnuplot_api.o obj/WS.o obj/pscian.o -lpthread

obj/main.o: src/main.cpp inc/dron.hh inc/Dr3D_gnuplot_api.hh inc/pow_morza.hh inc/interfejs_drona.hh inc/interfejs_przeszkody.hh inc/Wektor3D.hh inc/Macierz3D.hh
	g++ -c ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/dron.o: src/dron.cpp inc/interfejs_przeszkody.hh  inc/dron.hh inc/pscian.hh inc/Dr3D_gnuplot_api.hh inc/Macierz3D.hh inc/Wektor3D.hh inc/wirniki.hh inc/interfejs_drona.hh
	g++ -c ${CPPFLAGS} -o obj/dron.o src/dron.cpp

obj/pscian.o:inc/pscian.hh src/pscian.cpp inc/bryla.hh inc/Dr3D_gnuplot_api.hh inc/Macierz3D.hh inc/Wektor3D.hh inc/Draw3D_api_interface.hh 
	g++ -c ${CPPFLAGS} -o obj/pscian.o src/pscian.cpp

obj/Dr3D_gnuplot_api.o: src/Dr3D_gnuplot_api.cpp inc/Dr3D_gnuplot_api.hh inc/Draw3D_api_interface.hh
	g++ -c ${CPPFLAGS} -o obj/Dr3D_gnuplot_api.o src/Dr3D_gnuplot_api.cpp

obj/WS.o: src/Wektor3D.cpp inc/Wektor3D.hh src/WS.cpp src/Macierz3D.cpp inc/Macierz3D.hh inc/Dr3D_gnuplot_api.hh inc/Draw3D_api_interface.hh 
	g++ -c ${CPPFLAGS} -o obj/WS.o src/WS.cpp 

Dr3D_gnuplot_api.hh: inc/Draw3D_api_interface.hh
	touch inc/Dr3D_gnuplot_api.hh

pscian.hh: inc/bryla.hh
	touch inc/pscian.hh

dron.hh: inc/interfejs_drona.hh
	touch inc/dron.hh

pow.hh: inc/pow.hh inc/bryla.hh inc/Dr3D_gnuplot_api.hh

interfejs_przeszkody.hh: inc/interfejs_drona.hh inc/dron.hh inc/Dr3D_gnuplot_api.hh inc/pscian.hh
	touch inc/interfejs_przeszkody.hh




