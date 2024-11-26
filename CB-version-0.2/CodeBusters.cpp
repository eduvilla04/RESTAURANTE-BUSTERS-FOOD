#include <iostream>
#include <string>
using namespace std;

const int MAX_MESAS = 3; // Numero maximo de mesas

// Logo del restaurante
void mostrarFantasma() {
    cout << " __ " << endl;
    cout << "|- - |" << endl;
    cout << "\\/\\/\\/" << endl;
}

// Funcion para mostrar el estado de las mesas
void mostrarMesas(bool mesas[MAX_MESAS]) {
    cout << "Estado de las mesas:" << endl;
    for (int i = 0; i < MAX_MESAS; i++) {
        cout << "Mesa " << i + 1 << ": ";
        if (mesas[i]) {
            cout << "Bloqueada" << endl;
        } else {
            cout << "Disponible" << endl;
        }
    }
    cout << endl;
}

// Funcion para que el cliente elija su comida
double elegirComida() {
    double totalComida = 0;
    int opcionComida;
    bool agregarMas;

    do {
        cout << "Menu de Comida:" << endl;
        cout << "1. Pizza - $8.00" << endl;
        cout << "2. Hamburguesa - $5.00" << endl;
        cout << "3. Hotdog - $1.50" << endl;
        cout << "4. Pancakes - $4.50" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcionComida;

        switch (opcionComida) {
            case 1:
                totalComida += 8.00;
                break;
            case 2:
                totalComida += 5.00;
                break;
            case 3:
                totalComida += 1.50;
                break;
            case 4:
                totalComida += 4.50;
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
        }

        cout << "Desea agregar mas comida? (1 = Si, 0 = No): ";
        cin >> agregarMas;
    } while (agregarMas);

    return totalComida;
}

// Funcion para que el cliente elija su bebida
double elegirBebida() {
    double totalBebida = 0;
    int opcionBebida;

    cout << "Menu de Bebidas:" << endl;
    cout << "1. Soda - $1.00" << endl;
    cout << "2. Agua - $1.00" << endl;
    cout << "3. Jugo - $1.50" << endl;
    cout << "4. No deseo bebida" << endl;
    cout << "Seleccione una opcion: ";
    cin >> opcionBebida;

    switch (opcionBebida) {
        case 1:
        case 2:
            totalBebida += 1.00;
            break;
        case 3:
            totalBebida += 1.50;
            break;
        case 4:
            cout << "No se selecciono bebida." << endl;
            break;
        default:
            cout << "Opcion invalida." << endl;
    }

    return totalBebida;
}

// Funcion para realizar el pago. //Esta seccion de procesar pago fue hecha con chat gpt
bool procesarPago(double totalPedido) {
    int metodoPago;
    cout << "Seleccione metodo de pago:" << endl;
    cout << "1. Efectivo" << endl;
    cout << "2. Tarjeta" << endl;
    cin >> metodoPago;

    switch (metodoPago) {
        case 1: // Pago en efectivo
            cout << "Gracias por visitarnos!" << endl;
            return true;
        case 2: { // Pago con tarjeta
            string primeros4Digitos;
            bool pagoExitoso = false;
            do {
                cout << "Ingrese los primeros 4 digitos de su tarjeta: ";
                cin >> primeros4Digitos;

                if (primeros4Digitos.length() == 4 && isdigit(primeros4Digitos[0]) && isdigit(primeros4Digitos[1]) &&
                    isdigit(primeros4Digitos[2]) && isdigit(primeros4Digitos[3])) {
                    cout << "Gracias por visitarnos!" << endl;
                    pagoExitoso = true;
                } else {
                    cout << "Error: Debe ingresar exactamente 4 digitos numericos. Intente de nuevo." << endl;
                }
            } while (!pagoExitoso);
            return true;
        }
        default:
            cout << "Metodo de pago invalido." << endl;
            return false;
    }
}

// Funcion principal para el cliente
bool atenderCliente(bool mesas[MAX_MESAS]) {
    int numeroMesa;
    cout << "Mesas disponibles para elegir:" << endl;
    for (int i = 0; i < MAX_MESAS; i++) {
        if (!mesas[i]) {
            cout << "Mesa " << i + 1 << endl;
        }
    }

    cout << "Ingrese el numero de la mesa que desea elegir: ";
    cin >> numeroMesa;

    if (numeroMesa < 1 || numeroMesa > MAX_MESAS) {
        cout << "Numero de mesa invalido." << endl;
        return false;
    } else if (mesas[numeroMesa - 1]) {
        cout << "La mesa " << numeroMesa << " esta bloqueada y no puede ser elegida." << endl;
        return false;
    } else {
        cout << "Ha elegido la mesa " << numeroMesa << ". Gracias!" << endl;
        mesas[numeroMesa - 1] = true;

        double totalComida = elegirComida();
        double totalBebida = elegirBebida();

        double totalPedido = totalComida + totalBebida;
        cout << "El total de su pedido es: $" << totalPedido << endl;

        return procesarPago(totalPedido);
    }
}

int main() {
    bool mesas[MAX_MESAS] = {false}; // Estado de las mesas (false = disponible, true = bloqueada)
    string usuario_correcto = "admin", contrasenia_correcta = "1234";
    string usuario, contrasenia;
    int opcion;
    mostrarFantasma();
    do {
        cout << "Bienvenido a Code Busters!" << endl;
        cout << "Seleccione una opcion:" << endl;
        cout << "1. Administrador" << endl;
        cout << "2. Cliente" << endl;
        cout << "0. Salir" << endl;
        cin >> opcion;

        switch (opcion) {
            case 1: // Administrador
                cout << "Ingrese su usuario: ";
                cin >> usuario;
                cout << "Ingrese su contrasena: ";
                cin >> contrasenia;

                if (usuario == usuario_correcto && contrasenia == contrasenia_correcta) {
                    cout << "Bienvenido, administrador." << endl;
                    int opcionAdmin;
                    do {
                        mostrarMesas(mesas);
                        cout << "Opciones del administrador:" << endl;
                        cout << "1. Bloquear una mesa" << endl;
                        cout << "2. Desbloquear una mesa" << endl;
                        cout << "3. Volver al menu principal" << endl;
                        cin >> opcionAdmin;

                        switch (opcionAdmin) {
                            case 1: {
                                int numeroMesa;
                                cout << "Ingrese el numero de la mesa a bloquear (1-" << MAX_MESAS << "): ";
                                cin >> numeroMesa;
                                if (numeroMesa >= 1 && numeroMesa <= MAX_MESAS) {
                                    mesas[numeroMesa - 1] = true;
                                    cout << "Mesa bloqueada correctamente." << endl;
                                } else {
                                    cout << "Numero de mesa invalido." << endl;
                                }
                                break;
                            }
                            case 2: {
                                int numeroMesa;
                                cout << "Ingrese el numero de la mesa a desbloquear (1-" << MAX_MESAS << "): ";
                                cin >> numeroMesa;
                                if (numeroMesa >= 1 && numeroMesa <= MAX_MESAS) {
                                    mesas[numeroMesa - 1] = false;
                                    cout << "Mesa desbloqueada correctamente." << endl;
                                } else {
                                    cout << "Numero de mesa invalido." << endl;
                                }
                                break;
                            }
                            case 3:
                                cout << "Saliendo del menu de administrador..." << endl;
                                break;
                            default:
                                cout << "Opcion invalida." << endl;
                        }
                    } while (opcionAdmin != 3);
                } else {
                    cout << "Credenciales incorrectas. Acceso denegado." << endl;
                }
                break;

            case 2: // Cliente
                cout << "Bienvenido, cliente." << endl;
                if (atenderCliente(mesas)) {
                    return 0; // Salir del programa tras completar el pedido
                }
                break;

            case 0:
                cout << "Gracias por visitarnos. Hasta pronto!" << endl;
                break;

            default:
                cout << "Opcion invalida." << endl;
        }
    } while (opcion != 0);

    return 0;
}

