#pragma once
#include <Artifact/Core/Component.h>
#include <Artifact/Delegate.h>

class HealthComponent : public Artifact::Component
{
private:
    unsigned m_CurrentHealth = 0;
public:
    unsigned MaxHealth = 0;
    Artifact::Delegate<void(Artifact::GameObject a_GameObject)> OnDeath;
    Artifact::Delegate<void()> OnHit;

public:
    explicit HealthComponent(Artifact::GameObject a_GameObject);

    void initialise(unsigned a_MaxHealth);
    void dealDamage(unsigned a_Amount);
    unsigned getCurrentHealth() const;
};

