#include "raylib.h"
#include "Projectile.h"

void Projectile::fire(const ShotSettings& _settings)
{
	configurePhysics();
	cyclone::RigidBody& body = Body();
	body.setPosition(_settings.origin);

	cyclone::Vector3 dir = _settings.direction;
	if (dir.squareMagnitude() > 0.0f)
	{
		dir.normalise();
	}
	body.setVelocity(dir * _settings.speed);
	body.setRotation(cyclone::Vector3(0.0f, 0.0f, 0.0f));
	body.clearAccumulators();
	body.calculateDerivedData();
	m_sphere.calculateInternals();
}

void Projectile::draw() const
{
	cyclone::RigidBody& body = const_cast<Projectile*>(this)->Body();
	cyclone::Vector3 pos = body.getPosition();
	::Vector3 draw_pos{
		static_cast<float>(pos.x),
		static_cast<float>(pos.y),
		static_cast<float>(pos.z) };
	DrawSphere(draw_pos, static_cast<float>(m_sphere.radius), DARKGRAY);
}

void Projectile::registerPhysics(SceneObjects& _world)
{

}

void Projectile::ConfigureSphereBody(cyclone::real _mass, 
									cyclone::real _radius)
{
	cyclone::RigidBody& body = Body();
	body.setMass(_mass);
	body.setDamping(0.99f, 0.99f);
	body.setAcceleration(cyclone::Vector3(0.0f, -9.81f, 0.0f));

	cyclone::real coeff = 0.4f * _mass * _radius * _radius;
	cyclone::Matrix3 inertia;
	inertia.setDiagonal(coeff, coeff, coeff);
	body.setInertiaTensor(inertia);
	body.setAwake(true);

	m_sphere.body = &body;
	m_sphere.radius = _radius;
}
