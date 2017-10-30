#include "Queue.h"

Queue::Queue()
{

}

Event * Queue::CreateEvent()
{
	return new Event();
}

