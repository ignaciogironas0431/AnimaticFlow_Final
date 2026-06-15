#ifndef ARCHIVOS_H
#define ARCHIVOS_H

#include "AnimaticFlow.h"

// Funciones destinadas al control de la persistencia física binaria
void verificarOInicializarArchivo(const string& rutaArchivo);
void cargarArchivoEnVector(vector<Escena>& lista, const string& rutaArchivo);
void guardarVectorEnArchivo(const vector<Escena>& lista, const string& rutaArchivo);

#endif
