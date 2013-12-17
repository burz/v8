CC = g++ 
CFLAGS = -c -g

INCL = -Isrc
GL_LIBS = -lGL -lglut -lGLU

main: main.o
	$(CC) -o v8 $^ $(GL_LIBS)

clean:
	rm -f *.o

%.o:  %.cpp
	$(CC) $(CFLAGS) $^ $(INCL)

