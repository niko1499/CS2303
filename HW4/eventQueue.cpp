/*
 * Event.cpp
 *  Created on: 2/7/17
 *  Author: Nikolas X. Gamarra
 */

#include "eventQueue.h"

#include <cstdio>
#include <iostream>
#include "tellerQueue.h"
#include "qSim.h"
eventQueue::eventQueue() {
	head = NULL;
	length = 0;
}	//eventQueue::eventQueue() {

eventQueue::~eventQueue(void) {
	Event *p = head;

	while (!p) {
		Event *q = p->next;
		delete p;
		p = q;
	}
	return;
}	//	eventQueue::~eventQueue(void) {
void eventQueue::InsertItem(float itemValue, char t, int q) {
	Event *p = new Event(itemValue, t, q);
	length++;
	if (!head) {
		head = p;
		return;
	}
	else if (itemValue < head->payload) {
		p->next = head;
		head = p;
	}
	else {
		Event *q = head;
		while ((q->next) && (q->next->payload < itemValue))
			q = q->next;
		p->next = q->next;
		q->next = p;
	}
}//	void eventQueue::InsertItem(float itemValue, char t, int q) {

float eventQueue::action(tellerQueue *Qs, qSim *var) {
	var->actions++;

	float time = head->payload;
	if (this->head->type == 'c') {	//is a customer
		int shortest;
		if (var->tellers == 1) {
			shortest = 0;
		} else {
			shortest = Qs[0].shortestQueue(Qs, var->tellers);//find shortest
			//std::cout << "I cry every time2: " << std::endl;
		}
		Qs[shortest].addLast(head->payload);//put in shortest queue
		time=this->removeFirst();//set new time
	} else {	//is a teller
		int aq = head->assignedQ;
		int min = .1;
		int max = 2;
		float serviceTime = var->simClock + min + (rand() % (max - min));
		if (Qs[aq].getLength() > 0) {
			var->serviceTime += serviceTime;
			time= Qs[aq].removeFirst();//remove from event queue and get new time
			var->completeCustomers++;
			//std::cout << "super sadbois the sadening" << aq << std::endl;
			var->advTime += abs(time - var->simClock);
		} else {
			var->idleTime += serviceTime;
		}
		float tempTime =  var->simClock-time;
		if (tempTime > var->maxTime) {
			var->maxTime = tempTime;
		}
		this->InsertItem(serviceTime, 't', aq);
	}
	time=this->removeFirst();
	return time;
}//float eventQueue::action(tellerQueue *Qs, qSim *var) {
float eventQueue::removeFirst(void) {
	Event *tmp = head->next;
	delete head;
	head = tmp;
	length--;
	float time=head->payload;
	return time;
}//float eventQueue::removeFirst(void) {
int eventQueue::getLength(void) {
	int checkSum = 0;
	for (Event *p = head; p; p = p->next)
		checkSum += 1;
	if (checkSum != length)
		throw checkSum;
	return length;
}	// int eventQueue::getLength(void) {

