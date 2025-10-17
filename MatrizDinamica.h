#ifndef MATRIZDINAMICA_H
#define MATRIZDINAMICA_H

#include <iostream>
using namespace std;

// Matriz que funciona con cualquier tipo (int, float, double)
template <typename T>
class MatrizDinamica {
private:
    T **datos;    // Puntero doble para matriz 2D
    int filas;     
    int columnas;  

public:
    // Constructor: crea matriz de f x c
    MatrizDinamica(int f, int c) {
        filas = f;
        columnas = c;
        
        // Paso 1: Crear vector de punteros para las filas
        datos = new T*[filas];
        
        // Paso 2: Para cada fila, crear vector de columnas
        for (int i = 0; i < filas; i++) {
            datos[i] = new T[columnas];
            
            // Inicializar todo en cero
            for (int j = 0; j < columnas; j++) {
                datos[i][j] = T(0);
            }
        }
    }
    
    // Destructor: liberar memoria en orden inverso
    ~MatrizDinamica() {
        // Primero liberar las columnas
        for (int i = 0; i < filas; i++) {
            delete[] datos[i];
        }
        // Luego liberar las filas
        delete[] datos;
    }
    
    // Constructor de copia (Regla de los Tres)
    MatrizDinamica(const MatrizDinamica<T>& otra) {
        filas = otra.filas;
        columnas = otra.columnas;
        
        datos = new T*[filas];
        for (int i = 0; i < filas; i++) {
            datos[i] = new T[columnas];
            for (int j = 0; j < columnas; j++) {
                datos[i][j] = otra.datos[i][j];
            }
        }
    }
    
    // Operador de asignación (Regla de los Tres)
    MatrizDinamica<T>& operator=(const MatrizDinamica<T>& otra) {
        if (this != &otra) {
            // Liberar memoria actual
            for (int i = 0; i < filas; i++) {
                delete[] datos[i];
            }
            delete[] datos;
            
            // Copiar nueva matriz
            filas = otra.filas;
            columnas = otra.columnas;
            datos = new T*[filas];
            for (int i = 0; i < filas; i++) {
                datos[i] = new T[columnas];
                for (int j = 0; j < columnas; j++) {
                    datos[i][j] = otra.datos[i][j];
                }
            }
        }
        return *this;
    }
    
    // Poner un valor en posición [fila][columna]
    void establecer(int fila, int col, T valor) {
        if (fila >= 0 && fila < filas && col >= 0 && col < columnas) {
            datos[fila][col] = valor;
        }
    }
    
    // Obtener valor de posición [fila][columna]
    T obtener(int fila, int col) const {
        if (fila >= 0 && fila < filas && col >= 0 && col < columnas) {
            return datos[fila][col];
        }
        return T(0);
    }
    
    // Getters
    int getFilas() const { return filas; }
    int getColumnas() const { return columnas; }
    
    // REDIMENSIÓN DINÁMICA - REQUISITO OBLIGATORIO
    void redimensionar(int nuevaF, int nuevaC) {
        // Crear nueva matriz temporal con nuevas dimensiones
        T** nuevaMatriz = new T*[nuevaF];
        for (int i = 0; i < nuevaF; i++) {
            nuevaMatriz[i] = new T[nuevaC];
            // Inicializar en cero
            for (int j = 0; j < nuevaC; j++) {
                nuevaMatriz[i][j] = T(0);
            }
        }
        
        // Copiar datos de matriz antigua (solo los que quepan)
        int minFilas = (filas < nuevaF) ? filas : nuevaF;
        int minCols = (columnas < nuevaC) ? columnas : nuevaC;
        
        for (int i = 0; i < minFilas; i++) {
            for (int j = 0; j < minCols; j++) {
                nuevaMatriz[i][j] = datos[i][j];
            }
        }
        
        // Liberar memoria de matriz antigua
        for (int i = 0; i < filas; i++) {
            delete[] datos[i];
        }
        delete[] datos;
        
        // Asignar nueva matriz
        datos = nuevaMatriz;
        filas = nuevaF;
        columnas = nuevaC;
    }
    
    // Llenar matriz pidiendo valores al usuario
    void llenarDesdeUsuario() {
        cout << "\nIngresar valores para matriz " << filas << "x" << columnas << ":" << endl;
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                cout << "Elemento [" << i << "," << j << "]: ";
                cin >> datos[i][j];
            }
        }
    }
    
    // Mostrar matriz con formato bonito
    void imprimir(const string& nombre = "") const {
        if (!nombre.empty()) {
            cout << "\nMatriz " << nombre << ":" << endl;
        }
        
        for (int i = 0; i < filas; i++) {
            cout << "|";
            for (int j = 0; j < columnas; j++) {
                cout << " " << datos[i][j] << " |";
            }
            cout << endl;
        }
        cout << endl;
    }
    
    // Llenar con números consecutivos (para pruebas)
    void llenarSecuencial(T valorInicial = T(1)) {
        T valor = valorInicial;
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                datos[i][j] = valor;
                valor = valor + T(1);
            }
        }
    }
    
    // MULTIPLICACIÓN MATRICIAL - REQUISITO OBLIGATORIO
    static MatrizDinamica<T> multiplicar(const MatrizDinamica<T>& A, const MatrizDinamica<T>& B) {
        // Validar dimensiones: columnas de A = filas de B
        if (A.columnas != B.filas) {
            cout << "Error: No se pueden multiplicar matrices con dimensiones incompatibles" << endl;
            cout << "A es " << A.filas << "x" << A.columnas << ", B es " << B.filas << "x" << B.columnas << endl;
            return MatrizDinamica<T>(1, 1);  // Retornar matriz mínima
        }
        
        // Crear matriz resultado C de dimensión A.filas × B.columnas
        MatrizDinamica<T> C(A.filas, B.columnas);
        
        // Multiplicación: C[i][j] = suma de A[i][k] * B[k][j]
        for (int i = 0; i < A.filas; i++) {
            for (int j = 0; j < B.columnas; j++) {
                T suma = T(0);
                for (int k = 0; k < A.columnas; k++) {
                    suma = suma + (A.datos[i][k] * B.datos[k][j]);
                }
                C.datos[i][j] = suma;
            }
        }
        
        return C;
    }
};

#endif
