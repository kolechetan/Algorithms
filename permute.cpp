#include<iostream>
void printArr(int arr[], int n)
{

    for(int i=0; i<n ; ++i)
        std::cout<<arr[i];
    std::cout<<std::endl;

}

void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}
void permute(int arr[], int start, int end)
{
    if(start == end)
        printArr(arr, end);
    else
    {
        for(int i=start; i < end ; ++i)
        {
            swap(arr[start],arr[i]);
            permute(arr, start+1, end);
            swap(arr[start],arr[i]);
        }
    }
}

int main()
{
    int arr[]= {1,2,3,4,5};
    int start = 0;
    int end = sizeof(arr)/ sizeof(arr[0]);
    permute(arr,start,end);
return 0;
}
