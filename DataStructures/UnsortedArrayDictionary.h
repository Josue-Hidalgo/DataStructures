/*
 *
 * Nombre de Archivo: UnsortedArrayDictionary.h
 *
 * Descripción General:
 *
 * Esta clase implementa un diccionario genérico utilizando un arreglo
 * que almacena pares clave-valor. La clase hereda de la clase abstracta
 * llamada Dictionary y proporciona métodos para insertar, eliminar y
 * realizar búsquedas de pares clave-valor.
 *
 * Autor: Mauricio Avilés
 *
 */

#pragma once

#include <stdexcept>

#include "Dictionary.h"
#include "ArrayList.h"
#include "DLinkedList.h"
#include "KVPair.h"

using std::runtime_error;

template <typename K, typename V>
class UnsortedArrayDictionary : public Dictionary<K, V> {
private:
	List<KVPair<K, V>>* pairs;

	void checkNotExisting(K key) {
		KVPair<K, V> p(key);
		pairs->goToStart();
		while (!pairs->atEnd()) {
			if (p == pairs->getElement())
				throw runtime_error("Duplicated key.");
			pairs->next();
		}
	}

	void checkExisting(K key) {
		KVPair<K, V> p(key);
		pairs->goToStart();
		while (!pairs->atEnd()) {
			if (p == pairs->getElement())
				return;
			pairs->next();
		}
		throw runtime_error("Key not found.");
	}

public:
	UnsortedArrayDictionary(int max = DEFAULT_MAX) {
		pairs = new ArrayList<KVPair<K, V>>(max);
	}

	~UnsortedArrayDictionary() {
		delete pairs;
	}

	void insert(K key, V value) {
		checkNotExisting(key);
		KVPair<K, V> p(key, value);
		pairs->append(p);
	}

	V remove(K key) {
		checkExisting(key);
		KVPair<K, V> p = pairs->remove();
		return p.value;
	}

	V getValue(K key) {
		checkExisting(key);
		KVPair<K, V> p = pairs->getElement();
		return p.value;
	}

	void setValue(K key, V value) {
		checkExisting(key);
		KVPair<K, V> p(key, value);
		pairs->remove();
		pairs->append(p);
	}

	bool contains(K key) {
		KVPair<K, V> p(key);
		pairs->goToStart();
		while (!pairs->atEnd()) {
			if (p == pairs->getElement())
				return true;
			pairs->next();
		}
		return false;
	}

	List<K>* getKeys() {
		List<K>* keys = new DLinkedList<K>();
		pairs->goToStart();
		while (!pairs->atEnd()) {
			KVPair<K, V> p = pairs->getElement();
			keys->append(p.key);
			pairs->next();
		}
		return keys;
	}

	List<V>* getValues() {
		List<V>* values = new DLinkedList<V>();
		pairs->goToStart();
		while (!pairs->atEnd()) {
			KVPair<K, V> p = pairs->getElement();
			values->append(p.value);
			pairs->next();
		}
		return values;
	}

	int getSize() {
		return pairs->getSize();
	}

	void print() {
		pairs->print();
	}
};

