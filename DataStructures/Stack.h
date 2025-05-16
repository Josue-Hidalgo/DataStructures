
/*
 *
 * Nombre de Archivo: Stack.h
 *
 * Descripción General:
 *
 * Esta clase es una interfaz abstracta para la implementación de una pila.
 * En el que una pila se entiende como una estructura de datos que permite almacenar
 * datos de forma que el último elemento en entrar es el primero en salir (LIFO).
 *
 * Autor: Mauricio Avilés
 *
 */

#pragma once

template <typename E>
class Stack {
private:
	Stack(const Stack<E>& other) {}
	void operator =(const Stack<E>& other) {}

public:
	Stack() {}
	virtual ~Stack() {}
	virtual void push(E element) = 0;
	virtual E pop() = 0;
	virtual E topValue() = 0;
	virtual void clear() = 0;
	virtual bool isEmpty() = 0;
	virtual int getSize() = 0;
	virtual void print() = 0;
};

