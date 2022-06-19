#ifndef ITEM_H
#define ITEM_H
#include <iostream>
using namespace std;

//EDUARDO GERMAN RUIZ MAMANI
//CUI: 20193061

template <typename R> class Cola;
template <typename R> class Item {
public:
	Item(R val, Item* = NULL);
	~Item();
	friend class Cola<R>;
private:
	Item* detras;
	R valor;
};


template <typename R>
Item<R> :: Item(R val, Item* d) {
	valor = val;
	detras = d;
}

template <typename R>
Item<R> :: ~Item() {}

#endif
