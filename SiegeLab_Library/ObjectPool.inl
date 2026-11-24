#pragma once

template<typename T, const int Capacity>
inline ObjectPool<T, Capacity>::ObjectPool()
{
	if (Capacity <= 0) return; // TODO error
	
	objects = new T[Capacity];
	isUsed = new bool[Capacity]();
}

template<typename T, const int Capacity>
inline T& ObjectPool<T, Capacity>::Get(int _i)
{
	if (_i < 0 || _i >= Capacity) throw std::length_error("ObjectPool::Get : index not between [0, capacity]");
	if (actualNBObjects <= 0) throw std::length_error("ObjectPool::Get : objectpool is empty");

	return objects[_i];
}

template<typename T, int Capacity>
inline void ObjectPool<T, Capacity>::Destroy(int _i)
{
	if (_i < 0 || _i >= Capacity) throw std::length_error("ObjectPool::Destroy : index not between [0, capacity]");

	if (isUsed[_i]) {
		isUsed[_i] = false;
		actualNBObjects--;
	}
	
}


template<typename T, const int Capacity>
template<typename... Param>
inline void ObjectPool<T, Capacity>::Create(Param... _arg)
{
	if (Capacity <= actualNBObjects) throw std::length_error("ObjectPool::Create : objectpool is full"); 

	for (int i = 0; i < Capacity; i++) {
		if (!isUsed[i]) {
			objects[i] = T(_arg...);
			isUsed[i] = true;
			actualNBObjects++;
			break;
		}
	}

}
