#include <iostream>
#include <vector>
#include <string>

class Patient {
public:
    std::string name;
    int age;
    std::string gender;

    Patient(std::string name, int age, std::string gender) : name(name), age(age), gender(gender) {}
};

class Doctor {
public:
    std::string name;
    std::string specialty;

    Doctor(std::string name, std::string specialty) : name(name), specialty(specialty) {}
};

class Appointment {
public:
    Patient patient;
    Doctor doctor;
    std::string date_time;

    Appointment(Patient patient, Doctor doctor, std::string date_time) : patient(patient), doctor(doctor), date_time(date_time) {}
};

class MedicalAppointmentSystem {
private:
    std::vector<Patient> patients;
    std::vector<Doctor> doctors;
    std::vector<Appointment> appointments;

public:
    void addPatient(std::string name, int age, std::string gender) {
        patients.push_back(Patient(name, age, gender));
    }

    void addDoctor(std::string name, std::string specialty) {
        doctors.push_back(Doctor(name, specialty));
    }

    void addAppointment(std::string patientName, std::string doctorName, std::string dateTime) {
        Patient patient = findPatient(patientName);
        Doctor doctor = findDoctor(doctorName);
        appointments.push_back(Appointment(patient, doctor, dateTime));
    }

    void listPatients() {
        for (const Patient& patient : patients) {
            std::cout << "Patient: " << patient.name << ", Age: " << patient.age << ", Gender: " << patient.gender << std::endl;
        }
    }

    void listDoctors() {
        for (const Doctor& doctor : doctors) {
            std::cout << "Doctor: " << doctor.name << ", Specialty: " << doctor.specialty << std::endl;
        }
    }

    void listAppointments() {
        for (const Appointment& appointment : appointments) {
            std::cout << "Appointment: " << appointment.date_time << std::endl;
            std::cout << "  Patient: " << appointment.patient.name << std::endl;
            std::cout << "  Doctor: " << appointment.doctor.name << std::endl;
            std::cout << "--------------------------" << std::endl;
        }
    }

private:
    Patient findPatient(std::string name) {
        for (const Patient& patient : patients) {
            if (patient.name == name) {
                return patient;
            }
        }
        throw std::runtime_error("Patient not found.");
    }

    Doctor findDoctor(std::string name) {
        for (const Doctor& doctor : doctors) {
            if (doctor.name == name) {
                return doctor;
            }
        }
        throw std::runtime_error("Doctor not found.");
    }
};

int main() {
    MedicalAppointmentSystem system;

    system.addPatient("Alice", 30, "Female");
    system.addPatient("Bob", 45, "Male");

    system.addDoctor("Dr. Smith", "Cardiology");
    system.addDoctor("Dr. Johnson", "Dermatology");

    system.addAppointment("Alice", "Dr. Smith", "2023-08-15 10:00 AM");
    system.addAppointment("Bob", "Dr. Johnson", "2023-08-16 2:30 PM");

    std::cout << "Patients:" << std::endl;
    system.listPatients();

    std::cout << "\nDoctors:" << std::endl;
    system.listDoctors();

    std::cout << "\nAppointments:" << std::endl;
    system.listAppointments();

    return 0;
}
