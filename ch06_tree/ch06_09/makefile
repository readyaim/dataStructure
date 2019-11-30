objects=ch06_09.o
run:$(objects)
	g++ -o run $(objects) -L./ -std=c++11
ch06_09.o: ch06_09.cpp
	g++ -c ch06_09.cpp -std=c++11 -g 
.PHONY:clean 
clean:
	rm run $(objects)
