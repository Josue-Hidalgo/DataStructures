/*
 *
 * Nombre de Archivo: OrderedArrayList.h
 *
 * Descripción General:
 * 
 * Clase que implementa una lista ordenada utilizando composición
 * de un ArrayList como estructura de datos subyacente. Esta clase
 * ubica los elementos en orden ascendente al insertarlos.
 *
 * Autor: Mauricio Avilés
 *
 */

#pragma once
#include "ArrayList.h"

template <typename E>
class OrderedArrayList : public List<E> {
private:
	List<E>* data;

public:
	OrderedArrayList(int max = DEFAULT_MAX) {
		data = new ArrayList<E>(max);
	}

	~OrderedArrayList() {
		delete data;
	}

	void insert(E element) {
		data->goToStart();
		while (!data->atEnd() && element >= data->getElement())
			data->next();
		data->insert(element);
	}

	void append(E element) {
		insert(element);
	}

	E remove() {
		return data->remove();
	}

	E getElement() {
		return data->getElement();
	}

	void clear() {
		data->clear();
	}

	void goToStart() {
		data->goToStart();
	}

	void goToEnd() {
		data->goToEnd();
	}

	void goToPos(int pos) {
		data->goToPos(pos);
	}

	void next() {
		data->next();
	}

	void previous() {
		data->previous();
	}

	bool atStart() {
		return data->atStart();
	}

	bool atEnd() {
		return data->atEnd();
	}

	int getPos() {
		return data->getPos();
	}

	int getSize() {
		return data->getSize();
	}

	void print() {
		data->print();
	}

};

