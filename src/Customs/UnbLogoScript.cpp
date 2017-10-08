/**
	@file UnbLogoScript.cpp
	@brief Creates the UnB's symbol that shows up during the game opening.
	@copyright MIT License.
*/
#include "Customs/UnbLogoScript.hpp"
#include "Globals/EngineGlobals.hpp"

/**
    @brief Constructor for the classe UnbLogoScript.
*/
UnbLogoScript::UnbLogoScript(GameObject *owner) : Script(owner) {}

/**
    @brief Sets the initial definitions when starting the animation.
*/
void UnbLogoScript::Start() {
    // Creates the logo animations.
    CreateAnimations();
    // Get the position and the animator of the logo
    m_position = GetOwner()->GetPosition();
    m_animator = (Animator *)GetOwner()->GetComponent("Animator");
    // Get the inputs.
    m_input = InputSystem::GetInstance();
    m_gameController = m_input->GetGameController(0);
    // Set the zoom of the logo.
    GetOwner()->SetZoomProportion(Vector(0,0));

}

/**
    @brief Generates the animations on the screen.
*/
void UnbLogoScript::CreateAnimations() {
    // Set the animation of the logo.
    auto unb_LogoSprite = new Image("assets/introunb.png", 0, 0, 5115, 512);
    auto unbAnimation = new Animation(GetOwner(), unb_LogoSprite);
    for (int i = 0; i < 15; i++) {
        // Change frames in the animation.
        unbAnimation->AddFrame(new Frame(i * 341, 0, 341, 256));
    }
    for (int i = 0; i < 15; i++) {
        // Change frames in the animation.
        unbAnimation->AddFrame(new Frame(i * 341, 256, 341, 256));
    }

    // Set the animator of the logo.
    auto unbAnimator = new Animator(GetOwner());
    unbAnimation->SetFramesPerSecond(9);
    unbAnimator->AddAnimation("UNB ANIMATION", unbAnimation);
}

/**
    @brief Handles with changes on the component.
*/
void UnbLogoScript::ComponentUpdate() {
    if (m_gameController) {
        if (m_gameController->GetButtonDown(GC_INPUT_X)) {
            // Change the scene during the logo presentation.
            SceneManager::GetInstance()->SetCurrentScene("Main");
        }
    }
    if (m_input->GetKeyPressed(INPUT_RETURN)) {
        // Change the scene during the logo presentation.
        SceneManager::GetInstance()->SetCurrentScene("Main");
    }

}

/**
    @brief Updates the component's status every second and stops the animations
    after 100 seconds.
*/
void UnbLogoScript::FixedComponentUpdate() {
    m_time.Update(1);

    m_animator->PlayAnimation("UNB ANIMATION");

    if (m_time.GetTime()>=100) {
        m_animator->StopAllAnimations();
    }
}
