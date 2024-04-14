#include "Vehiculo.h"
#include <fstream>
#include <sstream>
#include <iostream>

std::string Vehiculo::getMarca() {
    return marca;
}
int Vehiculo::getPrecioVehiculo() {
    return precio_vehiculo;
}
int Vehiculo::getPrecioAccesorio1() {
    return precio_accesorio_1;
}
int Vehiculo::getPrecioAccesorio2() {
    return precio_accesorio_2;
}
std::string Vehiculo::getNombreAccesorio1() {
    return nombre_accesorio_1;
}
std::string Vehiculo::getNombreAccesorio2() {
    return nombre_accesorio_2;
}
int Vehiculo::getCantidadVehiculos() {
    return cantidad_vehiculos;
}

void Vehiculo::setPrecioVehiculo(int precio) {
    precio_vehiculo = precio;
}
void Vehiculo::setMarca(std::string marca) {
    this->marca = marca;
}
void Vehiculo::setPrecioAccesorio1(int precio){
    this->precio_accesorio_1 = precio;
}
void Vehiculo::setPrecioAccesorio2(int precio){
    this->precio_accesorio_2 = precio;
}
void Vehiculo::setNombreAccesorio1(std::string nombre){
    this->nombre_accesorio_1 = nombre;
}
void Vehiculo::setNombreAccesorio2(std::string nombre){
    this->nombre_accesorio_2 = nombre;
}
void Vehiculo::setCantidadVehiculos(int cantidad){
    this->cantidad_vehiculos = cantidad;
}

Vehiculo::Vehiculo() {
    marca = "";
    precio_vehiculo = 0;
}

int Vehiculo::getCantidadAccesorio1() {
    return cant_accesorio_1;
}

void Vehiculo::setCantidadAccesorio1(int cantidad) {
    cant_accesorio_1 = cantidad;
}

int Vehiculo::getCantidadAccesorio2(){
    return cant_accesorio_2;
}
void Vehiculo::setCantidadAccesorio2(int cantidad) {
    cant_accesorio_2 = cantidad;
}

void Vehiculo::setDataArchivo(int tipo_vehiculo, std::string marca_ingresada) {

    std::string nombre_archivo;
    std::string nombre_accesorio_1;
    std::string nombre_accesorio_2;
    switch (tipo_vehiculo)
    {
    case 1: //Auto
        nombre_archivo = "Auto.txt";
        nombre_accesorio_1 = "Puertas";
        nombre_accesorio_2 = "Luces";
        break;
    case 2: //Moto
        nombre_archivo = "Auto.txt";
        nombre_accesorio_1 = "Puertas";
        nombre_accesorio_2 = "Luces";
        break;
    case 3: //Camión
        nombre_archivo = "Auto.txt";
        nombre_accesorio_1 = "Puertas";
        nombre_accesorio_2 = "Luces";
        break;
    default:
        nombre_archivo = "Auto.txt";
        nombre_accesorio_1 = "Puertas";
        nombre_accesorio_2 = "Luces";
        break;
    }

    std::ifstream file(nombre_archivo);
    if (!file.is_open()) {
        std::cerr << "Error: No se pudo abrir el archivo " << nombre_archivo << std::endl;
        return;
    }

    std::cout << "Leyendo archivo " << nombre_archivo << std::endl;

    std::string line;
    std::string section;
    bool marcaEncontrada = false;
    int precio_accesorio_1 = 0;
    int precio_accesorio_2 = 0;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string key;
        int value;
        if (iss >> section) {
            if (section == "Accesorios:") {
                while (iss >> key >> value) {
                    if (key == nombre_accesorio_1)
                        precio_accesorio_1 = value;
                    else if (key == nombre_accesorio_2)
                        precio_accesorio_2 = value;
                }
            } else if (section == "Marcas:") {
                while (iss >> key >> value) {
                    if (key == marca_ingresada) {
                        setPrecioVehiculo(value);
                        setMarca(key);
                        setNombreAccesorio1(nombre_accesorio_1);
                        setNombreAccesorio2(nombre_accesorio_2);
                        setPrecioAccesorio1(precio_accesorio_1);
                        setPrecioAccesorio2(precio_accesorio_2);
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


void Vehiculo::limpiarDatosVehiculo(){
    marca = "";
    precio_vehiculo = 0;
    nombre_accesorio_1 = "";
    precio_accesorio_1 = 0;
    nombre_accesorio_2 = "";
    precio_accesorio_2 = 0;
    cantidad_vehiculos = 0;
}

void Vehiculo::imprimirDatosVehiculo() {
    std::cout << "Marca: " << getMarca() << std::endl;
    std::cout << "Precio del vehiculo: " << getPrecioVehiculo() << std::endl;
    std::cout << "Cantidad de vehiculos: " << getCantidadVehiculos() << std::endl;

    std::cout << "\n" << std::endl;

    std::cout << "Nombre del accesorio 1: " << getNombreAccesorio1() << std::endl;
    std::cout << "Precio del accesorio 1: " << getPrecioAccesorio1() << std::endl;
    std::cout << "Cantidad de accesorio 1: " << getCantidadAccesorio1() << std::endl;

    std::cout << "\n" << std::endl;

    std::cout << "Nombre del accesorio 2: " << getNombreAccesorio2() << std::endl;
    std::cout << "Precio del accesorio 2: " << getPrecioAccesorio2() << std::endl;
    std::cout << "Cantidad de accesorio 2: " << getCantidadAccesorio2() << std::endl;
}