#include<iostream>
#include<vector>

#include "medico.h"

int main() {
    std::vector<Medico *> medicos;

    altaMedico(medicos,0,"Dr. Pérez","C/Albania 3",1984, "Cardiología");
    altaMedico(medicos,1, "Dr. García","C/Dinamarca 10",1957, "Dermatología");
    altaMedico(medicos,2, "Dr. López","C/Budapest 5",1980, "Pediatría");

    listarPorEspecialidad(medicos, "Cardiología");

    // Modificar disponibilidad y mostrar médicos disponibles
    medicos[0]->setDisponibilidad(true); // El Dr. Pérez ya no está disponible
    listarPorDisponibilidad(medicos);

    // Asignar nueva especialidad y mostrar lista
    listarPorEspecialidad(medicos, "Ginecología");

    // Baja de un médico
    bajaMedico(medicos, 2);

    return 0;
}