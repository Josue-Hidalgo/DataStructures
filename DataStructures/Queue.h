/*
 *
 * Nombre de Archivo: Queue.h
 *
 * Descripción General:
 *
 * Clase abstracta que define la interfaz de una cola. Esta clase no puede ser instanciada.
 * Una cola es una estructura de datos que permite almacenar elementos en un orden de manera que
 * se puedan agregar elementos al final y eliminar/sacar elementos del principio.
 *
 * Autor: Mauricio Avilés
 *
 */

#pragma once

template <typename E>
class Queue {
private:
	Queue(const Queue<E>& other) {}
	void operator=(const Queue<E>& other) {}

public:

	Queue() {}
	virtual ~Queue() {}
	virtual void enqueue(E element) = 0;
	virtual E dequeue() = 0;
	virtual E frontValue() = 0;
	virtual void clear() = 0;
	virtual bool isEmpty() = 0;
	virtual int getSize() = 0;
	virtual void print() = 0;

};

