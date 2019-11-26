objects=ch06_01.o
run:$(objects)
	g++ -o run $(objects) -L./ -std=c++11
ch06_01.o: ch06_01.cpp
	g++ -c ch06_01.cpp -std=c++11 -g 
.PHONY:clean 
clean:
	rm run $(objects)
