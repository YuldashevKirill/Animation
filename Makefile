all: dz3

dz3: wm.o fig.o tree.o pig.o scene.o
	g++ wm.o fig.o tree.o pig.o scene.o -o dz3 -lfltk
	
wm.o: wm.cpp
	 g++ -c wm.cpp
    
fig.o: fig.cpp
	 g++ -c fig.cpp
    
tree.o: tree.cpp
	 g++ -c tree.cpp

pig.o: pig.cpp
	 g++ -c pig.cpp
    
scene.o: scene.cpp
	 g++ -c scene.cpp

clean:
	 rm -rf *.o dz3
