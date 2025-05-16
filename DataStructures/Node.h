/*
 *
 * Nombre de Archivo: Node.h
 *
 * Descripción General:
 *
 * Nodo que nos ayuda a implementar [Listas, Pilas y Colas] Enlazadas simples.
 *
 * Autor: Mauricio Avilés
 *
 */

#pragma once

template <typename E>
class Node {
public:
	E element;
	Node<E>* next;

	Node(E element, Node<E>* next = nullptr) {
		this->element = element;
		this->next = next;
	}

	Node(Node<E>* next = nullptr) {
		this->next = next;
	}
};

