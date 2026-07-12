#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> g;
vector<int> color;
vector<int> par;
bool f = false;

void dfs(int v)
{
	color[v] = 1;
	for (int i : g[v])
	{

		if (color[i] == 1)
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
			f = true;
			return;
		}
		if (color[i] == 0)
		{
			par[i] = v;
			dfs(i);
		}
	}
	color[v] = 2;
}

int main()
{
	int n, m;
	cin >> n >> m;
	g = vector<vector<int>>(n);
	color = vector<int>(n, 0);
	par = vector<int>(n);

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
	}

	for (int i = 0; i < n; i++)
	{
		if (color[i] == 0)
		{
			dfs(i);
		}
		if (f)
		{
			cout << "Est cicl";
			return 0;
		}
	}

	cout << "Net cicla";
	return 0;
}
