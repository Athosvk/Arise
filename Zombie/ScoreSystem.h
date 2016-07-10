#pragma once
#include <Artifact/Core/System.h>

class ScoreComponent;
class HealthComponent;

class ScoreSystem : public Artifact::System
{
public:
    ScoreSystem(Artifact::EntitySystem& a_EntitySystem, Artifact::MessagingSystem& a_MessagingSystem);

    virtual void registerListeners() override;
private:
    void onScoreComponentAdd(Artifact::ComponentHandle<ScoreComponent> a_ScoreComponent) const;
    void onEnemyDeath(Artifact::GameObject a_Enemy) const;
};

