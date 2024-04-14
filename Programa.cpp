#include "Programa.h"
#include "Auto.h"
#include <cstdlib>
#include <unistd.h>

Programa::Programa() {
}

int Programa::get_total_vehiculos() {
    int total_vehiculos_comprados = 0;
    for (auto& venta : ventas) {
        total_vehiculos_comprados += venta->getTotalVehiculos();
    }

    return total_vehiculos_comprados;
}

int Programa::get_total_clientes() {
    return ventas.size();
}

Programa::~Programa() {
    for (Venta* v : ventas) {
        delete v;
    }
    ventas.clear();
}

void Programa::ejecutar() {
    int opcion = 0;
    bool venta_en_curso = false;

    do
    {
        //system("clear");
        std::cout << "============ Menu ============\n";
        std::cout << "1. Realizar venta\n";
        std::cout << "2. Promedio de ventas \n";
        std::cout << "3. Cantidad de vehículos comprados \n";
        std::cout << "4. Salir\n";
        std::cout << "Ingrese una opcion: ";
        std::cin >> opcion;
        std::cout << "\n\n";

        switch (opcion)
        {
            // ================================ 1. Realizar venta
            case 1:
                //system("clear");
                if (venta_en_curso) {
                    std::cout << "Ya hay una venta en curso.\n";
                    break;
                }
                {
                    std::string nombre_cliente;
                    std::string rut_cliente;
                    std::cout << "Ingrese nombre del cliente:\n ";
                    std::cin >> nombre_cliente;
                    std::cout << "Ingrese Rut del cliente:\n ";
                    std::cin >> rut_cliente;
                    
                    Venta* nueva_venta = new Venta(nombre_cliente, rut_cliente);
                    venta_en_curso = true;

                    int opcion_venta = 0;
                    do
                    {
                        //system("clear");
                        std::cout << "\n============ Submenu Venta ============\n";
                        std::cout << "1. Comprar vehiculo o accesorios\n";
                        std::cout << "2. Guardar datos venta.\n";
                        std::cout << "3. Cancelar venta\n";
                        std::cout << "Ingrese una opcion: ";
                        std::cin >> opcion_venta;

                        std::string tipos_vehiculos[3] = {"Auto", "Moto", "Camión"};
                        switch (opcion_venta)
                        {
                            case 1:
                                {
                                    int tipo_vehiculo = 0;
                                    do
                                    {
                                        //system("clear");
                                        std::cout << "============ Elige el tipo de vehículo ============\n";
                                        std::cout << "1. Auto\n";
                                        std::cout << "2. Moto\n";
                                        std::cout << "3. Camión\n";
                                        std::cout << "4. Volver\n";
                                        std::cout << "Ingrese una opcion: ";
                                        std::cin >> tipo_vehiculo;
                                        std::cout << "\n\n";

                                        // std::string marca_ingresada;
                                        // Vehiculo vehiculo;

                                        switch (tipo_vehiculo)
                                        {
                                        case 1:
                                        case 2:
                                        // ================================
                                        case 3:
                                            {
                                                Vehiculo vehiculo;
                                                std::string marca_ingresada;
                                                //system("clear");
                                                std::cout << "Ingrese la marca del " << tipos_vehiculos[tipo_vehiculo-1] << ":\n " << std::endl;
                                                std::cin >> marca_ingresada;

                                                vehiculo.setDataArchivo(tipo_vehiculo, marca_ingresada);

                                                if (vehiculo.getMarca() == "") {
                                                    std::cout << "Marca ingresada no existe, volviendo a submenú.\n";
                                                    sleep(5);
                                                    break;
                                                } else {
                                                    int opcion_venta;
                                                    int cantidad_vehiculos = 0;
                                                    int cantidad_accesorio_1 = 0;
                                                    int cantidad_accesorio_2 = 0;

                                                    do
                                                    {
                                                        //system("clear");
                                                        system("cls");
                                                        std::cout << "============ Submenú venta de "  << tipos_vehiculos[tipo_vehiculo-1] << " y accesorios para marca " << vehiculo.getMarca() <<" ============" << std::endl;
                                                        std::cout << "1. Comprar " << tipos_vehiculos[tipo_vehiculo-1] << " " << vehiculo.getMarca() << std::endl;
                                                        std::cout << "2. Comprar Accesorios " << vehiculo.getMarca() << std::endl;
                                                        std::cout << "3. Guardar venta y volver"<< std::endl;
                                                        std::cout << "4. Deshacer venta y volver"<< std::endl;
                                                        std::cout << "Ingrese una opcion: ";
                                                        std::cin >> opcion_venta;
                                                        std::cout << "\n\n";

                                                        switch (opcion_venta) {
                                                            // ================================
                                                            case 1:
                                                                {
                                                                    //system("clear");
                                                                    int input_cantidad_vehiculos;
                                                                    std::cout << "Elige cantidad de " << tipos_vehiculos[tipo_vehiculo-1]<< " " << vehiculo.getMarca() << " a comprar, ya haz elegido " << cantidad_vehiculos << "!"  << std::endl;
                                                                    std::cin >> input_cantidad_vehiculos;
                                                                    cantidad_vehiculos += input_cantidad_vehiculos;
                                                                }
                                                                break;
                                                            // ================================
                                                            case 2:
                                                                int tipo_accesorio;
                                                                do {
                                                                    //system("clear");
                                                                    std::cout << "Ya haz seleccionado: " << std::endl;
                                                                    std::cout << cantidad_accesorio_1 << "-" << vehiculo.getNombreAccesorio1() << std::endl;
                                                                    std::cout << cantidad_accesorio_2 << "-" << vehiculo.getNombreAccesorio2() << std::endl;
                                                                    std::cout << "\n" << std::endl;
                                                                    std::cout << "Elige accesorios para " << tipos_vehiculos[tipo_vehiculo-1] << " " << vehiculo.getMarca() << " a comprar:"  << std::endl;
                                                                    std::cout << "1." << vehiculo.getNombreAccesorio1() << std::endl;
                                                                    std::cout << "2." << vehiculo.getNombreAccesorio2() << std::endl;
                                                                    std::cout << "3. Volver\n";
                                                                    std::cin >> tipo_accesorio;

                                                                    switch (tipo_accesorio) {
                                                                        int cantidad;
                                                                        // ================================
                                                                        case 1:
                                                                            //system("clear");
                                                                            system("cls");
                                                                            std::cout << "Elige cantidad de " << vehiculo.getNombreAccesorio1() <<", ya haz seleccionado " << cantidad_accesorio_1 << " a comprar" << std::endl;
                                                                            std::cin >> cantidad;
                                                                            cantidad_accesorio_1 += cantidad;
                                                                            break;
                                                                        // ================================
                                                                        case 2:
                                                                            //system("clear");
                                                                            system("cls");
                                                                            std::cout << "Elige cantidad de " << vehiculo.getNombreAccesorio2() <<", ya haz seleccionado " << cantidad_accesorio_2 << " a comprar" << std::endl;
                                                                            std::cin >> cantidad;
                                                                            cantidad_accesorio_2 += cantidad;
                                                                            break;
                                                                        // ================================
                                                                        default:
                                                                            break;
                                                                    }
                                                                }while (tipo_accesorio != 3);
                                                                break;
                                                            // ================================
                                                            case 3:
                                                                {
                                                                    //system("clear");
                                                                    vehiculo.setCantidadAccesorio1(cantidad_accesorio_1);
                                                                    vehiculo.setCantidadAccesorio2(cantidad_accesorio_2);
                                                                    vehiculo.setCantidadVehiculos(cantidad_vehiculos);
                                                                    nueva_venta->agregarVehiculo(vehiculo);
                                                                    std::cout << "Datos de la venta:\n" << std::endl;
                                                                    vehiculo.imprimirDatosVehiculo();
                                                                    std::cout << "Presiona 1 para volver.\n";
                                                                    int opcion_salir;
                                                                    std::cin >> opcion_salir;
                                                                    do {
                                                                        switch (opcion_salir)
                                                                        {
                                                                        case 1:
                                                                            break;
                                                                        default:
                                                                            std::cout << "Opción inválida. Inténtalo de nuevo: ";
                                                                            break;
                                                                        }
                                                                    }while (opcion_salir != 1);
                                                                }
                                                                break;
                                                            // ================================
                                                            case 4:
                                                                //system("clear");
                                                                vehiculo.limpiarDatosVehiculo();
                                                                std::cout << "Venta de vehiculo cancelada.\n";
                                                                vehiculo.imprimirDatosVehiculo();
                                                                break;
                                                            // ================================
                                                            default:
                                                                break;
                                                        }
                                                    } while (opcion_venta != 3 && opcion_venta != 4);
                                                }
                                            }
                                            break;
                                        // ================================
                                        case 4:
                                            break;
                                        default:
                                            std::cout << "Opcion invalida. Intente de nuevo.\n";
                                            sleep(3);
                                            break;
                                        }
                                    } while (tipo_vehiculo != 4);
                                }
                                break;
                            // ================================ 2. Guardar datos venta
                            case 2:
                                {
                                    //system("clear");
                                    venta_en_curso = false;
                                    ventas.push_back(nueva_venta);

                                    nueva_venta->guardarDatosVenta();
                                    std::cout << "Presiona 1 para volver.\n";
                                    int opcion_salir;
                                    std::cin >> opcion_salir;
                                    do {
                                        switch (opcion_salir)
                                        {
                                            case 1:
                                                break;
                                            default:
                                                std::cout << "Opción inválida. Inténtalo de nuevo: ";
                                                break;
                                        }
                                    }while (opcion_salir != 1);
                                }
                                break;
                            // ================================ 3. Cancelar venta
                            case 3:
                                {
                                    //system("clear");
                                    std::cout << "Cancelando venta.\n";
                                    sleep(5);
                                    venta_en_curso = false;
                                    delete nueva_venta; 
                                    break;
                                }
                            default:
                                std::cout << "Opcion invalida. Intente de nuevo.\n";
                                sleep(3);
                                break;
                        }
                    } while (opcion_venta != 2 && opcion_venta != 3);
                }
                break;

            // ================================ 2. Promedio de ventas

            // ================================ 3. Cantidad de vehículos comprados

            // ================================ 4. Salir
            default:
                break;
        }
    } while (opcion != 4);
}