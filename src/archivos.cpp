#include "../include/archivos.h"
#include <fstream>
#include <cstring>

// Sembrado automático de 10 registros si el archivo está vacío
void verificarOInicializarArchivo(const string& rutaArchivo) {
    ifstream comprobar(rutaArchivo.c_str(), ios::binary | ios::ate);
    
    if (!comprobar.is_open() || comprobar.tellg() == 0) {
        comprobar.close();
        
        ofstream archivo(rutaArchivo.c_str(), ios::binary | ios::out);
        if (!archivo.is_open()) return;

        Escena base[10] = {
            {"ESC001", "Plano Detalle Rostro", "2D", 48, "Boceto"},
            {"ESC003", "Plano General Bosque", "3D", 120, "Storyboard"},
            {"ESC005", "Primer Plano Asombro", "2D", 24, "Animacion"},
            {"ESC007", "Plano Medio Accion", "VFX", 72, "Boceto"},
            {"ESC009", "Plano Americano Dialogo", "3D", 96, "Renderizado"},
            {"ESC002", "Plano Medio Heroe", "2D", 48, "Listo"},
            {"ESC004", "Plano Subacuatico", "3D", 150, "Storyboard"},
            {"ESC006", "Contraplano Reaccion", "2D", 24, "Animacion"},
            {"ESC008", "Plano Cenital Laberinto", "StopMotion", 120, "Boceto"},
            {"ESC010", "Plano Nadir Despegue", "VFX", 84, "Renderizado"}
        };

        for (int i = 0; i < 10; i++) {
            archivo.write(reinterpret_cast<char*>(&base[i]), sizeof(Escena));
        }
        archivo.close();
    } else {
        comprobar.close();
    }
}

void cargarArchivoEnVector(vector<Escena>& lista, const string& rutaArchivo) {
    ifstream archivo(rutaArchivo.c_str(), ios::binary | ios::in);
    if (!archivo.is_open()) return;

    lista.clear();
    Escena temporal;
    while (archivo.read(reinterpret_cast<char*>(&temporal), sizeof(Escena))) {
        lista.push_back(temporal);
    }
    archivo.close();
}

void guardarVectorEnArchivo(const vector<Escena>& lista, const string& rutaArchivo) {
    ofstream archivo(rutaArchivo.c_str(), ios::binary | ios::trunc);
    if (!archivo.is_open()) return;

    for (size_t i = 0; i < lista.size(); i++) {
        archivo.write(reinterpret_cast<const char*>(&lista[i]), sizeof(Escena));
    }
    archivo.close();
}
