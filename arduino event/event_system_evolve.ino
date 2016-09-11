#include "static_counter.h"
#include "event.h"


int const a = counter_read( gg_event_counter );
counter_inc( gg_event_counter );

int const b = counter_read( gg_event_counter );
counter_inc( gg_event_counter );


void setup()
{
	Serial.begin(9600);
	
	Serial.println("Up n' runnin!");
	
	Button_Event *butt = new Button_Event();
	Keyboard_Event *keyb = new Keyboard_Event();
	GG_Event_Base *e = keyb;
	
	
	Serial.println(a);
	Serial.println(b);
	Serial.println(e->get_type());
	Serial.println(keyb->get_type());
	
	
	switch (e->get_type())
	{
	case Button_Event::id:
		Serial.println("DUde! Button!");
		break;
	case Keyboard_Event::id:
		Serial.println("DUde! Keyboard!");
		break;
	} 
	
}

void loop()
{

  /* add main program code here */

}
