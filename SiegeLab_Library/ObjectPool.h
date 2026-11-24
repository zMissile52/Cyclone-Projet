#ifndef SIEGELAB_LIBRARY_OBJECTPOOL_H_
#define SIEGELAB_LIBRARY_OBJECTPOOL_H_

#include <stdexcept>

template <typename T, const int Capacity>
class ObjectPool
{
private:
	T* objects;
	int pos = 0;

public:
	ObjectPool();

	template<typename ...Param>
	void Create(Param... _arg);

	T& Get(int _i);

};

#endif


#include "ObjectPool.inl"
