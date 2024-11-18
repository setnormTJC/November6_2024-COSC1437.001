// Some sorting and searching algos for our static array class.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include<cassert>

#include<algorithm>
#include <vector>

using std::cout; 

template<int capacity>
class StaticIntegerArray
{
private: 
    int theListOfNumbers[capacity]; 
    //size and capacity -> synonymous for a static array 
public: 

    StaticIntegerArray() = default; 

    void print()
    {
        for (int i = 0; i < capacity; ++i)
        {
            cout << theListOfNumbers[i] << " ";
        }
        cout << "\n";
    }

    void insert(int index, int element)
    {
        assert(index < capacity); 

        theListOfNumbers[index] = element; 
    }

    bool isInAscendingOrder()
    {
        for (int i = 0; i < capacity - 1; ++i)
        {
            if (theListOfNumbers[i] > theListOfNumbers[i + 1])
            // ex: list = 5, 2 -> NOT in ascending order since nums[0] = 5 > 2 = nums[1]
            {
                return false; 
            }
        }
        return true; 
    }

    void sort_in_place()
    {
        for (int leftIndex = 0; leftIndex < capacity - 1; ++leftIndex)
        {
            for (int rightIndex = leftIndex + 1; rightIndex < capacity; ++rightIndex)
            {
                if (theListOfNumbers[rightIndex] < theListOfNumbers[leftIndex])
                {
                    //std::swap def. is similar to `ourSwap` below: 
                    std::swap(theListOfNumbers[rightIndex], theListOfNumbers[leftIndex]);
                }
            }
        }
    }

    void myShuffle()
    {
        for (int i = 0; i < capacity - 1; ++i)
        {
            int randomIndex = rand() % capacity; 
            std::swap(theListOfNumbers[i], theListOfNumbers[randomIndex]); 
            //std::swap(i, randomIndex)
        }
    }

    /*
    This is perhaps our first example of a "brute force" algorithm 
    @returns the index at which THE FIRST (and ONLY the first) occurrence of search value occurs
    */
    int sequentialSearch(int valueToSearchFor)
    {
        for (int i = 0; i < capacity; ++i)
        {
            if (theListOfNumbers[i] == valueToSearchFor)
            {
                return i; 
            }
        }
        return -1; //not in array {1, 2, 3, 4}
    }

    int binarySearch(int valueToSearchFor)
    {
        int low = 0; 
        int high = capacity - 1; 
        int mid = (high - low) / 2; 

        bool found = false; 

        while (low <= high && !found)
        {

            if (theListOfNumbers[mid] == valueToSearchFor)
            {
                found = true; 
            }


        }

        if (found)
        {
            return mid; 
        }
        else
        {
            return -1; 
        }
    }
}; //END of the STATIC ARRAY class def.

void ourSwap(std::vector<int>& nums, int firstIndex, int secondIndex)
{
    int tempCopy = nums[firstIndex]; 

    nums[firstIndex] = nums[secondIndex]; 

    nums[secondIndex] = tempCopy; 
}

int main()
{
    //std::vector<int> nums = { 11, 22, 33, 44 }; 

    //ourSwap(nums, 1, 2); // -> should give -> 11, 33, 22, 44

    const int N = 10;
    StaticIntegerArray<N> someRandomNumbers; //{}
    //std::swap()
    //time_t result = time(0); 

    //cout << result << "\n"; ~ 1 billion? (this is the number of seconds since Jan 1, 1970 ( a common convention))
    //someRandomNumbers.insert(0, 3); 
    //someRandomNumbers.insert(1, 1);
    //someRandomNumbers.insert(2, 5);
    //someRandomNumbers.insert(3, 4);
    //someRandomNumbers.insert(4, 2);
    //someRandomNumbers.insert(5, 6);
    srand(time(0));  //"Big O Notation"
    for (int i = 0; i < N; ++i)
    {
        someRandomNumbers.insert(i, rand() % N);
    };

    someRandomNumbers.print(); 
    cout << std::boolalpha; //displays true instead of 1 and false instead of 0
    cout << "Is it in ascending order? " << someRandomNumbers.isInAscendingOrder() << "\n";

    //let's write a binary search algorithm and a "bubble" sort algorithm 
    someRandomNumbers.sort_in_place(); 
    cout << "\n\nAre the numbers sorted now? \n";

    someRandomNumbers.print(); //should be {1, 2, 3, 4, 5, 6}? 

    //now let's shuffle them
    someRandomNumbers.myShuffle();
    cout << "\n\nHow do the numbers look now? \n";
    someRandomNumbers.print();


    someRandomNumbers.sort_in_place(); 
    someRandomNumbers.print(); 

    while (true)
    {
        //let's search for a value supplied by the program user: 
        cout << "Enter a number to search for in that list: \n";
        int numberToSearchFor;
        std::cin >> numberToSearchFor;

        //int foundPosition = someRandomNumbers.sequentialSearch(numberToSearchFor);

        int foundPosition = someRandomNumbers.binarySearch(numberToSearchFor);

        cout << "That value was? found at index = " << foundPosition << "\n";

    }
 



}
