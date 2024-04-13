#include <string>

class Vehiculo {
private:
    std::string marca;
    int precio_vehiculo;

public:
    Vehiculo();
    std::string getMarca();
    int getPrecioVehiculo();
    void setPrecioVehiculo(int precio);
    void setMarca(std::string marca);
    void setDataArchivo(std::string nombre_archivo);
};