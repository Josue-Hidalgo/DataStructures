/*
 *
 * Nombre de Archivo: CircleList.h
 *
 * Descripción General:
 *
 * Clase hija de List que implementa una lista circular de elementos de tipo E por
 * medio de nodos enlazados. Esta clase permite la inserción, eliminación y
 * otras operaciones sobre la lista.
 *
 * Autor: Mauricio Avilés // Josué Hidalgo
 *
 */

#pragma once

#include <iostream>
#include <stdexcept>
#include "Node.h"
#include "CList.h"

using std::cout;
using std::endl;
using std::runtime_error;

template <typename E>
class CircleList : public CList<E> {
public:
	Node<E>* current;
	int size;

	void insertInitialNode(E element) {
		current->next = current = new Node<E>(element);
	}
	
	E removeLastNode() {
		E result = current->next->element;
		delete current;
		current = nullptr;
		return result;
	}

private:

	void insert(E element) {
		if (size == 0)
			insertInitialNode(element);
		else
			current->next = new Node<E>(element, current->next);
		size++;
	}

	void insertBack(E element) {
		if (size == 0)
			insertInitialNode(element);
		else
			current = current->next = new Node<E>(element, current->next);
		size++;
	}

	E remove() {
		if (size == 0)
			throw runtime_error("List is Empty");
		E result = current->next->element;
		if (size == 1)
			return removeLastNode();
		else {
			Node<E>* temp = current->next;
			current->next = temp->next;
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
			Node<E>* temp = current;
			while (temp->next != current) {
				temp = temp->next;
			}
			temp->next = current->next;
			delete current;
			current = temp;
		}
		size--;
		return result;
	}

	void clear() { //	MEJORAR
		while (size != 0)
			remove();
	}

	E getFront() {
		if (size == 0)
			throw runtime_error("List is empty");

		return current->next->element;
	}

	E getBack() {
		if (size == 0)
			throw runtime_error("List is empty");
		return current->element;
	}

	void next() {
		current = current->next;
	}

	void previous() {
		Node<E>* temp = current;
		while (temp->next != current) {
			temp = temp->next;
		}
		current = temp;
	}

	int getSize() {
		return size;
	}

	void print() {
		if (size == 0) 
			throw runtime_error("List is empty");

		Node<E>* temp = current->next;
		cout << "[ ";
		do {
			cout << temp->element << " ";
			temp = temp->next;
		} while (temp != current->next);
		cout << "]" << endl;
	}

};