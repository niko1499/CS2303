/*
 * tellerQueue.h
 * Nikolas X. Gamarra
 * 2/11/17
 * first in first out line
 */

#ifndef TELLERQUEUE_H_
#define TELLERQUEUE_H_

#include <cstdio>
#include <cstdlib>

class tellerQueue {
public:
	void addLast(long item);
	float removeFirst(void);
	int getLength(void);
	int shortestQueue(tellerQueue *Qs,int tellers);

	tellerQueue();	//	constructor
	~tellerQueue();	//	destructor

private:
	class listItem;
	listItem *head;
	int length;

	class listItem {	// an internal class
	public:

		const long payload;
		listItem *next;

		inline listItem(long item) :
				payload(item), next(NULL) {
		}
		;

	};
	// class tellerqueue

};

#endif /* TELLERQUEUE */
