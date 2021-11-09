CC = gcc
SRC = src
SRC_ADT = src/ADT
ADT_FILES = $(filter-out $(wildcard $(SRC_ADT)/*/driver.c), $(wildcard $(SRC_ADT)/*/*.c))
DRIVER_FILES = $(wildcard $(SRC_ADT)/$(f)/*.c)
LOAD_FILES = $(wildcard $(SRC)/Game/LoadSave/*.c)

run: compile
	$(SRC)/main

compile: 
	$(CC) -I $(SRC_ADT) $(ADT_FILES) $(SRC)/main.c -o $(SRC)/main

run2: $(SRC)/main
	$(SRC)/main

driver: driver_compile
	$(SRC_ADT)/$(f)/driver

driver_compile: $(SRC_ADT)/$(f)
	$(CC) -I $(SRC_ADT) $(DRIVER_FILES) -o $(SRC_ADT)/$(f)/driver

driver_run: $(SRC_ADT)/$(f)
	$(SRC_ADT)/$(f)/driver

# Testing
loadsave: lcompile
	$(SRC)/Game/LoadSave/driver

lcompile:
	$(CC) -I $(SRC_ADT) $(DRIVER_FILES) $(LOAD_FILES) -o src/Game/LoadSave/driver