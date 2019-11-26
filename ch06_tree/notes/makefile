objects=ch06_tree_notes.o
run:$(objects)
	g++ -o run $(objects) -L./ -std=c++11
ch06_tree_notes.o: ch06_tree_notes.cpp
	g++ -c ch06_tree_notes.cpp -std=c++11 -g
.PHONY:clean
clean:
	rm run $(objects)
