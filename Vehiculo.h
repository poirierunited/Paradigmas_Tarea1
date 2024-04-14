#ifndef VEHICULO_H
#define VEHICULO_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

class Vehiculo {
private:
    std::string marca;
    int precio_vehiculo;
    std::string nombre_accesorio_1;
    std::string nombre_accesorio_2;
    int precio_accesorio_1;
    int precio_accesorio_2;
    int cant_accesorio_1;
    int cant_accesorio_2;
    int cantidad_vehiculos;

public:
    Vehiculo();

    std::string getMarca();
    int getPrecioVehiculo();
    int getPrecioAccesorio1();
    int getPrecioAccesorio2();
    std::string getNombreAccesorio1();
    std::string getNombreAccesorio2();
    int getCantidadVehiculos();
    int getCantidadAccesorio1();
    int getCantidadAccesorio2();

    void setPrecioVehiculo(int precio);
    void setMarca(std::string marca);
    void setDataArchivo(int tipo_vehiculo, std::string marca_ingresada);
    void setPrecioAccesorio1(int precio);
    void setPrecioAccesorio2(int precio);
    void setNombreAccesorio1(std::string nombre);
    void setNombreAccesorio2(std::string nombre);
    void setCantidadVehiculos(int cantidad);
    void setCantidadAccesorio1(int cantidad);
    void setCantidadAccesorio2(int cantidad);

    void limpiarDatosVehiculo();
    void imprimirDatosVehiculo();
};

#endif // VEHICULO_H
