#include "pch.h"

bool showDefeatScreen()
{
	//Transition Timer
	int mmFadeTimer = 255;

	//Load font and configure upscaling
	Font mainFont = LoadFontEx("assets/fonts/MainFont.ttf", 54, NULL, 0);
	SetTextureFilter(mainFont.texture, TEXTURE_FILTER_BILINEAR);

	//Declare the play button
	Button playButton;
	playButton.rec = { GetScreenWidth() / 3.6f, GetScreenHeight() / 1.7f, 292, 113 };
	playButton.state = 0;
	playButton.color = CLITERAL(Color) { 2, 171, 58, 255 };
	playButton.hoverColor = CLITERAL(Color) { 0, 141, 28, 255 };
	Vector2 playButtonSize = MeasureTextEx(mainFont, "Try Again", 54, 0);

	//Declare the quit button
	Button quitButton;
	quitButton.rec = { GetScreenWidth() / 1.7f, GetScreenHeight() / 1.7f, 292, 113};
	quitButton.state = 0;
	quitButton.color = CLITERAL(Color) { 194, 51, 51, 255 };
	quitButton.hoverColor = CLITERAL(Color) { 164, 21, 21, 255 };
	Vector2 quitButtonSize = MeasureTextEx(mainFont, "Quit", 54, 0);

	while (!WindowShouldClose())
	{
		BeginDrawing();

		//Clear the image
		ClearBackground(BLACK);

		//Draw the title
		DrawTextEx(mainFont, "You died!", Vector2({ GetScreenWidth() / 2 - MeasureTextEx(mainFont, "You died!", 78, 0).x / 2, 304}), 78, 0, RED);

		//Act according to user actions
		if (handleButton(playButton, 292, true, false))
		{
			return true;
		}
		if (handleButton(quitButton, 292, true, false)) return false;

		//Draw text over buttons
		DrawTextEx(mainFont, "Try Again", Vector2({ (playButton.rec.x + (playButton.rec.width / 2)) - playButtonSize.x / 2 , (playButton.rec.y + (playButton.rec.height / 2)) - playButtonSize.y / 2 }), 54, 0, RAYWHITE);
		DrawTextEx(mainFont, "Quit", Vector2({ (quitButton.rec.x + (quitButton.rec.width / 2)) - quitButtonSize.x / 2, (quitButton.rec.y + (quitButton.rec.height / 2)) - quitButtonSize.y / 2 }), 54, 0, RAYWHITE);

		if (mmFadeTimer > 0)
		{
			mmFadeTimer -= 5;
			DrawRectangle(0, 0, 1280, 720, CLITERAL(Color){ 0, 0, 0, (unsigned char)mmFadeTimer});
		}

		EndDrawing();
	}

	UnloadFont(mainFont);

	return false;
}