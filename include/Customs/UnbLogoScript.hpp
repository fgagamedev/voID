/**
    @file UnbLogoScript.hpp
    @brief Creates the UnB's symbol that shows up during the game opening.
    @copyright MIT License.
*/
#ifndef __UNB_LOGO_SCRIPT__
#define __UNB_LOGO_SCRIPT__


#include "Engine/Timer.hpp"
#include "Engine/GameController.hpp"
#include "Engine/GameObject.hpp"
#include "Engine/SceneManager.hpp"
#include "Engine/InputSystem.hpp"

#include "Components/Animator.hpp"
#include "Components/Script.hpp"
#include "Math/Vector.hpp"

#include <string>

class UnbLogoScript : public Script {

public:
    UnbLogoScript(GameObject *owner);
    std::string GetComponentName() override {
        return "UnbLogoScript";
    };
    void FixedComponentUpdate() override;
    void Start() override;

protected:
    void ComponentUpdate() override;

private:
    // Store the time.
    Timer time;
    void CreateAnimations();
    // Object for inputs in the snow activator script.
    InputSystem *input = nullptr;
    // Object for the inputs from the game controller.
    GameController* gameController = nullptr;
    // Animator for the UNB logo.
    Animator *animator = nullptr;
    // Object that store positions in the game.
    Vector *position = nullptr;
    // Attribute not used in the UnbLogoScript.
    int play = 0;
};
#endif
