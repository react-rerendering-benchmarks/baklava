#include "pch.h"

bool fadeToGame()
{
	Rectangle fadeRec1 = { GetScreenWidth() * -1, 0, GetScreenWidth(), GetScreenHeight() / 4};
	Rectangle fadeRec2 = { GetScreenWidth(), GetScreenHeight() / 4, GetScreenWidth(), GetScreenHeight() / 4};
	Rectangle fadeRec3 = { GetScreenWidth() * -1, GetScreenHeight() / 4 * 2, GetScreenWidth(), GetScreenHeight() / 4};
	Rectangle fadeRec4 = { GetScreenWidth(), GetScreenHeight() / 4 * 3, GetScreenWidth(), GetScreenHeight() / 4};

	bool closeFlag = false;

	while (fadeRec4.x > -720 && !WindowShouldClose())
	{
		BeginDrawing();

		fadeRec1.x += 2220.0f * GetFrameTime();
		DrawRectangleRec(fadeRec1, BLACK);

		fadeRec2.x -= 2220.0f * GetFrameTime();
		DrawRectangleRec(fadeRec2, BLACK);

		fadeRec3.x += 2220.0f * GetFrameTime();
		DrawRectangleRec(fadeRec3, BLACK);

		fadeRec4.x -= 2220.0f * GetFrameTime();
		DrawRectangleRec(fadeRec4, BLACK);
		
		EndDrawing();
	}
	
	if (fadeRec4.x <= -720) return true;
	else return false;
}

bool mainMenuLoop()
{
	Font mainFont = LoadFontEx("assets/fonts/MainFont.ttf", 54, NULL, 0);
	SetTextureFilter(mainFont.texture, TEXTURE_FILTER_BILINEAR);

	//Declare the play button
	Button playButton;
	playButton.rec = { -6, 251, 319, 109 };
	playButton.state = 0;
	playButton.color = CLITERAL(Color){ 194, 51, 51, 255 };
	playButton.hoverColor = CLITERAL(Color) { 154, 11, 11, 255 };

	//Declare the quit button
	Button quitButton;
	quitButton.rec = { -6, 421, 319, 109 };
	quitButton.state = 0;
	quitButton.color = CLITERAL(Color) { 158, 47, 197, 255 };
	quitButton.hoverColor = CLITERAL(Color) { 138, 17, 167, 255 };


	while (!WindowShouldClose())
	{
		BeginDrawing();

		//Clear the image
		ClearBackground(RAYWHITE);

		//Draw the background gradient
		DrawRectangleGradientH(0, 0, GetScreenWidth(), GetScreenHeight(), CLITERAL(Color){ 2, 171, 58, 255 }, CLITERAL(Color) { 1, 97, 33, 255 });
		DrawRectangleGradientV(0, 0, GetScreenWidth(), GetScreenHeight(), CLITERAL(Color){ 2, 171, 58, 123 }, CLITERAL(Color) { 1, 97, 33, 123 });

		//Draw the title
		DrawTextEx(mainFont, "Baklava TD", Vector2({ GetScreenWidth() / 2 - MeasureTextEx(mainFont, "Baklava TD", 78, 0).x / 2, 51}), 78, 0, RAYWHITE);

		//Act according to user actions
		if (handleButton(playButton, 309, false, true))
		{
			if (fadeToGame()) return true;
			else return false;
		}
		if (handleButton(quitButton, 309, false, true)) return false;

		//Draw text over buttons
		DrawTextEx(mainFont, "Play", Vector2({ playButton.rec.x + (playButton.rec.width / 12), playButton.rec.y + (playButton.rec.height / 4) }), 54, 0, RAYWHITE);
		DrawTextEx(mainFont, "Quit", Vector2({ quitButton.rec.x + (quitButton.rec.width / 15), quitButton.rec.y + (quitButton.rec.height / 4) }), 54, 0, RAYWHITE);

		EndDrawing();
	}

	UnloadFont(mainFont);

	CloseWindow();

	return false;
}