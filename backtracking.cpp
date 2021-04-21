#include "bits/stdc++.h"
using namespace std;

bool isSafe(int **arr, int x, int y, int n)
{ // checks wether the rat can go in the specified position or not
    if (x < n && y < n && arr[x][y] == 1)
    {
        return true;
    }
    return false;
}

bool ratInMaze(int **arr, int x, int y, int n, int **solArray)
{
    if (x == n - 1 && y == n - 1)
    {
        solArray[x][y] = 1;
        return true;
    }
    if (isSafe(arr, x, y, n))
    {
        solArray[x][y] = 1;
        if (ratInMaze(arr, x + 1, y, n, solArray))
        {
            return true;
        }
        if (ratInMaze(arr, x, y + 1, n, solArray))
            return true;
        solArray[x][y] = 0; //backtracking;
        return false;
    }
    return false;
}

int main()
{
    // rat in a maze problem
    int n;
    cin >> n;

    int **arr = new int *[n]; // dynamically allocated array
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
    }

    int **solArr = new int *[n]; // dynamically allocated array
    for (int i = 0; i < n; i++)
    {
        solArr[i] = new int[n];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            solArr[i][j] = 0;
        }
    }
    if (ratInMaze(arr, 0, 0, n, solArr))
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << solArr[i][j] << " ";
            }
            cout << endl;
        }
    }
}