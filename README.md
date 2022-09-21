# **DAA-ASSIGNMENT** 

### **Assignment Question :**
Accept a One dimensional array using random number generator. The array may be in the range of [0,1,2] [Only three numbers are permitted] Scan the array and print "X" if number "0" is more than number of "1" and "2". Print "Y" if number of "1" are more than "0" and "2". Print "Z" if number of "2" are more than "0" and "1". Expected complexity O(log n).

### **Approach :**
We have to generate an Array of numbers [0, 1, 2] using randon number generator, calulate the occurrence of each number and print 'X' if numbers of "0" is more than number of "1" and "2". Print "Y" if number of "1" are more than "0" and "2". Print "Z" if number of "2" are more than "0" and "1".
We can solve this using Linear Search but in that the Complexity of the code will be O(n) and we are expecting complexity to be O(log n) so for that we have to used Binary Search operation.

### **Code Explanation :**

First we have created and Array using random number generator. So for that purpose we have included ( cstdlib ) library from which we will use rand() function and srand(seek).

**1.rand() :** The rand() function is used in C++ to generate random numbers in the range (0, RAND_MAX).
Note:_If random numbers are generated with rand() without first calling srand(), your program will create the same sequence of numbers each time it runs._

**2.srand() :** The srand() function sets the starting point for producing a series of pseudo-random integers. If srand() is not called, the rand() seed is set as if srand(1) were called at the program start.
*Syntax* : srand(time(0)).

After generating an array using random number generator and sorting it we have called the *BinarySearch* function which will return the index of the element to be search to the *FrequencyofNumber* function which will return the occurence of the element.

Here we have created two functions:

**1.Binary Search :** This function is used for finding the element to be search in the given array.

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
    
* Start with the mid element of the whole array as a search key.
* If the value of the search key is equal to the item then return an index of the search key to the FrequncyOfNum function.
* Or if the value of the search key is less than the item in the middle of the interval, then again call BinarySearch on ( low to mid-1 ) Otherwise, call BinarySearch on ( mid+1 to high).
* Repeatedly check from the second point until the value is found or the interval is empty.

**2.Frequency of Number :** This function is used to calculate the occurrence of th given element.
==> After geting index of the key element first we will traverse towards left of the array till left>=0 (0 starting index) and increment count if we found same key element otherwise traverse towards right of the array till right<=n-1 (n size of array) and increment count if we found same key element.
And finally return count to main function.


## **Main function :**
After geting count value apply if-else condition.

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
    count_0 , count_1 and count_2 are the variable created for storing frequency of the element (0, 1, 2).
    
 ```
  OUTPUT :
 
    Enter the size of Array : 15

    Given Array is : 2 0 1 1 2 0 1 1 2 0 1 1 2 2 2      

    Sorted Array is : 0 0 0 1 1 1 1 1 1 2 2 2 2 2 2     


    Number of '0' are : 2
    Number of '1' are : 5
    Number of '2' are : 3


    --> Y : Number of 1 are more than number of 0 and 2
    
 ```
 
 ```
 CODE :
 
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

```
