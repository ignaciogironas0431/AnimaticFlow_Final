# AnimaticFlow: Production Pipeline Control Tool

### Examen Final Integrador — Integración de Dimensiones 1, 2 y 3
* **Asignatura:** Programación I (SIS-112)
* **Gestión:** 1/2026
* **Estudiante:** Ignacio Alejandro Gironás Perez
* **Carrera:** Diseño Digital
* **Docente:** Ing. Pamela Shirley Valenzuela Fernández

---

## 1. Explicación del Dominio de Datos
AnimaticFlow es un sistema integrado modular enfocado en la automatización, control y organización del pipeline multimedia para proyectos de animación digital en sus variantes de 2D, 3D y VFX. El software permite administrar de forma jerárquica el estado de progreso de las tareas y la duración exacta en fotogramas de los activos audiovisuales, resolviendo de manera óptima los problemas de desorganización y pérdidas de datos técnicos en el área del Diseño Digital.

### Estructura del Struct Principal
La entidad nuclear del sistema se modela mediante la estructura `Escena`, diseñada con arreglos de caracteres estáticos de longitud fija para garantizar una persistencia binaria estable y contigua en disco:
* `id` (`char[10]`): Código único e identificador de la escena/tarea dentro del pipeline (Llave primaria).
* `nombrePlano` (`char[50]`): Descripción técnica del encuadre visual o composición de la toma.
* `tipoAnimacion` (`char[20]`): Técnica o categoría digital del asset (Ej: 2D, 3D, VFX).
* `fotogramas` (`int`): Cantidad total de cuadros de animación que determinan la duración temporal del plano.
* `estado` (`char[20]`): Estado actual del activo en la línea de producción (Ej: Boceto, Storyboard, Listo).

---

## 2. Instrucciones de Compilación y Ejecución
El proyecto cumple estrictamente con el estándar de programación modular, aislando la lógica de negocio y prohibiendo el uso de variables globales o comandos dependientes del sistema operativo.

### Comando de Compilación Nativa (g++ / MinGW):
Abra la terminal de comandos en la raíz del proyecto (donde se encuentra `main.cpp`) y ejecute la siguiente instrucción:
```bash
g++ main.cpp src/archivos.cpp src/logica.cpp src/utilidades.cpp -o AnimaticFlow
```
### Comando de Ejecución:
```bash
./AnimaticFlow
```
---
## 3. Guía de Uso Rápido del Programa
Paso 1: Inicialización Automática (Seeding)
Al ejecutar el programa, el sistema verifica el directorio data/. Si detecta que pipeline.dat no existe o su tamaño es de 0 bytes, inyecta por referencia un lote inicializado de 10 planos de prueba (2D, 3D y VFX) para permitir pruebas operativas inmediatas.

Paso 2: Consulta del Tablero (Opción 2)
Seleccione la Opción 2 para listar el estado actual de los registros en la memoria RAM. El sistema desplegará los datos técnicos de forma tabular, alineada y limpia (ID de Tarea, Nombre del Plano, Técnica, Fotogramas y Estado).

Paso 3: Modificación y Búsqueda Avanzada (Opción 3)
Para actualizar el progreso de un plano, elijo la Opción 3 e ingrese el ID buscado. El programa validará si el vector cumple el prerrequisito matemático de orden; si da positivo, permitirá seleccionar entre la Búsqueda Binaria Iterativa o la Búsqueda Binaria Recursiva (sugerida para el Grupo 1), desplegando las métricas de iteraciones o llamadas acumuladas en la pila de memoria.

Paso 4: Evaluación de Rendimiento (Opción 5)
Seleccione la Opción 5 para activar el módulo comparativo. El procesador ordenará el pipeline mediante el algoritmo de Bubble Sort Optimizado evaluando y contabilizando las comparaciones e intercambios físicos de estructuras realizados, contrastándolos con el modelo de Intercalación Lineal.

Paso 5: Sincronización y Cierre Técnico (Opción 6)
Tras realizar altas (Opción 1) o bajas físicas (Opción 4), elijo la Opción 6. Esto forzará el volcado final de bytes directo al almacenamiento secundario binario, cerrando el pipeline de producción sin fugas de memoria.
