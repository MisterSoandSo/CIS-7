#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "graph.h"

using namespace std;

int usermenu();
void displayInfo(const Graph &,  int);
void addEdge(Graph &, int &);
void finds_highest_deg(const Graph &, int&);
string list_iso_vertice(const Graph &);
void num_loop(const Graph &, int&);
bool isGraphConnected(const Graph &);
bool isGraphComplete(const Graph &);

int main()
{
	Graph graph;
	int numEdge = 0;

	int break_int = 0;

	while (break_int != 3)
	{
		displayInfo(graph, numEdge);
		break_int = usermenu();
		switch (break_int)
		{
		case 1:
			graph.addVertex();
			break;
		case 2:
			addEdge(graph, numEdge);
			break;
		case 3:
			break;
		default:
			cout << "~~~ Invalid Input! Please enter valid input ~~~" << endl<<endl;
		}
	}

	cout << "Goodbye!" << endl;

	return 0;

}

int usermenu()
{
	int input;
	cout << " ~~~~~~~~~~~~~~~ Graph Theory Program Main Menu ~~~~~~~~~~~~~~~ " << endl;
	cout << " 1. - Add a vertices" << endl;
	cout << " 2. - Add a edge" << endl;
	cout << " 3. - Quit Program" << endl;
	cout << "User Choice (1-3): ";
	cin >> input;

	cout << endl;

	return input;
}

void displayInfo(const Graph & graph,  int numEdge)
{
	int highest_deg, loop_num = 0;
	finds_highest_deg(graph, highest_deg);
	num_loop(graph, loop_num);

	cout << "Number of vertices: " << graph.size() << endl;
	cout << "Number of edges: " << numEdge << endl << endl;

	cout << "Vertex with highest degree: ";

	if (graph.size() != 0)
	{
		cout << highest_deg << endl;
	}
	else
	{
		cout << "N/A" << endl;
	}

	cout << "Isolated vertices: " << list_iso_vertice(graph) << endl;
	cout << "Number of loops: " << loop_num << endl;

	cout << "Connected: ";

	if (graph.size() != 0)
	{
		cout << (isGraphConnected(graph) ? "Yes" : "No") << endl;
	}

	else
	{
		cout << "N/A" << endl;
	}

	cout << "Complete: ";

	if (graph.size() != 0)
	{
		cout << (isGraphComplete(graph) ? "Yes" : "No") << endl << endl;
	}

	else
	{
		cout << "N/A" << endl << endl;
	}
}

void addEdge(Graph & graph, int &temp)
{
	static int count = 0;

	if (graph.size() == 0)
	{
		cout << "Error." << endl << endl;
	}

	else
	{
		 int u_input1, u_input2 = 0;

		cout << "Enter first vertex: ";
		cin >> u_input1;
		cout << endl;

		cout << "Enter second vertex: ";
		cin >> u_input2;
		cout << endl;

		if (graph.size() <= --u_input1 || graph.size() <= --u_input2)
		{
			cout << "Error." << endl << endl;
		}

		else
		{
			graph[u_input1]->addEdge(*graph[u_input2]);

			count++;
		}
	}

	temp = count;
}

void finds_highest_deg(const Graph & graph, int &temp)
{
	 int highest = 0;

	for (int i = 0; i < graph.size(); i++)
	{
		if (graph[i]->degrees() > graph[highest]->degrees())
		{
			highest = i;
		}
	}

	temp = highest + 1;
}

string list_iso_vertice(const Graph & graph)
{
	stringstream iso_vertice;

	for (int i = 0; i < graph.size(); i++)
	{
		if (graph[i]->degrees() == 0)
		{
			iso_vertice << i + 1;

			if (i + 1 < graph.size())
			{
				iso_vertice << ", ";
			}
		}
	}

	return iso_vertice.str().empty() ? "N/A" : iso_vertice.str();
}

void num_loop(const Graph & graph, int &temp)
{
    int Counter = 0;

	for (int i = 0; i < graph.size(); i++)
	{
		Counter += graph[i]->degrees(*graph[i]) / 2;
	}

	temp = Counter;
}

bool isGraphConnected(const Graph & graph)
{
	if (graph.size() > 1)
	{
		for (int i = 0; i < graph.size(); i++)
		{
			if (graph[i]->degrees() == graph[i]->degrees(*graph[i]) || graph[i]->isOnlyLoops())
			{
				return false;
			}
		}
	}

	return true;
}

bool isGraphComplete(const Graph & graph)
{
	vector <vector<int>> adjacency = graph.getAdjacency();

	for (int i = 0; i < adjacency.size(); i++)
	{
		for (int j = 0; j < adjacency[i].size(); j++)
		{
			if (i != j && adjacency[i][j] == 0)
			{
				return false;
			}
		}
	}

	return true;
}
