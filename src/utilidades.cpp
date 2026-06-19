#include "../include/utilidades.h"
#include <fstream>
#include <iomanip>
#include <limits>

void limpiarPantallaNativa() {
    cout << "\033[2J\033[1;1H"; 
}

void detenerFlujo() {
    cout << "\nPresione Enter para continuar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

// Genera el reporte exportable estructurado 
void exportarReporteEstructuradoPDF(const vector<Escena>& lista) {
    // Definimos la ruta de salida en la carpeta de datos
    string rutaReporte = "data/reporte_pipeline_pdf.txt";
    ofstream reporte(rutaReporte.c_str());
    
    if (!reporte.is_open()) {
        cout << ">> Error: No se pudo generar el archivo de reporte.\n";
        return;
    }

    // cabecera estructurada y formal para la entrega
    reporte << "=========================================================================================\n";
    reporte << "             UNIVERSIDAD CATOLICA BOLIVIANA \"SAN PABLO\" - LA PAZ                         \n";
    reporte << "         FACULTAD DE INGENIERIA - REPORTE EXPORTABLE DE PIPELINE (SIS-112)               \n";
    reporte << "=========================================================================================\n";
    reporte << " Estudiante: Ignacio Alejandro Gironas Perez                                             \n";
    reporte << " Sistema: AnimaticFlow V2.0 | Control de Produccion Audiovisual                         \n";
    reporte << "-----------------------------------------------------------------------------------------\n\n";
    
    reporte << left << setw(12) << "ID TAREA" << setw(30) << "NOMBRE DEL PLANO" << setw(18) << "TECNICA" << setw(15) << "FOTOGRAMAS" << setw(15) << "ESTADO" << "\n";
    reporte << "-----------------------------------------------------------------------------------------\n";
    
    // Volcamos  los datos procesados por el sistema
    for (size_t i = 0; i < lista.size(); i++) {
        reporte << left << setw(12) << lista[i].id 
                << setw(30) << lista[i].nombrePlano 
                << setw(18) << lista[i].tipoAnimacion 
                << setw(15) << lista[i].fotogramas 
                << " [" << lista[i].estado << "]\n";
    }
    
    reporte << "-----------------------------------------------------------------------------------------\n";
    reporte << " Fin del reporte. Documento listo para exportacion / impresion directa a formato PDF.   \n";
    reporte << "=========================================================================================\n";
    
    reporte.close();
    cout << ">> [REPORTE EXPORTABLE] Creado de forma estructurada en: '" << rutaReporte << "'\n";
    cout << ">> Nota: El archivo plano esta listo para impresion virtual o conversion directa a PDF.\n";
}
