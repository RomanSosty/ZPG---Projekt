TARGET = main

all:
	g++ -g --std=c++17 -I../include -L../lib ../src/*.cpp -framework Cocoa -framework OpenGL -framework IOKit -lglfw3 -lGLEW -o ${TARGET}
clean:
	rm -rf ${TARGET} *.o 