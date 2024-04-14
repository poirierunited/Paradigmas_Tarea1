#include <iostream>
#include <vector>
#include "Venta.h"

class Programa {
private:
    std::vector<Venta*> ventas;

public:
    Programa();
    ~Programa();
    void ejecutar();
    int get_total_vehiculos();
    int get_total_clientes();
};