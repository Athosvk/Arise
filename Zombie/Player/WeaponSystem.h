#pragma once
#include <Artifact/Core/System.h>

#include "../EntityPool.h"
#include "../Bullet.h"

class BulletComponent;
class WeaponComponent;

class FireWeaponMessage : public Artifact::Message
{
    Artifact::ComponentHandle<WeaponComponent> m_WeaponComponent;

public:
    FireWeaponMessage(Artifact::ComponentHandle<WeaponComponent> a_WeaponComponent);

	Artifact::ComponentHandle<WeaponComponent> getWeapon() const;
};

class WeaponSystem : public Artifact::System
{
private:
    EntityPool<Bullet> m_BulletPool;
public:
    WeaponSystem(Artifact::EntitySystem& a_EntitySystem, Artifact::MessagingSystem& a_MessagingSystem);

    virtual void registerListeners() override;
private:
    void tryFire(const FireWeaponMessage* a_FireMessage);
    void fire(Artifact::ComponentHandle<WeaponComponent> a_Weapon);
    void createBullet(const Artifact::ComponentHandle<Artifact::Transform> a_MuzzleTransform);
};

