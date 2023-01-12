CC=g++
CFLAGS=-o
LOCAL_OPTIONS=-std=c++11
# TARGET=EmployeeTest
# OBJS=EmployeeTest.o Employee.o

# TARGET=Databasetest
# OBJS=DatabaseTest.o Database.o Employee.o

TARGET=UserInterface
OBJS=UserInterface.o Database.o Employee.o

SRCS=$(OBJS:.o=.cpp)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $@ $(OBJS) $(LOCAL_OPTIONS)

%.o: %.cpp
	$(CC) -c -o $@ $^ $(LOCAL_OPTIONS)

clean:
	rm -f $(OBJS)
	rm -f $(TARGET)
