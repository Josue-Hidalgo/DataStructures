/*
 *
 * Nombre de Archivo: PriorityQueue.h
 *
 * Descripci�n General:
 *
 * Clase abstracta que define la interfaz de una cola de prioridad. Esta clase no puede ser instanciada.
 * Esta clase define los m�todos que deben implementar las clases que tengan una cola de prioridad como 
 * parte de su implementaci�n o la forma de una cola de prioridad. Nos funcionar� para las clases
 * HeapPriorityQueue y LinkedPriorityQueue.
 *
 * Autor: Mauricio Avil�s // Josu� Hidalgo
 *
 */

#pragma once

template <typename E>
class PriorityQueue {
private:
	PriorityQueue(const PriorityQueue<E>& other) {}
	void operator =(const PriorityQueue<E>& other) {}

public:
	PriorityQueue() {}
	virtual ~PriorityQueue() {}
	virtual void insert(E element, int priority) = 0;
	virtual E min() = 0;
	virtual E removeMin() = 0;
	virtual void clear() = 0;
	virtual int getSize() = 0;
	virtual bool isEmpty() = 0;
	virtual void print() = 0;
};

