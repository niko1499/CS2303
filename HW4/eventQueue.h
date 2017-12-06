/*
 * Event.h
 * Nikolas X. Gamarra
 * 2/11/17
 * keeps track of events in time order
 */

#ifndef EVENTQUEUE_H_
#define EVENTQUEUE_H_

#include <cstdio>
#include <cstdlib>

class tellerQueue;
class qSim;
class eventQueue {
public:
	float removeFirst(void);
	int getLength(void);
	float action(tellerQueue *r,qSim *s);
	void InsertItem(float item, char c, int aq);

	eventQueue();	//	constructor
	~eventQueue();	//	destructor

private:
	class Event;
	Event *head;
	int length;

	class Event {	// an internal class
	public:

		const float payload;
		const char type;
		const int assignedQ;
		Event *next;

		inline Event(float item, char t, int x) :
				payload(item), type(t), assignedQ(x), next(NULL) {
		}
		;

	};
	// class Event

};

#endif /* EVENTQUEUE_H_ */
