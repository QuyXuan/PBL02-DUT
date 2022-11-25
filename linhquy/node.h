#pragma once
#include<iostream>
using namespace std;

template<class T>
class list;

template<class T>
class node {
private:
	T data;
	node* next;
public:
	node();
	node(T x);
	node* getNext();
	T getData();
	friend class list<T>;
};

template<class T>
node<T>::node() {
	next = NULL;
}


template<class T>
T node<T>::getData() {
	return data;
}

template<class T>
node<T>* node<T>::getNext() {
	return next;
}

template<class T>
node<T>::node(T x) {
	data = x;
	next = NULL;
}
