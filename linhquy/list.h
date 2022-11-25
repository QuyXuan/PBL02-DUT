#pragma once
#include"node.h"
template<class T>
class list {
protected:
	int size;
	node<T>* head;
	node<T>* tail;
public:
	int getSize();
	list();
	void push_back(T x);
	void push_front(T x);
	void pop_back();
	void pop_front();
	bool remove(T x);
	node<T>* search(T x);
	template<class U>
	friend ostream& operator  <<(ostream& os, const list<U>& l);
};

template<class T>
list<T>::list() {
	size = 0;
	head = tail = NULL;
}

template<class T>
void list<T>::push_back(T x) {
	node<T>* temp = new node<T>(x);
	if (head == NULL) {
		head = tail = temp;
	}
	else {
		tail->next = temp;
		tail = temp;
	}

	size++;
}

template<class T>
void list<T>::push_front(T x) {
	node<T>* temp = new node<T>(x);
	if (head == NULL)
		head = tail = temp;
	else {
		temp->next = head;
		head = temp;
	}

	size++;
}

template<class T>
void list<T>::pop_back() {
	if (size == 0)
		return;
	node<T>* temp = head;
	while (temp->next != tail) {
		temp = temp->next;
	}

	delete tail;
	tail = temp;
	temp->next = NULL;
	size--;
}


template<class T>
bool list<T>::remove(T x) {
	if (head == NULL)
		return false;

	node<T>* after = head, * before = NULL;
	while (after && after->data != x) {
		before = after;
		after = after->next;
	}

	if (after != NULL) {
		size--;
		if (after == head)
			head = head->next;
		else before->next = after->next;
		if (after->next == NULL)
			tail = before;
		delete after;
		return true;
	}
	return false;
}

template<class T>
ostream& operator << (ostream& os, const list<T>& l) {
	node<T>* temp = l.head;
	while (temp) {
		os << temp->getData()<<" ";
		temp = temp->getNext();
	}
	return os;
}

template<class T>
node<T>* list<T>::search(T x) {
	node<T>* temp = head;
	while (temp) {
		if (temp->data == x)
			return temp;
		temp = temp->next;
	}

	return NULL;
}

template<class T>
int list<T>::getSize() {
	return size;
}