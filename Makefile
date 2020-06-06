CC = g++
CFLAGS = -std=c++17 -o
#LIBS = -lwiringPi -pthread
LIBS = -pthread
CPPFILES = main.cpp drone.cpp MPU9520.cpp I2C.cpp algorithms.cpp on_pins_4.cpp web_socket.cpp battery_1S.cpp
TARGET = test

all: $(CPPFILES)
	$(CC) $(CFLAGS) $(TARGET) $(CPPFILES)  $(LIBS)
clean:
	rm test
