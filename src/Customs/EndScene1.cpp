#include "Customs/EndScene1.hpp"
//#include "Customs/MenuAnimationScript.hpp"

/**
    @file EndScene1.cpp
    @brief Methods that manages the game over scene with a 'quit' button.
    @copyright LGPL. MIT License.
*/

// Constructor
EndScene1::EndScene1() {}

/**
    @brief On activation of the game over scene, creates 'quit' button.
*/
void EndScene1::OnActivation() {
    m_width_middle = EngineGlobals::screen_width / 2;
    m_height_middle = EngineGlobals::screen_height / 2;
    CreateGameOver();
    CreateQuitButton();
}

/**
    @brief Method for handling deactivation state changing.

*/
void EndScene1::OnDeactivation() {}

/**
    @brief Method for handling showing state changing.
*/
void EndScene1::OnShown() {}

/**
    @brief Method for handling on hidden state changing.
*/
void EndScene1::OnHidden() {}

/**
    @brief Creates game over scene.
*/
void EndScene1::CreateGameOver() {
    // defines the current center position
    int xMiddle = EngineGlobals::screen_width / 2 - 240;
    auto gameOver = new GameObject("Logo", new Vector(xMiddle,0), 500, 500,1);
    auto playText = new UIText(gameOver, "GAME OVER", "assets/Fonts/mini-pixel-7/mini-pixel-7.ttf",
                               200, 255, 255, 255, 150, 1);
  AddGameObject(gameOver);
}

/**
    @brief Creates 'quit' button on the middle of the screen.
*/
void EndScene1::CreateQuitButton() {
    // defines the current center position
    int xMiddle = EngineGlobals::screen_width / 2 - 100;
    auto quit = new GameObject("Quit", new Vector(xMiddle, 500), 200, 100,1);
    auto quitText = new UIText(quit, "Quit", "assets/Fonts/mini-pixel-7/mini-pixel-7.ttf",
                             200, 255, 255, 255, 150, 1);
    auto quitButton = new UIButton(quit);
    auto quitSound = new UISound(quit, "playSound", "assets/Audio/Button/MusicButton1.wav", false, false);
    auto script = new QuitButtonScript(quit);

    AddGameObject(quit);
}
