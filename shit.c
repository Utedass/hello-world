#include <stdlib.h>
typedef unsigned short nat16;
typedef unsigned int nat32;
#define MAX_SHIT 256
nat32 count = 0;
struct {
	nat16 x,y;
} stuf[MAX_SHIT];


void update_shit(nat32* s, nat32 w, nat32 h) {
	static int next = 1;
	if(!--next) {
		next = (rand()&15) + 1;
		if(count<MAX_SHIT) {
			stuf[count].x = rand()%w;
			stuf[count].y = rand()%h;
			++count;
		}
	}
	int n=0;
	while(n<count) {
		int r = rand();
		if((r&3)==3)r&=~2;
		stuf[n].x += (r&3)-1;
		r>>=2; if((r&3)==3)r&=~2;
		stuf[n].y += (r&3)-1;
		if(stuf[n].x >= w || stuf[n].y >= h ||
			(s[w*stuf[n].y+stuf[n].x]&0x808080) == 0x808080) {
			stuf[n] = stuf[--count];
			continue;
		}
		s[w*stuf[n].y+stuf[n].x] += 0x101010;
		s[n]=0xffffff;
		++n;
	}

}
