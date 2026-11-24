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

	pool.Create(10);
	pool.Create(20);
	pool.Create(30);
	EXPECT_ANY_THROW(pool.Create(40));

	EXPECT_EQ(10, pool.Get(0));
	EXPECT_EQ(20, pool.Get(1));
	EXPECT_EQ(30, pool.Get(2));
	EXPECT_THROW(pool.Get(3), std::length_error);

}

TEST(ObjectPool, RecycledSlot) {
	ObjectPool<int, 1> pool;
	
	int a = 7;
	int b = 42;

	pool.Create(a);

	EXPECT_EQ(7, pool.Get(0));

	pool.Destroy(0);
	EXPECT_THROW(pool.Get(0), std::length_error);


	pool.Create(b);
	EXPECT_EQ(42, pool.Get(0));
	

}