/*
 * more_events.h
 *
 * Created: 2016-09-12 01:25:05
 *  Author: Jonatan
 */ 
#include "static_counter.h"
#include "event.h"


#ifndef MORE_EVENTS_H_
#define MORE_EVENTS_H_


//class Laser_Event : public GG_Event_Base<counter_read( gg_event_counter )>
GG_EVENT(Laser_Event)
{
	public:
	Laser_Event() {};
};


#endif /* MORE_EVENTS_H_ */