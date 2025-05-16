/*
 * 
 * Nombre de Archivo: BSTDictionary.h
 * 
 * Descripci�n General: 
 * 
 * Este archivo contiene la definici�n de la clase BSTDictionary, que es una implementaci�n
 * de un diccionario utilizando un �rbol binario de b�squeda (BST). La clase hereda de la
 * clase asbtracta Dictionary y proporciona m�todos para insertar, eliminar y buscar pares clave-valor.
 * 
 * Autor: Josue Hidalgo // Mauricio Avil�s
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

