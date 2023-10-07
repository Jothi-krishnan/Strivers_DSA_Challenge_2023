#include<bits/stdc++.h>
using namespace std;

struct Node{
	Node *links[2];

	bool isPresent(int i){
		return (links[i] != NULL);
	}

	void putLink(int i, Node * node)
	{
		links[i] = node;
	}

	Node* getLink(int i)
	{
		return links[i];
	}
};

class Trie{
private:
	Node *root;

public:
	Trie()
	{
		root = new Node();
	}

	void insert(int num)
	{
		Node *node = root;

		for(int i = 31; i>= 0; i--)
		{
			if((num >> i) & 1)
			{
				if(!node->isPresent(1))
					node->putLink(1, new Node());

				node = node->getLink(1);
			}
			else{
				if(!node->isPresent(0))
					node->putLink(0, new Node());

				node = node->getLink(0);
			}
		}
	}

	int getMaxXOR(int x)
	{
		int ans = 0;
		Node *node = root;

		for(int i = 31; i>= 0; i--)
		{
			if((x >> i) & 1)
			{
				if(node->isPresent(0))
				{
					ans += (1 << i);
					node = node->getLink(0);
				}
				else{
					node = node->getLink(1);
				}
			}
			else{
				if(node->isPresent(1))
				{
					ans += (1 << i);
					node = node->getLink(1);
				}
				else{
					node = node->getLink(0);
				}
			}
		}
		return ans;
	}
};

vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
	Trie t;

	sort(arr.begin(), arr.end());
	int j = 0;
	int n = arr.size();

	vector<vector<int>> v;
	
	int m = queries.size();
	for(int i = 0 ;i<m; i++)
	{
        v.push_back({queries[i][0], queries[i][1], i});
    }

	sort(v.begin(), v.end(), [&](vector<int> a, vector<int> b){
		return a[1] <= b[1];
	});

	vector<int> ans(m, -1);

	for(auto q : v)
	{
		int x = q[0];
		int lim = q[1];
		int idx = q[2];

		while(j < n && arr[j] <= lim)
		{
			t.insert(arr[j]);
			j++;
		}

		if(j == 0)
			continue;

		int currValue = t.getMaxXOR(x);
		ans[idx] = currValue;
	}

	return ans;
}