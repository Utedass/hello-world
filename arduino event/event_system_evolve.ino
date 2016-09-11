#include "static_counter.h"
#include "event.h"
#include "more_events.h"


int const a = counter_read( gg_event_counter );
counter_inc( gg_event_counter );

int const b = counter_read( gg_event_counter );
counter_inc( gg_event_counter );

void setup()
{
	Serial.begin(9600);
	
	Serial.println("Up n' runnin!");
	
	Laser_Event *laser = new Laser_Event();
	Button_Event *butt = new Button_Event();
	Keyboard_Event *keyb = new Keyboard_Event();
	
	GG_Event *e = laser;
	
	
	Serial.println(Button_Event::id);
	Serial.println(Keyboard_Event::id);
	Serial.println(Laser_Event::id);
	Serial.println(a);
	Serial.println(b);
	
	
	switch (e->get_type())
	{
	case Button_Event::id:
		Serial.println("DUde! Button!");
		break;
	case Keyboard_Event::id:
		Serial.println("DUde! Keyboard!");
		break;
	case Laser_Event::id:
		Serial.println("DUde! LASER!");
		break;
	} 
	
}

void loop()
{

  /* add main program code here */

}
