#include "MatrizDinamica.h"

int main() {
    cout << "--- Sistema de Análisis de Transformaciones Lineales ---" << endl;
    
    // PARTE 1: MATRICES DE ENTEROS CON REDIMENSIÓN
    cout << "\n>> Prueba de Matriz ENTERA (Matriz A) <<" << endl;
    cout << "Creando Matriz A (Tipo INT) de 2x3..." << endl;
    
    MatrizDinamica<int> A(2, 3);
    A.llenarDesdeUsuario();
    
    cout << "\n>> Redimensionando Matriz A <<" << endl;
    cout << "Redimensionando A a 3x3. Datos conservados:" << endl;
    A.redimensionar(3, 3);
    A.imprimir("A redimensionada");
    cout << "(Nuevos valores inicializados a 0)" << endl;
    
    // PARTE 2: MATRICES DE FLOTANTES Y MULTIPLICACIÓN
    cout << "\n>> Prueba de Multiplicación (Tipo FLOAT) <<" << endl;
    cout << "Creando Matriz B (Tipo FLOAT) de 3x2..." << endl;
    
    MatrizDinamica<float> B(3, 2);
    // Establecer valores específicos según el ejemplo
    B.establecer(0, 0, 1.5f); B.establecer(0, 1, 0.5f);
    B.establecer(1, 0, 2.0f); B.establecer(1, 1, 1.0f);
    B.establecer(2, 0, 1.0f); B.establecer(2, 1, 2.5f);
    
    cout << "B[0,0]: 1.5, B[0,1]: 0.5" << endl;
    cout << "B[1,0]: 2.0, B[1,1]: 1.0" << endl;
    cout << "B[2,0]: 1.0, B[2,1]: 2.5" << endl;
    
    // Convertir matriz A de int a float para poder multiplicar
    MatrizDinamica<float> A_float(3, 3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            A_float.establecer(i, j, (float)A.obtener(i, j));
        }
    }
    
    cout << "\nMatriz C = A(3x3) x B(3x2) ..." << endl;
    
    // Realizar multiplicación
    MatrizDinamica<float> C = MatrizDinamica<float>::multiplicar(A_float, B);
    
    cout << "\nMatriz C (Resultado 3x2, Tipo FLOAT):" << endl;
    C.imprimir("C");
    
    cout << "Liberando memoria de todas las matrices..." << endl;
    cout << "Sistema completado exitosamente." << endl;
    
    return 0;
}
