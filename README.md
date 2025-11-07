# 🎓 Proyecto: Tutor Académico (ODS 4: Educación de calidad)

Sistema en C para la gestión de calificaciones de un grupo de estudiantes. Permite a un tutor registrar notas, calcular promedios, emitir alertas de riesgo académico, generar reportes, modificar datos y un histograma de rendimiento.

Este proyecto fue desarrollado para la materia de Programación Estructurada.

---

## 🚀 Características Principales

* **Captura Inicial Forzada:** El programa asegura la captura de todos los datos (nombres y calificaciones) antes de acceder al menú principal.
* **Cálculo de Promedios:** Calcula y almacena automáticamente los promedios de todos los estudiantes.
* **Reportes Básicos:** Muestra una lista detallada de calificaciones, un ranking Top 3 y el peor promedio del grupo.
* **Alertas de Riesgo:** Emite alertas para estudiantes con promedio menor a 70 o que hayan reprobado el último parcial.
* **Histograma Textual:** Genera un histograma por rangos de calificaciones (0-59, 60-69, ... 90-100).
* **Modificación en Vivo:** Permite modificar nombres o calificaciones individuales, recalculando automáticamente el promedio del alumno afectado.
* **Reinicio de Programa:** Permite borrar todos los datos y comenzar una nueva captura desde cero sin cerrar el ejecutable.

---

## 🛠️ Stack de Tecnología

* **Lenguaje:** C
* **Compilador:** GCC (MinGW para Windows)
* **Control de Versiones:** Git y GitHub
* **Arquitectura:** Modular (separación de archivos `.h` en `include/` y `.c` en `src/`)

---

## ⚙️ Cómo Compilar y Ejecutar

Este proyecto está diseñado para ser compilado con GCC.

### 1. Prerrequisitos

Asegúrate de tener instalado `Git` y un compilador de C como `GCC` (MinGW en Windows) configurado en el PATH de tu sistema.

### 2. Clonar el Repositorio

Abre una terminal y clona el proyecto:
```bash
git clone [https://github.com/Cometines/proyecto-tutor-academico.git](https://github.com/Cometines/proyecto-tutor-academico.git)
```

### 3. Navegar al Directorio

```bash
cd proyecto-tutor-academico
```

### 4. Compilar

Ejecuta el siguiente comando en la terminal (estando en la carpeta raíz del proyecto). Este comando enlaza todos los módulos `.c` y le dice al compilador dónde encontrar las cabeceras (`-Iinclude`).

```bash
gcc main.c src/captura.c src/reportes.c src/alertas.c src/histograma.c src/modificar.c -Iinclude -o TutorAcademico.exe
```

### 5. Ejecutar

Una vez compilado, ejecuta el programa:

```bash
./TutorAcademico.exe
```
(O `TutorAcademico.exe` si estás en el Símbolo del sistema de Windows).

---

## 🧪 Casos de Prueba

| Caso | Entrada | Resultado Esperado |
| :--- | :--- | :--- |
| **1. Camino Feliz** | 3 Estudiantes, 2 Evaluaciones.<br> (Datos variados) | El programa captura, calcula y muestra reportes sin errores. El ranking y los promedios son correctos. |
| **2. Límite (Todos 100)**| 2 Estudiantes, 2 Evaluaciones.<br>Todas las calificaciones = 100. | Promedios = 100. Ranking correcto. **No debe mostrar alertas.** Histograma solo en rango 90-100. |
| **3. Límite (Todos 60)** | 2 Estudiantes, 2 Evaluaciones.<br>Todas las calificaciones = 60. | Promedios = 60. **Debe mostrar alertas para todos.** Histograma solo en rango 60-69. |
| **4. Modificación** | 2 Estudiantes (Ana: 50, Luis: 100).<br>1. Correr reportes (Ana es la peor).<br>2. Ir a Opción 4 (Modificar).<br>3. Cambiar la nota de Ana a 100.<br>4. Correr reportes de nuevo. | El recálculo debe ser exitoso. Al correr reportes de nuevo, Ana debe tener promedio 100 y ya no debe ser la peor. |
| **5. Reinicio** | Capturar datos. Correr Opción 5 (Reiniciar). | El programa debe volver a la pantalla de captura inicial, borrando todos los datos anteriores. |

---

## 👥 División de Tareas

El proyecto se dividió en módulos, con un responsable asignado a cada componente lógico.

| Rol | Miembro del Equipo | Módulo Asignado | Responsabilidades |
| :--- | :--- | :--- | :--- |
| **Líder de Proyecto / Integrador** | Leonardo Alberto Méndez Lagunes | `main.c` / GitHub | Supervisión general, control de versiones, integración de Pull Requests, reglas de repositorio y desarrollo del bucle principal. |
| **Desarrollador 1** | (Nombre del Alumno 2) | `src/captura.c` | Implementación de la captura inicial de datos, validaciones de entrada y cálculo inicial de promedios. |
| **Desarrollador 2** | (Nombre del Alumno 3) | `src/reportes.c` | Implementación de la lista de alumnos, cálculo de promedios por evaluación y generación del ranking (Top 3 y peor). |
| **Desarrollador 3** | (Nombre del Alumno 4) | `src/alertas.c` | Implementación de la lógica para identificar y mostrar a los estudiantes en riesgo académico. |
| **Desarrollador 4** | (Nombre del Alumno 5) | `src/histograma.c` | Implementación de la lógica para contar y mostrar el histograma textual de calificaciones. |
| **Desarrollador 5** | (Nombre del Alumno 6) | `src/modificar.c` | Implementación del submenú de modificaciones, lógica de acceso por No. de lista y recálculo de promedios. |

*(Nota: Si son 5 miembros, ajusten los roles 3, 4 y 5 según corresponda. Por ejemplo, una persona pudo haber hecho Alertas e Histograma).*