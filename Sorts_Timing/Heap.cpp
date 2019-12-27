#include <iostream>
using namespace std;
void heapify(int array[], int len, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < len && array[left] > array[largest])
        largest = left;

    if (right < len && array[right] > array[largest])
        largest = right;

    if (largest != i)
    {
        swap(array[i], array[largest]);

        heapify(array, len, largest);
    }
}

void heapSort(int array[], int len)
{
    for (int i = len / 2 - 1; i >= 0; i--)
        heapify(array, len, i);

    for (int i = len - 1; i >= 0; i--)
    {
        swap(array[0], array[i]);
        heapify(array, i, 0);
    }
}

void print(int array[], int len)
{
    cout << "After sorting the array is: \n";
    for (int i = 0; i < len; ++i)
        cout << array[i] << " ";
    cout << endl;
}

int main()
{
    int array[] = {12, 20, 6, 15, 2, 11,123};
    int len = sizeof(array) / sizeof(array[0]);

    heapSort(array, len);
    print(array, len);
}
