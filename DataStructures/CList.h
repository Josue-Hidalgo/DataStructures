
/*
 *
 * Nombre de Archivo: CList.h
 *
 * Descripción General:
 *
 * Esta es una interfaz que nos ayuda a implementar una lista cirrcular
 * en la que podemos insertar elementos al frente y al final. Esta es una serie
 * de nodos enlazados que forman un ciclo, por lo que el último nodo apunta al primero.
 *
 * Autor: Mauricio Avilés
 *
 */

#pragma once  

template <typename E>
class CList {
private:
	CList(const CList<E>& other) {}
	void operator =(const CList<E>& other) {}

public:
	
	CList() {}
	virtual ~CList() {}

	virtual void insert(E element) = 0;
	virtual void insertBack(E element) = 0;
	virtual E remove() = 0;
	virtual E removeBack() = 0;
	virtual void clear() = 0;
	virtual E getFront() = 0;
	virtual E getBack() = 0;
	virtual void next() = 0;
	virtual void previous() = 0;
	virtual int getSize() = 0;
	virtual void print() = 0;
};
