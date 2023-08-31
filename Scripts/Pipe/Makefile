CC ?= gcc

APP_NAME_SIMPLE = pipe_simple
OBJ_FILES_SIMPLE = pipe_simple.o
LIBS = .

APP_NAME_SIMPLE2 = pipe_simple2
OBJ_FILES_SIMPLE2 = pipe_simple2.o

all: $(APP_NAME_SIMPLE) $(APP_NAME_SIMPLE2)

$(APP_NAME_SIMPLE): $(OBJ_FILES_SIMPLE)
	$(CC) -o $@ $^

$(APP_NAME_SIMPLE2): $(OBJ_FILES_SIMPLE2)
	$(CC) -o $@ $^


%.o: %.c
	$(CC) -o $@ -c $^ -g

clean:
	rm *.o $(APP_NAME_SIMPLE)
	rm *.o $(APP_NAME_SIMPLE2)
fresh:
	make clean
	make all
