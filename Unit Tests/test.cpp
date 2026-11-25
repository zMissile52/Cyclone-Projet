#include "pch.h"
#include <Game.h>
#include <cyclone/cyclone.h>
#include <ObjectPool.h>

TEST(TestCaseName, TestName) {

	Game game;

  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

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