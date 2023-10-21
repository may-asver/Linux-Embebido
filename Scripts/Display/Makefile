CC ?= gcc
CPP ?= g++
CXX ?= g++

APP_NAME = display_client
OBJ_FILES = display_client.o

LIBS = -lwayland-client

all: $(APP_NAME)

$(APP_NAME): $(OBJ_FILES)
	$(CXX) $^ -o $@ $(LIBS)

%.o: %.c
	$(CC) -o $@ -c $^

clean:
	rm *.o $(APP_NAME) $(APP_PLAY)

fresh:
	make clean
	make
