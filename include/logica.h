#ifndef LOGICA_H
#define LOGICA_H

#include "AnimaticFlow.h"

// Operaciones esenciales del CRUD binario
void registrarNuevaEscena(vector<Escena>& lista);
void visualizarTablero(const vector<Escena>& lista);
void modificarEstadoEscena(vector<Escena>& lista);
void eliminarEscenaFisica(vector<Escena>& lista);

// Métricas solicitadas y sugeridas para el Grupo 1
void ejecutarModuloComparativo(vector<Escena>& lista);
void ordenarBubbleSortConMetricas(vector<Escena>& lista, int& comparaciones, int& intercambios);

// Funciones de búsqueda exigidas por la rúbrica (Iterativa y Recursiva)
int buscarBinariaIterativa(const vector<Escena>& lista, const string& idBuscado, int& iteraciones);
int buscarBinariaRecursiva(const vector<Escena>& lista, int izquierda, int derecha, const string& idBuscado, int& llamadas);

bool verificarSiEstaOrdenado(const vector<Escena>& lista);

#endif
