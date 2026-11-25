#pragma once

template<typename T, const int Capacity>
inline ObjectPool<T, Capacity>::ObjectPool()
{
	
	if (Capacity <= 0) return; // TODO error
	
	objects = new T[Capacity];
	isUsed = new bool[Capacity]();
	IdList = new EntityId[Capacity];
	for (uint32_t i = 0; i < Capacity; i++) {
		IdList[i].slot = i;
	}
}

template<typename T, const int Capacity>
inline T& ObjectPool<T, Capacity>::Get(EntityId& _i)
{
	if (_i.slot < 0 || _i.slot >= Capacity) throw std::length_error("ObjectPool::Get : index not between [0, capacity]");
	if (actualNBObjects <= 0) throw std::length_error("ObjectPool::Get : objectpool is empty");
	if (_i.generation != IdList[_i.slot].generation) throw std::invalid_argument("ObjectPool::Get : id invalid");

	return objects[_i.slot];
}

template<typename T, int Capacity>
inline void ObjectPool<T, Capacity>::Destroy(EntityId& _i)
{
	if (_i.slot < 0 || _i.slot >= Capacity) throw std::length_error("ObjectPool::Destroy : index not between [0, capacity]");

	if (isUsed[_i.slot]) {
		isUsed[_i.slot] = false;
		actualNBObjects--;
	}
	
}

template<typename T, int Capacity>
inline EntityId ObjectPool<T, Capacity>::GetId(int _i) const
{
	return IdList[_i];
}

template<typename T, int Capacity>
inline void ObjectPool<T, Capacity>::Clear()
{
	for (uint32_t i = 0; i < Capacity; i++) {
		isUsed[i] = false;
		objects[i] = T{};
		IdList[i].generation = 0;
		actualNBObjects = 0;
	}
}

template<typename T, int Capacity>
inline T* ObjectPool<T, Capacity>::ForEach(T _model)
{
	uint32_t size = 0;
	T* list;
	for (int i = 0; i < Capacity; i++) {
		if (isUsed[i]) {
			if (_model == objects[i]) {
				list[0] = objects[i];
				size++;
			}
		}
	}

	return list;
}


template<typename T, const int Capacity>
template<typename... Param>
inline EntityId ObjectPool<T, Capacity>::Create(Param... _arg)
{
	if (Capacity <= actualNBObjects) throw std::length_error("ObjectPool::Create : objectpool is full"); 

	for (int i = 0; i < Capacity; i++) {
		if (!isUsed[i]) {
			objects[i] = T(_arg...);
			isUsed[i] = true;
			actualNBObjects++;
			IdList[i].generation++;
			return IdList[i];
		}
	}

}
