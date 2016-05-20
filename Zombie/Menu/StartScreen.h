#pragma once
#include <Artifact/Core/World.h>

namespace Artifact
{
    class AudioSource;
}

class StartScreen : public Artifact::World
{
private:
    Artifact::ComponentHandle<Artifact::AudioSource> m_BackgroundMusic = Artifact::ComponentHandle<Artifact::AudioSource>::NullHandle;
    Artifact::GameObject m_ControlsPopup;

public:
    StartScreen(Artifact::GameTime& a_GameTime, Artifact::Game* a_CurrentGame);
    virtual ~StartScreen() override;

private:
    void handleInput();
    void initializeOptions();
    void initializePopup();
};

