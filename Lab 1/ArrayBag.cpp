#include "ArrayBag.h"
#include <iostream>
#include <cstddef>
#include <vector>

// Example of adding a new method
template<class ItemType>
void ArrayBag<ItemType>::bubbleSort()
{
   for (int i{0}; i < itemCount - 1; i++) {
      for (int x{0}; x < itemCount - i - 1; x++) {
         if(items[x] > items[x+1]) 
            std::swap(items[x], items[x+1]); //swap items[a] with items [a+1]
      }
   }
}  // end isEmpty

template<class ItemType>
bool ArrayBag<ItemType>::binarySearchIterative()
{
	return true;
}  // end isEmpty

template<class ItemType>
bool ArrayBag<ItemType>::binarySearchRecursiveHelper(const ItemType& searchItem) {

   int minIndex = 0;
   int maxIndex = itemCount - 1;
   bool found = binarySearchRecursive(searchItem, minIndex, maxIndex);

   return found;
}

template<class ItemType>
bool ArrayBag<ItemType>::binarySearchRecursive(const ItemType& searchItem, ItemType minIndex, ItemType maxIndex)
{
   bool found = false;
   if (minIndex == maxIndex) {
      return false;
   }
   else {
      int index = minIndex + (maxIndex - minIndex) / 2;
      if (searchItem == items[index])
         return true;
      else if (searchItem < items[index])
         return binarySearchRecursive(searchItem, minIndex, maxIndex - 1);
      else
         return binarySearchRecursive(searchItem, minIndex + 1, maxIndex);
   }
}  // end binarySearchRecursive

/////////////////////// BEGIN DEFAULT CODE /////////////////////////////////////

template<class ItemType>
ArrayBag<ItemType>::ArrayBag(): itemCount(0), maxItems(DEFAULT_CAPACITY)
{
}  // end default constructor

template<class ItemType>
int ArrayBag<ItemType>::getCurrentSize() const
{
	return itemCount;
}  // end getCurrentSize

template<class ItemType>
bool ArrayBag<ItemType>::isEmpty() const
{
	return itemCount == 0;
}  // end isEmpty

template<class ItemType>
bool ArrayBag<ItemType>::add(const ItemType& newEntry)
{
	bool hasRoomToAdd = (itemCount < maxItems);
	if (hasRoomToAdd)
	{
		items[itemCount] = newEntry;
		itemCount++;
	}  // end if
    
	return hasRoomToAdd;
}  // end add

template<class ItemType>
bool ArrayBag<ItemType>::remove(const ItemType& anEntry)
{
   int locatedIndex = getIndexOf(anEntry);
	bool canRemoveItem = !isEmpty() && (locatedIndex > -1);
	if (canRemoveItem)
	{
		itemCount--;
		items[locatedIndex] = items[itemCount];
	}  // end if
    
	return canRemoveItem;
}  // end remove

template<class ItemType>
void ArrayBag<ItemType>::clear()
{
	itemCount = 0;
}  // end clear

template<class ItemType>
int ArrayBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const
{
   int frequency = 0;
   int curIndex = 0;       // Current array index
   while (curIndex < itemCount)
   {
      if (items[curIndex] == anEntry)
      {
         frequency++;
      }  // end if
      
      curIndex++;          // Increment to next entry
   }  // end while
   
   return frequency;
}  // end getFrequencyOf

template<class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType& anEntry) const
{
	return getIndexOf(anEntry) > -1;
}  // end contains

template<class ItemType>
std::vector<ItemType> ArrayBag<ItemType>::toVector() const
{
   std::vector<ItemType> bagContents;
	for (int i = 0; i < itemCount; i++)
		bagContents.push_back(items[i]);
      
   return bagContents;
}  // end toVector

// private
template<class ItemType>
int ArrayBag<ItemType>::getIndexOf(const ItemType& target) const
{
	bool found = false;
   int result = -1;
   int searchIndex = 0;
   
   // If the bag is empty, itemCount is zero, so loop is skipped
   while (!found && (searchIndex < itemCount))
   {
      if (items[searchIndex] == target)
      {
         found = true;
         result = searchIndex;
      } 
      else
      {
         searchIndex++;
      }  // end if
   }  // end while
   
   return result;
}  // end getIndexOf

