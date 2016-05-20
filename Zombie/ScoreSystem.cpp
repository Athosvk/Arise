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
    a_ScoreComponent->getComponent<HealthComponent>()->OnDeath += [this](Artifact::ComponentHandle<HealthComponent> a_Health)
    {
        onEnemyDeath(a_Health);
    };
}

void ScoreSystem::onEnemyDeath(Artifact::ComponentHandle<HealthComponent> a_EnemyHealth) const
{
    auto awardedScore = a_EnemyHealth->getComponent<ScoreComponent>()->Amount;
    m_EntitySystem.getComponentsOfType<PlayerScoreComponent>()[0]->CurrentScore += awardedScore;
}
