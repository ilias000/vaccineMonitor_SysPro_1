FILE = -c citizenRecordsFile 
BLOOMSIZE = -b 100000

CC = g++
CFLAGS = -Wall -g
 
PROGRAM = vaccineMonitor
 
OBJS = VaccineMonitor.o Functions.o

$(PROGRAM): clean $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(PROGRAM) 

VaccineMonitor.o: VaccineMonitor.cpp Functions.h
	$(CC) $(CFLAGS) -c VaccineMonitor.cpp 

Functions.o: Functions.cpp Functions.h
	$(CC) $(CFLAGS) -c Functions.cpp 
 
clean:
	rm -f $(PROGRAM) $(OBJS)

run: 
	./$(PROGRAM) $(FILE) $(BLOOMSIZE)

