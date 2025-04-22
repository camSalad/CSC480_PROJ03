#include "Router.hpp"

using namespace std;

//Constructor
Router::Router(string name) : _name(name)
{
	// initial addition
	updateRouteEntry(name, name, 0); // update will also add if it doesnt exist this is initial add
}


void Router::updateRouteEntry(string destination, string nextHop, int cost) 
{
	
	// first check if exists
	bool exists = false;
	for(int i = 0; i < _routingTable.size(); i++)
	{
		if (_routingTable[i].destination == destination) // already exists so just update
		{
		  exists = true; 
		}
	}

	if (exists) // just update entry
	{

	}

}
