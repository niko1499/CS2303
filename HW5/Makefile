#CS-2303 HW4 Nikolas Gamarra

CXXFLAGS = -g -Wall -fmessage-length=0

OBJS =	Rational.o PA5.o

LIBS =

TARGET = PA5

$(TARGET):	$(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS) $(LIBS)

*.o: *.cpp
	$(CXX) -c $(CXXFLAGS) *.cpp

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
