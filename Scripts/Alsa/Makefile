CC ?= gcc
CPP ?= g++
CXX ?= g++

APP_NAME = alsa_output
APP_PLAY = alsa_capture
OBJ_FILES = alsa_output.o
OBJ_FILES_PLAY = alsa_capture.o
LIB_DIRS = .

LIB = -lasound

all: $(APP_NAME) $(APP_PLAY)

$(APP_NAME): $(OBJ_FILES)
	$(CC) $^ -o $@ -L$(LIB_DIRS) $(LIB)

$(APP_PLAY): $(OBJ_FILES_PLAY)
	$(CC) $^ -o $@ -L$(LIB_DIRS) $(LIB)

%.o: %.c
	$(CC) -o $@ -c $^

clean:
	rm *.o $(APP_NAME) $(APP_PLAY)

fresh:
	make clean
	make
