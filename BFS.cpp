#include<bits/stdc++.h>
using namespace std;


struct State
{
	pair<int,int> cell;
	pair<int,int> parent;
	int cost;
};

pair<int,int> goal;

bool isGoal(pair<int,int> cell)
{
	return cell==goal;
}

int getIndex(pair<int,int> point)
{
	int sum=point.first+point.second;
	int before=sum*(sum+1)/2;
	int index=before-1+point.first;
	return index;
}

class Graph
{
	private:
	int numVertices;
	vector<vector<pair<int,int> > > adj;
	
	public:
	Graph(int numVertices)
	{
		this->numVertices=numVertices+1;
		adj.resize(numVertices+1);	
	}	
	
	void addEdge(pair<int,int> u,pair<int,int> v)
	{
		adj[getIndex(u)].push_back(v);
		adj[getIndex(v)].push_back(u);
	}
	
	State bfs(pair<int,int> src)
	{
		queue<State> fringe;
		State state;
		state.cell=src;
		state.parent=make_pair(-1,-1);
		state.cost=0;
		fringe.push(state);
		bool found=false;
		while(!fringe.empty() && !found)
		{
			State currState=fringe.front();
			fringe.pop();
			cout<<currState.cell.first<<" "<<currState.cell.second<<"\n";
			if(isGoal(currState.cell))
			{
				state=currState;
				found=true;
			}
			else
			{
				for(int i=0;i<adj[getIndex(currState.cell)].size();i++)
				{
					State temp;
					temp.cell=adj[getIndex(currState.cell)][i];
					temp.parent=currState.cell;
					temp.cost=currState.cost+1;
					if(temp.cell!=currState.parent)
					{
						fringe.push(temp);	
					}
				}
			}
		}
		return state;
	}
};


int main()
{
	Graph g(getIndex(make_pair(4,3)));
	g.addEdge(make_pair(1,1),make_pair(1,2));
	g.addEdge(make_pair(1,1),make_pair(2,1));
	g.addEdge(make_pair(1,2),make_pair(1,3));
	g.addEdge(make_pair(2,1),make_pair(2,2));
	g.addEdge(make_pair(2,1),make_pair(3,1));
	g.addEdge(make_pair(1,3),make_pair(2,3));
	g.addEdge(make_pair(2,2),make_pair(3,2));
	g.addEdge(make_pair(3,1),make_pair(4,1)); 
	g.addEdge(make_pair(2,3),make_pair(3,3));
	g.addEdge(make_pair(4,1),make_pair(4,2));
	g.addEdge(make_pair(3,3),make_pair(4,3));
	g.addEdge(make_pair(4,2),make_pair(4,3));
	goal=make_pair(3,2);
	State state=g.bfs(make_pair(1,1));
	cout<<state.cell.first<<" "<<state.cell.second<<"\n";
	return 0;
}
