CXX = gcc

snq: Stack.o src/driver.c
	${CXX} -o bin/snq src/driver.c src/Stack.o

debug: Stack.o src/driver.c
	${CXX} -o bin/snq.dbg -g src/driver.c src/Stack.o

Stack.o: src/Node.h src/RetCodes.h src/Stack.h src/Stack.c
	${CXX} -o src/Stack.o -c src/Stack.c

clean:
	rm -rf bin/* 
	rm src/*.o
