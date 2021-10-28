CC = gcc
SRC = src
SRC_ADT = src/ADT
ADT_FILES = $(filter-out $(wildcard $(SRC_ADT)/*/driver.c), $(wildcard $(SRC_ADT)/*/*.c))
DRIVER_FILES = $(wildcard $(SRC_ADT)/$(folder)/*.c)

run: compile
	$(SRC)/main

compile: 
	$(CC) -I $(SRC_ADT) $(ADT_FILES) $(SRC)/main.c -o $(SRC)/main

driver: driver_compile
	$(SRC_ADT)/$(folder)/driver

driver_compile: $(SRC_ADT)/$(folder)
	$(CC) -I $(SRC_ADT) $(DRIVER_FILES) -o $(SRC_ADT)/$(folder)/driver