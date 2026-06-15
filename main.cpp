#include "include/AnimaticFlow.h"
#include "include/archivos.h"
#include "include/logica.h"
#include "include/utilidades.h"

int main() {
    // El archivo binario operativo se aloja obligatoriamente en la carpeta data
    const string archivoDatos = "data/pipeline.dat";
    vector<Escena> memoriaTrabajo;

    // Seeding obligatorio y carga automatizada de datos iniciales
    verificarOInicializarArchivo(archivoDatos);
    cargarArchivoEnVector(memoriaTrabajo, archivoDatos);

    int seleccion;
    do {
        limpiarPantallaNativa();
        cout << "===================================================\n";
        cout << "    ANIMATICFLOW V2.0: EXAMEN INTEGRADOR FINAL     \n";
        cout << "===================================================\n";
        cout << " 1. Registrar plano cinematografico (ALTA)\n";
        cout << " 2. Visualizar tablero de produccion (CONSULTA)\n";
        cout << " 3. Modificar progreso de tarea (CAMBIO / UPDATE)\n";
        cout << " 4. Eliminar escena del pipeline (BAJA FISICA)\n";
        cout << " 5. Reporte comparativo de ordenacion (SUGERENCIA)\n";
        cout << " 6. Sincronizar persistencia binaria y Salir\n";
        cout << "===================================================\n";
        cout << "Seleccione una opcion: ";
        cin >> seleccion;

        switch (seleccion) {
            case 1: registrarNuevaEscena(memoriaTrabajo); detenerFlujo(); break;
            case 2: visualizarTablero(memoriaTrabajo); detenerFlujo(); break;
            case 3: modificarEstadoEscena(memoriaTrabajo); detenerFlujo(); break;
            case 4: eliminarEscenaFisica(memoriaTrabajo); detenerFlujo(); break;
            case 5: ejecutarModuloComparativo(memoriaTrabajo); detenerFlujo(); break;
            case 6: 
                guardarVectorEnArchivo(memoriaTrabajo, archivoDatos);
                cout << "\n>> Archivo binario guardado. Pipeline cerrado correctamente.\n";
                break;
            default: cout << "Opcion incorrecta.\n"; detenerFlujo(); break;
        }
    } while (seleccion != 6);

    return 0;
}
