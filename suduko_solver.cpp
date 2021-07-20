#include <bits/stdc++.h>
using namespace std;

bool isValid (int arr[9][9], int x, int y, int val) {
    for (int j=0; j<9;j++) {
        if (arr[x][j] == val)
            return false;
    }

    for (int i=0; i<9;i++) {
        if (arr[i][y] == val) 
            return false;
    }

     // to check in 3X3 submatrix 
    int smi = x/3 * 3;
    int smj = y/3 * 3;
    for (int i=0;i<3;i++) {
        for (int j=0; j<3;j++) {
            if (arr[i + smi][j + smj] == val)
                return false;
        }
    }

    return true;
}

bool sudoku_solver(int arr[9][9], int i, int j) {
    // if (i == arr[0].size()-1 and j == arr[0].size()-1)
    //     return;
    if (i == 9)
        return true;
    int ni=0, nj=0; // ni -> next i and nj -> next j

    if (j == 9 - 1){ 
        nj = 0;
        ni = i + 1;
    } else {
        ni = i;
        nj = j + 1;
    }

    if (arr[i][j] != 0){
        return sudoku_solver(arr,ni,nj);
    }
    else {
        for (int po=1; po <= 9 ;po++) { // po signifies possible outcomes
            if (isValid(arr,i,j,po)) {
                arr[i][j] = po;
                if (sudoku_solver(arr,ni,nj))
                    return true;
                arr[i][j] = 0;
            } 
        }
    }
    return false;
}


void print(int arr[9][9]) {
    for (int i=0;i<9;i++) {
        for (int j=0;j<9;j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    
    int arr[9][9] =  { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
                       { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
                       { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
                       { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
                       { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
                       { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
                       { 0, 0, 5, 2, 0, 6, 3, 0, 0 } };
     
    if (sudoku_solver(arr,0,0))
        print(arr);
    return 0;
}