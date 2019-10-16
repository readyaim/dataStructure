objects=ch05_01.o
run:$(objects)
	g++ -o run $(objects) -L./ -std=c++11
ch05_01.o: ch05_01.cpp
	g++ -c ch05_01.cpp -std=c++11
.PHONY:clean
clean:
	rm run $(objects)
