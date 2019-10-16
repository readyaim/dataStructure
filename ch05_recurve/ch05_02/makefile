objects=ch05_02.o
run:$(objects)
	g++ -o run $(objects) -L./ -std=c++11
ch05_02.o: ch05_02.cpp
	g++ -c ch05_02.cpp -std=c++11
.PHONY:clean
clean:
	rm run $(objects)
