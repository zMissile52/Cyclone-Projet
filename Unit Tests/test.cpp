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