CC = gcc
SRC = src
SRC_ADT = src/ADT
ADT_FILES = $(filter-out $(wildcard $(SRC_ADT)/*/driver.c), $(wildcard $(SRC_ADT)/*/*.c))
DRIVER_FILES = $(wildcard $(SRC_ADT)/$(f)/*.c)
LOAD_FILES = $(wildcard $(SRC)/Game/LoadSave/*.c)

ifeq ($(OS), Windows_NT)
	CLEAR = cls
else
	CLEAR = clear
endif

run: compile
	$(SRC)/main.exe

compile: 
	$(CC) -I $(SRC_ADT)/Header $(ADT_FILES) $(SRC)/main.c -o $(SRC)/main.exe && $(CLEAR)

run2: $(SRC)/main
	$(SRC)/main.exe

driver: driver_compile
	$(SRC_ADT)/$(f)/driver.exe

driver_compile: $(SRC_ADT)/$(f)
	$(CC) -I $(SRC_ADT)/Header $(DRIVER_FILES) -o $(SRC_ADT)/$(f)/driver.exe

driver_run: $(SRC_ADT)/$(f)
	$(SRC_ADT)/$(f)/driver.exe

# $(CC) -I $(SRC_ADT)/Header $(DRIVER_FILES) src/ADT/ListDinamis/listdin.c src/ADT/Point/point.c src/ADT/Queue/queue.c src/ADT/Pesanan/Pesanan.c src/ADT/LinkedList/list_linked.c src/ADT/LinkedList/node.c src/ADT/Stack/stack.c src/ADT/ListStatis/listStatik.c -o $(SRC_ADT)/$(f)/driver