all: 
	gcc main.c ./src/lerArquivo.c ./src/simulacao.c ./src/KMP.c ./src/produtoCartesiano.c ./src/similaridade.c ./src/BM.c -o main.exe -Wall -lm 
	./main.exe

clean: 
	rm ./bin/* ./obj/*