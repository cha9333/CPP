CC=g++
CFLAGS=-o
LOCAL_OPTIONS=-std=c++11
TARGET=hello
OBJS=hello.o
SRCS=$(OBJS:.o=.cpp)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $@ $(OBJS) $(LOCAL_OPTIONS)

$(OBJS): hello.cpp
	$(CC) -c -o $(OBJS) $(SRCS) $(LOCAL_OPTIONS)

clean:
	rm -f $(OBJS)
	rm -f $(TARGET)
