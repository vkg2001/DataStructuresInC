//VivekKumar

#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <fstream>

using namespace std;

typedef pair<int, string> pi;
priority_queue<pi, vector<pi>, greater<pi> > pq;
const int SIZE=6;
int graph[6][6];

struct Records
{
        string name;
        string location;
        float a;
        float b;
        float ab;
        float O;
}record[SIZE];

struct mapd
{
	string name;
	int x;
}rec[6];

int minimumDist(int dist[], bool Tset[])
{
	int min=INT_MAX,index;

	for(int i=0;i<6;i++)
	{
		if(Tset[i]==false && dist[i]<=min)
		{
			min=dist[i];
			index=i;
		}
	}
	return index;
}

void Dijkstra(int graph[6][6],int src)
{
	int dist[6];
	bool Tset[6];
	for(int i = 0; i<6; i++)
	{
		dist[i] = INT_MAX;
		Tset[i] = false;
	}

	dist[src] = 0;

	for(int i = 0; i<6; i++)
	{
		int m=minimumDist(dist,Tset);
		Tset[m]=true;
		for(int i = 0; i<6; i++)
		{

			if(!Tset[i] && graph[m][i] && dist[m]!=INT_MAX && dist[m]+graph[m][i]<dist[i])
				dist[i]=dist[m]+graph[m][i];
		}
	}
	for(int i = 0; i<6; i++)
	{  if(i!=0)
		pq.push(make_pair(dist[i],rec[i].name));
	}
}

int main
{
    int i;
    ifstream in("Data.txt");
    if (!in){
    cerr << "File can't be opened! " << endl;
    system("PAUSE");
    exit(1);
    }
    for (int i=0; i < SIZE; i++){
    in >> record[i].name >> record[i].location
    >>record[i].a>> record[i].b>> record[i].ab>>record[i].O ;
    }
    for (int i=0;i< SIZE;i++) {
        cout << record[i].name<<"  ";
        cout << record[i].location<<" ";
        cout << record[i].a<<"  ";
        cout << record[i].b<< "  ";
        cout << record[i].ab<< "   ";
        cout << record[i].O<< "   ";
        cout<<endl;
    }
	ifstream gh("MAP.txt");
    if (!gh){
    cerr << "File can't be opened! " << endl;
    system("PAUSE");
    exit(1);
    }
	for (int i=0; i < SIZE; i++){
    gh >> rec[i].name >> rec[i].x;
    }
	int graph[6][6]={
		{0, 10, 20, 0, 0, 0},
		{10, 0, 0, 50, 10, 0},
		{20, 0, 0, 20, 33, 0},
		{0, 50, 20, 0, 20, 2},
		{0, 10, 33, 20, 0, 1},
		{0, 0, 0, 2, 1, 0}};
	Dijkstra(graph,0);
	pair<int, string> top = pq.top();
    cout<<"Enter type of blood required";
    string c;
    cin>>c;
    cout <<top.second<<" ";
    for(int i=0;i<6;i++){
        if(record[i].name.compare(top.second))
          continue;
          else
            {
                if(c=="a")
                 cout<<record[i].a;
                 else if(c=="b")
                 cout<<record[i].b;
                   else if(c=="ab")
                   cout<<record[i].ab;
                   else
                     cout<<record[i].O;
            }
    }
return 0;
}

