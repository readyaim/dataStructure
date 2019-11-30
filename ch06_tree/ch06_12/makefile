objects=ch06_12.o
run:$(objects)
	g++ -o run $(objects) -L./ -std=c++11
ch06_12.o: ch06_12.cpp
	g++ -c ch06_12.cpp -std=c++11 -g 
.PHONY:clean 
clean:
	rm run $(objects)
