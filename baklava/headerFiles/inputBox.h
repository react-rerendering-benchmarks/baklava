#pragma once

/// Stores the information required for displaying the input box
struct InputBoxInfo
{
	char input[5] = {' ', ' ', ' ', ' '};
	int numCount = 0;
	Rectangle textBox;
};

/// Displayes the input box
/// 
/// This function displays the input box. The input box is limited by a char array with 5 available spaces, 4 for input and 1 for the null terminating character.
/// @param input struct whitch contains the requared information for drawing the input box
/// @see InputBoxInfo
void drawInputBox(InputBoxInfo &input);

/// Convertes the player answer to int
/// 
/// This function converts the player's answer from array char to int so it could be compared to the actual answer.
/// @param inputBox the information for the input box.
/// @return player answer as an int
/// @see InputBoxInfo
int convertedPlayerAnswer(InputBoxInfo &inputBox);
