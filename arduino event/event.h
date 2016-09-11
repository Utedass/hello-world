#include "static_counter.h"

struct gg_event_counter {};

class GG_Event_Base
{
	public:
	GG_Event_Base() {}
	
	virtual unsigned int get_type() = 0;
};

template <const int type_val>
class GG_Event : public GG_Event_Base
{
	public:
	GG_Event() {}
	unsigned int get_type() { return id; }
	
	static const unsigned int id = type_val;
};
/*
template <const int type_val>
const unsigned int GG_Event<type_val>::id = counter_read( gg_event_counter );
counter_inc( gg_event_counter );
*/

class Button_Event : public GG_Event<counter_read( gg_event_counter )>
{
	public:
	Button_Event() {};
};
counter_inc( gg_event_counter );

class Keyboard_Event : public GG_Event<counter_read( gg_event_counter )>
{
	public:
	Keyboard_Event() {};
};
counter_inc( gg_event_counter );