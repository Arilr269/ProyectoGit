#include <iostream>
#include <limits>
#include <vector>
#include <string>

using namespace std;

// Estructura que representa una tarea
struct Tarea {
    string descripcion;
    bool completada;
};

void agregarTarea(vector<Tarea>& tareas);
void mostrarTareas(const vector<Tarea>& tareas);
void eliminarTarea(vector<Tarea>& tareas);
void completarTarea(vector<Tarea>& tareas);

int main() {
    vector<Tarea> tareas;
    int opcion = 0;

    while (opcion != 5) {
        cout << "\nLISTA DE TAREAS\n\n";
        cout << "1. Agregar tarea\n";
        cout << "2. Mostrar tareas\n";
        cout << "3. Eliminar tarea\n";
        cout << "4. Marcar tarea como completada\n";
        cout << "5. Salir\n\n";
        cout << "Seleccione una opción: ";

        if (!(cin >> opcion)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Opción no válida.\n";
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (opcion) {
            case 1:
                agregarTarea(tareas);
                break;
            case 2:
                mostrarTareas(tareas);
                break;
            case 3:
                eliminarTarea(tareas);
                break;
            case 4:
                completarTarea(tareas);
                break;
            case 5:
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opción no válida.\n";
                break;
        }
    }

    return 0;
}

// Agrega una nueva tarea al vector
void agregarTarea(vector<Tarea>& tareas) {
    Tarea nuevaTarea;
    cout << "Ingrese la tarea: ";
    getline(cin, nuevaTarea.descripcion);

    if (nuevaTarea.descripcion.empty()) {
        cout << "La descripción no puede estar vacía.\n";
        return;
    }

    nuevaTarea.completada = false;
    tareas.push_back(nuevaTarea);
    cout << "Tarea agregada correctamente.\n";
}

// Muestra todas las tareas
void mostrarTareas(const vector<Tarea>& tareas) {
    if (tareas.empty()) {
        cout << "No hay tareas registradas.\n";
        return;
    }

    cout << "\nTAREAS\n";
    for (size_t i = 0; i < tareas.size(); ++i) {
        cout << i + 1 << ". ["
            << (tareas[i].completada ? "Completada" : "Pendiente")
            << "] " << tareas[i].descripcion << '\n';
    }
}

void eliminarTarea(vector<Tarea>& tareas) {
    if (tareas.empty()) {
        cout << "No hay tareas para eliminar.\n";
        return;
    }

    mostrarTareas(tareas);
    int numero;
    cout << "Ingrese el número de la tarea a eliminar: ";
    if (!(cin >> numero)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Número de tarea no válido.\n";
        return;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (numero < 1 || static_cast<size_t>(numero) > tareas.size()) {
        cout << "Número de tarea no válido.\n";
        return;
    }

    tareas.erase(tareas.begin() + numero - 1);
    cout << "Tarea eliminada correctamente.\n";
}

// Marca una tarea como completada
void completarTarea(vector<Tarea>& tareas) {
    if (tareas.empty()) {
        cout << "No hay tareas para completar.\n";
        return;
    }

    mostrarTareas(tareas);
    int numero;
    cout << "Seleccione la tarea: ";
    if (!(cin >> numero)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Número de tarea no válido.\n";
        return;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (numero < 1 || static_cast<size_t>(numero) > tareas.size()) {
        cout << "Número de tarea no válido.\n";
        return;
    }

    tareas[numero - 1].completada = true;
    cout << "Tarea marcada como completada.\n";
}
