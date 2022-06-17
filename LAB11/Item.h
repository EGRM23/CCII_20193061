#ifndef ITEM_H
#define ITEM_H
#include <iostream>
using namespace std;

//EDUARDO GERMAN RUIZ MAMANI
//CUI: 20193061

template <typename R> class Stack;
template <typename R> class Item {
public:
	Item(R val, Item* = NULL);
	~Item();
	friend class Stack<R>;
private:
	Item* debajo;
	R valor;
};


template <typename R>
Item<R> :: Item(R val, Item* d) {
	valor = val;
	debajo = d;
}

template <typename R>
Item<R> :: ~Item() {}

#endif

