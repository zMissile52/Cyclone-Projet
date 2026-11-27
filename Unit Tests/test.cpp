#include "pch.h"


// Test ObjectPool
TEST(ObjectPool, poolCapacity) {
	ObjectPool<int, 3> pool;

	EntityId a = pool.Create(10);
	EntityId b = pool.Create(20);
	EntityId c = pool.Create(30);

	EXPECT_ANY_THROW(pool.Create(40));

	EXPECT_EQ(10, pool.Get(a));
	EXPECT_EQ(20, pool.Get(b));
	EXPECT_EQ(30, pool.Get(c));
	c.slot = 3;
	EXPECT_THROW(pool.Get(c), std::length_error);

}

TEST(ObjectPool, RecycledSlot) {
	ObjectPool<int, 1> pool;
	
	EntityId a = pool.Create(7);

	EXPECT_EQ(7, pool.Get(a));

	pool.Destroy(a);
	EXPECT_THROW(pool.Get(a), std::length_error);


	EntityId b = pool.Create(42);
	EXPECT_NE(b, a);
}

TEST(ObjectPool, StaleHandleRejected) {
	ObjectPool<int, 1> pool;
	EntityId a = pool.Create(7);
	pool.Destroy(a);
	EntityId b = pool.Create(42);
	EXPECT_ANY_THROW(pool.Get(a));
	EXPECT_EQ(42, pool.Get(b));
	EXPECT_NE(7, pool.Get(b));
}

TEST(ObjectPool, LiveAdressStable) {
	ObjectPool<int, 3> pool;

	EntityId a = pool.Create(10);
	EntityId b = pool.Create(20);
	EntityId c = pool.Create(30);

	EXPECT_EQ(10, pool.Get(a));
	EXPECT_EQ(a, pool.GetId(0));
}

TEST(ObjectPool, ClearInvalidatesHandles) {
	ObjectPool<int, 2> pool;
	EntityId a = pool.Create(10);
	EntityId b = pool.Create(20);

	pool.Clear();

	EXPECT_ANY_THROW(pool.Get(a));
	EXPECT_ANY_THROW(pool.Get(b));
	EntityId c = pool.Create(30);

	EXPECT_EQ(30, pool.Get(c));
}


#include "OrbitCameraTest.inl"


#include "LauncherTest.inl"


TEST_F(LauncherTest, ZeroAzimuthHasNoZComponent) {
	Launcher l;
	InputSnapshot i;
	Set_Azimuth(l, 0);
	Set_Elevation(l, 30);
	l.aim(i, 0.25);

	double ecart = 1e-4;

	cyclone::Vector3 result(0.866, 0.5, 0.0);
	EXPECT_TRUE(Ecart(l.shotSettings().direction, result, ecart));
}

TEST_F(LauncherTest, DirectionNormalised) {
	Launcher l;
	InputSnapshot i;
	Set_Azimuth(l, 30);
	Set_Elevation(l, 30);
	l.aim(i, 0.25);

	double ecart = 1e-4;
	
	cyclone::real distance = l.shotSettings().direction.magnitude();
	
	EXPECT_TRUE(distance < 1 + ecart && distance > 1 - ecart);
	
	Set_Elevation(l, 45);
	distance = l.CalculDir().magnitude();
	EXPECT_TRUE(distance < 1 + ecart && distance > 1 - ecart);

}

TEST_F(LauncherTest, ParametersAreClamped) {
	Launcher l1;
	Launcher l2;

	InputSnapshot i;
	Set_Azimuth(l1, -35);
	Set_Azimuth(l2, 35);

	Set_Elevation(l1, 0);
	Set_Elevation(l2, 60);

	Set_Speed(l1, 7);
	Set_Speed(l2, 24);

	l1.aim(i, 0.25);
	l2.aim(i, 0.25);

	EXPECT_EQ(Get_Azimuth(l1), -30);
	EXPECT_EQ(Get_Azimuth(l2), 30);

	EXPECT_EQ(Get_Elevation(l1), 5);
	EXPECT_EQ(Get_Elevation(l2), 55);

	EXPECT_EQ(Get_Speed(l1), 8);
	EXPECT_EQ(Get_Speed(l2), 22);

}


TEST_F(LauncherTest, AimIsIndependentFromCamera) {
	Launcher l;
	OrbitCamera cam;
	Set_Azimuth(l, 20);
	Set_Elevation(l, 30);

	cyclone::Vector3 res(0.8138, 0.5, 0.2962);

	bool ecart = Ecart(l.CalculDir(), res, 1e-4);
	EXPECT_TRUE(ecart);

}

TEST_F(LauncherTest, SelectsConcreteProjectileKind) {
	Launcher l;
	InputSnapshot i;
	Set_Speed(l, 16);
	l.shotSettings().projectileKind = ProjectileType::STANDARD;
	
	i.isPressed2 = true;
	l.aim(i, 0.25);
	EXPECT_EQ(l.shotSettings().projectileKind, ProjectileType::HEAVY);
	EXPECT_EQ(Get_Speed(l), 16);

	i.isPressed1 = true;
	i.isPressed2 = false;
	l.aim(i, 0.25);
	EXPECT_EQ(l.shotSettings().projectileKind, ProjectileType::STANDARD);
	EXPECT_EQ(Get_Speed(l), 16);
	
}
