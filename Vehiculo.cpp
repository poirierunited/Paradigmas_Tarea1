#include "Vehiculo.h"

std::string Vehiculo::getMarca() {
    return marca;
}

int Vehiculo::getPrecioVehiculo() {
    return precio_vehiculo;
}

void Vehiculo::setPrecioVehiculo(int precio) {
    precio_vehiculo = precio;
}

void Vehiculo::setMarca(std::string marca) {
    this->marca = marca;
}

Vehiculo::Vehiculo() {
    marca = "";
    precio_vehiculo = 0;
}