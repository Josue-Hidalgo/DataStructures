/*
 *
 * Nombre de Archivo: AVLTree.h
 *
 * Descripción General:
 *
 * Clase que implementa un árbol AVL, que es un árbol binario de búsqueda
 * que se auto-balancea. Esto significa que la diferencia de altura entre
 * los subárboles izquierdo y derecho de cualquier nodo es como máximo 1.
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
class AVLTree {

private:
	BSTNode<E>* root;

	BSTNode<E>* insertAux(BSTNode<E>* current, E element) {
		if (current == nullptr)
			return new BSTNode<E>(element);
		// este caso es para cuando el árbol no acepta repetidos
		if (element == current->element)
			throw runtime_error("Duplicated element.");
		if (element < current->element) {
			current->left = insertAux(current->left, element);
			current = rebalanceLeft(current);
		}
		else {
			current->right = insertAux(current->right, element);
			current = rebalanceRight(current);
		}
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
			return rebalanceRight(current);
		}
		if (element > current->element) {
			current->right = removeAux(current->right, element, result);
			return rebalanceLeft(current);
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
		return rebalanceLeft(current);
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

	BSTNode<E>* rotateRight(BSTNode<E>* current) {
		if (current == nullptr)
			throw runtime_error("Can't rotate right with null root.");
		if (current->left == nullptr)
			throw runtime_error("Can't rotate right with null left child.");
		BSTNode<E>* temp = current->left;
		current->left = temp->right;
		temp->right = current;
		return temp;
	}

	BSTNode<E>* rotateLeft(BSTNode<E>* current) {
		if (current == nullptr)
			throw runtime_error("Can't rotate left with null root.");
		if (current->right == nullptr)
			throw runtime_error("Can't rotate left with null right child.");
		BSTNode<E>* temp = current->right;
		current->right = temp->left;
		temp->left = current;
		return temp;
	}

	BSTNode<E>* rebalanceLeft(BSTNode<E>* current) {
		int lh = heightAux(current->left);
		int rh = heightAux(current->right);
		if (lh - rh > 1) {
			int llh = heightAux(current->left->left);
			int lrh = heightAux(current->left->right);
			if (llh >= lrh)
				// zig-zig
				return rotateRight(current);
			else {
				// zig-zag
				current->left = rotateLeft(current->left);
				return rotateRight(current);
			}
		}
		return current;
	}

	BSTNode<E>* rebalanceRight(BSTNode<E>* current) {
		int rh = heightAux(current->right);
		int lh = heightAux(current->left);
		if (rh - lh > 1) {
			int rrh = heightAux(current->right->right);
			int rlh = heightAux(current->right->left);
			if (rrh >= rlh)
				// zig-zig
				return rotateLeft(current);
			else {
				// zig-zag
				current->right = rotateRight(current->right);
				return rotateLeft(current);
			}
		}
		return current;
	}


public:
	AVLTree() {
		root = nullptr;
	}

	~AVLTree() {
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



