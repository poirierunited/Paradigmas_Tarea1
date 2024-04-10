#include "Vehiculo.h"
#include <string>

class Auto : public Vehiculo {
private:
    int precio_puertas;
    int precio_luces;

public:
    Auto(std::string marca);
    int getPrecioPuertas();
    int getPrecioLuces();
    void setPrecioPuertas(int precio);
    void setPrecioLuces(int precio);
};