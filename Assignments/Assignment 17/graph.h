#ifndef graph_h
#define graph_h

#include <vector>
using namespace std;

class Graph
{
private:

	class Vertex
	{
	private:

		class Edge
		{
		private:
			Vertex * start;
			Vertex * end;
		public:

			Edge(Vertex *head, Vertex *tail)
			{
				start = head;
				end = tail;
			}
			const Vertex *head() const
			{
				return start;
			}
			const Vertex *tail() const
			{
				return end;
			}
		};

		vector <Edge> vertex_edges;

	public:

		 int degrees() const
		{
			return vertex_edges.size();
		}
		 int degrees(const Vertex &temp) const 
		{
			 int count = 0;

			for (int i = 0; i < temp.vertex_edges.size(); i++)
			{
				if (temp.vertex_edges[i].tail() == this)
				{
					count++;
				}
			}

			return count;
		}

		Vertex & addEdge(Vertex &temp)
		{
			vertex_edges.push_back(Edge(this, &temp));

			temp.vertex_edges.push_back(Edge(&temp, this));

			return *this;
		}
		
		bool isOnlyLoops() const
		{
			if (degrees(*this) == degrees())
			{
				return true;
			}

			return false;
		}
	};

	vector <Vertex *> vertice;

public:

	~Graph()
	{
		for (int i = 0; i < vertice.size(); i++)
		{
			delete vertice[i];
		}
	}
	Graph & addVertex() 
	{
		Vertex * vertex = new Vertex;

		vertice.push_back(vertex);

		return *this;
	}
	vector <vector< int>> getAdjacency() const 
	{
		vector <vector<int>> adjacency(vertice.size());

		for (int i = 0; i < vertice.size(); i++)
		{
			for (int j = 0; j < vertice.size(); j++)
			{
				adjacency[i].push_back(vertice[i]->degrees(*vertice[j]));
			}
		}

		return adjacency;
	}
	int size() const
	{
		return vertice.size();
	}
	Vertex * & operator[](int index)
	{
		return vertice[index];
		
	}
	Vertex * operator[](int index) const
	{
		return vertice[index];

	}
};

#endif