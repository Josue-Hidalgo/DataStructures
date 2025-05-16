/*
 *
 * Nombre de Archivo: BSTNode.h
 *
 * Descripci�n General:
 *
 * Nodo que nos ayuda a implementar un �rbol binario de b�squeda (BST).
 *
 * Autor: Mauricio Avil�s
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

	int childrenCount() {
		return (left == nullptr? 0 : 1) + (right == nullptr? 0 : 1);
	}

	BSTNode<E>* getOnlyChild() {
		return left == nullptr ? right : left;
	}

};

