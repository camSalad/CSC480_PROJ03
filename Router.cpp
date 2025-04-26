//Cameron Salamone
//4/25/25
// Implementation of the Router class
#include "Router.hpp"
#include <iostream>


using namespace std;

Router::Router() : _name("") {} 

//Constructor
Router::Router(string name) : _name(name)
{
	// initial addition
	updateRouteEntry(name, name, 0); // update will also add if it doesnt exist this is initial add
}


void Router::updateRouteEntry(string destination, string nextHop, int cost) 
{
	//intial addition case
	if(_routingTable.size() == 0)
	{
		_routingTable.push_back({0, _name, _name});
		return;
	}
	
	// first check if exists
	bool exists = false;
	for(int i = 0; i < _routingTable.size(); i++)
	{
		if (_routingTable[i].destination == destination) // already exists so just update
		{
			_routingTable[i].cost = cost;
			_routingTable[i].nextRouter = nextHop; 
		  exists = true; 
		}
	}

	if (!exists) // if it doesn't exist add it
	{
		_routingTable.push_back({cost, nextHop, destination});
	}

}


void Router::addNeighbor(Router r, int cost)
{
	// initial addition
	if (_neighbors.size() == 0 )
	{
		_neighbors.push_back({r._name, cost}); 
		updateRouteEntry(r._name, r._name, cost); 

	}


	// if we already have neighbors
	for(int i = 0; i < _neighbors.size(); i++) 
	{
		if (r._name == _neighbors[i].name) { return; } // already exists so just return

		// otherwise add to list
		_neighbors.push_back({r._name, cost}); 
		// and upate the routing table with this info
		updateRouteEntry(r._name, r._name, cost);
	}
	

}

void Router::printInfo()
{
	for(int i = 0; i < _routingTable.size(); i++)
	{
		cout << "\nDestination: " << _routingTable[i].destination << "\nNext Hop:  " <<  _routingTable[i].nextRouter << "\n Cost: " << _routingTable[i].cost << endl << endl; 
	}
}


void Router::routeThroughNeighbor(vector<Router>& network) 
{
	// loop through each neighbor 
	for (int i = 0; i < _neighbors.size(); i++)
	{
		string neighborName = _neighbors[i].name; 
		int conCost = _neighbors[i].cost; 
		Router neighbor;

		// find router object
		for (int routerIndex = 0; routerIndex < network.size(); routerIndex++)
		{
			if (network[routerIndex]._name == neighborName)
			{
				//current neighbor
				neighbor = network[routerIndex]; 
				break;
			}
		}
			
		// loop through routing table of this neighbor and update from there
		for (int j = 0; j < neighbor._routingTable.size(); j++)
		{
			int newCost = conCost + neighbor._routingTable[i].cost; 
			bool knownRouter = false;// to check if we have seen a certain router yet or not 

			// check our own table to see if we have a route to here
			for (int localIndex = 0; localIndex < _routingTable.size(); localIndex++)
			{
				if (_routingTable[localIndex].destination == neighbor._routingTable[j].destination) 
				{
					// update the cost to get to this destination
					if (newCost == _routingTable[localIndex].cost)
					{
						_routingTable[localIndex].cost = newCost; 
						_routingTable[localIndex].nextRouter = neighborName;
					}
					knownRouter = true; 
					break; //get out

				}

			}

			// if we have not seen this router add it to our local routing table
			if (!knownRouter)
			{
				_routingTable.push_back({newCost, neighbor._routingTable[j].destination, neighborName, }); 
			}

		}



	}
	

}









