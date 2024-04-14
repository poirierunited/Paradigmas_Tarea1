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
    int get_total_accesorios();
    int get_total_clientes();
    std::pair<int, std::string> get_max_accesorios();
    std::pair<int, std::string> get_max_vehiculos();
};