/*
 * Nombre del Archivo: TrieNode.h
 * 
 * Descripción General:
 * 
 * El TrieNode es una clase que representa un nodo en la estructura
 * de datos Trie. Cada nodo contiene información sobre si es un
 * nodo final de una palabra, el conteo de prefijos que pasan.
 * 
 * 
 * 
 */

#pragma once

#include "UnsortedArrayDictionary.h"
#include "List.h"

class TrieNode {
public:
	bool isFinal;
	int prefixCount;
	Dictionary<char, TrieNode*>* children;

	TrieNode() {
		isFinal = false;
		prefixCount = 0;
		children = new UnsortedArrayDictionary<char, TrieNode*>(256);
	}
	~TrieNode() {
		delete children;
	}
	bool containsChild(char c) {
		return children->contains(c);
	}
	TrieNode* getChild(char c) {
		return children->getValue(c);
	}
	void addChild(char c) {
		children->insert(c, new TrieNode());
	}
	void removeChild(char c) {
		children->remove(c);
	}
	List<char>* getChildren() {
		return children->getKeys();
	}
};

