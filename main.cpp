#include <iostream> 
#include <fstream> 

using namespace std; 

void printNeighbors()
{

}

void printAll()
{

}

void contactNeighbors()
{

} 

int main(int argc, char * argv[]) 
{
	// process file
	fstream fin("simple.data");

	// user input 
	string uin;
	
	// main loop
	while(true)
	{
		cout << ">";
		cin >> uin;

		if (uin == "p") { printNeighbors(); } 
		else if ( uin == "l") { printAll(); } 
		else if ( uin == "") { contactNeighbors(); }
		
	}


	return 1;
}
