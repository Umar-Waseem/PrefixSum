#include <iostream>
using namespace std;

typedef long long int llint;

/* -------------------------------------------------------------------------- */
/*                // *  Overloaded functions for prefix sum                   */
/* -------------------------------------------------------------------------- */


int* calcPrefixSum(int *arr, int n) // ? prefix sum of 1D array
{
    int *prefix = new int[n]; // allocating memory for prefix sum array
    prefix[0] = 0;            // 0 on index 0 so that sum till each index is same as index number
    for (int i = 1; i < n; ++i)
    {
        prefix[i] = prefix[i - 1] + arr[i];
    }
    return prefix;
}

llint calcPrefixSum(int *arr, int n, int arg1, int arg2) //? prefix sum of 1D array from index 1 to index 2
{
    int *prefix = new int[n]; // allocating memory for prefix sum array
    prefix[0] = 0;            // 0 on index 0 so that sum till each index is same as index number
    for (int i = 1; i < n; ++i)
    {
        prefix[i] = prefix[i - 1] + arr[i];
    }

    llint sum = prefix[arg2] - prefix[arg1 - 1]; // prefix sum from index 1 to 2 is prefix sum stored on index 2 minus all prefix sums stored behind index 1.

    return sum;
}

int** calcPrefixSum(int **arr, int row, int col) // ? prefix sum of 2D array
{
    int **prefix = new int *[row];
    for (int i = 0; i < row; ++i)
    {
        prefix[i] = new int[col];
    } // allocating memory to rows and cols for prefix sum 2d array

    prefix[0][0] = 0;

    for (int i = 1; i < row; ++i)
    {
        for (int j = 1; j < col; ++j)
        {
            prefix[i][j] = arr[i][j] + prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
        }
    }

    return prefix;
}

llint calcPrefixSum(int **arr, int row, int col, int x1, int y1, int x2, int y2) // ? prefix sum of 2D array from index 1 to index 2
{
    int **prefix = new int *[row];
    for (int i = 0; i < row; ++i)
    {
        prefix[i] = new int[col];
    } // allocating memory to rows and cols for prefix sum 2d array

    for(int i = 0; i < row; ++i)
        prefix[i][0] = 0;

    for(int i = 0; i < col; ++i)
        prefix[0][i] = 0;

    for (int i = 1; i < row; ++i)
    {
        for (int j = 1; j < col; ++j)
        {
            prefix[i][j] = arr[i][j] + prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
        }
    }


    llint sum = prefix[x2][y2] - prefix[x1 - 1][y2] - prefix[x2][y1 - 1] + prefix[x1 - 1][y1 - 1];

    return sum;
}

// int main()
// {
//     int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//     int n = sizeof(arr1) / sizeof(arr1[0]);

//     int row = 6 , col = 6;
//     int** arr2 = new int*[row];
//     for (int i = 0; i < row; ++i)
//     {arr2[i] = new int[col];}

//     for (int i = 0; i < row; ++i)
//     {
//         for (int j = 0; j < col; ++j)
//         {
//             arr2[i][j] = 1;
//         }
//     }

        
//     cout << calcPrefixSum(arr1, n, 2, 4) << endl;   // sum from index 2 to index 4
//     cout << calcPrefixSum(arr2, row, col, 2, 2, 4, 4) << endl;  // sum from (2,2) to (4,4)
// }

