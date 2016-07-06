CFLAGS=-std=c++11

all: sasm 

sasm: sasm.o lexer.o
	$(CXX) $(CFLAGS) sasm.o lexer.o -o $@

lexer.o: lexer.h lexer.cpp
	$(CXX) $(CFLAGS) -c lexer.cpp

sasm.o: lexer.h sasm.cpp
	$(CXX) $(CFLAGS) -c sasm.cpp

clean:
	rm -f sasm *.o *.bin
