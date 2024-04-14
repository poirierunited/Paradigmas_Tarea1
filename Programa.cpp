#include "Programa.h"
#include "Auto.h"
#include <cstdlib>
#include <unistd.h>

Programa::Programa() {
}

int Programa::get_total_vehiculos() {
    int total_vehiculos_comprados = 0;
    for (auto& venta : ventas) {
        total_vehiculos_comprados += venta->getTotalVehiculos();
    }

    return total_vehiculos_comprados;
}

int Programa::get_total_clientes() {
    return ventas.size();
}

Programa::~Programa() {
    for (Venta* v : ventas) {
        delete v;
    }
}

void Programa::ejecutar() {
    int opcion = 0;
    bool ventaEnCurso = false;

    do
    {
        system("clear");
        std::cout << "============ Menu ============\n";
        std::cout << "1. Realizar venta\n";
        std::cout << "2. Promedio de ventas \n";
        std::cout << "3. Cantidad de vehículos comprados \n";
        std::cout << "4. Salir\n";
        std::cout << "Ingrese una opcion: ";
        std::cin >> opcion;
        std::cout << "\n\n";

        switch (opcion)
        {
        case 1:
            system("clear");
            if (ventaEnCurso) {
                std::cout << "Ya hay una venta en curso.\n";
                break;
            }
            {std::string nombre_cliente;
            std::string rut_cliente;
            std::cout << "Ingrese nombre del cliente:\n ";
            std::cin >> nombre_cliente;
            std::cout << "Ingrese Rut del cliente:\n ";
            std::cin >> rut_cliente;}
            break;
        default:
            break;
        }
    } while (opcion != 4);
}