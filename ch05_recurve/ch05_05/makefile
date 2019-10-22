objects=ch05_05.o
run:$(objects)
	g++ -o run $(objects) -L./ -std=c++11
ch05_05.o: ch05_05.cpp
	g++ -c ch05_05.cpp -std=c++11
.PHONY:clean
clean:
	rm run $(objects)
