programa: Arquib.o Bola.o Campo.o Cenario.o Jogador.o Placa.o Trave.o Refletor.o texturaTGA.o main.cpp
	g++ main.cpp -o PeleEterno -lGL -lGLU -lglut Cenario.o Campo.o Bola.o Jogador.o Refletor.o Placa.o Arquib.o Trave.o texturaTGA.o

Arquib.o: Arquib.cpp Arquib.hpp
	g++ -c Arquib.cpp -lGL -lGLU -lglut 

Bola.o: Bola.cpp Bola.hpp
	g++ -c Bola.cpp -lGL -lGLU -lglut 

Campo.o: Campo.cpp Campo.hpp
	g++ -c Campo.cpp -lGL -lGLU -lglut 

Cenario.o: Cenario.cpp Cenario.hpp
	g++ -c Cenario.cpp -lGL -lGLU -lglut 

Jogador.o: Jogador.cpp Jogador.hpp
	g++ -c Jogador.cpp -lGL -lGLU -lglut 

Trave.o: Trave.cpp Trave.hpp
	g++ -c Trave.cpp -lGL -lGLU -lglut 
	
Refletor.o: Refletor.cpp Refletor.hpp
	g++ -c Refletor.cpp -lGL -lGLU -lglut 

Placa.o: Placa.cpp Placa.hpp
	g++ -c Placa.cpp -lGL -lGLU -lglut 

texturaTGA.o: texturaTGA.c texturaTGA.h
	g++ -c texturaTGA.c -lGL -lGLU -lglut 

view:
	./PeleEterno

clean:
	rm  -fv   *~   *.o  *.exe a.out PeleEterno