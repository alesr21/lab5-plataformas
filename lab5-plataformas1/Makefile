#Variables para el compilador

CC=gcc
CFLAGS=-Wall -Wextra -g
TARGET=main


all: $(TARGET)

#Generar el ejecutable

$(TARGET): main.o double_list.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o double_list.o

#Compilacion

main.o: main.c double_list.h
	$(CC) $(CFLAGS) -c main.c

double_list.o: double_list.c double_list.h
	$(CC) $(CFLAGS) -c double_list.c

#Limpiar archivos generados

clean:
	rm -f main.o double_list.o $(TARGET)

#Ejecutar el programa

run: $(TARGET)
	./$(TARGET)
