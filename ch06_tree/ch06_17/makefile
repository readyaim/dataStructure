objects=ch06_17.o
run:$(objects)
	g++ -o run $(objects) -L./ -std=c++11
ch06_17.o: ch06_17.cpp
	g++ -c ch06_17.cpp -std=c++11 -g 
.PHONY:clean 
clean:
	rm run $(objects)
