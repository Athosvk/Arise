#pragma once
#include <Artifact/Core/Component.h>
#include <Artifact/Transform.h>

#include "../TimerComponent.h"

class WeaponComponent : public Artifact::Component
{
public:
	Artifact::ComponentHandle<Artifact::Transform> MuzzleTransform = Artifact::ComponentHandle<Artifact::Transform>::NullHandle;
    Artifact::ComponentHandle<TimerComponent> FireDelayTimer;

public:
    WeaponComponent(Artifact::GameObject a_GameObject);
};

