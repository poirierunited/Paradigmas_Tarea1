#include "Vehiculo.h"
#include <string>

class Auto : public Vehiculo {
private:
    std::string tipo_vehiculo = "Auto";

public:
    Auto();
    std::string getTipoVehiculo();
};