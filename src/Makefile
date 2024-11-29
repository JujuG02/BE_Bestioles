main : main.cpp Aquarium.o Bestiole.o Milieu.o BestioleCreator.o Gregaire.o Kamikaze.o Peureuse.o Prevoyante.o Camouflage.o Carapace.o Nageoire.o Sensor.o
	g++ -Wall -std=c++17 -o main main.cpp Aquarium.o Bestiole.o Milieu.o BestioleCreator.o Gregaire.o Kamikaze.o Peureuse.o Prevoyante.o Camouflage.o Nageoire.o Sensor.o Carapace.o -I . -lX11 -lpthread

Aquarium.o : Aquarium.h Aquarium.cpp
	g++ -Wall -std=c++17  -c Aquarium.cpp -I .

Bestiole.o : Bestiole.h Bestiole.cpp Clone.h
	g++ -Wall -std=c++17  -c Bestiole.cpp -I .

Milieu.o : Milieu.h Milieu.cpp
	g++ -Wall -std=c++17  -c Milieu.cpp -I .

BestioleCreator.o : Creator.h BestioleCreator.h BestioleCreator.cpp
	g++ -Wall -std=c++17  -c BestioleCreator.cpp -I .

Gregaire.o : Behavior.h Gregaire.h Gregaire.cpp 
	g++ -Wall -std=c++17  -c Gregaire.cpp -I .

Kamikaze.o : Behavior.h Kamikaze.h Kamikaze.cpp 
	g++ -Wall -std=c++17  -c Kamikaze.cpp -I .

Peureuse.o : Behavior.h Peureuse.h Peureuse.cpp 
	g++ -Wall -std=c++17  -c Peureuse.cpp -I .

Prevoyante.o : Behavior.h Prevoyante.h Prevoyante.cpp 
	g++ -Wall -std=c++17  -c Prevoyante.cpp -I .

Nageoire.o : Decorator.h Nageoire.h Nageoire.cpp
	g++ -Wall -std=c++17  -c Nageoire.cpp -I .

Sensor.o : Decorator.h Sensor.h Sensor.cpp
	g++ -Wall -std=c++17  -c Sensor.cpp -I .

Carapace.o : Decorator.h Carapace.h Carapace.cpp
	g++ -Wall -std=c++17  -c Carapace.cpp -I .

Camouflage.o : Decorator.h Camouflage.h Camouflage.cpp
	g++ -Wall -std=c++17  -c Camouflage.cpp -I .

clean:
	rm -rf *.o main

