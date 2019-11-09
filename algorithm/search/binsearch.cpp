#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

const int SIZE = 100;

int binarySearch(int *arr, const int val, const int L, const int H)
{
    int mid;
    int low = L;
    int high = H;

    while (low <= high)
    {
        mid = low + (high - low) / 2;

        if (arr[mid] == val)
        {
            return mid;
        }
        else if (arr[mid] < val)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    
    return -1;
}

int binarySearchRecursive(int *arr, const int val, const int low, const int high)
{
    if (low > high)
    {
        return -1;
    }

    int mid = low + (high - low) / 2;

    if (arr[mid] == val)
    {
        return mid;
    }
    else if (arr[mid] < val)
    {
        binarySearchRecursive(arr, val, mid + 1, high);
    }
    else
    {
        binarySearchRecursive(arr, val, low, mid - 1);
    }
}

int main()
{
    unsigned seed = time(0);
    srand(seed);

    int arr[SIZE] = {0};

    for (int i=0; i<SIZE; ++i)
    {
        arr[i] = rand() % SIZE * 2 + 1;
    }

    sort(arr, arr + SIZE);

    for (int i=0; i<SIZE; ++i)
    {
        printf("%3d ", arr[i]);

        if ((i+1) % 10 == 0)
        {
            printf("\n");
        }
    }
    printf("\n");

    for (int i=0; i<10; ++i)
    {
        const int val = rand () % SIZE * 2 + 1;

        printf("%3d found at index %3d          ", val, binarySearch(arr, val, 0, SIZE - 1));
        printf("%3d found at index %3d\n", val, binarySearchRecursive(arr, val, 0, SIZE - 1));
    }

    return 0;
}
