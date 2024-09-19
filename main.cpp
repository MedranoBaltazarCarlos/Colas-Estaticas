#include <iostream>
#include <queue>  // Usaremos la STL cola temporalmente.
#include <string>
using namespace std;

// Clase Alumno
class Alumno {
private:
    string nombre;
    string carrera;
    int materiasAprobadas;
    float promedio;

public:
    Alumno() : nombre(""), carrera(""), materiasAprobadas(0), promedio(0.0) {}

    Alumno(string nom, string carr, int matAprob, float prom)
        : nombre(nom), carrera(carr), materiasAprobadas(matAprob), promedio(prom) {}

    // Sobrecarga del operador de entrada >>
    friend istream& operator>>(istream& in, Alumno& a) {
        cout << "Nombre del alumno: ";
        in >> ws;
        getline(in, a.nombre);
        cout << "Carrera: ";
        getline(in, a.carrera);
        cout << "Total de materias aprobadas: ";
        in >> a.materiasAprobadas;
        cout << "Promedio general: ";
        in >> a.promedio;
        return in;
    }

    // Sobrecarga del operador de salida <<
    friend ostream& operator<<(ostream& out, const Alumno& a) {
        out << "Constancia de Estudio\n";
        out << "Nombre: " << a.nombre << endl;
        out << "Carrera: " << a.carrera << endl;
        out << "Materias Aprobadas: " << a.materiasAprobadas << endl;
        out << "Promedio General: " << a.promedio << endl;
        return out;
    }
};

// Clase Cola (cola genérica para el ejemplo, ya que tu clase debe ser ajustada)
class Cola {
private:
    queue<Alumno> colaAlumnos;

public:
    void encolar(const Alumno& alumno) {
        colaAlumnos.push(alumno);
    }

    void atenderSolicitud() {
        if (!colaAlumnos.empty()) {
            Alumno alumno = colaAlumnos.front();
            cout << alumno;  // Imprime la constancia de estudio
            colaAlumnos.pop();  // Elimina el alumno de la cola
        } else {
            cout << "No hay solicitudes en espera.\n";
        }
    }

    bool vacia() const {
        return colaAlumnos.empty();
    }
};

// Función principal
int main() {
    Cola colaSolicitudes;
    int opcion;
    Alumno nuevoAlumno;

    do {
        cout << "\nMenu de opciones:\n";
        cout << "1. Alta de solicitud\n";
        cout << "2. Elaborar constancia (atender solicitud)\n";
        cout << "3. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                cout << "Ingresar datos del alumno:\n";
                cin >> nuevoAlumno;
                colaSolicitudes.encolar(nuevoAlumno);
                break;
            case 2:
                cout << "Atendiendo solicitud...\n";
                colaSolicitudes.atenderSolicitud();
                break;
            case 3:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opcion no valida.\n";
        }
    } while(opcion != 3);

    return 0;
}
