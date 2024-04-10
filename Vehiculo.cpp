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

Vehiculo::Vehiculo(std::string marca) : marca(marca) {
    precio_vehiculo = 0; // Valor por defecto
}