#include "Venta.h"
#include <iostream>
#include <fstream>
#include <ctime>

// funciones Helper
std::string obtenerFechaActual() {
    std::time_t tiempoActual = std::time(nullptr);
    std::tm* tiempoLocal = std::localtime(&tiempoActual);
    char fecha[11];
    std::strftime(fecha, sizeof(fecha), "%Y-%m-%d", tiempoLocal);
    return fecha;
}

Venta::Venta(std::string nombre_cliente, std::string rut_cliente)
    : nombre_cliente(nombre_cliente), rut_cliente(rut_cliente) {}

void Venta::agregarVehiculo(const Vehiculo& vehiculo) {
    lista_vehiculos.push_back(vehiculo);
}

const std::vector<Vehiculo>& Venta::getVehiculos() const {
    return lista_vehiculos;
}

void Venta::guardarDatosVenta() {
    int vehiculos_total = 0;
    int accesorios_total = 0;
    int total_precio_accesorios = 0;
    int total_precio_vehiculos = 0;
    int total_precio_vehiculos_descuento = 0;
    int total_general = 0;
    
    for (auto& vehiculo : lista_vehiculos) {
        vehiculos_total += vehiculo.getCantidadVehiculos();
        total_precio_vehiculos += vehiculo.getPrecioVehiculo() * vehiculo.getCantidadVehiculos();
        accesorios_total += vehiculo.getCantidadAccesorio1() + vehiculo.getCantidadAccesorio2();
        total_precio_accesorios += vehiculo.getCantidadAccesorio1()*vehiculo.getPrecioAccesorio1() + vehiculo.getCantidadAccesorio2()*vehiculo.getPrecioAccesorio2();
    }

    int descuento = 0;
    switch (vehiculos_total) {
        case 0 ... 999:
            descuento = total_precio_vehiculos * 0.01;
            break;
        case 1000 ... 4999:
            descuento = total_precio_vehiculos * 0.03;
            break;
        case 5000 ... 10000:
            descuento = total_precio_vehiculos * 0.05;
            break;
        default:
            descuento = total_precio_vehiculos * 0.10;
            break;
    }
    
    total_precio_vehiculos_descuento = total_precio_vehiculos - descuento;
    total_general = total_precio_vehiculos_descuento + total_precio_accesorios;

    std::ofstream archivo("ventas_" + obtenerFechaActual() + ".txt", std::ios::app);

    if (!archivo.is_open()) {
        std::cerr << "Error: No se pudo abrir el archivo para escribir." << std::endl;
        return;
    }

    archivo << "CLIENTE: " << nombre_cliente << std::endl;
    std::cout << "CLIENTE: " << nombre_cliente << std::endl;

    archivo << "RUT: " << rut_cliente << std::endl;
    std::cout << "RUT: " << rut_cliente << std::endl;


    archivo << "CANTIDAD (Vehículos Total):" << vehiculos_total << std::endl;
    std::cout << "CANTIDAD (Vehículos Total):" << vehiculos_total << std::endl;

    archivo << "CANTIDAD (Accesorios Total):" << accesorios_total << std::endl;
    std::cout << "CANTIDAD (Accesorios Total):" << accesorios_total << std::endl;

    archivo << "Total precio Accesorios:" << total_precio_accesorios << std::endl;
    std::cout << "Total precio Accesorios:" << total_precio_accesorios << std::endl;

    archivo << "TOTAL precio Vehículos:" << total_precio_vehiculos << std::endl;
    std::cout << "TOTAL precio Vehículos:" << total_precio_vehiculos << std::endl;

    archivo << "TOTAL con descuento %:" << total_precio_vehiculos_descuento << std::endl;
    std::cout << "TOTAL con descuento %:" << total_precio_vehiculos_descuento << std::endl;

    archivo << "TOTAL GENERAL " << total_general << std::endl;
    archivo << "\n\n" << std::endl;
    std::cout << "TOTAL GENERAL " << total_general << std::endl;

    archivo.close();
}


void Venta::setTotalVehiculosAccesorios() {
    int vehiculos_total = 0;
    int accesorios_total = 0;

    for (auto& vehiculo : lista_vehiculos) {
        vehiculos_total += vehiculo.getCantidadVehiculos();
        accesorios_total += vehiculo.getCantidadAccesorio1();
        accesorios_total += vehiculo.getCantidadAccesorio2();
    }

    cantidad_total_vehiculos = vehiculos_total;
    cantidad_total_accesorios = accesorios_total;
}

int Venta::getTotalVehiculos() {
    return cantidad_total_vehiculos;
}

int Venta::getTotalAccesorios() {
    return cantidad_total_accesorios;
}

std::string Venta::getNombreCliente() {
    return nombre_cliente;
};