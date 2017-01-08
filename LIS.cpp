#include<iostream>

int findIndex(int input[], int T[], int end, int key)
{
 
    int start = 0 ;
    int ln = end;
    int middle;
    while( start <= end )
    {
        middle = (start + end)/2;   
        if(  middle < ln && input[T[middle]] < key && key <= input[T[middle + 1]]) 
            return middle + 1;
        else if( input[middle] < key )
            start = middle +1;
        else
            end = middle - 1;
    }  
    return  -1 ;
}

void printLIS( int arr[], int R[], int n, int lastIndex)
{
    int i = lastIndex;
   
    std::cout<<arr[i]<<", ";
    while(R[i] != -1)
    {
        std::cout<<arr[R[i]]<<", ";
        i =R[i];
    }
}
void LIS( int arr[], int n)
{
    int R[n] , T[n], tIndex =0 ;
    for( int i=0; i<n ; ++i )
    {
        R[i] = -1;
        T[i] = 0;
    }

    for( int i=1; i<n ; ++i )
    {
         if( arr[i] > arr[i-1] ) 
         {
             T[tIndex] = i; 
             R[ i ] = T[tIndex -1] ;
             tIndex++;
         }
         else
         { 
             int tmpIndex = findIndex(arr, T, tIndex, arr[i]);
             T[tmpIndex] = i;
             R[ i ] = T[tmpIndex -1] ;
         }
    }
    printLIS(arr, R, n, T[tIndex -1]);
    std::cout<<"Max Length of Increasing sequence = "<< tIndex+1 << std::endl; 
}


int main()
{
 //int arr[] ={1,3,2,4,0,7,6,8};
 int arr[] ={2,5,3,7,11};
 int n = sizeof(arr)/ sizeof(arr[0]);
 LIS(arr, n);
 std::cout<<n;
return 0;

}
