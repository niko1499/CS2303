#CS-2303 HW4 Nikolas Gamarra

CXXFLAGS = -g -Wall -fmessage-length=0

OBJS =	qSim.o tellerQueue.o eventQueue.o

LIBS =

TARGET = qSim

$(TARGET):	$(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS) $(LIBS)

*.o: *.cpp
	$(CXX) -c $(CXXFLAGS) *.cpp

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
