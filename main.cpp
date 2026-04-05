#include <iostream>
#include <vector>
#include <fstream>
#include "student.h"

std::string emphasisToString(ART_EMPHASIS e) {
    switch(e) {
        case ART_STUDIO: return "Art Studio";
        case ART_HISTORY: return "Art History";
        case ART_EDUCATION: return "Art Education";
    }
    return "";
}

std::string concentrationToString(CONCENTRATION c) {
    switch(c) {
        case BIOPHYSICS: return "Biophysics";
        case EARTH_AND_PLANETARY_SCIENCES: return "Earth and Planetary Sciences";
    }
    return "";
}

int main() {
    std::vector<Art_Student*> artStudents;
    std::vector<Physics_Student*> physicsStudents;

    // Create 5 Art Students
    for(int i = 0; i < 5; i++) {
        Art_Student* s = new Art_Student();
        s->setFirstName("John_" + std::to_string(i));
        s->setLastName("Doe" + std::to_string(i));
        s->setGPA(3.0 + i * 0.1);
        s->setEmphasis((ART_EMPHASIS)(i % 3));
        artStudents.push_back(s);
    }

    // Create 5 Physics Students
    for(int i = 0; i < 5; i++) {
        Physics_Student* s = new Physics_Student();
        s->setFirstName("PhysFirst" + std::to_string(i));
        s->setLastName("PhysLast" + std::to_string(i));
        s->setGPA(3.2 + i * 0.1);
        s->setConcentration((CONCENTRATION)(i % 2));
        physicsStudents.push_back(s);
    }

    // Write to file
    std::ofstream file("students.txt");

    file << "=== Art Students ===\n";
    for(auto s : artStudents) {
        file << s->getFirstName() << " " << s->getLastName()
             << ", GPA: " << s->getGPA()
             << ", Emphasis: " << emphasisToString(s->getEmphasis())
             << "\n";
    }

    file << "\n=== Physics Students ===\n";
    for(auto s : physicsStudents) {
        file << s->getFirstName() << " " << s->getLastName()
             << ", GPA: " << s->getGPA()
             << ", Concentration: " << concentrationToString(s->getConcentration())
             << "\n";
    }

    file.close();

    // Cleanup (VERY IMPORTANT)
    for(auto s : artStudents) delete s;
    for(auto s : physicsStudents) delete s;

    return 0;
}
