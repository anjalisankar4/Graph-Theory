#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void shortest_distance(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == -1)
                {
                    matrix[i][j] = 1e9; // initialising all paths that are not direct edges as infinity
                }
                if (i == j)
                    matrix[i][j] = 0; // the cost of reaching from a node to itself is zero
            }
        }

        for (int k = 0; k < n; k++)
        { // reaching all i and j pairs via k
            for (int i = 0; i < n; i++)
            { // these i and j loops are for reaching all pairs of nodes.
                for (int j = 0; j < n; j++)
                {
                    matrix[i][j] = min(matrix[i][j],
                                       matrix[i][k] + matrix[k][j]);
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 1e9)
                {
                    matrix[i][j] = -1; // we are changing the unreachable nodes to -1 because the question(in GFG) said so
                }
            }
        }
    }
};

int main()
{

    int V = 4;
    vector<vector<int>> matrix(V, vector<int>(V, -1));
    matrix[0][1] = 2;
    matrix[1][0] = 1;
    matrix[1][2] = 3;
    matrix[3][0] = 3;
    matrix[3][1] = 5;
    matrix[3][2] = 4;

    Solution obj;
    obj.shortest_distance(matrix);
    // printing cost
    for (auto row : matrix)
    {
        for (auto cell : row)
        {
            cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}
