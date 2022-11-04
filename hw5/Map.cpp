#include <map>

#include "Map.h"

void Map::insert(int key, TwoTuple* _data) {
   // fill this in. Insert a std::pair that contains an int and a TwoTuple* as its members.
	map[key] = _data;
}

TwoTuple* Map::lookUp(int key) {
   // use the map container find function to lookup a key and get the Tuple that is the data.
   // Return a pointer to the data, or a nullptr if the entry corresponding to the key isn't
   // found.
	std::map<int, TwoTuple*>::iterator search = map.find(key);
	if (search == map.end()) return nullptr;
	else return search -> second; 
}
