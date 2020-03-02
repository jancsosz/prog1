#include <stdio.h>
#include <curses.h>
#include <unistd.h>

int main(void){

	WINDOW *ablak;
	ablak = initscr();
	
	int x = 0; 
	int y = 0; 

	int deltax=1;
	int deltay=1;

	int mx;
	int my;

	for ( ;; ) {

		getmaxyx ( ablak, my ,mx );

		mvprintw ( y, x, "o");

		refresh();
		usleep(50000);

		clear();

		x = x + deltax;
		y = y + deltay;

		if (x<=0) {deltax = deltax*-1;}

		if (y<=0) {deltay = deltay*-1;}

		if (y>=my-1) {deltay = deltay*-1;}

		if (x>=mx-1) {deltax = deltax*-1;}

	}

}
		

