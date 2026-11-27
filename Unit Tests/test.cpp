#include "pch.h"

#include <cmath>


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

//Test Launcher

TEST_F(LauncherTest, ZeroAzimuthHasNoZComponent)
{
	Launcher launcher;
	AimAt(launcher, 0.0, 30.0, 8.0);

	const cyclone::Vector3 direction = launcher.GetShotSettings().direction;
	const cyclone::Vector3 expected = ExpectedDirection(0.0, 30.0);
	EXPECT_TRUE(Ecart(direction, expected));
	EXPECT_NEAR(0.0, direction.z, kTolerance);
}

TEST_F(LauncherTest, DirectionIsNormalized)
{
	Launcher positive_azimuth;
	AimAt(positive_azimuth, 30.0, 30.0, 8.0);
	EXPECT_TRUE(Ecart(positive_azimuth.GetShotSettings().direction,
		ExpectedDirection(30.0, 30.0)));
	EXPECT_NEAR(1.0, positive_azimuth.GetShotSettings().direction.magnitude(),
		kTolerance);

	Launcher negative_azimuth;
	AimAt(negative_azimuth, -30.0, 45.0, 8.0);
	EXPECT_TRUE(Ecart(negative_azimuth.GetShotSettings().direction,
		ExpectedDirection(-30.0, 45.0)));
	EXPECT_NEAR(1.0, negative_azimuth.GetShotSettings().direction.magnitude(),
		kTolerance);
}

TEST_F(LauncherTest, ParametersAreClamped)
{
	Launcher launcher;
	AimAt(launcher, 45.0, -10.0, 30.0);

	EXPECT_TRUE(Ecart(launcher.GetShotSettings().direction,
		ExpectedDirection(30.0, 5.0)));
	EXPECT_DOUBLE_EQ(22.0, launcher.GetShotSettings().speed);
}

TEST_F(LauncherTest, AimIsIndependentFromCamera)
{
	Launcher launcher;
	AimAt(launcher, 20.0, 30.0, 8.0);
	const cyclone::Vector3 expected = ExpectedDirection(20.0, 30.0);

	OrbitCamera camera;
	InputSnapshot camera_input{};
	camera_input.right_mouse_down = true;
	camera_input.mouse_delta.x = 120.0f;
	camera.update(camera_input, 1.0f);
	EXPECT_TRUE(Ecart(launcher.GetShotSettings().direction, expected));
	const ::Vector3 camera_position_after_first_move =
		camera.getCamera().position;

	camera_input.mouse_delta.x = -240.0f;
	camera.update(camera_input, 1.0f);
	EXPECT_TRUE(Ecart(launcher.GetShotSettings().direction, expected));
	const ::Vector3 camera_position_after_second_move =
		camera.getCamera().position;
	const double camera_position_delta =
		std::abs(camera_position_after_first_move.x - camera_position_after_second_move.x)
		+ std::abs(camera_position_after_first_move.y - camera_position_after_second_move.y)
		+ std::abs(camera_position_after_first_move.z - camera_position_after_second_move.z);
	EXPECT_GT(camera_position_delta, kTolerance);
}

TEST_F(LauncherTest, SelectsConcreteProjectileKind)
{
	Launcher launcher;
	AimAt(launcher, 20.0, 30.0, 16.0);
	const cyclone::Vector3 expected_direction = ExpectedDirection(20.0, 30.0);
	InputSnapshot input{};

	input.select_heavy_2 = true;
	launcher.Aim(input, 0.0f);
	EXPECT_EQ(ProjectileKind::kHeavy,
		launcher.GetShotSettings().projectile_kind);
	EXPECT_NEAR(16.0, launcher.GetShotSettings().speed, kTolerance);
	EXPECT_TRUE(Ecart(launcher.GetShotSettings().direction, expected_direction));

	input = {};
	input.select_standard_1 = true;
	launcher.Aim(input, 0.0f);
	EXPECT_EQ(ProjectileKind::kStandard,
		launcher.GetShotSettings().projectile_kind);
	EXPECT_NEAR(16.0, launcher.GetShotSettings().speed, kTolerance);
	EXPECT_TRUE(Ecart(launcher.GetShotSettings().direction, expected_direction));
}