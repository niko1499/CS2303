README for PA4(qSim.cpp) -- Nikolas X. Gamarra
------------------------------------------------------------------
To compile:
Type 'make' from the command line in the project directory.
------------------------------------------------------------------
To Run:
Type './qSim #customber #tellers runtime advServiceTime seed(optional)

------------------------------------------------------------------
Description:
This is an implementation of an event driven simulation that 
modles and analizes customers using two different queueing schemes.
In Common customers enter a single line serviced by all tellers. 
In One per Teller each teller has its own queue and customers go
to the shortest one.

------------------------------------------------------------------
Structure:
PA4 consists of 3 .cpp files and 3 .h file
qSim.cpp
main loop of the program. gets user input. Objects of other classes are
created and manipulated here. Also has two helper functions. One to 
print the results and one to clear global variables.

qSim.h
file to hold variables that need to be referenced in multiple classes.
a pointer of an object of this class gets passed to functions that 
need the data.

eventQueue.cpp
A linked list of events sorted by the time the occur. contains customers and
tellers. When the action method of this class gets called it performs
the appropriate action for teller or customer on the top of the line an
updates the time. Customers get put to a teller queue. Tellers take a
customer out of a teller queue and put themselves back in the event queue.
The whole time data is gathered for statisticl anlysis.

eventQueue.h
Header file for eventQueue. Allows qSim to create objects of type eventQueue with
the functions implemented in eventQue.cpp

tellerQueue.ccp
First in first out linked list. Represents a literal queue. One or multiple
of these are creaed depending on the queueing scheme.

tellerQueue.h 
Header file for tellerQueue. Allows qSim to create tellerQueue objects.


------------------------------------------------------------------
Problems:

While implementing this program I ran into many runtime errors especially
segmentation faults. These were especially hard to trace down because
the debugger runs so poorly in the VM. Many fatial ones I was able to trace
down but ocasionally they still occur. One I was not able to fix
 is certian values for the runtime still cause a seg fault.
Certain random numbers also cause seg faults. 
 ------------------------------------------------------------------
Results:

Here are two examples of successful runs. They show the advantages
of a common queue in terms of effeciency. 

ngamarra@CS-2303-VirtualBox:~/CS2303/HW4$ ./qSim 90 50 150 2.3 
-----------------------
-Qtype: Common
Total customers served: 67
Total time run: 150 min
Number of tellers: 50
Mean time: 0 min
Maximum wait time: 0.814148
Teller Service time: 5089.3
Teller idle time: 417337
Actions performed: 7696
-----------------------
-Qtype: One per teller
Total customers served: 61
Total time run: 150 min
Number of tellers: 50
Mean time: 0.0111111 min
Maximum wait time: 1.28582
Teller Service time: 4180.65
Teller idle time: 376065
Actions performed: 7384

ngamarra@CS-2303-VirtualBox:~/CS2303/HW4$ ./qSim 900 500 120 2 666
Warning: rand number uses seed: 666
-----------------------
-Qtype: Common
Total customers served: 477
Total time run: 120.115 min
Number of tellers: 500
Mean time: 0 min
Maximum wait time: 0.118538
Teller Service time: 28930
Teller idle time: 6.72404e+06
Actions performed: 112931
-----------------------
-Qtype: One per teller
Total customers served: 482
Total time run: 120.115 min
Number of tellers: 500
Mean time: 0.0177778 min
Maximum wait time: 3.99701
Teller Service time: 28763.5
Teller idle time: 6.65697e+06
Actions performed: 111863
------------------------------------------------------------------
Referenced Code:
The structures of eventQueue and tellerQueue were modled after
the lab4 example of a linked list in C++.

 
