CC ?= gcc

APP_NAME_READER = smh_reader
OBJ_FILES_READER = smh_reader.o
LIBS = .

APP_NAME_WRITTER = smh_writer
OBJ_FILES_WRITTER = smh_writer.o

LIB_DIRS = .
LIB = pathread

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
