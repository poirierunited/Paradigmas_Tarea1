#include "Moto.h"
#include <fstream>
#include <sstream>
#include <iostream>

int Moto::getPrecioPedales() {
    return precio_pedales;
}

int Moto::getPrecioEspejos() {
    return precio_espejos;
}

void Moto::setPrecioPedales(int precio) {
    precio_pedales = precio;
}

void Moto::setPrecioEspejos(int precio) {
    precio_espejos = precio;
}

Moto::Moto(std::string marca) : Vehiculo(marca) {
    std::string fileName = "Moto.txt";
    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "Error: No se pudo abrir el archivo " << fileName << std::endl;
        return;
    }

    std::cout << "Leyendo archivo " << fileName << std::endl;

    std::string line;
    std::string section;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string key;
        int value;
        if (iss >> section) {
            if (section == "Accesorios:") {
                while (iss >> key >> value) {
                    // std::cout << "Accesorio: " << key << ", Precio: " << value << std::endl; // Salida de depuración
                    if (key == "Pedales")
                        setPrecioPedales(value);
                    else if (key == "Espejos")
                        setPrecioEspejos(value);
                }
            } else if (section == "Marcas:") {
                while (iss >> key >> value) {
                    // std::cout << "Marca: " << key << ", Precio del vehículo: " << value << std::endl; // Salida de depuración
                    if (key == marca) {
                        setPrecioVehiculo(value);
                        break;
                    }
                }
            }
        }
    }

    std::cout << "Lectura finalizada." << std::endl;
}