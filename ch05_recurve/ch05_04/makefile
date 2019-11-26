objects=ch05_04.o
run:$(objects)
	g++ -o run $(objects) -L./ -std=c++11
ch05_04.o: ch05_04.cpp
	g++ -c ch05_04.cpp -std=c++11 -g
.PHONY:clean
clean:
	rm run $(objects)
