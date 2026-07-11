#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> g;
vector<bool> used;
vector<int> par;

bool dfs(int v, int pred)
{
	used[v] = true;
	par[v] = pred;
	for (int i : g[v])
	{
		if (i == pred) continue;
		if (used[i])
		{
			vector<int> res;
			int t = v;
			while (t != i)
			{
				res.push_back(t);
				t = par[t];
			}
			res.push_back(i);
			reverse(res.begin(), res.end());
			res.push_back(i);
			for (int j : res) cout << j << " ";
			cout << endl;
			return true;
		}
		if (dfs(i, v)) return true;
	}
	return false;
}

int main()
{
	int n, m;
	cin >> n >> m;
	g = vector<vector<int>>(n);
	used = vector<bool>(n, false);
	par = vector<int>(n);

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	for (int i = 0; i < n; i++)
	{
		if (!used[i])
		{
			if (dfs(i, -1))
			{
				cout << "Cicl est" << endl;
				return 0;
			}
		}
	}

	cout << "Net cicla";
	return 0;
}
