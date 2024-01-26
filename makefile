VPATH = ./src
CC = g++
LINKER = $(CC)
CFLAGS = -O2 -Wall -msse3
func = openblas

objects = main.o matrix.o dclock.o $(func).o

gemm : $(objects)
	$(CC) $(objects) -lopenblas -lpthread -o gemm 

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

run:	
	make clean;
	make;
	echo $(func) > ./data/$(func).txt;
	./gemm >> ./data/$(func).txt;
	python draw.py;

clean:
	rm -f *.o *~ core *.x
