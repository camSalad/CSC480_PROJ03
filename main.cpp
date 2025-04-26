//Cameron Salamone
// 4/25/25
// main file that parses input
// and runs the main command prompt loop


#include <iostream> 
#include <fstream> 
#include "Router.hpp"

using namespace std; 


bool checkExists(string routerName, const vector<Router>& network) 
{
	for (int i = 0; i < network.size(); i++) 
	{
		if (network[i]._name == routerName) { return true; } 
	}
	return false; 
}


Router* findRouter(string name, vector<Router>& network) 
{
	Router * rPoint;
	for(int i = 0; i < network.size(); i++)
	{
		if (name == network[i]._name)
		{
			return rPoint = &network[i]; // return by reference
		}
	}
	return NULL; 

	
}


int main(int argc, char * argv[]) 
{
	vector<Router> network;


	// process file
	fstream fin("simple.data");
	
	
	string r1, r2; 
	int conCost; 
	while (fin >> r1) 
	{
		fin >> r2; 
		fin >> conCost; 

		//check first router
		if (!checkExists(r1, network) )
		{
			network.push_back(Router(r1)); 
		}

		//check second router
		if(!checkExists(r2, network)) 
		{
			network.push_back(Router(r2)); 
		}	


		// get the actual router objects from the network
		Router* router1 = findRouter(r1, network); 
		Router* router2 = findRouter(r2, network); 

		// add each router as a neighbor of each other
		if (router1 != NULL && router2 != NULL)
		{
			router1 -> addNeighbor(r2, conCost); 
			router2 -> addNeighbor(r1, conCost); 
		}

	}


	// user input 
	string uin;
	
	// main loop
	while(true)
	{
		cout << ">";
		cin >> uin;

		if (uin == "p") 
		{ 
			// read in router name
			string routerName;
			cin >> routerName;

			// get router object
			Router * router = findRouter(routerName, network); 

			// print the info
			router->printInfo();

		} 
		else if ( uin == "l") 
		{ 
			for (int i = 0; i < network.size(); i++) 
			{
				cout << "Data for " << network[i]._name << endl;
				network[i].printInfo(); 
			}
		} 
		else if ( uin == "u") 
		{ 
			string routerName; 
			cin >> routerName; 

			// find the router object
			Router * router = findRouter(routerName, network); 

			// update this router
			router->routeThroughNeighbor(network); 


		}
		else { return 1;} // quit
		
	}


	return 1;
}
