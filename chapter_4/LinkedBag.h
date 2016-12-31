/******************************************************************* 
 ** NOT MY CODE, FOLLOWED ALONG AND USED THIS CODE FOR SELF STUDY **
 ** CODE IS FROM FRANK M. CARRANO AND TIMOTHY HENRY'S DATA 		  **
 ** ABSTRACTION AND PROBLEM SOLVING WITH C++					  ** 	
 *******************************************************************/

#ifndef _LINKED_BAG
#define _LINKED_BAG

#include "BagInterface.h"
#include "Node.h"

template<class ItemType>
// notes that it implements the bag interface
class LinkedBag : public BagInterface<ItemType>
{
private:
	Node<ItemType>* headPtr;
	int itemCount;
	Node<ItemType>* getPointerTo(const ItemType& target) const;
public:
	LinkedBag();	
	LinkedBag(const LinkedBag<ItemType>& aBag);	// copy constructor
	virtual ~LinkedBag();
	int getCurrentSize() const;
	bool isEmpty() const;
	bool add(const ItemType& newEntry);
	bool remove(const ItemType& anEntry);
	void clear();
	bool contains(const ItemType& anEntry) const;
	int getFrequencyOf(const ItemType& anEntry) const;
	std::vector<ItemType> toVector() const;
};

#include "LinkedBag.cpp"
#endif