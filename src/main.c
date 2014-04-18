/**
 *  leafFTP
 *  A simple and lightweight, ncurses-based, FTP client.
 *
 *  @author Nathan Campos <nathanpc@dreamintech.net>
 */

#include <ncurses.h>
#include <cdk/cdk.h>

#include "ui_helper.h"

int main(int argc, char **argv) {
	WINDOW *win = NULL;
	CDKSCREEN *cdkScreen = NULL;
	CDKSCROLL *listBox = NULL;

	// Initialize the windows.
	initUI(&win, &cdkScreen);

	// Creates the list box.
	char *items[] = { "Hello", "World", "Test" };
	createListBox(&cdkScreen, &listBox, items, 3);

	// Get selection.
	int selection = activateCDKScroll(listBox, NULL);
	if (listBox->exitType == vESCAPE_HIT) {
		char *msg[] = { "<C>No items selected.", "", "<C>Press any key to continue." };
		popupLabel(cdkScreen, msg, 3);
	} else if (listBox->exitType == vNORMAL) {
		char buffer[100];
		sprintf(buffer, "<C>You've selected: %s", items[selection]);
		char *msg[] = { buffer, "", "<C>Press any key to continue." };
		popupLabel(cdkScreen, msg, 3);
	}

	// Clean up.
	destroyCDKScroll(listBox);
	destroyCDKScreen(cdkScreen);
	delwin(win);
	endCDK();

	return EXIT_SUCCESS;
}
