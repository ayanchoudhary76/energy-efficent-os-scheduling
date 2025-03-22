CC = g++
CFLAGS = -Wall

all: scheduler

scheduler: main.cpp modules/scheduler.cpp utils/logger.cpp
	$(CC) $(CFLAGS) -Iutils -Imodules main.cpp modules/scheduler.cpp utils/logger.cpp -o scheduler.exe
