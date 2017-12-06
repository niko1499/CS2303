/*
 * tellerQueue.cpp
 *  Created on: 2/7/17
 *  Author: Nikolas X. Gamarra
 */

#include <cstdio>
#include <iostream>

#include "tellerQueue.h"

tellerQueue::tellerQueue() {
	head = NULL;
	length = 0;
}	// tellerQueue::tellerQueue()

tellerQueue::~tellerQueue(void) {
	listItem *p = head;

	while (p) {
		listItem *q = p->next;
		delete p;
		p = q;
	}
	return;
}	//	tellerQueue::~tellerQueue(void)

void tellerQueue::addLast(long itemValue) {

	listItem *p = new listItem(itemValue);
	if (!head) {
		head = p;
		length++;
	} else {
		listItem *q = head;
		while (q->next)
			q = q->next;
		p->next = q->next;
		q->next = p;
		length++;
	}
}	//	void  tellerQueue::addLast(long itemValue)
float tellerQueue::removeFirst(void) {
	if(head){
		listItem *tmp = head->next;
		float payload = head->payload;
		delete head;
		head = tmp;
		//make teller action
		length--;
		return payload;
	}
	else
	{
		return -1;
	}
}//float tellerQueue::removeFirst(void) {
int tellerQueue::getLength(void) {
	long checkSum = 0;
	for (listItem *p = head; p; p = p->next)
		checkSum += 1;
	if (checkSum != length)
		throw checkSum;
	return length;
}	//int tellerQueue::getLength(void) {
int tellerQueue::shortestQueue(tellerQueue *Qs, int tellers) {
	int shortest = 0;
	int previousLength = Qs[0].getLength();
	for (int i = 0; i < tellers - 1; i++) {
		if (Qs[i].getLength() < previousLength) {
			shortest = i;
		}
	}
	return shortest;

}	//end shortestQueue

