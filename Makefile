CC = gcc
SRC = src
SRC_ADT = src/ADT
ADT_FILES = $(filter-out $(wildcard $(SRC_ADT)/*/driver.c), $(wildcard $(SRC_ADT)/*/*.c))

run: compile
	$(SRC)/main

compile: 
	$(CC) -I$(SRC_ADT)/ $(ADT_FILES) $(SRC)/main.c -o $(SRC)/main

# Tambah buat run/compile per driver