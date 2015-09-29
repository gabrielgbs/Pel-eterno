programa: Arquib.o Bola.o Campo.o Cenario.o Jogador.o Placa.o Trave.o Refletor.o texturaTGA.o main.cpp
	g++ -lGL -lglut Arquib.o Bola.o Campo.o Cenario.o Jogador.o Trave.o Refletor.o Placa.o texturaTGA.o main.cpp -o alejo

Arquib.o: Arquib.cpp Arquib.hpp
	g++ -c Arquib.cpp

Bola.o: Bola.cpp Bola.hpp
	g++ -c Bola.cpp

Campo.o: Campo.cpp Campo.hpp
	g++ -c Campo.cpp

Cenario.o: Cenario.cpp Cenario.hpp
	g++ -c Cenario.cpp

Jogador.o: Jogador.cpp Jogador.hpp
	g++ -c Jogador.cpp

Trave.o: Trave.cpp Trave.hpp
	g++ -c Trave.cpp
	
Refletor.o: Refletor.cpp Refletor.hpp
	g++ -c Refletor.cpp

Placa.o: Placa.cpp Placa.hpp
	g++ -c Placa.cpp

texturaTGA.o: texturaTGA.c texturaTGA.h
	g++ -c texturaTGA.c

view:
	./alejo

clean:
	rm  -fv   *~   *.o  *.exe a.out   alejo