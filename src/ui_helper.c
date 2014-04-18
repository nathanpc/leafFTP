/**
 *  ui_helper.c
 *  Helper functions to manipulate the UI.
 *
 *  @author Nathan Campos <nathanpc@dreamintech.net>
 */

#include "ui_helper.h"

void initUI(WINDOW **win, CDKSCREEN **screen) {
	*win = initscr();
	*screen = initCDKScreen(*win);
	initCDKColor();
}

void createListBox(CDKSCREEN **screen, CDKSCROLL **listBox, char *items[], int count) {
	*listBox = newCDKScroll(*screen, CENTER, CENTER, RIGHT,
							10, 50, "ncurses + CDK Test", items, 3,
							FALSE, A_REVERSE, TRUE, FALSE);

	// Check if the Selection was create successfully.
	if (listBox == NULL) {
		destroyCDKScreen(*screen);
		endCDK();

		printf("Oops. Couldn't create a item list. Maybe the window is too small.\n");
		exit(EXIT_FAILURE);
	}
}
