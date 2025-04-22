#ifndef ROUTER_HPP
#define ROUTER_HPP

#include <string>
#include <vector>
#include <iostream>

struct RouteEntry
{
  int cost; 
  std::string nextRouter; 
  std::string destination;

};

class Router {

public: 
	
	std::string _name; // name of this router
	std::vector<Router> _neighbors; // every Router connected to this router 
	std::vector<RouteEntry> _routingTable; 

	// Constructor
	Router(std::string name);
	
	//Methods
	void updateRouteEntry(std::string destination, std::string nextHop, int hopCost); 
	void addNeighbor(Router r, int cost); 
	void printInfo(); 


}; 


#endif 
