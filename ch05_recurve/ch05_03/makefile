objects=ch05_03.o
run:$(objects)
	g++ -o run $(objects) -L./ -std=c++11
ch05_03.o: ch05_03.cpp
	g++ -c ch05_03.cpp -std=c++11
.PHONY:clean
clean:
	rm run $(objects)
