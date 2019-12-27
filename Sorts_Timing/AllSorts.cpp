
#include <chrono>
#include <iostream>
using namespace std;
using namespace std::chrono;

/************************  Merge Sort StartS  ***************************/
void merge(int *,int, int , int, int);
void merge_sort(int *arr, int low, int high, int n)
{
    int mid;
    if (low < high){
        //divide the array at mid and sort independently using merge sort
        mid=(low+high)/2;
        merge_sort(arr,low,mid,n);
        merge_sort(arr,mid+1,high,n);
        //merge or conquer sorted arrays
        merge(arr,low,high,mid,n);
    }
}
// Merge sort
void merge(int *arr, int low, int high, int mid,int n)
{
    int i, j, k, c[n];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high) {
        if (arr[i] < arr[j]) {
            c[k] = arr[i];
            k++;
            i++;
        }
        else  {
            c[k] = arr[j];
            k++;
            j++;
        }
    }
    while (i <= mid) {
        c[k] = arr[i];
        k++;
        i++;
    }
    while (j <= high) {
        c[k] = arr[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)  {
        arr[i] = c[i];
    }
}
/************************  Merge Sort Ends  ***************************/

/************************  Heap Sort Starts  ***************************/
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
/************************  Heap Sort Ends  ******************************/

/************************  Quick Sort Starts  ***************************/
int partition(int *a,int start,int end)
{
    int pivot=a[end];
    //P-index indicates the pivot value index

    int P_index=start;
    int i,t; //t is temporary variable

    //Here we will check if array value is
    //less than pivot
    //then we will place it at left side
    //by swapping

    for(i=start;i<end;i++)
    {
    	if(a[i]<=pivot)
        {
            t=a[i];
            a[i]=a[P_index];
            a[P_index]=t;
            P_index++;
        }
     }
     //Now exchanging value of
     //pivot and P-index
      t=a[end];
      a[end]=a[P_index];
      a[P_index]=t;

     //at last returning the pivot value index
     return P_index;
 }
 void quicksort(int *a,int start,int end)
 {
    if(start<end)
    {
         int P_index=partition(a,start,end);
             quicksort(a,start,P_index-1);
             quicksort(a,P_index+1,end);
    }
}
/************************  Quick Sort Ends  *****************************/

/************************  Shell Sort Starts  ***************************/
/* function to sort arr using shellSort */
int shellSort(int arr[], int n)
{
    // Start with a big gap, then reduce the gap
    for (int gap = n/2; gap > 0; gap /= 2)
    {
        // Do a gapped insertion sort for this gap size.
        // The first gap elements a[0..gap-1] are already in gapped order
        // keep adding one more element until the entire array is
        // gap sorted
        for (int i = gap; i < n; i += 1)
        {
            // add a[i] to the elements that have been gap sorted
            // save a[i] in temp and make a hole at position i
            int temp = arr[i];

            // shift earlier gap-sorted elements up until the correct
            // location for a[i] is found
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];

            //  put temp (the original a[i]) in its correct location
            arr[j] = temp;
        }
    }
    return 0;
}
/************************  Shell Sort Ends  *********************************/

/************************  Insertion Sort Starts  ***************************/
/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
/************************  Insertion Sort Ends  ***************************/

/************************ Creating Array Function *************************/
void CreateArray(int* RandomArray, int n)
{
 srand((unsigned)time(NULL));
 int newArray[n];

 for (int i = 0; i < n; i++){
      int b = rand() ;
      newArray[i] = b;
  }
  RandomArray = newArray;
}
/************************ Creating Array Function *************************/

int main(){
  int n;
  int nArray[4] = {50, 100, 150, 200};

  //Get Input From User
  cout << "Enter number of elements to be sorted:" << endl;
  cin >> n;

  for(int i=0;i<4;i++){
    n = nArray[i] * 1000;
    //Create Array Of Random Int
    int MyArray1[n];
    int MyArray2[n];
    int MyArray3[n];
    int MyArray4[n];
    int MyArray5[n];
    CreateArray(MyArray1, n);
    CreateArray(MyArray2, n);
    CreateArray(MyArray3, n);
    CreateArray(MyArray4, n);
    CreateArray(MyArray5, n);

      //UnComment for Sorted Input
      heapSort(MyArray1, n);
      heapSort(MyArray2, n);
      heapSort(MyArray3, n);
      heapSort(MyArray4, n);
      heapSort(MyArray5, n);

      //UnComment for Reverse Sort Input
      heapSort(MyArray1, n);
      heapSort(MyArray2, n);
      heapSort(MyArray3, n);
      heapSort(MyArray4, n);
      heapSort(MyArray5, n);
      for(int i=0;i<=5;i++){
        MyArray1[i] = MyArray1[n-i];
        MyArray2[i] = MyArray2[n-i];
        MyArray3[i] = MyArray3[n-i];
        MyArray4[i] = MyArray4[n-i];
        MyArray5[i] = MyArray5[n-i];
      }


      cout <<'\n' << '\n';
      cout << "Input Number Is:" << n << endl;
    /************************** MergeSort ***********************************/
    cout<<"Merge Sort Timing\n";
    // Get starting timepoint
    auto startMerge = high_resolution_clock::now();
    //MergeSort Function
    merge_sort(MyArray1 ,0, n-1 , n);
    // Get ending timepoint
    auto stopMerge = high_resolution_clock::now();

    // use duration cast method
    auto durationMerge = duration_cast<microseconds>(stopMerge - startMerge);
    cout << "Time taken by MergeSort Function: " << durationMerge.count() << " microseconds" << endl;

    /************************** HeapSort ************************************/
    cout << "Heap Sort Timing" << '\n';
    // Get starting timepoint
    auto startHeap = high_resolution_clock::now();
    //MergeSort Function
    heapSort(MyArray2, n);
    // Get ending timepoint
    auto stopHeap = high_resolution_clock::now();

    // use duration cast method
    auto durationHeap = duration_cast<microseconds>(stopHeap - startHeap);
    cout << "Time taken by HeapSort Function: " << durationHeap.count() << " microseconds" << endl;

    /************************** QuickSort ***********************************/
    cout << "Quick Sort Timing" << '\n';
    // Get starting timepoint
    auto startQuick = high_resolution_clock::now();
    //MergeSort Function
    quicksort(MyArray3, 0, n-1);
    // Get ending timepoint
    auto stopQuick = high_resolution_clock::now();

    // use duration cast method
    auto durationQuick = duration_cast<microseconds>(stopQuick - startQuick);
    cout << "Time taken by QuickSort Function: " << durationQuick.count() << " microseconds" << endl;

    /************************** ShellSort ***********************************/
    cout << "Shell Sort Timing" << '\n';
    // Get starting timepoint
    auto startShell = high_resolution_clock::now();
    //MergeSort Function
    shellSort(MyArray4, n);
    // Get ending timepoint
    auto stopShell = high_resolution_clock::now();

    // use duration cast method
    auto durationShell = duration_cast<microseconds>(stopShell - startShell);
    cout << "Time taken by ShellSort Function: " << durationShell.count() << " microseconds" << endl;

    /************************** InsertionSort *********************************/
    cout << "Insertion Sort Timing" << '\n';
    // Get starting timepoint
    auto startInsertion = high_resolution_clock::now();
    //MergeSort Function
    shellSort(MyArray5, n);
    // Get ending timepoint
    auto stopInsertion = high_resolution_clock::now();

    // use duration cast method
    auto durationInsertion = duration_cast<microseconds>(stopInsertion - startInsertion);
    cout << "Time taken by InsertionSort Function: " << durationInsertion.count() << " microseconds" << endl;

}



}
