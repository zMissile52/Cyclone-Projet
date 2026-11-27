#include "Projectile.h"

#include "raylib.h"

void Projectile::Fire(const ShotSettings& _settings)
{
    ConfigurePhysics();
    cyclone::RigidBody& body = Body();
    body.setPosition(_settings.origin);

    cyclone::Vector3 dir = _settings.direction;
    if (dir.squareMagnitude() > 0.0)
    {
        dir.normalise();
    }
    body.setVelocity(dir * static_cast<cyclone::real>(_settings.speed));
    body.setRotation(cyclone::Vector3(0.0, 0.0, 0.0));
    body.clearAccumulators();
    body.calculateDerivedData();
    m_sphere.calculateInternals();
}

void Projectile::Draw() const
{
    const cyclone::Vector3 pos = GetBody().getPosition();
    const ::Vector3 draw_pos{
        static_cast<float>(pos.x),
        static_cast<float>(pos.y),
        static_cast<float>(pos.z) };
    DrawSphere(draw_pos, static_cast<float>(m_sphere.radius), DARKGRAY);
}

void Projectile::RegisterPhysics(SceneObjects& /*_world*/)
{
}

void Projectile::ConfigureSphereBody(cyclone::real _mass,
    cyclone::real _radius)
{
    cyclone::RigidBody& body = Body();
    body.setMass(_mass);
    body.setDamping(0.99, 0.99);
    body.setAcceleration(cyclone::Vector3(0.0, -9.81, 0.0));

    const cyclone::real coeff = static_cast<cyclone::real>(0.4) * _mass *
        _radius * _radius;
    cyclone::Matrix3 inertia;
    inertia.setDiagonal(coeff, coeff, coeff);
    body.setInertiaTensor(inertia);
    body.setAwake(true);

    m_sphere.body = &body;
    m_sphere.radius = _radius;
}