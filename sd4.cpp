#include<iostream>
using namespace std;
 
class Prims
{
private:
	int visited[20]; //visited array will store if node is visited or not
	int dist[20]; // it will be initialized with a max value at beginning
	int parent[20]; //to store the parent(other node of the edge pair)
	int nodes; //number of nodes
	int edges; // number of edges
	int adjacency[20][20]; 
	int min; //we'll find node which is not visited and has minimum dist value in dist array and store it's index in min
public:
	Prims() // initializing all arrays and variables
	{
		for(int i = 0; i<20; i++)
		{
			visited[i] = 0;
			dist[i] = 1000;
		}
		
		for(int i = 0; i<20; i++)
			for(int j= 0; j<20; j++)
				adjacency[i][j] = 0; 
 
				min = 0; 
	}
 
void enter(); // will prepare adjacency matrix of weighted graph
 
void print_prims(); // will find out and print prim's mst
 
 
};
 
void Prims::print_prims()
{
 
	dist[0] = 0; // initialize first node dist to 0
	for(int k = 0; k<nodes; k++) // loop runs till all nodes are visited
	{
 
		for(int i = 0; i < nodes; i++) //this loop finds the minimum element of dist array that is not visited
			if(dist[i] <= dist[min] && visited[i] != 1)
				min = i; // index of minimum element is stored in min
 
		visited[min] = 1; // visit the min element
		/*cout<<"\nMIN IS: "<<min;
		*/
 
		for(int i = 0; i<nodes; i++)
		{
			if(adjacency[min][i] != 0) // if there is an edge between min and the i th node, 
			{
				if(visited[i] == 0 && adjacency[min][i] < dist[i]) // and if i is not visited, and edge value is less than the dist value
				{
					dist[i] = adjacency[min][i]; //update dist array, and parent of i as well
					parent[i] = min;
				}
			}
		}
		for(int i = 0; i< nodes; i++)
			{
				if(visited[i] == 0) // traverse till you find an unvisited node and store it's index in min, else the loop to find min element that is not visited won't work in the next iteration
				{
					min = i;
					break;
				}
			}
		}
	cout<<"\nPRIM'S MST OF THE GRAPH IS: ";
	for(int i = 1; i<nodes; i++) 
		cout<<"\n"<<i<<"-"<<parent[i];
	cout<<endl;
 
 	int sum = 0;
	for(int j = 1; j<nodes; j++)
		sum += adjacency[j][parent[j]];
	cout<<"\nCOST OF MST IS: "<<sum<<endl;
	
	
}
 
void Prims::enter()
{
	
	cout<<"\nENTER THE NUMBER OF NODES IN GRAPH. ";
	cin>>nodes;
	cout<<"\nENTER THE NUMBER OF EDGES. ";
	cin>>edges;
	cout<<"\nENTER THE VERTICES AND WEIGHT. (e.g. FOR EDGE BETWEEN 0 AND 1 OF WEIGHT 2, ENTER 0 1 2)"<<endl;
	
	for(int i = 0; i<edges; i++)
	{
		int v1, v2, weight;
		cin>>v1>>v2>>weight;
		adjacency[v1][v2] = weight;
		adjacency[v2][v1] = weight;
	}
	
}
int main()
{
Prims obj; // create object of class
obj.enter(); //enter function will prepare adjacency matrix of the weighted graph
obj.print_prims(); // it will find out and print the Prim's MST
 
 
return 0;
}

