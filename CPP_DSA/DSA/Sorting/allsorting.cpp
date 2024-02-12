#include <bits/stdc++.h>
using namespace std;
void bubblesort(int A[], int size)
{
    int r, i, t;
    for (r = 1; r <= size - 1; r++)
    {
        for (i = 0; i <= size - 1 - r; i++)
        {
            if (A[i] > A[i + 1])
            {
                t = A[i];
                A[i] = A[i + 1];
                A[i + 1] = t;
            }
        }
    }
}
void modifiedBubblesort(int A[], int size)
{
    int r, i, t;
    bool flag = true;
    for (r = 0; r < size - 1; r++)
    {
        flag = true;
        for (i = 0; i <= size - 1 - r; i++)
        {
            if (A[i] > A[i + 1])
            {
                t = A[i];
                A[i] = A[i + 1];
                A[i + 1] = t;
                flag = false;
            }
        }
        if (flag)
            break;
    }
}
int minvalueindex(int A[], int size, int j)
{
    int min, minindex;
    min = A[j];
    minindex = j;
    for (int i = j + 1; i <= size - 1; i++)
    {
        if (A[i] < min)
        {
            min = A[i];
            minindex = i;
        }
    }
    return minindex;
}
void selectionsort(int A[], int size)
{
    int i = 0, minindex, t;
    for (i = 0; i < size - 2; i++)
    {
        minindex = minvalueindex(A, size, i);
        t = A[minindex];
        A[minindex] = A[i];
        A[i] = t;
    }
}
void insertionsort(int A[], int size)
{
    int i, j, temp;
    for (int i = 1; i < size; i++)
    {
        temp = A[i];
        for (j = i - 1; j >= 0; j--)
        {
            if (temp < A[j])
            {
                A[j + 1] = A[i];
            }
            else
                break;
        }
        A[j + 1] = temp;
    }
}
int Quick(int A[], int left, int right)
{
    int loc = left, t;
    while (left < right)
    {
        while (left < right && A[loc] = A[right])
            right--;
        if (left == right)
            break;
        t = A[loc];
        A[loc] = A[right];
        A[right] = t;
        loc = right;
        while (left < right && A[left] <= A[loc])
            left++;
        if (left == right)
            break;
        t = A[left];
        A[left] = A[loc];
        A[loc] = t;
        loc = left;
    }
    return loc;
}
void Quicksort(int A[], int l, int u)
{
    int loc;
    loc = Quick(A, l, u);
    if (loc > l + 1)
        Quicksort(A, l, loc - 1);
    if (loc < u - 1)
        Quicksort(A, loc + 1, u);
}
void merging(int A[], int l, int m, int u)
{
    int l[m - l + 1], r[u - m], i, j, k;
    for (i = 0; i < m - l + 1; i++)
        l[i] = A[l + i];
    for (j = 0; j < u - m; j++)
        r[j] = A[m  + 1 + j];
    for (i = 0, j = 0, k = 1; i < m - l + 1 && j < u - m; k++)
    {
        if (l[i] < r[j])
        {
            A[k] = l[i];
            i++;
        }
        else
        {
            A[k] = r[j];
            j++;
        }
    }
    while (i < m - l + 1)
    {
        A[k] = l[i];
        i++;
        k++;
    }
    while (j < u - m)
    {
        A[k] = r[j];
        j++;
        k++;
    }
}
void mergesort(int A[], int l, int u)
{
    int m;
    if (l < u)
    {
        m = (l + u) / 2;
        mergesort(A, l, m);
        mergesort(A, m + 1, u);
        merging(A, l, m, u);
    }
}