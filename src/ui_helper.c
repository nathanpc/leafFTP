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
	*listBox = newCDKScroll(*screen, LEFT, TOP, RIGHT,
							LINES - 2, COLS, "/home/nathanpc", items,
							count, FALSE, A_REVERSE, TRUE, FALSE);

	// Check if the Selection was create successfully.
	if (*listBox == NULL) {
		destroyCDKScreen(*screen);
		endCDK();

		printf("Oops. Couldn't create a item list. Maybe the window is too small.\n");
		exit(EXIT_FAILURE);
	}
}

void createMessageLabel(CDKSCREEN **screen, CDKLABEL **label, char *text) {
	char *msgs[] = { text };
	*label = newCDKLabel(*screen, LEFT, LINES - 2, msgs, 1, FALSE, FALSE);

	if (*label == NULL) {
		destroyCDKScreen(*screen);
		endCDK();

		printf("Oops. Couldn't create a label.\n");
		exit(EXIT_FAILURE);
	}
}

void createCommandEntry(CDKSCREEN **screen, CDKENTRY **entry) {
	*entry = newCDKEntry(*screen, LEFT, BOTTOM, NULL, "</B/>> <!B>",
						 A_NORMAL, ' ', vMIXED, 0, 0, 256, FALSE, FALSE);

	if (*entry == NULL) {
		destroyCDKScreen(*screen);
		endCDK();

		printf("Oops. Couldn't create a entry field.\n");
		exit(EXIT_FAILURE);
	}
}
