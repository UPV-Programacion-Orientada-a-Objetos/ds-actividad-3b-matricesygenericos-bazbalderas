#include <iostream>
#include "MatrizDinamica.h"

int main() {
    #include <iostream>

using namespace std;


int main(){
int matrizA[2][3];
float matrizB[3][2];
float matrizC[3][3];

cout << "-- BIENVENIDO --" << endl;
cout << " Sistema de Análisis de Transformaciones Lineales " << endl;

//Llenar los valores dentro de la matriz A
cout << "Ingrese los valores de la matriz A (2x3):" << endl;
for(int i = 0 ; i < 2 ; i++){
    for(int j = 0; < 3; j++){
        cout << "A[" << i << "]" << "[" << j << "]" << endl;
        int valor;
        cin >> valor;
        matrizA[2][3] = valor;
        
    }
}

cout << "---------------------------------" << endl;
cout << ">> Redimensionando Matriz A <<" << endl;
cout << "REdimensionando A a 3x3. Datos conservados:" << endl;
for(int i=0; i< 2 << i++){
    cout << "|";
    for(int j=0; j<3; j++){
        cout << matriz A[i][j] << " ";
    }
    cout << "|" << endl;
}

//Llenar los valores dentro de la matriz B
cout << "Ingrese los valores de la matriz B (3X2):" << endl;
for(int i = 0 ; i < 3 ; i++){
    for(int j = 0; < 2; j++){
        cout << "B[" << i << "]" << "[" << j << "]" << endl;
        int valor;
        cin >> valor;
        matrizB[3][2] = valor;
        
    }
}

cout << "---------------------------------" << endl;
cout << ">> Redimensionando Matriz B <<" << endl;
cout << "REdimensionando B a 3x3. Datos conservados:" << endl;
for(int i=0; i< 3 << i++){
    cout << "|";
    for(int j=0; j<2; j++){
        cout << matriz B[i][j] << " ";
    }
    cout << "|" << endl;
}

//Mltiplicación de A*B para sacar la matriz C
//Aqui vamo a poner toda la lógica de la multiplicación, cuando ande mas motivado


//Liberar Memoria
//Aqui va toda la lógica de liberacion de memoria de todas las matrices tambien cuando ande mas motivado
}
    return 0;
}
