#include "Sets.h"




Sets::Sets(int sz)
{
	n = sz;
	parent = new int[sz];
	location = new int[sz];
	for (int i = 0; i < n; i++)
	{
		parent[i] = -1;
		location[i] = i;
	}
	parent[0] = sz-1;
}

void Sets::weightedUnion(int i, int j)
//Union sets with roots i and j, i �� j, using the weighting rule.
//parent[ i ] = - count[ i ] and parent[ j ] = - count[ j ].
{
	int temp = parent[i] + parent[j];
	if (parent[i] > parent[j]) { // i has fewer nodes
		parent[i] = j;
		parent[j] = temp;
		location[j] = location[i];
		
	}
	else { // j has fewer nodes (or i and j have the same number of nodes)
		parent[j] = i;
		parent[i] = temp;
		
	}
}
int Sets::CollapsingFind(int i)
// find the root of the tree containing element i.
// Use the collapsing rule to collapse all nodes from i to the root
{
	int r = 0;
	for (r = i; parent[r] >= 0; r = parent[r]);      //find root
	
	while (i != r) {
		int s = parent[i];
		parent[i] = r;
		i = s;
	}
	return r;
}
void Sets::SimpleUnion(int i, int j)
//Replace the disjoint sets with roots i and j, i! = j with //their union
{
	parent[i] = j;
}

int Sets::SimpleFind(int i)
//find the root of the tree containing element i.
{
	while (parent[i] >= 0) i = parent[i];
	return i;
}


Sets::~Sets()
{
	delete parent;
	delete location;
}
