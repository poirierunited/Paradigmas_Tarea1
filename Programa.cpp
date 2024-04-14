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
}

void Programa::ejecutar() {
    int opcion;
    bool ventaEnCurso = false;
    do {
        system("clear");
        system("cls");
        std::cout << "Menu:\n";
        std::cout << "1. Realizar venta\n";
        std::cout << "2. Promedio de ventas \n";
        std::cout << "3. Cantidad de vehículos comprados \n";
        std::cout << "4. Salir\n";
        std::cout << "Ingrese una opcion: ";
        std::cin >> opcion;
        std::cout << "\n\n";

        int max_vehiculos = 0;
        int max_accesorios = 0;
        std::string nombre_cliente_max_vehiculos = "";
        std::string nombre_cliente_max_accesorios = "";

        std::string rut_cliente;
        std::string nombre_cliente;
        switch (opcion) {
            case 1: {
                system("clear");
                system("cls");
                if (ventaEnCurso) {
                    std::cout << "Ya hay una venta en curso.\n";
                    break;
                }

                
                std::cout << "Ingrese nombre del cliente:\n ";
                std::cin >> nombre_cliente;

                
                std::cout << "Ingrese Rut del cliente:\n ";
                std::cin >> rut_cliente;

                Venta* nuevaVenta = new Venta(nombre_cliente, rut_cliente);
                ventaEnCurso = true;
                
                int opcionVenta;
                do {
                    system("clear");
                    system("cls");
                    std::cout << "\nSubmenu Venta:\n";
                    std::cout << "1. Guardar datos venta.\n";
                    std::cout << "2. Cancelar venta\n";
                    std::cout << "3. Comprar vehiculo o accesorios\n";
                    std::cout << "Ingrese una opcion: ";
                    std::cin >> opcionVenta;
                    
                    std::string tipos_vehiculos[3] = {"Auto", "Moto", "Camión"};
                    switch (opcionVenta) {
                        case 1:
                            system("clear");
                            system("cls");
                            ventaEnCurso = false;
                            ventas.push_back(nuevaVenta);

                            nuevaVenta->guardarDatosVenta();
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
                            break;
                        case 2:
                            system("clear");
                            system("cls");
                            std::cout << "Cancelando venta.\n";
                            sleep(5);
                            ventaEnCurso = false;
                            delete nuevaVenta; 
                            break;
                        case 3:
                            int tipo_vehiculo;
                            do {
                                system("clear");
                                system("cls");
                                std::cout << "Elige el tipo de vehículo.\n";
                                std::cout << "1. Auto\n";
                                std::cout << "2. Moto\n";
                                std::cout << "3. Camión\n";
                                std::cout << "4. Volver\n";
                                std::cout << "Ingrese una opcion: ";
                                std::cin >> tipo_vehiculo;
                                std::cout << "\n\n";

                                std::string marca_ingresada;
                                Vehiculo vehiculo;

                                switch (tipo_vehiculo) {
                                    case 1:
                                    case 2:
                                    case 3: {
                                        system("clear");
                                        system("cls");
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

                                            do {
                                                system("clear");
                                                system("cls");
                                                std::cout << "Submenú venta de "  << tipos_vehiculos[tipo_vehiculo-1] << " y accesorios para marca " << vehiculo.getMarca() << std::endl;
                                                std::cout << "1. Comprar " << tipos_vehiculos[tipo_vehiculo-1] << " " << vehiculo.getMarca() << std::endl;
                                                std::cout << "2. Comprar Accesorios " << vehiculo.getMarca() << std::endl;
                                                std::cout << "3. Guardar venta y volver"<< std::endl;
                                                std::cout << "4. Deshacer venta y volver"<< std::endl;
                                                std::cout << "Ingrese una opcion: ";
                                                std::cin >> opcion_venta;
                                                std::cout << "\n\n";

                                                switch (opcion_venta) {
                                                case 1:
                                                    system("clear");
                                                    system("cls");
                                                    int input_cantidad_vehiculos;
                                                    std::cout << "Elige cantidad de " << tipos_vehiculos[tipo_vehiculo-1]<< " " << vehiculo.getMarca() << " a comprar, ya haz elegido " << cantidad_vehiculos << "!"  << std::endl;
                                                    std::cin >> input_cantidad_vehiculos;
                                                    cantidad_vehiculos += input_cantidad_vehiculos;
                                                    break;
                                                case 2:
                                                    int tipo_accesorio;
                                                    do {
                                                        system("clear");
                                                        system("cls");
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
                                                        case 1:
                                                            system("clear");
                                                            system("cls");
                                                            std::cout << "Elige cantidad de " << vehiculo.getNombreAccesorio1() <<", ya haz seleccionado " << cantidad_accesorio_1 << " a comprar" << std::endl;
                                                            std::cin >> cantidad;
                                                            cantidad_accesorio_1 += cantidad;
                                                            break;
                                                        case 2:
                                                            system("clear");
                                                            system("cls");
                                                            std::cout << "Elige cantidad de " << vehiculo.getNombreAccesorio2() <<", ya haz seleccionado " << cantidad_accesorio_2 << " a comprar" << std::endl;
                                                            std::cin >> cantidad;
                                                            cantidad_accesorio_2 += cantidad;
                                                            break;
                                                        default:
                                                            break;
                                                        }
                                                    }while (tipo_accesorio != 3);
                                                    break;
                                                case 3:
                                                    system("clear");
                                                    system("cls");
                                                    vehiculo.setCantidadAccesorio1(cantidad_accesorio_1);
                                                    vehiculo.setCantidadAccesorio2(cantidad_accesorio_2);
                                                    vehiculo.setCantidadVehiculos(cantidad_vehiculos);
                                                    nuevaVenta->agregarVehiculo(vehiculo);
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
                                                    break;
                                                case 4:
                                                    system("clear");
                                                    system("cls");
                                                    vehiculo.limpiarDatosVehiculo();
                                                    std::cout << "Venta de vehiculo cancelada.\n";
                                                    vehiculo.imprimirDatosVehiculo();
                                                    break;
                                                default:
                                                    break;
                                                }

                                            }while (opcion_venta != 3 && opcion_venta != 4);
                                            break;
                                        }
                                        break;
                                    }
                                    case 4:
                                        break;
                                    default:
                                        std::cout << "Opcion invalida. Intente de nuevo.\n";
                                        sleep(3);
                                        break;
                                }
                            } while (tipo_vehiculo != 4);
                            break;
                        default:
                            std::cout << "Opcion invalida. Intente de nuevo.\n";
                            sleep(3);
                            break;
                    }
                } while (opcionVenta != 1 && opcionVenta != 2);
                break;
            }
            case 2: {
                float promedio_ventas_totales_por_cliente = 0;
                promedio_ventas_totales_por_cliente = get_total_vehiculos() / get_total_clientes();
                std::cout << "Promedio de ventas totales por cliente: " << promedio_ventas_totales_por_cliente << std::endl;
                break;
                }
            case 3:
                int total_vehiculos_comprados = get_total_vehiculos();
                std::cout << "Total de vehiculos comprados: " << total_vehiculos_comprados << std::endl;
                break;
            // case 4: {
            //     for (auto& venta : ventas) {
            //         if (max_vehiculos < venta->getTotalVehiculos()) {
            //             max_vehiculos = venta->getTotalVehiculos();
            //             nombre_cliente_max_vehiculos = venta->getNombreCliente();
            //         }
            //         if (max_accesorios < venta->getTotalAccesorios()) {
            //             max_accesorios = venta->getTotalAccesorios();
            //             nombre_cliente_max_accesorios = venta->getNombreCliente();
            //         }
            //     }

            //     std::cout << "Cliente que compro más vehículos: " << nombre_cliente_max_vehiculos << std::endl;
            //     std::cout << "Compro un total de " << max_vehiculos << " vehiculos: " << std::endl;
            //     std::cout << "\n\n" << std::endl;
            //     std::cout << "Cliente que compro más accesorios: " << nombre_cliente_max_accesorios << std::endl;
            //     std::cout << "Compro un total de " << max_vehiculos << " accesorios: " << std::endl;
            //     std::cout << "Saliendo del programa...\n";
            //     break;
            // }
            default:
                std::cout << "Opcion invalida. Intente de nuevo.\n";
                sleep(3);
                break;
        }
        
    } while (opcion != 4);
}
