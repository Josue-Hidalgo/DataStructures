
/*
 *
 * Nombre de Archivo: BSTree.h
 *
 * Descripción General:
 *
 * Clase que implementa un árbol de búsqueda binario (BST).
 * Este funciona con un nodo que tiene un puntero al izquierdo y otro al nodo 
 * derecho. De manera que podemos recorrer el árbol con los métodos de recorrido
 * tales como in-orden, pre-orden y post-orden.
 *
 * Autor: Mauricio Avilés
 *
 */

#pragma once

#include <stdexcept>
#include <iostream>
#include "BSTNode.h"
#include "DLinkedList.h"

using std::runtime_error;
using std::cout;
using std::endl;

template <typename E>
class BSTree {
private:
	BSTNode<E>* root;

	BSTNode<E>* insertAux(BSTNode<E>* current, E element) {
		if (current == nullptr)
			return new BSTNode<E>(element);
		// No duplicated elements allowed
		if (element == current->element)
			throw runtime_error("Duplicated element.");
		if (element < current->element) 
			current->left = insertAux(current->left, element);
		else 
			current->right = insertAux(current->right, element);
		return current;
	}

	bool containsAux(BSTNode<E>* current, E element) {
		if (current == nullptr)
			return false;
		if (element == current->element)
			return true;
		if (element < current->element)
			return containsAux(current->left, element);
		else
			return containsAux(current->right, element);
	}

	E findAux(BSTNode<E>* current, E element) {
		if (current == nullptr)
			throw runtime_error("Element not found.");
		if (element == current->element)
			return current->element;
		if (element < current->element)
			return findAux(current->left, element);
		else
			return findAux(current->right, element);
	}

	BSTNode<E>* removeAux(BSTNode<E>* current, E element, E* result) {
		if (current == nullptr)
			throw runtime_error("Element not found.");
		if (element < current->element) {
			current->left = removeAux(current->left, element, result);
			return current;
		}
		if (element > current->element) {
			current->right = removeAux(current->right, element, result);
			return current;
		}
		// element == current->element
		*result = current->element;
		if (current->childrenCount() == 0) {
			delete current;
			return nullptr;
		}
		if (current->childrenCount() == 1) {
			BSTNode<E>* onlyChild = current->getOnlyChild();
			delete current;
			return onlyChild;
		}
		// current->childrenCount() == 2
		BSTNode<E>* successor = getMin(current->right);
		swap(current, successor);
		current->right = removeAux(current->right, element, result);
		return current;
	}

	BSTNode<E>* getMin(BSTNode<E>* current) {
		while (current->left != nullptr)
			current = current->left;
		return current;
	}

	void swap(BSTNode<E>* node1, BSTNode<E>* node2) {
		E temp = node1->element;
		node1->element = node2->element;
		node2->element = temp;
	}

	void clearAux(BSTNode<E>* current) {
		if (current == nullptr)
			return;
		clearAux(current->left);
		clearAux(current->right);
		delete current;
	}

	void getElementsAux(BSTNode<E>* current, List<E>* elements) {
		if (current == nullptr)
			return;
		getElementsAux(current->left, elements);
		elements->append(current->element);
		getElementsAux(current->right, elements);
	}

	int getSizeAux(BSTNode<E>* current) {
		if (current == nullptr)
			return 0;
		return 1 + getSizeAux(current->left) + getSizeAux(current->right);
	}

	int heightAux(BSTNode<E>* current) {
		if (current == nullptr) return 0;
		int lh = heightAux(current->left);
		int rh = heightAux(current->right);
		return (lh > rh ? lh : rh) + 1;
	}

public:

	BSTree() {
		root = nullptr;
	}
	
	~BSTree() {
		clear();
	}

	void insert(E element) {
		root = insertAux(root, element);
	}

	bool contains(E element) {
		return containsAux(root, element);
	}

	E find(E element) {
		return findAux(root, element);
	}

	E remove(E element) {
		E result;
		root = removeAux(root, element, &result);
		return result;
	}

	void clear() {
		clearAux(root);
		root = nullptr;
	}

	List<E>* getElements() {
		List<E>* elements = new DLinkedList<E>();
		getElementsAux(root, elements);
		return elements;
	}

	int getSize() {
		return getSizeAux(root);
	}

	int height() {
		return heightAux(root);
	}

	void print() {
		List<E>* elements = getElements();
		elements->print();
		delete elements;
	}
};

