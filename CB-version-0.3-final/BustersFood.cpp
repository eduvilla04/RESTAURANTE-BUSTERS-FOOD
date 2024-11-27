#include <iostream>
#include <string>
using namespace std;

const int MAX_MESAS = 3; // Número máximo de mesas en el restaurante

// Logo del restaurante (dibujo de un fantasma)
void mostrarFantasma() {
    cout << " __ " << endl;
    cout << "|- - |" << endl;
    cout << "\\/\\/\\/" << endl;
}

// Función para mostrar el estado actual de las mesas
void mostrarMesas(bool mesas[MAX_MESAS]) {
    cout << "Estado de las mesas:" << endl;
    for (int i = 0; i < MAX_MESAS; i++) {
        cout << "Mesa " << i + 1 << ": ";
        if (mesas[i]) { // Si la mesa está bloqueada (true), la mostramos como bloqueada
            cout << "Bloqueada" << endl;
        } else { // Si la mesa está disponible (false), la mostramos como disponible
            cout << "Disponible" << endl;
        }
    }
    cout << endl;
}

// Función para que el cliente elija su comida del menú
double elegirComida() {
    double totalComida = 0; // Variable para acumular el total de la comida
    int opcionComida; // Opción de comida elegida
    bool agregarMas; // Variable para preguntar si desea agregar más comida

    do {
        cout << "Menu de Comida:" << endl;
        cout << "1. Pizza - $8.00" << endl;
        cout << "2. Hamburguesa - $5.00" << endl;
        cout << "3. Hotdog - $1.50" << endl;
        cout << "4. Pancakes - $4.50" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcionComida;

        // Sumar el precio del plato seleccionado
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

        // Preguntar si el cliente desea agregar más comida
        cout << "Desea agregar mas comida? (1 = Si, 0 = No): ";
        cin >> agregarMas;
    } while (agregarMas); // Se repite si la respuesta es "sí"

    return totalComida; // Regresa el total de comida seleccionada
}

// Función para que el cliente elija su bebida
double elegirBebida() {
    double totalBebida = 0; // Variable para acumular el total de la bebida
    int opcionBebida; // Opción de bebida elegida

    cout << "Menu de Bebidas:" << endl;
    cout << "1. Soda - $1.00" << endl;
    cout << "2. Agua - $1.00" << endl;
    cout << "3. Jugo - $1.50" << endl;
    cout << "4. No deseo bebida" << endl;
    cout << "Seleccione una opcion: ";
    cin >> opcionBebida;

    // Sumar el precio de la bebida seleccionada
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

    return totalBebida; // Regresa el total de bebida seleccionada
}

// Función para procesar el pago del cliente
bool procesarPago(double totalPedido) {
    int metodoPago; // Método de pago seleccionado
    cout << "Seleccione metodo de pago:" << endl;
    cout << "1. Efectivo" << endl;
    cout << "2. Tarjeta" << endl;
    cin >> metodoPago;

    switch (metodoPago) {
        case 1: // Pago en efectivo
            cout << "Gracias por visitarnos!" << endl;
            return true; // Pago exitoso
        case 2: { // Pago con tarjeta
            string primeros4Digitos; // Primeros 4 dígitos de la tarjeta
            bool pagoExitoso = false; // Variable para verificar si el pago fue exitoso
            do {
                cout << "Ingrese los primeros 4 digitos de su tarjeta: ";
                cin >> primeros4Digitos;

                // Validación de que los primeros 4 dígitos sean numéricos
                if (primeros4Digitos.length() == 4 && isdigit(primeros4Digitos[0]) && isdigit(primeros4Digitos[1]) &&
                    isdigit(primeros4Digitos[2]) && isdigit(primeros4Digitos[3])) {
                    cout << "Gracias por visitarnos!" << endl;
                    pagoExitoso = true;
                } else {
                    cout << "Error: Debe ingresar exactamente 4 digitos numericos. Intente de nuevo." << endl;
                }
            } while (!pagoExitoso); // Repite hasta que el pago sea exitoso
            return true; // Pago exitoso
        }
        default:
            cout << "Metodo de pago invalido." << endl;
            return false; // Pago fallido si el método es inválido
    }
}

// Función para atender a un cliente en el restaurante
bool atenderCliente(bool mesas[MAX_MESAS]) {
    int numeroMesa; // Número de mesa que el cliente elige
    cout << "Mesas disponibles para elegir:" << endl;
    for (int i = 0; i < MAX_MESAS; i++) {
        if (!mesas[i]) { // Si la mesa está disponible, la mostramos
            cout << "Mesa " << i + 1 << endl;
        }
    }

    cout << "Ingrese el numero de la mesa que desea elegir: ";
    cin >> numeroMesa;

    // Validación de la mesa elegida
    if (numeroMesa < 1 || numeroMesa > MAX_MESAS) {
        cout << "Numero de mesa invalido." << endl;
        return false; // Si la mesa no es válida, retorna false
    } else if (mesas[numeroMesa - 1]) {
        cout << "La mesa " << numeroMesa << " esta bloqueada y no puede ser elegida." << endl;
        return false; // Si la mesa está bloqueada, retorna false
    } else {
        cout << "Ha elegido la mesa " << numeroMesa << ". Gracias!" << endl;
        mesas[numeroMesa - 1] = true; // Bloquea la mesa (ya no estará disponible)

        // El cliente elige su comida y bebida
        double totalComida = elegirComida();
        double totalBebida = elegirBebida();

        // Suma el total del pedido
        double totalPedido = totalComida + totalBebida;
        cout << "El total de su pedido es: $" << totalPedido << endl;

        // Procesa el pago del cliente
        return procesarPago(totalPedido);
    }
}

int main() {
    bool mesas[MAX_MESAS] = {false}; // Estado inicial de las mesas (false = disponible, true = bloqueada)
    string usuario_correcto = "admin", contrasenia_correcta = "1234"; // Credenciales del administrador
    string usuario, contrasenia; // Variables para ingresar el usuario y contraseña
    int opcion; // Opción seleccionada en el menú principal
    mostrarFantasma(); // Muestra el logo del restaurante
    do {
        cout << "Bienvenido a Code Busters!" << endl;
        cout << "Seleccione una opcion:" << endl;
        cout << "1. Administrador" << endl;
        cout << "2. Cliente" << endl;
        cout << "0. Salir" << endl;
        cin >> opcion;

        switch (opcion) {
            case 1: // Opción del administrador
                cout << "Ingrese su usuario: ";
                cin >> usuario;
                cout << "Ingrese su contrasena: ";
                cin >> contrasenia;

                // Verificación de las credenciales
                if (usuario == usuario_correcto && contrasenia == contrasenia_correcta) {
                    cout << "Bienvenido, administrador." << endl;
                    int opcionAdmin;
                    do {
                        mostrarMesas(mesas); // Muestra el estado de las mesas
                        cout << "Opciones del administrador:" << endl;
                        cout << "1. Bloquear una mesa" << endl;
                        cout << "2. Desbloquear una mesa" << endl;
                        cout << "3. Volver al menu principal" << endl;
                        cin >> opcionAdmin;

                        switch (opcionAdmin) {
                            case 1: { // Opción para bloquear una mesa
                                int numeroMesa;
                                cout << "Ingrese el numero de la mesa a bloquear (1-" << MAX_MESAS << "): ";
                                cin >> numeroMesa;
                                if (numeroMesa >= 1 && numeroMesa <= MAX_MESAS) {
                                    mesas[numeroMesa - 1] = true; // Bloquea la mesa
                                    cout << "Mesa bloqueada correctamente." << endl;
                                } else {
                                    cout << "Numero de mesa invalido." << endl;
                                }
                                break;
                            }
                            case 2: { // Opción para desbloquear una mesa
                                int numeroMesa;
                                cout << "Ingrese el numero de la mesa a desbloquear (1-" << MAX_MESAS << "): ";
                                cin >> numeroMesa;
                                if (numeroMesa >= 1 && numeroMesa <= MAX_MESAS) {
                                    mesas[numeroMesa - 1] = false; // Desbloquea la mesa
                                    cout << "Mesa desbloqueada correctamente." << endl;
                                } else {
                                    cout << "Numero de mesa invalido." << endl;
                                }
                                break;
                            }
                            case 3: // Salir del menú de administrador
                                cout << "Saliendo del menu de administrador..." << endl;
                                break;
                            default:
                                cout << "Opcion invalida." << endl;
                        }
                    } while (opcionAdmin != 3); // Vuelve al menú principal si se elige la opción 3
                } else {
                    cout << "Credenciales incorrectas. Acceso denegado." << endl;
                }
                break;

            case 2: // Opción del cliente
                cout << "Bienvenido, cliente." << endl;
                if (atenderCliente(mesas)) {
                    return 0; // Sale del programa si el pedido fue exitoso
                }
                break;

            case 0: // Opción para salir
                cout << "Gracias por visitarnos. Hasta pronto!" << endl;
                break;

            default:
                cout << "Opcion invalida." << endl;
        }
    } while (opcion != 0); // Repite el menú principal hasta que se elija la opción de salir

    return 0;
}
