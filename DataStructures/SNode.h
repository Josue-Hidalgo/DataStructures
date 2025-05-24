/* 
 * Nombre de Archivo: SNode.h
 * 
 * Descripci�n General:
 * 
 * Es un nodo que se utiliza para implementar un �rbol Splay. 
 * Este funciona teniendo adem�s de un elemento, un puntero 
 * para el hijo izquierdo, el hijo derecho y el padre.
 * 
 * Autor: Mauricio Avil�s
 * 
 */

#ifndef SNODE_H // para evitar incluir el archivo m�s de una vez
#define SNODE_H // definir el archivo

template <typename E>
class SNode {
public:
    SNode<E> *left;
    SNode<E> *right;
    SNode<E> *parent;
    E element;

    SNode(E element) {
        this->element = element;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
    }

    int childrenCount() {
        return (left == nullptr? 0 : 1) + (right == nullptr? 0 : 1);
    }
    
    SNode<E>* getOnlyChild() {
        return (left == nullptr? right : left);
    }

};

#endif // SNODE_H
