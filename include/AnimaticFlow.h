#ifndef ANIMATICFLOW_H
#define ANIMATICFLOW_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Estructura fija para persistencia binaria estable en archivos .dat
struct Escena {
    char id[10];                // ID de la tarea (Llave primaria para búsquedas)
    char nombrePlano[50];       // Descripción del encuadre visual
    char tipoAnimacion[20];     // Técnica (2D, 3D, VFX)
    int fotogramas;             // Cantidad de cuadros (duración)
    char estado[20];            // Estado en el pipeline (Boceto, Storyboard, Listo)
};

#endif
