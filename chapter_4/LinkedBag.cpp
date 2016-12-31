#include "LinkedBag.h"
#include "Node.h"
#include <cstddef>



template<class ItemType>
LinkedBag<ItemType>::LinkedBag() : headPtr(nullptr), itemCount(0) {}

// creates a deep copy of the chain
template<class ItemType>
LinkedBag<ItemType>::LinkedBag(const LinkedBag<ItemType>& aBag) {
	itemCount = aBag.itemCount;
	Node<ItemType>* originChainPtr = aBag.headPtr;
	if(originChainPtr == nullptr)
		headPtr = nullptr;
	else {
		headPtr = new Node<ItemType>();
		headPtr->setItem(originChainPtr->getItem());

		Node<ItemType>* newChainPtr = headPtr;
		originChainPtr = originChainPtr->getNext();
		while(originChainPtr != nullptr) {
			ItemType nextItem = originChainPtr->getItem();
			Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);
			newChainPtr = newChainPtr->getNext();
			originChainPtr = originChainPtr->getNext();
		}
		newChainPtr->setNext(nullptr);
	}
}

template<class ItemType>
bool LinkedBag<ItemType>::add(const ItemType& newEntry){ 
	Node<ItemType>* newNodePtr = new Node<ItemType>();
	newNodePtr->setItem(newEntry);
	newNodePtr->setNext(headPtr);
	headPtr = newNodePtr;
	itemCount++;
	return true;
}

template<class ItemType>
std::vector<ItemType> LinkedBag<ItemType>::toVector() const {
	std::vector<ItemType> bagContents;
	Node<ItemType>* curPtr = headPtr;
	int counter = 0;
	while((curPtr != nullptr) && (counter < itemCount)) {
		bagContents.push_back(curPtr->getItem());
		curPtr = curPtr->getNext();
		counter++;
	}
	return bagContents;
}

template<class ItemType>
bool LinkedBag<ItemType>::isEmpty() const {
	return itemCount == 0;
}

template<class ItemType>
int LinkedBag<ItemType>::getCurrentSize() const {
	return itemCount;
}

template<class ItemType>
int LinkedBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const {
	int frequency = 0;
	int counter = 0;
	Node<ItemType>* curPtr = headPtr;
	while((curPtr != nullptr) && (counter < itemCount)) {
		if(anEntry == curPtr->getItem()) {
			frequency++;
		}
		counter++;
		curPtr = curPtr->getNext();
	}
	return frequency;
}

template<class ItemType>
Node<ItemType>* LinkedBag<ItemType>::getPointerTo(const ItemType& target) const {
	bool found = false;
	Node<ItemType>* curPtr = headPtr;
	while(!found && (curPtr != nullptr)) {
		if(target == curPtr->getItem()) 
			found = true;
		else 
			curPtr = curPtr->getNext();
	}
	return curPtr;
}

template<class ItemType>
bool LinkedBag<ItemType>::contains(const ItemType& anEntry) const {
	return getPointerTo(anEntry) != nullptr;
}

template<class ItemType>
bool LinkedBag<ItemType>::remove(const ItemType& anEntry) {
	Node<ItemType>* entryNodePtr = getPointerTo(anEntry);
	bool canRemoveItem = !isEmpty() && (entryNodePtr != nullptr);
	if(canRemoveItem) {
		entryNodePtr->setItem(headPtr->getItem());
		Node<ItemType>* nodeToDeletePtr = headPtr;
		headPtr = headPtr->getNext();
		nodeToDeletePtr->setNext(nullptr);
		delete nodeToDeletePtr;
		nodeToDeletePtr = nullptr;
		itemCount--;
	}
	return canRemoveItem;
}

template<class ItemType>
void LinkedBag<ItemType>::clear() {
	Node<ItemType>* nodeToDeletePtr = headPtr;
	while(headPtr != nullptr) {		
		headPtr = headPtr->getNext();
		nodeToDeletePtr->setNext(nullptr);
		
	}
	delete nodeToDeletePtr;
	nodeToDeletePtr = nullptr;
	itemCount = 0;
}

template<class ItemType>
LinkedBag<ItemType>::~LinkedBag() {
	clear();
}