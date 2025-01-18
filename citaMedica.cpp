#include "citaMedica.h"
#include<iostream>

CitaMedica::CitaMedica(int id,const Paciente &paciente,const Medico &medico, const Fecha &fecha,bool urgente){
    this->id=id;
    this->paciente=paciente;
    this->medico=medico;
    this->fecha=fecha;
    this->urgente=urgente;
}

void CitaMedica::mostrarCita() const{
    std::cout<<"\nPaciente: "<<this->paciente.getNombre();
    std::cout<<"\nMedico: "<<this->medico.getNombre();
    std::cout<<"\nFecha: "<<this->fecha;
    if(this->urgente){
        std::cout<<"\nUrgente: Si\n";
    }
    else{
        std::cout<<"\nUrgente: No\n";
    }
}

int CitaMedica::getId(){
    return this->id;
}

void CitaMedica::setId(int id){
    this->id=id;
}

Paciente CitaMedica::getPaciente() const{
    return this->paciente;
}
void CitaMedica::setPaciente(const Paciente &paciente){
    this->paciente=paciente;
}
Medico CitaMedica::getMedico() const{
    return this->medico;
}
void CitaMedica::setMedico(const Medico &medico){
    this->medico=medico;
}
Fecha CitaMedica::getFecha() const{
    return this->fecha;
}
void CitaMedica::setFecha(const Fecha &fecha){
    this->fecha=fecha;
}
bool CitaMedica::getUrgente() const{
    return this->urgente;
}
void CitaMedica::setUrgente(bool urgente){
    this->urgente=urgente;
}

//funciones

void asignarCita(std::vector<CitaMedica *>& citas,int id,const Paciente &paciente,const Medico &medico, const Fecha &fecha,bool urgente){
    CitaMedica* cita= new CitaMedica(id,paciente,medico, fecha,urgente);
    citas.push_back(cita);
    std::cout << "Cita con id " << id << " agregada.\n";
}