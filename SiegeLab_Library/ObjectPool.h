#ifndef SIEGELAB_LIBRARY_OBJECTPOOL_H_
#define SIEGELAB_LIBRARY_OBJECTPOOL_H_

#include <stdexcept>

template <typename T, const int Capacity>
class ObjectPool
{
private:
	T* objects;
	bool* isUsed;
	int actualNBObjects = 0;

public:
	ObjectPool();

	template<typename ...Param>
	void Create(Param... _arg);

	T& Get(int _i); //TODO : remplace les int des index par l'entityID (regarde le doc)

	void Destroy(int _i);

};

#endif


#include "ObjectPool.inl"
