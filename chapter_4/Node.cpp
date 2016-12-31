/******************************************************************* 
 ** NOT MY CODE, FOLLOWED ALONG AND USED THIS CODE FOR SELF STUDY **
 ** CODE IS FROM FRANK M. CARRANO AND TIMOTHY HENRY'S DATA 		  **
 ** ABSTRACTION AND PROBLEM SOLVING WITH C++					  ** 	
 *******************************************************************/

#include "Node.h"
#include <cstddef>

// used for generics
template<class ItemType>
// default constructor 
Node<ItemType>::Node() : next(nullptr) {}


template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem) : item(anItem), next(nullptr) {}

template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem, Node<ItemType>* nextNodePtr) : item(anItem), next(nextNodePtr) {}

template<class ItemType>
void Node<ItemType>::setItem(const ItemType& anItem) {
	item = anItem;
}

template<class ItemType>
void Node<ItemType>::setNext(Node<ItemType>* nextNodePtr) {
	next = nextNodePtr;
}

template<class ItemType>
ItemType Node<ItemType>::getItem() const {
	return item;
}

template<class ItemType>
Node<ItemType>* Node<ItemType>::getNext() const {
	return next;
}