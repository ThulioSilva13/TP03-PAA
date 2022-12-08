all: 
	gcc main.c ./src/lerArquivo.c ./src/KMP.c -o main.exe -Wall -lm 
	./main.exe

clean: 
	rm ./bin/* ./obj/*