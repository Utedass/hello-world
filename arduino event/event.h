#include "static_counter.h"


#ifndef EVENT_H_
#define EVENT_H_

#define GG_EVENT( name ) \
counter_inc( gg_event_counter ); \
class name : public GG_Event_Base<counter_read( gg_event_counter )>

struct gg_event_counter {};

class GG_Event
{
	public:
	GG_Event() {}
	
	virtual unsigned int get_type() = 0;
};

template <const int type_val>
class GG_Event_Base : public GG_Event
{
	public:
	GG_Event_Base() {}
	unsigned int get_type() { return id; }
	
	static const unsigned int id = type_val;
};
/*
template <const int type_val>
const unsigned int GG_Event<type_val>::id = counter_read( gg_event_counter );
counter_inc( gg_event_counter );
*/

GG_EVENT(Button_Event)
{
	public:
	Button_Event() {};
};

GG_EVENT(Keyboard_Event)
{
	public:
	Keyboard_Event() {};
};

#endif EVENT_H_