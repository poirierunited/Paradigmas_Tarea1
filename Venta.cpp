#include "Venta.h"

Venta::Venta(std::string nombre_cliente, std::string rut_cliente) {
    this->nombre_cliente = nombre_cliente;
    this->rut_cliente = rut_cliente;
    cant_vehiculos = 0;
    cant_accesorios = 0;
    total_venta_vehiculos = 0;
    total_venta_accesorios = 0;
}
void Venta::setCantVehiculos(int total) {
    cant_vehiculos = total;
}
void Venta::setCantAccesorios(int total) {
    cant_accesorios = total;
}
void Venta::setTotalVentaVehiculos(int total) {
    total_venta_vehiculos = total;
}
void Venta::setTotalVentaAccesorios(int total) {
    total_venta_accesorios = total;
}
int Venta::getCantVehiculos() {
    return cant_vehiculos;
}
int Venta::getCantAccesorios() {
    return cant_accesorios;
}
int Venta::getTotalVentaVehiculos() {
    return total_venta_vehiculos;
}
int Venta::getTotalVentaAccesorios() {
    return total_venta_accesorios;
}
