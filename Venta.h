#include <string>

class Venta {
private:
    std::string nombre_cliente;
    std::string rut_cliente;
    int cant_vehiculos;
    int cant_accesorios;
    int total_venta_vehiculos;
    int total_venta_accesorios;

public:
    Venta(std::string nombre_cliente, std::string rut_client);
    void setCantVehiculos(int total);
    void setCantAccesorios(int total);
    void setTotalVentaVehiculos(int total);
    void setTotalVentaAccesorios(int total);
    int getCantVehiculos();
    int getCantAccesorios();
    int getTotalVentaVehiculos();
    int getTotalVentaAccesorios();
};