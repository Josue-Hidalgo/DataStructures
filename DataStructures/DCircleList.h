/*
 *
 * Nombre de Archivo: DCircleList.h
 *
 * Descripción General:
 *
 * Clase hija de List que implementa una lista circular de elementos de tipo E por
 * medio de nodos doblemente enlazados. Esta clase permite la inserción, eliminación y
 * otras operaciones sobre la lista.
 *
 * Autor: Mauricio Avilés // Josué Hidalgo
 *
 */

#pragma once

#include "CList.h"

#include <iostream>
#include <stdexcept>
#include "DNode.h"

using std::cout;
using std::endl;
using std::runtime_error;
using std::cin;

template <typename E>
class DCircleList : public CList<E> {
public:
	DNode<E>* current;
	int size;

	void insertInitialNode(E element) {
		current->previous = current->next = current = new DNode<E>(element);
	}

	E removeLastNode() {
		E result = current->element;
		delete current;
		current = nullptr;
		return result;
	}

private:

	void insert(E element) {
		if (size == 0)
			insertInitialNode(element);
		else
			current->next = current->next->previous = new DNode<E>(element, current->next, current);
		size++;
	}

	void insertBack(E element) {
		if (size == 0)
			insertInitialNode(element);
		else
			current = current->next = current->next->previous = new DNode<E>(element, current->next, current);
		size++;
	}

	E remove() {
		
		if (size == 0)
			throw runtime_error("List is Empty");

		E result = current->next->element;

		if (size == 1)
			return removeLastNode();
		
		else {
			DNode<E>* temp = current->next;
			current->next = current->next->next;
			current->next->previous = current;
			delete temp;
		}
		size--;
		return result;
	}

	E removeBack() {

		if (size == 0)
			throw runtime_error("List is Empty");

		E result = current->element;

		if (size == 1)
			return removeLastNode();

		else {
			DNode<E>* temp = current;
			while (current->next != temp)
				current = current->next;
			current->next = current->next->next;
			current->next->previous = current;	
			delete temp;
		}
		size--;
		return result;
	}

	void clear() {
		while (size > 0)
			remove();
	}

	E getFront() {
		if (size == 0)
			throw runtime_error("List is Empty");
		return current->next->element;
	}

	E getBack() {
		if (size == 0)
			throw runtime_error("List is Empty");
		return current->element;
	}

	void next() {
		if (size == 0)
			throw runtime_error("List is Empty");
		current = current->next;
	}

	void previous() {
		if (size == 0)
			throw runtime_error("List is Empty");
		current = current->previous;
	}

	int getSize() {
		return size;
	}

	void print() {
		if (size == 0)
			throw runtime_error("List is Empty");
		DNode<E>* temp = current;
		cout << "[ ";
		for (int i = 0; i < size; i++) {
			cout << temp->element << " ";
			temp = temp->next;
		}
		cout << "]" << endl;
	}

};