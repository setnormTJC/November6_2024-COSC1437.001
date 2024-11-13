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
        for (int redArrow = 0; redArrow < capacity - 1; ++redArrow)
        {
            for (int greenArrow = redArrow + 1; greenArrow < capacity; ++greenArrow)
            {
                if (theListOfNumbers[greenArrow] < theListOfNumbers[redArrow])
                {
                    //std::swap def. is similar to `ourSwap` below: 
                    std::swap(theListOfNumbers[greenArrow], theListOfNumbers[redArrow]);
                }
            }
        }
    }
};

void ourSwap(std::vector<int> nums, int firstIndex, int secondIndex)
{
    int tempCopy = nums[firstIndex]; 

    nums[firstIndex] = nums[secondIndex]; 

    nums[secondIndex] = tempCopy; 
}

int main()
{
    //std::vector<int> nums = { 11, 22, 33, 44 }; 

    //ourSwap(nums, 1, 2); // -> should give -> 11, 33, 22, 44

    const int N = 100;
    StaticIntegerArray<N> someRandomNumbers;
    //std::swap()
    //time_t result = time(0); 

    //cout << result << "\n"; ~ 1 billion? (this is the number of seconds since Jan 1, 1970 ( a common convention))
    //someRandomNumbers.insert(0, 3); 
    //someRandomNumbers.insert(1, 1);
    //someRandomNumbers.insert(2, 5);
    //someRandomNumbers.insert(3, 4);
    //someRandomNumbers.insert(4, 2);
    //someRandomNumbers.insert(5, 6);
    srand(time(0));  
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
}
