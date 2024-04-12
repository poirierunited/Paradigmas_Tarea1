#include <iostream>
#include "Auto.h"
#include "Programa.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    // Auto toyota("Toyota");
    // std::cout << "Precio del vehiculo Toyota: " << toyota.getPrecioVehiculo() << std::endl;
    // std::cout << "Precio de puertas para Toyota: " << toyota.getPrecioPuertas() << std::endl;
    // std::cout << "Precio de luces para Toyota: " << toyota.getPrecioLuces() << std::endl;

    Auto* autoPtr = new Auto("Suzukii");
    if (autoPtr == nullptr) {
        std::cerr << "Error al crear el objeto Auto." << std::endl;
        return 1;
    }
    std::cout << "Precio del vehiculo Suzukii: " << autoPtr->getPrecioVehiculo() << std::endl;
    std::cout << "Get marca: " << autoPtr->getMarca() << std::endl;
    std::cout << "Precio de puertas para Suzukii: " << autoPtr->getPrecioPuertas() << std::endl;
    std::cout << "Precio de luces para Suzukii: " << autoPtr->getPrecioLuces() << std::endl;

    // Programa programa;
    // programa.ejecutar();

    return 0;
}