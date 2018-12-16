#ifndef WORKER_H
#define WORKER_H

using namespace std;

class Worker {
    public:
        Worker() {}
        Worker(string _name, int _id, string _employmentDate) : name(_name), id(_id), employmentDate(_employmentDate) {}

        string getName() { return name; }
        void setName(string val) { name = val; }
        int getId() { return id; }
        void setId(int val) { id = val; }
        string getEmploymentDate() { return employmentDate; }
        void setEmploymentDate(string val) { employmentDate = val; }

    private:
        string name;
        int id;
        string employmentDate;
};

#endif // WORKER_H
