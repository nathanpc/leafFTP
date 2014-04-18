/**
 *  ui_helper.h
 *  Helper functions to manipulate the UI.
 *
 *  @author Nathan Campos <nathanpc@dreamintech.net>
 */

#ifndef _UI_HELPER_H
#define _UI_HELPER_H

#include <ncurses.h>
#include <cdk/cdk.h>

void initUI(WINDOW **win, CDKSCREEN **screen);
void createListBox(CDKSCREEN **screen, CDKSCROLL **listBox, char *items[], int count);

#endif
