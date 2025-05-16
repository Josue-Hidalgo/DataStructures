/*
 * 
 * Nombre de Archivo: BSTDictionary.h
 * 
 * Descripción General: 
 * 
 * Este archivo contiene la definición de la clase BSTDictionary, que es una implementación
 * de un diccionario utilizando un árbol binario de búsqueda (BST). La clase hereda de la
 * clase asbtracta Dictionary y proporciona métodos para insertar, eliminar y buscar pares clave-valor.
 * 
 * Autor: Josue Hidalgo // Mauricio Avilés
 * 
 */

#pragma once

#include <stdexcept>
#include <iostream>
#include "Dictionary.h"
#include "BSTree.h"
#include "KVPair.h"

using std::runtime_error;
using std::cout;
using std::endl;

template <typename K, typename V>
class BSTDictionary : public Dictionary<K, V> {
private:
	BSTree<KVPair<K, V>>* pairs;

public:
	BSTDictionary() {
		pairs = new BSTree<KVPair<K, V>>();
	}
	// completar para la tarea 5
};

