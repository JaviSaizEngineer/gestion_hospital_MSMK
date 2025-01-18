#include<iostream>
#include<vector>

#include "medico.h"
#include "paciente.h"

int main() {
    std::vector<Medico *> medicos;
    std::vector<Paciente *> pacientes;
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

    listarPorEspecialidad(medicos, "Cardiología");

    // Modificar disponibilidad y mostrar médicos disponibles
    medicos[0]->setDisponibilidad(true); // El Dr. Pérez ya no está disponible
    listarPorDisponibilidad(medicos);

    // Asignar nueva especialidad y mostrar lista
    listarPorEspecialidad(medicos, "Ginecología");

    // Baja de un médico
    bajaMedico(medicos, 2);

    std::cout<<"------------------------------------\n";

    pacientes[0]->agregarRegistro(registro1);
    pacientes[0]->agregarRegistro(registro2);
    pacientes[0]->mostrarHistorial();
    listarPorFechaRegistro(pacientes,fecha1);
    busquedaPorNombre(pacientes,"Mr AUZ");
    busquedaPorId(pacientes,0);

    pacientes[0]->mostrarInformacion();

    bajaPaciente(pacientes,0);

    return 0;
}