#pragma once
#include <Artifact/Core/Component.h>
#include <Artifact/Input/Keycode.h>

#include "WeaponComponent.h"

class PlayerInputComponent : public Artifact::Component
{
public:
    float MovementSpeed = 0.9f;
    Artifact::KeyCode MoveUpKey;
    Artifact::KeyCode MoveDownKey;
    Artifact::KeyCode MoveLeftKey;
    Artifact::KeyCode MoveRightKey;
    Artifact::KeyCode FireKey;
	Artifact::ComponentHandle<WeaponComponent> Weapon = Artifact::ComponentHandle<WeaponComponent>::NullHandle;

public:
    PlayerInputComponent(Artifact::GameObject a_GameObject);
};

