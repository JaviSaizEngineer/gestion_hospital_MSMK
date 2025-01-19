#include<iostream>
#include<vector>

#include "medico.h"
#include "paciente.h"
#include "citaMedica.h"

int menuPrincipal(){
    int opcion;
    do{
        std::cout<<"---------Menu principal---------\n";
        std::cout<<"1. Gestion de pacientes\n";
        std::cout<<"2. Gestion de medicos\n";
        std::cout<<"3. Gestion de citas\n";
        std::cout<<"0. Salir\n";
        std::cout<<"Opcion: ";
        std::cin>>opcion;
    }while(opcion<0 || opcion>3);

    return opcion;
}

int menuPacientes(){
    int opcion;
    do{
        std::cout<<"---------Menu pacientes---------\n";
        std::cout<<"1. Alta de pacientes\n";
        std::cout<<"2. Baja de pacientes\n";
        std::cout<<"3. Modificación de datos personales.\n";
        std::cout<<"4. Búsqueda de pacientes por nombre.\n";
        std::cout<<"5. Búsqueda de pacientes por id.\n";
        std::cout<<"6. Búsqueda de pacientes por fecha de ingreso.\n";
        std::cout<<"7. Mostrar historial clinico.\n";
        std::cout<<"8. Aniadir registro al historial clinico.\n";
        std::cout<<"0. Salir\n";
        std::cout<<"Opcion: ";
        std::cin>>opcion;
    }while(opcion<0 || opcion > 8);

    return opcion;
}

int menuMedicos(){
    int opcion;
    do{
        std::cout<<"---------Menu medicos---------\n";
        std::cout<<"1. Alta de medicos\n";
        std::cout<<"2. Baja de medicos\n";
        std::cout<<"3. Listado de médicos por especialidad\n";
        std::cout<<"4. Listado de médicos por disponibilidad.\n";
        std::cout<<"5. Mostrar informacion de un medico\n";
        std::cout<<"0. Salir\n";
        std::cout<<"Opcion: ";
        std::cin>>opcion;
    }while(opcion<0 || opcion > 5);

    return opcion;
}

int menuCitas(){
    int opcion;
    do{
        std::cout<<"---------Menu citas---------\n";
        std::cout<<"1. Asignacion de citas\n";
        std::cout<<"2. Ordenar citas\n";
        std::cout<<"3. Cancelacion de citas\n";
        std::cout<<"4. Modificacion de citas.\n";
        std::cout<<"0. Salir\n";
        std::cout<<"Opcion: ";
        std::cin>>opcion;
    }while(opcion<0 || opcion > 4);

    return opcion;
}

int main() {
    /*std::vector<Medico *> medicos;
    std::vector<Paciente *> pacientes;
    std::vector<CitaMedica *> citas;

    Fecha fecha1=Fecha(18,1,2023);
    Fecha fecha2=Fecha(3,4,2022);
    Fecha fecha3=Fecha(7,2,2021);
    RegistroClinico registro1=RegistroClinico(fecha2,"caries","muy grave","cura");
    RegistroClinico registro2=RegistroClinico(fecha3,"esguince","grave","reposo");

    altaMedico(medicos,0,"Dr. Pérez","C/Albania 3",1984, "Cardiología");
    altaMedico(medicos,1, "Dr. García","C/Dinamarca 10",1957, "Dermatología");
    altaMedico(medicos,2, "Dr. López","C/Budapest 5",1980, "Pediatría");

    altaPaciente(pacientes,0,"Mr Saiz","C/Albania 3",2000, 664595385,"herida en la pierna",fecha1);
    altaPaciente(pacientes,1, "Mr AUZ","C/Dinamarca 10",2004, 666666666,"herida en el brazo",fecha1);

    std::cout<<"------------------------------------\n";

    pacientes[0]->agregarRegistro(registro1);
    pacientes[0]->agregarRegistro(registro2);
    pacientes[0]->mostrarHistorial();


    std::cout<<"------------Citas--------------\n";
    asignarCita(citas,0,*pacientes[0],*medicos[1],fecha2,false);
    asignarCita(citas,1,*pacientes[1],*medicos[1],fecha3,false);
    asignarCita(citas,2,*pacientes[0],*medicos[0],fecha1,true);
    mostrarCitas(citas);
    ordenarCitasPorUrgenciaYFecha(citas);
    mostrarCitas(citas);*/

    std::vector<Medico *> medicos;
    std::vector<Paciente *> pacientes;
    std::vector<CitaMedica *> citas;

    int opcionMenuPrincipal=menuPrincipal();
    int opcionGestionPacientes,opcionGestionMedicos,opcionGestionCitas;
    int idPaciente,anioNacimiento,dia, mes, anio,telefonoPaciente,edadPaciente;
    int idMedico,anioNacimientoMedico;
    int idCita;
    bool urgente;
    std::string nombrePaciente,direccionPaciente,notas;
    std::string diagnostico, tratamiento, observacion;
    std::string nombreMedico,direccionMedico,especialidad;
    char respuestaUrgente;
    Fecha fecha;
    while(opcionMenuPrincipal!=0){
        switch(opcionMenuPrincipal){
            case 1:
                opcionGestionPacientes=menuPacientes();
                switch(opcionGestionPacientes){
                    case 1:
                        std::cout<<"Introduce el id del paciente: ";
                        std::cin>>idPaciente;
                        std::cout<<"Introduce el nombre del paciente: ";
                        std::cin.ignore();
                        getline(std::cin,nombrePaciente);
                        std::cout<<"Introduce la direccion del paciente: ";
                        std::cin>>direccionPaciente;
                        std::cout<<"Introduce el anio de nacimiento del paciente: ";
                        std::cin>>anioNacimiento;
                        std::cout<<"Introduce el telefono del paciente: ";
                        std::cin>>telefonoPaciente;
                        std::cout<<"Introduce la nota del paciente: ";
                        std::cin>>notas;
                        std::cout<<"Introduce el dia de ingreso: ";
                        std::cin>>dia;
                        std::cout<<"Introduce el mes de ingreso: ";
                        std::cin>>mes;
                        std::cout<<"Introduce el anio de ingreso: ";
                        std::cin>>anio;
                        fecha=Fecha(dia,mes,anio);
                        altaPaciente(pacientes,idPaciente,nombrePaciente,direccionPaciente,anioNacimiento, telefonoPaciente,notas,fecha);
                    break;
                    case 2:
                        std::cout<<"Id de paciente al que quieres dar baja: ";
                        std::cin>>idPaciente;
                        bajaPaciente(pacientes,idPaciente);
                    break;
                    case 3:
                        std::cout<<"Introduce el id del paciente del que quieres modificar informacion: ";
                        std::cin>>idPaciente;
                        std::cout<<"Introduce la nueva direccion: ";
                        std::cin.ignore();
                        getline(std::cin,direccionPaciente);
                        std::cout<<"Introduce la nueva edad del paciente: ";
                        std::cin>>edadPaciente;
                        std::cout<<"Introduce ela nueva nota del paciente: ";
                        std::cin.ignore();
                        getline(std::cin,notas);
                        std::cout<<"Introduce el nuevo telefono del paciente: ";
                        std::cin>>telefonoPaciente;
                        pacientes[idPaciente]->modificarDatosPersonales(direccionPaciente,edadPaciente,notas,telefonoPaciente);
                    break;
                    case 4:
                        std::cout<<"Introduce el nombre del paciente a buscar: ";
                        std::cin.ignore();
                        getline(std::cin,nombrePaciente);
                        busquedaPorNombre(pacientes,nombrePaciente);
                    break;
                    case 5:
                        std::cout<<"Introduce el id del paciente a buscar: ";
                        std::cin>>idPaciente;
                        busquedaPorId(pacientes,idPaciente);
                    break;
                    case 6:
                        std::cout<<"Introduce el anio de ingreso del paciente a buscar: ";
                        std::cin>>anio;
                        std::cout<<"Introduce el mes de ingreso del paciente a buscar: ";
                        std::cin>>mes;
                        std::cout<<"Introduce el dia de ingreso del paciente a buscar: ";
                        std::cin>>dia;
                        fecha=Fecha(dia,mes,anio);
                        listarPorFechaRegistro(pacientes,fecha);
                    break;
                    case 7:
                        std::cout<<"Introduce el id del paciente del que queires mostrar el historial clinico: ";
                        std::cin>>idPaciente;
                        pacientes[idPaciente]->mostrarHistorial();
                    break;
                    case 8:
                        std::cout<<"Introduce el id del paciente al que quieres agregar un nuevo registro: ";
                        std::cin>>idPaciente;
                        std::cout<<"Introduce el anio: ";
                        std::cin>>anio;
                        std::cout<<"Introduce el mes: ";
                        std::cin>>mes;
                        std::cout<<"Introduce el dia: ";
                        std::cin>>dia;
                        std::cout<<"Introduce el diagnostico del paciente: ";
                        std::cin>>diagnostico;
                        
                        std::cout<<"Introduce el tratamiento del paciente: ";
                        std::cin>>tratamiento;
                        std::cout<<"Introduce la observacion del paciente: ";
                        std::cin>>observacion;
                        fecha=Fecha(dia,mes,anio);
                        RegistroClinico registro=RegistroClinico(fecha,diagnostico,tratamiento,observacion);
                        pacientes[idPaciente]->agregarRegistro(registro);
                    break;
                }
            break;
            case 2:
            opcionGestionMedicos=menuMedicos();
                switch(opcionGestionMedicos){
                    case 1:
                        std::cout<<"Introduce el id del medico: ";
                        std::cin>>idMedico;
                        std::cout<<"Introduce el nombre del medico: ";
                        std::cin.ignore();
                        getline(std::cin,nombreMedico);
                        std::cout<<"Introduce la direccion del medico: ";
                        std::cin.ignore();
                        getline(std::cin,direccionMedico);
                        std::cout<<"Introduce la especialidad del medico: ";
                        std::cin.ignore();
                        getline(std::cin,especialidad);
                        std::cout<<"Introduce el anio de nacimiento del medico: ";
                        std::cin>>anioNacimientoMedico;
                        altaMedico(medicos,idMedico,nombreMedico,direccionMedico,anioNacimientoMedico,especialidad);
                    break;
                    case 2:
                        std::cout<<"Id del medico al que quieres dar baja: ";
                        std::cin>>idMedico;
                        bajaMedico(medicos,idMedico);
                    break;
                    case 3:
                        std::cout<<"Introduce la especialidad a buscar: ";
                        std::cin.ignore();
                        getline(std::cin,especialidad);
                        listarPorEspecialidad(medicos,especialidad);
                    break;
                    case 4:
                        listarPorDisponibilidad(medicos);
                    break;
                    case 5:
                    std::cout<<"Introduce el id del medico del que queires mostrar su informacion: ";
                        std::cin>>idMedico;
                        medicos[idMedico]->mostrarInformacion();
                    break;
                }
            break;
            case 3:
            opcionGestionCitas=menuCitas();
                switch(opcionGestionCitas){
                    case 1:
                        //asignarCita(citas,)
                    break;
                    case 2:
                        ordenarCitasPorUrgenciaYFecha(citas);
                    break;
                    case 3:
                        std::cout<<"Introduce el id de la cita que quieres cancelar: ";
                        std::cin>>idCita;
                        cancelarCita(citas,idCita);
                    break;
                    case 4:
                        std::cout<<"Introduce el id de la cita que quieres modificar: ";
                        std::cin>>idCita;
                        std::cout<<"Introduce el nuevo dia de la cita: ";
                        std::cin>>dia;
                        std::cout<<"Introduce el nuevo mes de la cita: ";
                        std::cin>>mes;
                        std::cout<<"Introduce el nuevo anio de la cita: ";
                        std::cin>>anio;
                        std::cout<<"Introduce si es urgente o no (S/N): ";
                        std::cin>>respuestaUrgente;
                        if(respuestaUrgente=='S'){
                            urgente=true;
                        }
                        else{
                            urgente=false;
                        }
                        fecha=Fecha(dia,mes,anio);
                        modificarCita(citas,idCita,fecha,urgente);
                    break;
                }
            break;
        }
        opcionMenuPrincipal=menuPrincipal();
    }

    return 0;
}