#include <iostream> //Llamamos las librerias a usar
#include <string> //Llamamos la libreria string para poder declarar variables con cadena de caracteres
using namespace std;

// Definimos las credenciales válidas
string usuario_correcto = "administrador", contrasenia_correcta = "233444"; 

// Filas y columnas de la matriz
const int filas = 3, columnas = 3;

// Función para mostrar el estado de las mesas
void mostrarMesas(char mesas[filas][columnas]) {
    cout << "Estado de las mesas." << endl;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << "[" << mesas[i][j] << "]";
        }
        cout << endl;
    }
    cout << "Las casillas con la letra 'D' indican que la mesa esta disponible, mientras que 'R' indica que esta reservada." << endl;
}

// Función para bloquear una mesa
void bloquearMesa(char mesas[filas][columnas], int numeroMesa) {
    // Convertir el número de la mesa en fila y columna
    int fila = (numeroMesa - 1) / columnas; 
    int columna = (numeroMesa - 1) % columnas; 
    
    // Verificar si la mesa ya está reservada
    if (mesas[fila][columna] == 'R') {
        cout << "La mesa " << numeroMesa << " ya esta reservada." << endl;
    } else {
        mesas[fila][columna] = 'R'; // Reservamos la mesa
        cout << "Mesa " << numeroMesa << " reservada correctamente." << endl;
    }
}

void desbloquearMesa(char mesas[filas][columnas], int numeroMesa) {
    // Convertir el número de la mesa en fila y columna
    int fila = (numeroMesa - 1) / columnas; 
    int columna = (numeroMesa - 1) % columnas; 
    
    // Verificar si la mesa ya está reservada
    if (mesas[fila][columna] == 'D') {
        cout << "La mesa " << numeroMesa << " ya esta desbloqueada." << endl;
    } else {
        mesas[fila][columna] = 'D'; // Reservamos la mesa
        cout << "Mesa " << numeroMesa << " desbloqueada correctamente." << endl;
    }
}
//Iniciamos el cuerpo del codigo
int main() {
    string usuario, contrasenia; // Variables para almacenar las credenciales ingresadas
    char mesas[filas][columnas] = {{'D', 'D', 'D'}, {'D', 'D', 'D'}, {'D', 'D', 'D'}}; // Inicializamos las mesas disponibles
    
    int opcion, numeroMesa;

    do {
        // Bienvenida y selección del tipo de usuario
        cout << "Bienvenido a Restaurante Code Buster" << endl;
        cout << "Como desea ingresar?" << endl;
        cout << "1. Administrador" << endl;
        cout << "2. Cliente" << endl;
        cout << "0. Salir" << endl;
        cin >> opcion;

        switch (opcion) {
            case 1: // Administrador
                cout << "Bienvenido, Admin." << endl;
                cout << "Por favor, ingrese su usuario." << endl;
                cin >> usuario;
                cout << "Por favor, ingrese la contrasenia." << endl;
                cin >> contrasenia;
                if (usuario == usuario_correcto && contrasenia == contrasenia_correcta) {
                    cout << "Credenciales correctas. Bienvenido." << endl;

                    do {
                        // Mostrar el estado actual de las mesas
                        mostrarMesas(mesas);
                        
                        // Menú de opciones
                        cout << "Opciones:" << endl;
                        cout << "1. Bloquear una mesa" << endl;
                        cout << "2. Desbloquear una mesa" << endl;
                        cout << "3. Volver al menu principal" << endl; // Opción para regresar al menú principal
                        cout << "Seleccione una opcion: ";
                        cin >> opcion;

                        switch (opcion) {
                            case 1:
                                cout << "Ingrese el numero de la mesa a bloquear (1 al 9): " << endl;
                                cin >> numeroMesa;
                                if (numeroMesa >= 1 && numeroMesa <= 9) {
                                    bloquearMesa(mesas, numeroMesa);
                                } else {
                                    cout << "Numero de mesa invalido. Por favor elija una mesa entre 1 y 9." << endl;
                                }
                                break;
                            case 2:
                                cout << "Ingrese el numero de la mesa a desbloquear (1 al 9): " << endl;
                                cin >> numeroMesa;
                                if (numeroMesa >= 1 && numeroMesa <= 9) {
                                    desbloquearMesa(mesas, numeroMesa);
                                } else {
                                    cout << "Numero de mesa invalido. Por favor elija una mesa entre 1 y 9." << endl;
                                }
                                break;
                            case 3:
                                cout << "Volviendo al menu principal..." << endl;
                                break;
                            default:
                                cout << "Opcion invalida, intente de nuevo." << endl;
                        }

                    } while (opcion != 3); // El ciclo sigue hasta que se seleccione la opción 2

                } else {
                    cout << "Usuario o contrasenia incorrectos. Acceso denegado." << endl;
                }
                
                break;

            case 2: // Cliente
                cout << "Bienvenido, cliente." << endl;
                break;

            case 0: // Salir
                cout << "Gracias por visitarnos, esperamos tenerte de nuevo pronto." << endl;
                break;

            default:
                cout << "Opción invalida." << endl;
        }

    } while (opcion != 0); // El ciclo sigue hasta que se seleccione la opción 3 para salir

    return 0;
}
