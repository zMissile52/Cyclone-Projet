#pragma once

template<typename T, const int Capacity>
inline ObjectPool<T, Capacity>::ObjectPool()
{
	if (Capacity <= 0) return; // TODO error
	
	objects = new T[Capacity];
}

template<typename T, const int Capacity>
inline T& ObjectPool<T, Capacity>::Get(int _i)
{
	if (_i < 0 || _i >= Capacity) throw std::length_error("ObjectPool : index > capacity"); // TODO error
	
	return objects[_i];
}



template<typename T, const int Capacity>
template<typename... Param>
inline void ObjectPool<T, Capacity>::Create(Param... _arg)
{
	if (Capacity <= pos) throw std::length_error("ObjectPool : objectpool is full"); // TODO faudrais une erreur

	objects[pos] = T(_arg...);

	pos++;
}
