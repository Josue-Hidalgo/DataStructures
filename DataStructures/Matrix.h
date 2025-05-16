/*
 *
 * Nombre de Archivo: Matrix.h
 *
 * Descripción General:
 *
 * Clase que representa una matriz de tamaño variable, con métodos para
 * realizar operaciones básicas como agregar o eliminar filas y columnas,
 * e incluso transpocisionar la matriz.
 *
 * Autor: Mauricio Avilés // Josué Hidalgo
 *
 */

#pragma once

#include <iostream>
#include <stdexcept>

using std::runtime_error;
using std::cout;
using std::endl;

template<typename E>
class Matrix {
private:
	E** matrix;
	int rows;
	int cols;

public:
	Matrix(int rows, int cols) {
		if (rows < 1 || cols < 1)
			throw runtime_error("Rows and columns must be positive integers.");
		matrix = new E * [rows];
		for (int i = 0; i < rows; i++)
			matrix[i] = new E[cols];
		this->rows = rows;
		this->cols = cols;
	}

	~Matrix() {
		for (int i = 0; i < rows; i++)
			delete[] matrix[i];
		delete[] matrix;
	}

	void set(int r, int c, E value) {
		if (r < 0 || r >= rows)
			throw runtime_error("Invalid row.");
		if (c < 0 || c >= cols)
			throw runtime_error("Invalid column.");
		matrix[r][c] = value;
	}

	E get(int r, int c) {
		if (r < 0 || r >= rows)
			throw runtime_error("Invalid row.");
		if (c < 0 || c >= cols)
			throw runtime_error("Invalid column.");
		return matrix[r][c];
	}
	
	int getRows() { return rows; }

	int getCols() { return cols; }

	void setAll(E value) {
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				matrix[i][j] = value;
	}

	void addRow(E value) {
		E** temp = new E * [rows + 1];
		for (int i = 0; i < rows; i++)
			temp[i] = matrix[i];
		delete[] matrix;
		matrix = temp;
		matrix[rows] = new E[cols];
		for (int i = 0; i < cols; i++)
			matrix[rows][i] = value;
		rows++;
	}

	void addColumn(E value) {
		for (int i = 0; i < rows; i++) {
			E* newRow = new E[cols + 1];
			for (int j = 0; j < cols; j++)
				newRow[j] = matrix[i][j];
			newRow[cols] = value;
			delete[] matrix[i];
			matrix[i] = newRow;
		}
		cols++;
	}

	void removeCol(int c) {
		if (c < 0 || c >= cols) 
			throw runtime_error("Invalid column index.");

		for (int i = 0; i < rows; i++) {
			E* newRow = new E[cols - 1];
			int pos = 0;

			for (int j = 0; j < cols; j++) {
				if (!(c == j)){
					newRow[pos] = matrix[i][j];
					pos++;
				}
			}

			delete[] matrix[i];
			matrix[i] = newRow;
		}

		cols--;
	}

	void removeRow(int r) {
		if (r < 0 || r >= rows)
			throw runtime_error("Invalid row index.");

		// Liberar la memoria de la fila eliminada
		delete[] matrix[r];

		E** newPointerArray = new E * [rows - 1];
		int pos = 0;

		for (int i = 0; i < rows; i++) {
			if (i != r) { // Copiar todas las filas excepto la eliminada
				newPointerArray[pos] = matrix[i];
				pos++;
			}
		}
		delete[] matrix;
		matrix = newPointerArray;
		rows--;
	}

	void transpose() {
		E** temp = new E * [cols];
		for (int i = 0; i < cols; i++)
			temp[i] = new E[rows];

		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++)
				temp[j][i] = matrix[i][j];
		}

		for (int i = 0; i < rows; i++)
			delete[] matrix[i];
		delete[] matrix;

		matrix = temp;
		int tempRows = rows;
		rows = cols;
		cols = tempRows;
	}

	void print() {
		for (int i = 0; i < rows; i++) {
			cout << "[ " << "\t";
			for (int j = 0; j < cols; j++)
				cout << matrix[i][j] << "\t";
			cout << "]" << endl;
		}
	}
};

