CC=gcc
CFLAGS=-o
LOCAL_OPTIONS=-std=c++11
TARGET=intro_exe
OBJS=job.o hobby.o main.o
SRCS=$(OBJS:.o=.c)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $@ $(OBJS)

%.o: %.c
	$(CC) -c -o $@ $^

clean:
	rm -f *.o
	rm intro_exe



