CC ?= gcc

APP_NAME_READER = memory_reader
OBJ_FILES_READER = memory_reader.o
LIBS = .

APP_NAME_WRITTER = memory_writter
OBJ_FILES_WRITTER = memory_writter.o

all: $(APP_NAME_READER) $(APP_NAME_WRITTER)

$(APP_NAME_READER): $(OBJ_FILES_READER)
	$(CC) -o $@ $^

$(APP_NAME_WRITTER): $(OBJ_FILES_WRITTER)
	$(CC) -o $@ $^


%.o: %.c
	$(CC) -o $@ -c $^ -g

clean:
	rm *.o $(APP_NAME_READER)
	rm *.o $(APP_NAME_WRITTER)
fresh:
	make clean
	make all
