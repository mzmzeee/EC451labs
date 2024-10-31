all: f.exe

f.exe: firstapp.o secondapp.o
	gcc -o f.exe firstapp.o secondapp.o
firstapp.o: firstapp.c
	gcc -c firstapp.c
secondapp.o: secondapp.c
	gcc -c secondapp.c
clean:
	rm *.o f.exe