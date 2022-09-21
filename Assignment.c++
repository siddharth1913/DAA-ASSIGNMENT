/*
Name : Siddharth .S. Shah
Roll No: 64

Assignment Questions:
Accept a One dimensional array using random number generator.
The array may be in the range of [0,1,2] [Only three numbers are permitted]
Scan the array and print "X" if number "0" is more than number of "1" and "2".
Print "Y" if number of "1" are more than "0" and "2".
Print "Z" if number of "2" are more than "0" and "1".
Expected complexity O(log n)
*/

// CODE
#include<bits/stdc++.h>
#include <iostream>
#include <cstdlib>
#include<time.h>
using namespace std;

int binarySearch(int arr[], int low, int high, int key){
    if(low > high){
        return -1;
    }
    int mid = (low + high)/2;
    if(arr[mid] == key){
        return mid;
    }
    if(arr[mid] > key){
        binarySearch(arr,low,mid-1,key);
    }else{
        binarySearch(arr,mid+1,high,key);
    }
}
//Recursive Binary Search

int frequencyofnum(int arr[], int n, int key){
    int index = binarySearch(arr,0,n-1,key);

    if(index == -1){
        return -1;
    }

    int count=1;
    int left,right;

    // count the key element on left side of an array
    left = index - 1;
    while(left>=0 && arr[left]==key){
        count++;
        left--;
    }

    // count the key element on the right side of an array
    right = index + 1;
    while(right<=0 && arr[right]==key){
        count++;
        right++;
    }

    return count;
}
int main()
{
    // n = size of array, max = largest element of an array , min = smallest element of an array.
    int n , max = 2, min = 0;
    int count_0 = 0, count_1 = 0, count_2 = 0;

    cout<<"Enter the size of Array : ";
    cin>>n;
    int arr[n];

    srand(time(0)); //use for getting new sequence everytime.

    for(int i=0;i<n;i++){
        //int random = intial_value + (rand() % (max - min + 1));
        arr[i] = 0 + (rand()%(max-min+1));
    }

    //printing array
    cout<<"\nGiven Array is : ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";  
    }
    cout<<endl;

    //Sorting the given array
    sort(arr, arr+n);

    //print array after sorting
    cout<<"\nSorted Array is : ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";  
    }
    cout<<endl;

    count_0 = frequencyofnum(arr, n, 0);
    count_1 = frequencyofnum(arr, n, 1);
    count_2 = frequencyofnum(arr, n, 2);

    cout<<"\n\n";
    cout<<"Number of '0' are : "<<count_0<<endl;
    cout<<"Number of '1' are : "<<count_1<<endl;
    cout<<"Number of '2' are : "<<count_2<<endl;
    cout<<"\n";

    if(count_0 > count_1 && count_0 >count_2){
        cout<<"\n--> X : Number of 0 are more than number of 1 and 2 "<<endl;
    }
    else if(count_1 > count_0 && count_1 > count_2){
        cout<<"\n--> Y : Number of 1 are more than number of 0 and 2 "<<endl;
    }
    else if(count_2 > count_0 && count_2 >count_1){
        cout<<"\n--> Z: Number of 2 are more than number of 0 and 1 "<<endl;
    }
    else if(count_0 == count_1 || count_0 == count_2 || count_1 == count_2 ){
        cout<<"\n--> Occurence of some element are equal "<<endl;
    }
}