/*
 *
 * Nombre de Archivo: BSTNode.h
 *
 * Descripción General:
 *
 * Nodo que nos ayuda a implementar un árbol binario de búsqueda (BST).
 *
 * Autor: Mauricio Avilés
 *
 */

#pragma once

template <typename E>
class BSTNode {
public:
	E element;
	BSTNode<E>* left;
	BSTNode<E>* right;

	BSTNode(E element) {
		this->element = element;
		left = right = nullptr;
	}

	BSTNode(E element, BSTNode<E>* left, BSTNode<E>* right) {
		this->element = element;
		this->left = left;
		this->right = right;
	}

	int childrenCount() {
		return (left == nullptr? 0 : 1) + (right == nullptr? 0 : 1);
	}

	BSTNode<E>* getOnlyChild() {
		return left == nullptr ? right : left;
	}

};

