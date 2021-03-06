//implementation of FenwickTree using structs in c++

#include <vector>

using namespace std;

struct FenwickTree
{
	vector<int> bit;
	int n;
	//constructors
	FenwickTree(int n)
	{
		this->n = n;
		bit.assign(n, 0);	//binary index tree
	}

	FenwickTree(vector<int> a) : FenwickTree(a.size()) ///inheritence
	{
		for(int i = 0; i < a.size(); i++)
		{
			add(i, a[i]);
		}
	}
	//member function
	int sum(int r)
	{
		int res = 0;
		int x = r;

		while(x>=0)
		{
			res+=bit[x];
			x = x&(x+1)-1;	//set all the ones after the non-set bit to 1, and that will be g(i) and decrease it to 1 to find the start of next segment
		}

		return res;
	}
	//query
	int sum(int l, int r)
	{
		return sum(r)-sum(l-1);
	}
	//update
	void add(int idx, int delta)
	{
		int x = idx;

		while(x<=n)
		{
			bit[x]+=delta;
			x = x|(x+1);	//set the lowest unset bit
		}
	}
};