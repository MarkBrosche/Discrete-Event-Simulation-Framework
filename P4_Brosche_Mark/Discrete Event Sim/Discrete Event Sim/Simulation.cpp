#include "Simulation.h"
#include <iostream> 
using namespace std;

class SimObj::EventSet 
{
public:
	EventSet()
	{
		_first = 0;		//initialized the pointer to the head EventNode 
	}

	void AddEvent(Time time, Event *ev)
	{
		EventNode *en = new EventNode(time, ev);
		if (_first == 0)
		{
			_first = en;						//if this is the first event, add it to the EventSet and point to it.
		}
		else if (time < _first->_time)
		{
			en->_next = _first;					//if this event is before the next event then add it to the front of the EventSet
			_first = en;
		}
		else
		{
			EventNode *current = _first;
			while ((current->_next == 0) ? false : (current->_next->_time <= time))		//adds node to middle of EventSet
			{
				current = current->_next;
			}
			en->_next = current->_next;
			current->_next = en;
		}
	}



	Event *GetEvent()
	{
		// Remove and return the event from the event set with the smallest value of time
		Event *ev = _first->_ev;
		EventNode *en = _first;
		en->_next = _first;
		//delete _first;
		return (ev);
	}

	Time GetTime()
	{
		// Return the smallest timestamp of all events in the event set
		return _first->_time + 1.0;
	}

	bool HasEvent()
	{
		// Determine if there are any events left in the system
		if (_first != NULL) // if the pointer to the first node is equal to null, then there are no events
			return true;
		else return false;
	}

private:
	struct EventNode
	{
		EventNode(Time time, Event *ev)
		{
			_time = time;			//time that this event should be executed
			_ev = ev;				//event associated with this node
			_next = 0;				//pointer to the next event in the sequence of events
		}
		Time _time;
		Event *_ev;
		EventNode *_next;
	};
	EventNode *_first;				//pointer to the first event in the EventSet
};

Time SimObj::GetCurrentSimTime()
{
	return SimObj::_currentTime;	//returns the current simulation time
}

void SimObj::RunSimulation()
{
	//while (_eventSet.HasEvent())
//	{
		Event *event = _eventSet.GetEvent();   // access next event in the eventset
		cout << "Event: " << &event << " executed at time: " << GetCurrentSimTime() << endl; // execute code
		_eventSet.GetTime(); // update system to find next event
		// update time to time of next event
	//}

}

void SimObj::RunSimulation(Time endTime)
{
	while (_eventSet.HasEvent() == true && GetCurrentSimTime() <= endTime) 
	{
		Event *ev = _eventSet.GetEvent();   // access next event in the eventset
		cout << "Event: " << &ev << " executed at time: " << GetCurrentSimTime() << endl; // execute code
		_eventSet.GetTime(); 
	}
//update system to find next event
// acces next event in the eventset

	// update system to find next event

	// update time to time of next event
}

Time SimObj::_currentTime = 0.0;	//initializes simulation time to zero at the start of the simulation

SimObj::EventSet SimObj::_eventSet;	//instantiates the eventSet at the start of the simulation

SimObj::SimObj()
{
	//don't put anything in here for assignment 4
}

void SimObj::ScheduleEventIn(Time deltaTime, Event * ev)
{
	Time time = deltaTime + GetCurrentSimTime();
	_eventSet.AddEvent(time, ev);
}

void SimObj::ScheduleEventAt(Time time, Event * ev)
{
	_eventSet.AddEvent(time, ev);
	cout << "Event: " << &ev << " scheduled for time: " << time << endl;
}
