#include <SDL/SDL.h>
#define	ERROR(str, ...) fprintf(stderr, str, __VA_ARGS__)
#define true 1
#define false 0
#define SCR_W 320
#define SCR_H 240

int				running;
Uint32			tick, oldtick;
SDL_Surface*	screen;
SDL_Event		event;
Uint8			key_held[SDLK_LAST] = {0};

void init	(int argc, char* argv[]);
void update	(void);
void quit	(void);
void draw	(void);

int main(int argc, char* argv[]) {
	init(argc, argv);
	while(running) {
		while(SDL_PollEvent(&event)) {
	        switch(event.type) {
            case SDL_KEYDOWN:
				key_held[event.key.keysym.sym] = true;
                switch( event.key.keysym.sym ) {
				case SDLK_LEFT:		break;
				case SDLK_RIGHT:	break;
				case SDLK_UP:		break;
				case SDLK_DOWN:		break;
				case SDLK_SPACE:	break;
				case SDLK_ESCAPE:	running = 0;
				default:			break;
                } break;
			case SDL_KEYUP:	key_held[event.key.keysym.sym] = false;	break;
			case SDL_QUIT:	running = 0;
	        }
	    }
		tick = SDL_GetTicks();
		if((tick-oldtick) >= 20) {
			oldtick = tick;
			update();
			draw();
		}
	}
	quit();
    return 0;
}

void
init(int argc, char* argv[]) {
	if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER) < 0) {
        ERROR("Couldn't initialize SDL: %s\n", SDL_GetError());
        exit(1);
    }
	atexit(SDL_Quit);
	SDL_WM_SetCaption("Man of Shit", 0);
	if(!(screen = SDL_SetVideoMode(SCR_W, SCR_H, 32, SDL_SWSURFACE|SDL_DOUBLEBUF))) {
        ERROR("Couldn't set %ix%ix32 video mode: %s\n", SCR_W, SCR_H, SDL_GetError());
        exit(1);
    }
	running = 1;
    oldtick = SDL_GetTicks();
}

void
update(void) {
	if(key_held[SDLK_SPACE]) {
	}
}

void
draw(void) {
	Uint32* px = screen->pixels, x, y;
	SDL_FillRect(screen,0,0x000080ff);
	for(y=0;y<SCR_H;++y)
	for(x=0;x<SCR_W;++x) {
		*px++ = x^y;
	}
	SDL_Flip(screen);
}

void
quit(void) {
}
