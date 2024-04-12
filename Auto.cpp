#include "Auto.h"
#include <fstream>
#include <sstream>
#include <iostream>

int Auto::getPrecioPuertas() {
    return precio_puertas;
}

int Auto::getPrecioLuces() {
    return precio_luces;
}

void Auto::setPrecioPuertas(int precio) {
    precio_puertas = precio;
}

void Auto::setPrecioLuces(int precio) {
    precio_luces = precio;
}

Auto::Auto(std::string marca) : Vehiculo() {
    std::string fileName = "Auto.txt";
    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "Error: No se pudo abrir el archivo " << fileName << std::endl;
        return;
    }

    std::cout << "Leyendo archivo " << fileName << std::endl;

    std::string line;
    std::string section;
    bool marcaEncontrada = false; // Bandera para verificar si se encontró la marca
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string key;
        int value;
        if (iss >> section) {
            if (section == "Accesorios:") {
                while (iss >> key >> value) {
                    // std::cout << "Accesorio: " << key << ", Precio: " << value << std::endl; // Salida de depuración
                    if (key == "Puertas")
                        setPrecioPuertas(value);
                    else if (key == "Luces")
                        setPrecioLuces(value);
                }
            } else if (section == "Marcas:") {
                while (iss >> key >> value) {
                    // std::cout << "Marca: " << key << ", Precio del vehículo: " << value << std::endl; // Salida de depuración
                    if (key == marca) {
                        setPrecioVehiculo(value);
                        setMarca(key);
                        marcaEncontrada = true;
                        break;
                    }
                }
            }
        }
    }

    if (!marcaEncontrada) {
        std::cerr << "Error: La marca " << marca << " no existe en el archivo." << std::endl;
        file.close();
        return;
    }

    std::cout << "Lectura finalizada." << std::endl;
    file.close();
}
