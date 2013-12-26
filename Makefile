CC = g++
CFLAGS = -c -g

INCL = -Isrc

OS_NAME := $(shell uname -s)
ifeq ($(OS_NAME), Darwin)
  GL_LIBS = -frameworkGL -frameworkglut -frameworkGLU
else
  GL_LIBS = -lGL -lglut -lGLU
endif

VPATH += src/
FILES = \
  Vector.o \
  Matrix.o

main: main.o $(FILES)
	$(CC) -o v8 $^ $(GL_LIBS)

clean:
	rm -f *.o

%.o: %.cpp
	$(CC) $(CFLAGS) $^ $(INCL)

