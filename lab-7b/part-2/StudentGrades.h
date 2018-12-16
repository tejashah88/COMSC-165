#ifndef STUDENTGRADES_H
#define STUDENTGRADES_H

class StudentGrades {
    public:
        StudentGrades(int _grade1, int _grade2, int _grade3, int _grade4) {
            grade1 = _grade1;
            grade2 = _grade2;
            grade3 = _grade3;
            grade4 = _grade4;
        };

        int getGrade1() { return grade1; }
        int setGrade1(int val) { grade1 = val; }

        int getGrade2() { return grade2; }
        int setGrade2(int val) { grade2 = val; }

        int getGrade3() { return grade3; }
        int setGrade3(int val) { grade3 = val; }

        int getGrade4() { return grade4; }
        int setGrade4(int val) { grade4 = val; }

        void printGrades();
        float getAverageGrade() const { return (grade1 + grade2 + grade3 + grade4) / 4; };

    private:
        int grade1, grade2, grade3, grade4;
};

#endif // STUDENTGRADES_H
