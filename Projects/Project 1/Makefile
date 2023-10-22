CC ?= gcc
CPP ?= g++
CXX ?= g++

APP_LED_CALL = led_call
OBJ_LED_CALL = led_call.o
APP_LED_DENY = led_denied
OBJ_LED_DENY = led_denied.o
APP_LED_INCALL = led_in_call
OBJ_LED_INCALL = led_in_call.o

LIB_DIRS = .

all: $(APP_LED_CALL) $(APP_LED_DENY) $(APP_LED_INCALL)

$(APP_LED_CALL): $(OBJ_LED_CALL)
	$(CC) $^ -o $@ -L$(LIB_DIRS)
%.o: %.c
	$(CC) -o $@ -c $^

$(APP_LED_DENY): $(OBJ_LED_DENY)
	$(CC) $^ -o $@ -L$(LIB_DIRS)
%.o: %.c
	$(CC) -o $@ -c $^
	
$(APP_LED_INCALL): $(OBJ_LED_INCALL)
	$(CC) $^ -o $@ -L$(LIB_DIRS)
%.o: %.c
	$(CC) -o $@ -c $^

clean:
	rm *.o $(APP_LED_CALL) $(APP_LED_DENY) $(APP_LED_INCALL)

fresh:
	make clean
	make
