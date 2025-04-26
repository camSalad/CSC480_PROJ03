//Cameron Salamone
//4/25/25
// Router class that represent a router 
// in a network
#ifndef ROUTER_HPP
#define ROUTER_HPP

#include <string>
#include <vector>

struct RouteEntry
{
  int cost; 
  std::string nextRouter; 
  std::string destination;

};

struct Neighbor
{
  std::string name; 
  int cost;
};

class Router {

public: 
	
  std::string _name; // name of this router
  std::vector<Neighbor> _neighbors; // every Router connected to this router 
  std::vector<RouteEntry> _routingTable; 

  // Constructor
  Router(std::string name);
  Router(); 
	

  //Methods
  void updateRouteEntry(std::string destination, std::string nextHop, int hopCost); 
  void addNeighbor(Router r, int cost); 
  void routeThroughNeighbor(std::vector<Router>&);
  void printInfo(); 



}; 


#endif 
