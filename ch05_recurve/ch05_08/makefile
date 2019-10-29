objects=ch05_08.o
run:$(objects)
	g++ -o run $(objects) -L./ -std=c++11
ch05_08.o: ch05_08.cpp
	g++ -c ch05_08.cpp -std=c++11
.PHONY:clean
clean:
	rm run $(objects)
