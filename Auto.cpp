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

std::string Auto::getAccesorioN1() {
    return accesorio_n1;
}
std::string Auto::getAccesorioN2() {
    return accesorio_n2;
}

Auto::Auto() : Vehiculo() {
    precio_puertas = 0;
    precio_luces = 0;
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
    bool marcaEncontrada = false;
    int precio_puertas = 0;
    int precio_luces = 0;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string key;
        int value;
        if (iss >> section) {
            if (section == "Accesorios:") {
                while (iss >> key >> value) {
                    if (key == "Puertas")
                        precio_puertas = value;
                    else if (key == "Luces")
                        precio_luces = value;
                }
            } else if (section == "Marcas:") {
                while (iss >> key >> value) {
                    if (key == marca) {
                        setPrecioVehiculo(value);
                        setMarca(key);
                        setPrecioPuertas(precio_puertas);
                        setPrecioLuces(precio_luces);
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
