#include <iostream>
#include "Auto.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    Auto toyota("Toyota");
    std::cout << "Precio del vehiculo Toyota: " << toyota.getPrecioVehiculo() << std::endl;
    std::cout << "Precio de puertas para Toyota: " << toyota.getPrecioPuertas() << std::endl;
    std::cout << "Precio de luces para Toyota: " << toyota.getPrecioLuces() << std::endl;

    Auto suzuki("Suzuki");
    std::cout << "Precio del vehiculo Suzuki: " << suzuki.getPrecioVehiculo() << std::endl;
    std::cout << "Precio de puertas para Suzuki: " << suzuki.getPrecioPuertas() << std::endl;
    std::cout << "Precio de luces para Suzuki: " << suzuki.getPrecioLuces() << std::endl;

    return 0;

}