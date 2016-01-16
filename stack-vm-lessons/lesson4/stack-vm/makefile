CFLAGS=-std=c++11

all: stack-vm

stack-vm: stack-vm.o main.o
	$(CXX) $(CFLAGS) stack-vm.o main.o -o stack-vm

main.o: main.cpp
	$(CXX) $(CFLAGS) -c main.cpp

stack-vm.o: stack-vm.h stack-vm.cpp
	$(CXX) $(CFLAGS) -c stack-vm.cpp

clean:
	rm -f *.o stack-vm
