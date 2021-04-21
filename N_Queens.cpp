#include "bits/stdc++.h" 
using namespace std;

bool isSafe(int **arr, int x,int y,int n) {
    for (int i=0;i<x;i++) {
        if (arr[i][y] == 1)
        {
            return false;
        }
    }
    int row=x,col=y;
    while (row>=0 && col>=0) {
        if (arr[row][col] == 1) {
            return false;
        }
        row--;
        col--;
    }
    row = x;col = y;
    while (row>=0 && col<n) {
        if (arr[row][col] == 1)     
            return false;
        row--;
        col++;
    }
    return true;
}

bool nQueens(int **arr, int x,int n){
    if (x>=n) 
        return true;
    for (int j=0;j<n;j++) {
        if (isSafe(arr,x,j,n)){
            arr[x][j] = 1;
            if (nQueens(arr,x+1,n))
                return true;
            arr[x][j] = 0; // backtracking 
        }
    }
    return false;
}
int main() {
    int n;
    cin>>n;
    int** arr = new int*[n];
    for (int i=0;i<n;i++) {
        arr[i] = new int[n];
        for (int j=0;j<n;j++) {
            arr[i][j] = 0;
        }
    }

    if (nQueens(arr,0,n)) {
        for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            cout<<arr[i][j]<< " ";

        }cout<<endl;
    }
    }
}