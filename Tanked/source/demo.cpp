/* ********************************************************************************* *
 * *                       SIT255 - Advanced Game Development                      * *
 * *                Assignment #1 - Develop a Software Framework                   * *
 * *                                for Agent-based Games                          * *
 * *                                                                               * *
 * *  This code is provided to students as a basic framework for the purposes of   * *
 * *  developing an agent-based game that meets the requirements of the assessment * *
 * *  guidelines. This code base does not provide all features necessary to        * *
 * *  complete the assessment task. Students must modify and extend this framework * *
 * *  to achieve the specific objectives of the task.                              * *
 * *                                                                               * *
 * *  The code is provided as-is and while significant efforts have been made to   * *
 * *  ensure that it is bug-free, this is not a guarantee. It is each student's    * *
 * *  responsibility to ensure that their final submission compiles and executes   * *
 * *  without error.                                                               * *
 * *                                                                               * *
 * *  COPYRIGHT NOTICE                                                             * *
 * *  ----------------                                                             * *
 * *  (C) [2012] - [2016] Deakin University                                        * *
 * *  All rights reserved.                                                         * *
 * *  All information contained herein is, and remains the property of Deakin      * *
 * *  University and the author (Tim Wilkin).                                      * *
 * *  Dissemination of this information or reproduction of this material is        * *
 * *  strictly forbidden unless prior written permission is obtained from Deakin   * *
 * *  University. The right to create derivative works from this material is       * *
 * *  hereby granted to students enrolled in SIT255, but only for the purposes of  * *
 * *  assessment while an enrolled student at Deakin University.                   * *
 * *                                                                               * *
 * ********************************************************************************* *
 * *  STUDENT ID:                                                                  * *
 * *  STUDENT NAME:                                                                * *
 * *  DATE:                                                                        * *
 * ********************************************************************************* *
 */



#include <iostream>
#include <fstream>
#include <string>

#include <time.h>
#include <vector>

#include "ui\WinCanvas.h"
#include "ui\WinTexture.h"
#include "ui\InputState.h"

#include "..\Tank.h"


// Constant values used in the code - this is the whole window size including
// menu buttons and border - actual graphics canvas size is smaller!
const unsigned int	WINDOW_WIDTH = 600;
const unsigned int	WINDOW_HEIGHT = 400;




// The main function of the program
int main()
{

	/**************************************************************************
	 *
	 *	Declare a WinCanvas object. We wouldn't normally create an object this way as
	 *  it is non-portable, but this is a very simple 'graphics canvas' interface to
	 *  the Windows Graphical Device Interface (GDI) API.
	 */

	WinCanvas wc(WINDOW_WIDTH, WINDOW_HEIGHT, L"My Demo");

	/*
	 *  An InputState object provides an interface to the Keyboard and Mouse devices.
	 */

	InputState	  ui;
	OpenUIHandler(ui);	// Initialise the input interface

	Tank frank(300,200);

	/*
 	 *  Execute a trivial application loop with rendering of a message (so we know it works)
	 */
	float xpos = 0;
	float ypos = WINDOW_HEIGHT/2.0;

	while (wc.IsActive())
	{
		wc.Clear(255, 255, 255);
	
		frank.update();
		frank.handleInput(ui);
		frank.render(wc);

		// display
		wc.Write(int(xpos)%WINDOW_WIDTH, ypos, "Hello World", LRGB(255, 0, 0));
		wc.Display();
	}
	/**************************************************************************/


	return 0;
}
