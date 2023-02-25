#include <iostream>
#include <fstream>
#include <iomanip> 
#include <cassert>
#include"iterator.h"
#include"linkedList.h"
#include"unorderedLinkedList.h"
#include"LinkedQueueType.h"
using namespace std;


//********************class graphType********************
class graphType
{
protected:
	int maxSize = 0;    //maximum number of vertices
	int gSize = 0;      //current number of vertices
	unorderedLinkedList<int>* graph; //array to create adjacency lists 

public:
	bool isEmpty() const
	{
		return (gSize == 0);
	}
	//Function to determine whether the graph is empty.
	//Postcondition: Returns true if the graph is empty; otherwise, returns false.

	void createGraph()
	{
		ifstream infile;
		infile.open("data.txt");

		int index;
		int vertex;
		int adjacentVertex;

		if (gSize != 0)	//if the graph is not empty, make it empty
			clearGraph();

		if (!infile)
		{
			cout << "Cannot open input file." << endl;
			return;
		}

		infile >> gSize;	//get the number of vertices
		cout << "Number of Vertices: " << gSize << endl;

		for (index = 0; index < gSize; index++)
		{
			infile >> vertex;
			infile >> adjacentVertex;

			cout << "Vertex: " << vertex << "\t";
			if (adjacentVertex != -999)
				cout << "Adjacent Vertex: " << adjacentVertex << " ";

			while (adjacentVertex != -999)
			{
				graph[vertex].insertLast(adjacentVertex);
				infile >> adjacentVertex;
				if (adjacentVertex != -999)
					cout << adjacentVertex << " ";
			} //end while
			cout << endl;
		} // end for

		infile.close();
	} //end createGraph
	  //Function to create a graph.
	  //Postcondition: The graph is created using the  
	  //               adjacency list representation.

	void clearGraph()
	{
		int index;

		for (index = 0; index < gSize; index++)
			graph[index].destroyList();

		gSize = 0;
	} //end clearGraph
	  //Function to clear graph.
	  //Postcondition: The memory occupied by each vertex 
	  //               is deallocated.

	void printGraph() const
	{
		int index;

		for (index = 0; index < gSize; index++)
		{
			cout << index << " ";
			graph[index].print();
			cout << endl;
		}

		cout << endl;
	} //end printGraph
	  //Function to print graph.
	  //Postcondition: The graph is printed.

	//void depthFirstTraversal()
	//{
	//	bool* visited; //pointer to create the array to keep track of the visited vertices
	//	visited = new bool[gSize];

	//	int index;

	//	for (index = 0; index < gSize; index++)
	//		visited[index] = false;

	//	//For each vertex that is not visited, do a depth first traverssal
	//	for (index = 0; index < gSize; index++)
	//	{
	//		if (!visited[index])
	//		{
	//			dft(index, visited);
	//		}
	//	}
	//	delete[] visited;
	//} //end depthFirstTraversal
	  //Function to perform the depth first traversal of
	  //the entire graph.
	  //Postcondition: The vertices of the graph are printed 
	  //               using depth first traversal algorithm.

	/*void dftAtVertex(int vertex)
	{
		bool* visited;

		visited = new bool[gSize];

		for (int index = 0; index < gSize; index++)
			visited[index] = false;

		dft(vertex, visited);

		delete[] visited;
	}*/ // end dftAtVertex
	//  //Function to perform the depth first traversal of 
	//  //the graph at a node specified by the parameter vertex.
	//  //Postcondition: Starting at vertex, the vertices are 
	//  //               printed using depth first traversal 
	//  //               algorithm.

	void breadthFirstTraversal(int vertex)
	{
		linkedQueueType<int> queueType;
		bool* visited;
		visited = new bool[gSize];

		for (int ind = 0; ind < gSize; ind++)
			visited[ind] = false;

		linkedListIterator<int> graphIt;

		for (int index = 0; index < gSize; ++index)
			if (!visited[index])
			{
				queueType.addQueue(index);
				visited[index] = true;
				cout << " " << index << " ";
				while (!queueType.isEmptyQueue())
				{
					int u = queueType.front();
					queueType.deleteQueue();
					for (graphIt = graph[u].begin();
						graphIt != graph[u].end(); ++graphIt)
					{
						int w = *graphIt;
						if (!visited[w])
						{
							queueType.addQueue(w);
							visited[w] = true;
							cout << " " << w << " ";
			
						}
					}
				} //end while
			}
		delete[] visited;
	}




	graphType(int size = 0)
	{
		maxSize = size;
		gSize = 0;
		graph = new unorderedLinkedList<int>[size];
	}
	//Constructor
	//Postcondition: gSize = 0; maxSize = size;
	//               graph is an array of pointers to linked
	//               lists.

	~graphType()
	{
		clearGraph();
	}
	//Destructor
	//The storage occupied by the vertices is deallocated.

};

//private:
//	void dft(int v, bool visited[])
//	{
//		visited[v] = true;
//		cout << " " << v << " ";  //visit the vertex
//
//		linkedListIterator<int> graphIt;
//
//		//for each vertex adjacent to v
//		for(graphIt = graph[v].begin(); graphIt != graph[v].end(); ++graphIt)
//		{
//			int w = *graphIt;
//			if (!visited[w])
//				dft(w, visited);
//		} //end loop
//	} //end dft
//	 /* Function to perform the depth first traversal of 
//	  the graph at a node specified by the parameter vertex.
//	  This function is used by the public member functions
//	  depthFirstTraversal and dftAtVertex.
//	  Postcondition: Starting at vertex, the vertices are 
//	                 printed using depth first traversal 
//	                 algorithm.*/
//};

//********************main function********************
int main()
{
	cout << "GRAPH Traversal" << endl;
	cout << "===============" << endl;
	graphType myGraph(50);

	myGraph.createGraph();
	cout << endl << endl;

	cout << "BreadthFirstTraversal First Traversal: ";
	myGraph.breadthFirstTraversal(10);
	cout << endl;

	return 0;
}
