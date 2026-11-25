#ifndef SIEGELAB_LIBRARY_OBJECTPOOL_H_
#define SIEGELAB_LIBRARY_OBJECTPOOL_H_

#include <stdexcept>
#include "EntityId.h"

template <typename T, const int Capacity>
class ObjectPool
{
private:
	T* objects;
	bool* isUsed;
	EntityId* IdList;
	int actualNBObjects = 0;

public:
	ObjectPool();

	template<typename ...Param>
	EntityId Create(Param... _arg);

	T& Get(EntityId& _i); //TODO : remplace les int des index par l'entityID (regarde le doc)

	void Destroy(EntityId& _i);

	void Clear();
	
	EntityId GetId(int _i) const;

	//TODO fonction non verifié
	T* ForEach(T _model);

};

#endif


#include "ObjectPool.inl"
