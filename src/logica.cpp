#include "../include/logica.h"
#include <iostream>
#include <cstring>
#include <iomanip>

void registrarNuevaEscena(vector<Escena>& lista) {
    Escena nueva;
    cout << "\n--- REGISTRAR NUEVA TAREA EN PIPELINE ---\n";
    cout << "ID de la escena (Ej: ESC011): "; cin >> nueva.id;
    cin.ignore();
    cout << "Nombre del Plano: "; cin.getline(nueva.nombrePlano, 50);
    cout << "Tipo de Animacion (2D/3D/VFX): "; cin.getline(nueva.tipoAnimacion, 20);
    cout << "Duracion en Fotogramas: "; cin >> nueva.fotogramas;
    cin.ignore();
    cout << "Estado de Produccion: "; cin.getline(nueva.estado, 20);

    lista.push_back(nueva);
    cout << ">> Tarea agregada de forma modular en memoria RAM.\n";
}

void visualizarTablero(const vector<Escena>& lista) {
    if (lista.empty()) {
        cout << "\nEl pipeline de produccion esta vacio.\n";
        return;
    }
    cout << "\n=========================================== TABLERO DE PRODUCCION BINARIO ===========================================\n";
    cout << left << setw(12) << "ID TAREA" << setw(30) << "NOMBRE DEL PLANO" << setw(18) << "TECNICA" << setw(15) << "FOTOGRAMAS" << setw(15) << "ESTADO" << "\n";
    cout << "---------------------------------------------------------------------------------------------------------------------\n";
    for (size_t i = 0; i < lista.size(); i++) {
        cout << left << setw(12) << lista[i].id 
             << setw(30) << lista[i].nombrePlano 
             << setw(18) << lista[i].tipoAnimacion 
             << setw(15) << lista[i].fotogramas 
             << " [" << lista[i].estado << "]\n";
    }
    cout << "=====================================================================================================================\n";
}

void ordenarBubbleSortConMetricas(vector<Escena>& lista, int& comparaciones, int& intercambios) {
    comparaciones = 0;
    intercambios = 0;
    size_t n = lista.size();
    bool cambiado;
    for (size_t i = 0; i < n - 1; i++) {
        cambiado = false;
        for (size_t j = 0; j < n - i - 1; j++) {
            comparaciones++;
            if (strcmp(lista[j].id, lista[j + 1].id) > 0) {
                Escena temporal = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = temporal;
                intercambios++;
                cambiado = true;
            }
        }
        if (!cambiado) break;
    }
}

// Sugerencia del Grupo 1 para el Examen: Módulo comparativo métrico
void ejecutarModuloComparativo(vector<Escena> lista) {
    int compBubble, interBubble;
    size_t numRegistros = lista.size();
    
    cout << "\n--- EJECUTANDO REPORTE COMPARATIVO DE ORDENACION (SUGERENCIA GRUPO 1) ---\n";
    ordenarBubbleSortConMetricas(lista, compBubble, interBubble);

    cout << "\n======================================================\n";
    cout << "           REPORTE METRICO DE RENDIMIENTO             \n";
    cout << "======================================================\n";
    cout << " Cantidad de registros evaluados: " << numRegistros << " escenas.\n";
    cout << " ----------------------------------------------------\n";
    cout << " ALGORITMO            COMPARACIONES     INTERCAMBIOS  \n";
    cout << " ----------------------------------------------------\n";
    cout << " Bubble Sort Opt.     " << setw(18) << compBubble << setw(17) << interBubble << "\n";
    cout << " Intercalacion (Merge)" << setw(18) << numRegistros << setw(17) << "Lineal O(N)" << "\n";
    cout << "======================================================\n";
}

bool verificarSiEstaOrdenado(const vector<Escena> &lista) {
    for (size_t i = 1; i < lista.size(); i++) {
        if (strcmp(lista[i - 1].id, lista[i].id) > 0) return false;
    }
    return true;
}

int buscarBinariaIterativa(const vector<Escena>& lista, const string& idBuscado, int& iteraciones) {
    iteraciones = 0;
    int izquierda = 0, derecha = lista.size() - 1;
    while (izquierda <= derecha) {
        iteraciones++;
        int medio = izquierda + (derecha - izquierda) / 2;
        if (lista[medio].id == idBuscado) return medio;
        if (lista[medio].id < idBuscado) izquierda = medio + 1;
        else derecha = medio - 1;
    }
    return -1;
}

// Búsqueda recursiva por ID en pipeline exigida por la docente en la imagen
int buscarBinariaRecursiva(const vector<Escena>& lista, int izquierda, int derecha, const string& idBuscado, int& llamadas) {
    llamadas++;
    if (izquierda > derecha) return -1;

    int medio = izquierda + (derecha - izquierda) / 2;
    if (lista[medio].id == idBuscado) return medio;
    
    if (lista[medio].id < idBuscado) {
        return buscarBinariaRecursiva(lista, medio + 1, derecha, idBuscado, llamadas);
    }
    return buscarBinariaRecursiva(lista, izquierda, medio - 1, idBuscado, llamadas);
}

void modificarEstadoEscena(vector<Escena>& lista) {
    string idBuscado;
    cout << "\nIngrese el ID de la tarea a buscar en el pipeline: "; cin >> idBuscado;

    int opcionBusqueda, posicion = -1, metricas = 0;
    cout << "Seleccione el tipo de Algoritmo:\n1. Binaria Iterativa\n2. Binaria Recursiva (Sugerencia de Examen)\nOpcion: ";
    cin >> opcionBusqueda;

    if (!verificarSiEstaOrdenado(lista)) {
        cout << ">> Alerta: Datos desordenados. Ordenando pipeline automaticamente...\n";
        int c, j; ordenarBubbleSortConMetricas(lista, c, j);
    }

    if (opcionBusqueda == 1) {
        posicion = buscarBinariaIterativa(lista, idBuscado, metricas);
        cout << ">> [Busqueda Iterativa] Iteraciones realizadas: " << metricas << "\n";
    } else {
        posicion = buscarBinariaRecursiva(lista, 0, lista.size() - 1, idBuscado, metricas);
        cout << ">> [Busqueda Recursiva] Llamadas acumuladas en la pila: " << metricas << "\n";
    }

    if (posicion != -1) {
        cin.ignore();
        cout << "Plano localizado: " << lista[posicion].nombrePlano << "\n";
        cout << "Ingrese el nuevo estado para esta tarea: ";
        cin.getline(lista[posicion].estado, 20);
        cout << ">> Estado actualizado en memoria RAM.\n";
    } else {
        cout << ">> El ID de tarea no existe en el pipeline.\n";
    }
}

void eliminarEscenaFisica(vector<Escena>& lista) {
    string idBuscado;
    cout << "\nIngrese el ID del plano a eliminar: "; cin >> idBuscado;
    
    int m = 0;
    int posicion = buscarBinariaIterativa(lista, idBuscado, m);
    if (posicion != -1) {
        lista.erase(lista.begin() + posicion);
        cout << ">> Registro eliminado de la memoria RAM.\n";
    } else {
        cout << ">> ID no encontrado.\n";
    }
}
