// C++ implementation of the above approach
#include <bits/stdc++.h>
#define inf 100000000
using namespace std;
 
// Function to find the smallest path
// with exactly K edges
double smPath(int s, int d,
              vector<pair<pair<int, int>, int> > ed,
              int n, int k)
{
    // Array to store dp
    int dis[n + 1];
 
    // Initialising the array
    for (int i = 0; i <= n; i++)
        dis[i] = inf;
    dis[s] = 0;
 
    // Loop to solve DP
    for (int i = 0; i < k; i++) {
 
        // Initialising next state
        int dis1[n + 1];
        for (int j = 0; j <= n; j++)
            dis1[j] = inf;
 
        // Recurrence relation
        for (auto it : ed)
            dis1[it.first.second] = min(dis1[it.first.second],
                                        dis[it.first.first]
                                            + it.second);
        for (int i = 0; i <= n; i++)
            dis[i] = dis1[i];
    }
 
    // Returning final answer
    if (dis[d] == inf)
        return -1;
    else
        return dis[d];
}
 
// Driver code
int main()
{
 
    int n = 4;
    vector<pair<pair<int, int>, int> > ed;
 
    // Input edges
    ed = { { { 0, 1 }, 10 },
           { { 0, 2 }, 3 },
           { { 0, 3 }, 2 },
           { { 1, 3 }, 7 },
           { { 2, 3 }, 7 } };
 
    // Source and Destination
    int s = 0, d = 3;
 
    // Number of edges in path
    int k = 2;
 
    // Calling the function
    cout << smPath(s, d, ed, n, k);
}