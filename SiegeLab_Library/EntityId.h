#ifndef SIEGELAB_LIBRARY_ENTITYID_H_
#define SIEGELAB_LIBRARY_ENTITYID_H_

#include <cstdint>

struct EntityId
{
	uint32_t slot = 0;
	uint32_t generation = 0;


	bool operator==(const EntityId& id) const {
		return id.generation == generation && id.slot == slot;
	}

	bool operator!=(const EntityId& id) const {
		return id.generation != generation || id.slot != slot;
	}
};

#endif