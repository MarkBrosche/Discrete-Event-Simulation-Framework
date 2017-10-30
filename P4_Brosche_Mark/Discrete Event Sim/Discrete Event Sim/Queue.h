#pragma once
#include "Simulation.h"
#include "Event.h"

class Queue : public SimObj
{
public:
	Queue();
	/*
		Queue
			Parameters:
				none
			Return value:
				none
			Behavior:
				Constructor for the Queue class based on SimObj
	*/

	Event *CreateEvent();
	/*
		*CreateEvent
			Parameters:
				none
			Return value:
				new Event object
			Behavior:
				creates and returns a new Event object
	*/

private:
	Event _ev;
};
