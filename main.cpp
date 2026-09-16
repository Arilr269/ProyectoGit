#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Estructura que representa una tarea
struct Tarea {
    string descripcion;
    bool completada;
};

// Prototipos
void agregarTarea(vector<Tarea>& tareas);
void mostrarTareas(const vector<Tarea>& tareas);
void completarTarea(vector<Tarea>& tareas);

int main() {
    vector<Tarea> tareas;
    int opcion;

    while (opcion != 5) {
        cout << "\nLISTA DE TAREAS\n\n";
        cout << "1. Agregar tarea\n";
        cout << "2. Mostrar tareas\n";
        cout << "3. Marcar tarea como completada\n";
        cout << "4. Salir\n\n";
        cout << "Seleccione una opción: ";

        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                // agregarTarea(tareas);
                break;
            case 2:
                mostrarTareas(tareas);
                break;
            case 3:
                // completarTarea(tareas);
                break;
            case 4:
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

// void agregarTarea(vector<Tarea>& tareas) {
// 
// }

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

// Marca una tarea como completada
void completarTarea(vector<Tarea>& tareas) {
// Imprimir tareas
    mostrarTareas(tareas);


// Cambiar tarea completada a true

// Numero de tarea a completar
    int numeroTarea;
    cout << "Seleccione la tarea completada: ";
    cin >> numeroTarea;
    cin.ignore();

    if (numeroTarea < 1 || static_cast<size_t>(numeroTarea) > tareas.size()) {
        cout << "TAREA INVALIDA." << endl;
        return;
    }

    tareas[numeroTarea - 1].completada = true;
    cout << "Tarea completada correctamente." << endl;
}
