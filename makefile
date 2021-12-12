all: main clean

main: main.o tarefa.o
	gcc -Wall main.o telas.o verificacoes.o agenda.o aniversario.o reuniao.o  tarefa.o -o exercicio

main.o: main.c telas.h verificacoes.h agenda.h aniversario.h reuniao.h  tarefa.h
	gcc -Wall -c main.c

clean:
	rm *.o