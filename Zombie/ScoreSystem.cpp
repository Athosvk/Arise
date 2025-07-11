#include <Artifact/Core/EntitySystem.h>

#include "ScoreSystem.h"
#include "ScoreComponent.h"
#include "HealthComponent.h"
#include "Player/PlayerComponent.h"
#include "Player/PlayerScoreComponent.h"

ScoreSystem::ScoreSystem(Artifact::EntitySystem & a_EntitySystem, Artifact::MessagingSystem & a_MessagingSystem)
    : System(a_EntitySystem, a_MessagingSystem)
{
}

void ScoreSystem::registerListeners()
{
    using namespace Artifact;
    m_MessagingSystem.registerListener<ComponentAddedMessage<ScoreComponent>>([this](const Message* a_Message)
    {
        onScoreComponentAdd(static_cast<const ComponentAddedMessage<ScoreComponent>*>(a_Message)->getAddedComponent());
    });
}

void ScoreSystem::onScoreComponentAdd(Artifact::ComponentHandle<ScoreComponent> a_ScoreComponent) const
{
    a_ScoreComponent->getComponent<HealthComponent>()->OnDeath += [this](Artifact::GameObject a_GameObject)
    {
        onEnemyDeath(a_GameObject);
    };
}

void ScoreSystem::onEnemyDeath(Artifact::GameObject a_Enemy) const
{
    auto awardedScore = a_Enemy.getComponent<ScoreComponent>()->Amount;
    m_EntitySystem.getComponentsOfType<PlayerScoreComponent>()[0]->CurrentScore += awardedScore;
}
