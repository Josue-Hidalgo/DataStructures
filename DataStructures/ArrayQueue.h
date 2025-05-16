/*
 *
 * Nombre de Archivo: ArrayQueue.h
 *
 * Descripción General:
 *
 * Clase hija que implementa una cola utilizando un Array.
 *
 * Autor: Mauricio Avilés
 *
 */

#pragma once

#define DEFAULT_MAX 1024

#include <stdexcept>
#include <iostream>

#include "Queue.h"

using std::runtime_error;
using std::cout;
using std::endl;

template <typename E>
class ArrayQueue : public Queue<E> {
private:
	E* elements;
	int front;
	int back;
	int size;
	int max;

public:
	ArrayQueue(int max = DEFAULT_MAX) {
		if (max < 1)
			throw runtime_error("Invalid max size.");
		elements = new E[max];
		size = back = front = 0;
		this->max = max;
	}

	~ArrayQueue() {
		delete[] elements;
	}

	void enqueue(E element) {
		if (size == max)
			throw runtime_error("Queue is full.");
		elements[back] = element;
		back = (back + 1) % max;
		size++;
	}

	E dequeue() {
		if (size == 0)
			throw runtime_error("Queue is empty.");
		front = (front + 1) % max;
		size--;
		return elements[(front + max - 1) % max];
	}

	E frontValue() {
		if (size == 0)
			throw runtime_error("Queue is empty.");
		return elements[front];
	}

	void clear() {
		front = back = size = 0;
		//delete[] elements;
		//elements = new E[max];
	}

	bool isEmpty() {
		return size == 0;
	}

	int getSize() {
		return size;
	}

	void print() {
		cout << "[ ";
		for (int i = front; i != back; i = (i + 1) % max)
			cout << elements[i] << " ";
		cout << "]" << endl;
	}

};

