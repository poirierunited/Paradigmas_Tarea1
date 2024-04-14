#ifndef VENTA_H
#define VENTA_H

#include <string>
#include "Vehiculo.h"

class Venta {
private:
    std::string nombre_cliente;
    std::string rut_cliente;
    std::vector<Vehiculo> lista_vehiculos;
    int cantidad_total_vehiculos;
    int cantidad_total_accesorios;

public:
    Venta(std::string nombre_cliente, std::string rut_cliente);
    void agregarVehiculo(const Vehiculo& vehiculo);
    const std::vector<Vehiculo>& getVehiculos() const;
    void guardarDatosVenta();
    void setTotalVehiculosAccesorios();
    int getTotalVehiculos();
    int getTotalAccesorios();
    std::string getNombreCliente();
};

#endif // VENTA_H