#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Estructura que representa una tarea
struct Tarea {
    string descripcion;
    bool completada;
    string prioridad;
};

// Prototipos
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

        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();

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
                cout << "Opcion no valida.\n";
                break;
        }
    }

    return 0;
}


// Agrega una nueva tarea
void agregarTarea(vector<Tarea>& tareas) {

    Tarea nueva;

    cout << "\nIngrese la tarea: ";
    getline(cin, nueva.descripcion);

    if (nueva.descripcion == "") {
        cout << "La tarea no puede estar vacia.\n";
        return;
    }

    cout << "Ingrese la prioridad (Alta, Media o Baja): ";
    getline(cin, nueva.prioridad);

    while (nueva.prioridad != "Alta" &&
            nueva.prioridad != "Media" &&
            nueva.prioridad != "Baja") {

        cout << "Prioridad invalida.\n";
        cout << "Ingrese Alta, Media o Baja: ";
        getline(cin, nueva.prioridad);
    }

    nueva.completada = false;

    tareas.push_back(nueva);

    cout << "Tarea agregada correctamente.\n";
}


// Muestra todas las tareas
void mostrarTareas(const vector<Tarea>& tareas) {

    cout << "\nTAREAS\n\n";

    if (tareas.empty()) {
        cout << "No hay tareas registradas.\n";
        return;
    }

    for (int i = 0; i < tareas.size(); i++) {

        cout << i + 1 << ". ";

        if (tareas[i].completada == true) {
            cout << "[Completada] ";
        } else {
            cout << "[Pendiente] ";
        }

        cout << "[" << tareas[i].prioridad << "] ";
        cout << tareas[i].descripcion << endl;
    }
}


// Elimina una tarea
void eliminarTarea(vector<Tarea>& tareas) {

    if (tareas.empty()) {
        cout << "\nNo hay tareas para eliminar.\n";
        return;
    }

    mostrarTareas(tareas);

    int numeroTarea;

    cout << "\nSeleccione la tarea que desea eliminar: ";
    cin >> numeroTarea;

    if (numeroTarea < 1 || numeroTarea > tareas.size()) {
        cout << "Tarea invalida.\n";
        return;
    }

    tareas.erase(tareas.begin() + numeroTarea - 1);

    cout << "Tarea eliminada correctamente.\n";
}


// Marca una tarea como completada
void completarTarea(vector<Tarea>& tareas) {

    if (tareas.empty()) {
        cout << "\nNo hay tareas para completar.\n";
        return;
    }

    mostrarTareas(tareas);

    int numeroTarea;

    cout << "\nSeleccione la tarea completada: ";
    cin >> numeroTarea;

    if (numeroTarea < 1 || numeroTarea > tareas.size()) {
        cout << "Tarea invalida.\n";
        return;
    }

    tareas[numeroTarea - 1].completada = true;

    cout << "Tarea marcada como completada.\n";
}