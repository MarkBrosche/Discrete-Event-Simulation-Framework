#include "Simulation.h"
#include "Queue.h"
#include <iostream>
using namespace std;

void main()
{
	Queue queue;										// Creates a SimObj called queue
	queue.ScheduleEventAt(1.0, queue.CreateEvent());	// adds a new Queue event to the eventSet
	queue.ScheduleEventAt(3.0, queue.CreateEvent());
	queue.ScheduleEventAt(2.0, queue.CreateEvent());
	queue.ScheduleEventAt(5.0, queue.CreateEvent());
	queue.ScheduleEventAt(4.0, queue.CreateEvent());
	SimObj::RunSimulation(5.0);							// runs the simulation until no events are left

	cout << "<enter> to terminate." << endl;
	cin.get();											// pauses the simulation to keep the window open
}