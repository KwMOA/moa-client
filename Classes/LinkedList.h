#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

#include <iostream>
#include <iterator>

using namespace std;

template <class item>
class node {

private:
	item data;
	node* prev;
	node* next;
public:
	node() { data = NULL; prev = NULL; next = NULL; }
	node(item _data) { data = _data; prev = NULL; next = NULL; }
	void setPrev(node* _prev) { prev = _prev; }
	void setNext(node* _next) { next = _next; }
	void setData(item _data) { data = _data; }

	node* getPrev() { return prev; }
	node* getNext() { return next; }
	item getData() { return data; }
};

template <class item>
class LinkedList
{
private:
	int clickedBuildingNo;
	int clickedUnitNo;
	int clickedUpgradeNo;
	int upgradeCount;
	node<item>* head_ptr;
	node<item>* tail_ptr;
	void hang_node(node<item>* prev_node, node<item>* new_node);
public:
	class iterator {
		node<item>* itr;
	public:
		iterator() { itr = NULL; }
		iterator(node<item>* node) { itr = node; }
		item getData()const { return itr->getData(); }
		item &operator*()const { return itr->getData(); }
		item *operator->()const { return &itr->getData(); }
		iterator operator ++(int) {
			iterator old = *this;
			itr = itr->getNext();
			return old;
		}
		bool operator ==(const iterator right)const { return itr == right.itr; }
		bool operator !=(const iterator right)const { return itr != right.itr; }

	};


	iterator begin() {
		return iterator(head_ptr->getNext());
	}
	iterator end() {
		return iterator(tail_ptr->getPrev());
	}
	LinkedList();
	bool isEmpty();
	void insert(node<item>* prev_node, item data);
	void insert_head(item data);
	void insert_tail(item data);
	void insert_location(size_t loc, item data);
	node<item>* search_node(item data);
	item getFront();
	size_t list_length();
	item pop();
	void remove_head_node();
	void remove_section_node(node<item>* from_node, node<item>* to_node);
	void remove_section_node(node<item>* from_node, node<item>* to_node, node<item>* end_node);
	void insert_section_node(node<item>* from_node, node<item>* to_node, node<item>* insert_node);
	void print_content();
	void setClickedBuilding(int no);
	void setClickedUnit(int no);
	void setUpgradeCount(int no);
	int getUpgradeCount();
	int getClickedBuilding();
	int getClickedUnit();
	int getClickedUpgrade();
};

template <class item>
int LinkedList<item>::getClickedUpgrade() {
	clickedUpgradeNo = clickedUnitNo - upgradeCount;
	return clickedUpgradeNo;
}
template <class item>
void LinkedList<item>::setUpgradeCount(int no) {
	upgradeCount = no;
}

template <class item>
int LinkedList<item>::getUpgradeCount() {
	return upgradeCount;
}

template <class item>
void LinkedList<item>::setClickedUnit(int no) {
	clickedUnitNo = no;
}

template <class item>
int LinkedList<item>::getClickedUnit() {
	return clickedUnitNo;
}

template <class item>
item LinkedList<item>::pop() {
	node<item>* del_node = new node<item>();
	item data;
	if(head_ptr->getNext() != tail_ptr->getPrev()){
	del_node = head_ptr->getNext();
	data = del_node->getData();
	head_ptr->setNext(del_node->getNext());
	del_node->getNext()->setPrev(NULL);
	}
	else {
		del_node = head_ptr->getNext();
		data = del_node->getData();
		head_ptr->setNext(NULL);
		del_node->setPrev(NULL);
	}

	delete del_node;

	return data;
}

template<class item>
void LinkedList<item>::hang_node(node<item>* prev_node, node<item>* new_node)
{
	new_node->setNext(prev_node->getNext());
	new_node->setPrev(prev_node);
	prev_node->getNext()->setPrev(new_node);
	prev_node->setNext(new_node);
}

template<class item>
LinkedList<item>::LinkedList() {
	head_ptr = new node<item>();
	tail_ptr = new node<item>();
	clickedBuildingNo = -1;
	clickedUnitNo = -1;
	clickedUpgradeNo = -1;
	upgradeCount = 0;
}

template<class item>
void LinkedList<item>::insert_head(item data)
{
	node<item>* new_node = new node<item>(data);

	if (isEmpty()) {
		head_ptr->setNext(new_node);
		tail_ptr->setPrev(new_node);

	}
	else {
		new_node->setNext(head_ptr->getNext());
		head_ptr->getNext()->setPrev(new_node);
		head_ptr->setNext(new_node);
	}
}

template<class item>
void LinkedList<item>::insert_tail(item data)
{
	node<item>* new_node = new node<item>(data);

	if (isEmpty()) {
		head_ptr->setNext(new_node);
		tail_ptr->setPrev(new_node);

	}
	else {
		new_node->setPrev(tail_ptr->getPrev());
		tail_ptr->getPrev()->setNext(new_node);
		tail_ptr->setPrev(new_node);
	}
}

template<class item>
void LinkedList<item>::insert_location(size_t loc, item data)
{
	node<item>* new_node = new node<item>(data);
	node<item>* cursor;
	size_t location = 0;
	for (cursor = head_ptr->getNext(); location != loc; cursor = cursor->getNext()) {
		location++;
	}

	hang_node(cursor, new_node);

}

template<class item>
node<item>* LinkedList<item>::search_node(item data)
{
	node<item>* cursor = new node<item>();
	for (cursor = head_ptr->getNext(); cursor != NULL; cursor = cursor->getNext()) {
		if (cursor->getData() == data)
			return cursor;
	}
	return NULL;
}

template<class item>
void LinkedList<item>::print_content()
{
	node<item>* cursor = 0;
	for (cursor = head_ptr->getNext(); cursor != NULL; cursor = cursor->getNext())
	{
		std::cout << cursor->getData() << " ";
	}
	std::cout << endl;
}

template<class item>
void LinkedList<item>::setClickedBuilding(int no)
{
	clickedBuildingNo = no;
}

template<class item>
int LinkedList<item>::getClickedBuilding() {
	return clickedBuildingNo;
}



template<class item>
bool LinkedList<item>::isEmpty()
{
	if (head_ptr->getNext() == NULL) {
		return true;
	}

	return false;
}

template<class item>
item LinkedList<item>::getFront()
{
	return head_ptr->getNext()->getData();
}

template<class item>
size_t LinkedList<item>::list_length()
{
	node<item>* cursor;
	size_t length = 0;
	for (cursor = head_ptr->getNext(); cursor != NULL; cursor = cursor->getNext()) {
		length++;
	}
	return length;
}

template<class item>
void LinkedList<item>::remove_head_node()
{

}

template<class item>
void LinkedList<item>::remove_section_node(node<item>* from_node, node<item>* to_node)
{
	node<item>* del_node;
	del_node = from_node->getNext();
	to_node->getPrev()->setNext(NULL);
	from_node->setNext(to_node);
	to_node->setPrev(from_node);

	//node<item>* cursor;
	//for (cursor = del_node; cursor != NULL; cursor = del_node->getNext()) {
	//delete cursor;
	//}
}

template<class item>
void LinkedList<item>::remove_section_node(node<item>* from_node, node<item>* to_node, node<item>* end_node) {
	if (to_node == NULL) {
		to_node = end_node;
	}
	node<item>* del_node;
	del_node = from_node->getNext();
	to_node->getPrev()->setNext(NULL);
	from_node->setNext(to_node);
	to_node->setPrev(from_node);

}

template<class item>
void LinkedList<item>::insert(node<item>* prev_node, item data)
{
	node<item>* new_node = new node<item>(data);
	hang_node(prev_node, new_node);
}



#endif // __LINKEDLIST_H__
