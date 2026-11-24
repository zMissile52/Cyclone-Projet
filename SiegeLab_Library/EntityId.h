#ifndef SIEGELAB_LIBRARY_ENTITYID_H_
#define SIEGELAB_LIBRARY_ENTITYID_H_

#include <cstdint>

struct EntityId
{
	uint32_t slot = 0;
	uint32_t generation = 0;
};

#endif