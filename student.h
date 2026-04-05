#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>

enum ART_EMPHASIS {
    ART_STUDIO,
    ART_HISTORY,
    ART_EDUCATION
};

enum CONCENTRATION {
    BIOPHYSICS,
    EARTH_AND_PLANETARY_SCIENCES
};

class Student {
public:
    Student() {
        first_name = "John";
        last_name = "Doe";
        grad_year = "2026";
        grad_sem = "Spring";
        enrolled_year = "2022";
        enrolled_sem = "Fall";
        level = "Undergrad";
        gpa = 0.0;
    }

    // IMPORTANT: virtual destructor
    virtual ~Student() {}

    // Getters
    std::string getFirstName() { return first_name; }
    std::string getLastName() { return last_name; }
    std::string getGradYear() { return grad_year; }
    std::string getGradSem() { return grad_sem; }
    std::string getEnrolledYear() { return enrolled_year; }
    std::string getEnrolledSem() { return enrolled_sem; }
    std::string getLevel() { return level; }
    double getGPA() { return gpa; }

    // Setters
    void setFirstName(std::string fn) { first_name = fn; }
    void setLastName(std::string ln) { last_name = ln; }
    void setGradYear(std::string gy) { grad_year = gy; }
    void setGradSem(std::string gs) { grad_sem = gs; }
    void setEnrolledYear(std::string ey) { enrolled_year = ey; }
    void setEnrolledSem(std::string es) { enrolled_sem = es; }
    void setLevel(std::string l) { level = l; }
    void setGPA(double g) { gpa = g; }

protected:
    std::string first_name;
    std::string last_name;
    std::string grad_year;
    std::string grad_sem;
    std::string enrolled_year;
    std::string enrolled_sem;
    std::string level;
    double gpa;
};

class Art_Student : public Student {
public:
    Art_Student() : emphasis(ART_STUDIO) {}

    ~Art_Student() {}

    void setEmphasis(ART_EMPHASIS e) { emphasis = e; }
    ART_EMPHASIS getEmphasis() { return emphasis; }

private:
    ART_EMPHASIS emphasis;
};

class Physics_Student : public Student {
public:
    Physics_Student() : concentration(BIOPHYSICS) {}

    ~Physics_Student() {}

    void setConcentration(CONCENTRATION c) { concentration = c; }
    CONCENTRATION getConcentration() { return concentration; }

private:
    CONCENTRATION concentration;
};

#endif
