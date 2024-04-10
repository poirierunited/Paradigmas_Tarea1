#include "Camion.h"
#include <fstream>
#include <sstream>
#include <iostream>

int Camion::getPrecioCaja() {
    return precio_caja;
}

int Camion::getPrecioEjes() {
    return precio_ejes;
}

void Camion::setPrecioCaja(int precio) {
    precio_caja = precio;
}

void Camion::setPrecioEjes(int precio) {
    precio_ejes = precio;
}

Camion::Camion(std::string marca) : Vehiculo(marca) {
    std::string fileName = "Camion.txt";
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
                    if (key == "Caja")
                        setPrecioCaja(value);
                    else if (key == "Ejes")
                        setPrecioEjes(value);
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





