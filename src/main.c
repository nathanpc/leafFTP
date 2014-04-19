/**
 *  leafFTP
 *  A simple and lightweight, ncurses-based, FTP client.
 *
 *  @author Nathan Campos <nathanpc@dreamintech.net>
 */

#include <ncurses.h>
#include <cdk/cdk.h>

#include "ui_helper.h"

void loopUI();

WINDOW *win = NULL;
CDKSCREEN *cdkScreen  = NULL;
CDKSCROLL *listBox    = NULL;
CDKLABEL  *msgLabel   = NULL;
CDKENTRY  *txtCommand = NULL;

char *items[] = { "Folder 1", "Folder 2", "Folder 3", "File 1.txt", "File 2.bin" };

int main(int argc, char **argv) {
	// Initialize the windows.
	initUI(&win, &cdkScreen);

	// Create the list box.
	createListBox(&cdkScreen, &listBox, items, 5);

	// Create the server status label.
	createMessageLabel(&cdkScreen, &msgLabel, "</B/24/>230 Login successful.");
	drawCDKLabel(msgLabel, FALSE);

	// Create the command entry box.
	createCommandEntry(&cdkScreen, &txtCommand);

	loopUI();

	// Clean up.
	destroyCDKScroll(listBox);
	destroyCDKScreen(cdkScreen);
	delwin(win);
	endCDK();

	return EXIT_SUCCESS;
}

void loopUI() {
	while (true) {
		// Get selection.
		int selection = activateCDKScroll(listBox, NULL);
		if (listBox->exitType == vNORMAL) {
			// TODO: Open menu with options of what to do with the file or folder!


			char buffer[100];
			sprintf(buffer, "<C>You've selected: %s", items[selection]);
			char *msg[] = { buffer, "", "<C>Press any key to continue." };
			popupLabel(cdkScreen, msg, 3);

			break;
		}

		// Get command.
		char *text = activateCDKEntry(txtCommand, NULL);
		if (txtCommand->exitType == vNORMAL) {
			char *msg[3] = { text, "", "<C>Press any key to continue." };
			popupLabel(cdkScreen, msg, 3);

			break;
		}
	}
}
