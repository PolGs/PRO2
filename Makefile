OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o idioma.o cjt_idioma.o tabla.o treecode.o
	g++ -o program.exe *.o

program.o: program.cc idioma.hh cjt_idioma.hh treecode.hh tabla.hh
	g++ -c program.cc $(OPCIONS)

idioma.o: idioma.cc treecode.hh tabla.hh
	g++ -c idioma.cc $(OPCIONS)

cjt_idioma.o: cjt_idioma.cc idioma.hh treecode.hh tabla.hh
	g++ -c cjt_idioma.cc $(OPCIONS)

tabla.o: tabla.cc tabla.hh
	g++ -c tabla.cc $(OPCIONS)

treecode.o: treecode.cc tabla.hh
	g++ -c treecode.cc $(OPCIONS)

clean:
	rm -f *.o
	rm -f *.exe
