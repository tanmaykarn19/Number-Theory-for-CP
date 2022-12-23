#include <bits/stdc++.h>
using namespace std;

#define N 101
int ar[N][N], I[N][N];

// simple matrix multiplication code:
void mul(int A[][N], int B[][N], int dim)
{
    int res[dim + 1][dim + 1];
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            res[i][j] = 0;
            for (int k = 0; k < dim; k++)
            {
                res[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    // copy the result of res to A:
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            A[i][j] = res[i][j];
        }
    }
}

// print the mat:
void printMat(int A[][N], int dim)
{
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}

void power(int A[][N], int dim, int n)
{
    // init an identity matrix: (diagonal elements are 1, rest are 0);
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            if (i == j)
                I[i][j] = 1;
            else
                I[i][j] = 0;
        }
    }
    // multiply the matrix n number of times; using linear brute force. O(M^3 * N)
    // for (int i = 0; i < n; i++)
    // {
    //     mul(I, A, dim);
    // }

    // multiply using binary exponentiation O(M^3 * logN) time.
    while (n)
    {
        if (n % 2)
            mul(I, A, dim), n--;

        else
            mul(A, A, dim), n /= 2;
    }

    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            A[i][j] = I[i][j];
        }
    }
}

int main()
{
    int t, dim, n;
    cin >> t;
    while (t--)
    {
        cin >> dim >> n;
        for (int i = 0; i < dim; i++)
        {
            for (int j = 0; j < dim; j++)
            {
                cin >> ar[i][j];
            }
        }

        power(ar, dim, n);
        printMat(ar, dim);
    }
}