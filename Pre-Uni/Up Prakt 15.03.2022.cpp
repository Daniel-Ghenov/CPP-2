#include <iostream>
#include <fstream>

const int MAX_NAME_LEN = 16;
const int CLASS_MAX_LEN  = 1024;
const int MAX_FIRM_NAME = 25;

enum class HairColor{
    brown,
    red,
    blonde,
    red,
    white
};
struct Class{
    struct Student{
        char FirstName[MAX_NAME_LEN];
        char LastName[MAX_NAME_LEN];
        int fn;
        HairColor hair;
        Student(){
            hair = HairColor::brown;
        }
        void writetoFile(std::ofstream& outFile) const{
            if(!outFile.is_open())
                return;

            outFile.write((const char*) this, sizeof(this));
        }
        void getStudent(std::ifstream& inFile){
            if(this == nullptr)
                return;
            if(!inFile.is_open())
                return;
            inFile.read((char*) this, sizeof(this));
        }

    };

    Student* students;
    int size = 0;

    Class(){
        students = new Student[0];
        size = 0;
    }
    ~Class(){
        delete[] students;
    }

    void addStudent(const Student& student){
        if(size == CLASS_MAX_LEN)
            return;

        Student* NewStudents = new Student[size + 1];
        for(size_t i {0}; i < size; i++){
            NewStudents[i] = students[i];
        }
        NewStudents[size++] = student;
        if(size > 0)
            delete[] students;
        students = NewStudents;
    }


    void writeToFile(std::ofstream& outFile) const{
        if(this == nullptr)
            return;
        if(!outFile.is_open())
            return;
        outFile.write((const char*)size, sizeof(size));
        for(size_t i {0}; i < size; i++){
            students[i].writetoFile(outFile);
        }
        outFile.close();
    }
    void getClassFromFile(std::ifstream& inFile){
        if(this == nullptr)
            return;
        if(!inFile.is_open())
            return;
        inFile.read((char*) size, sizeof(size));
        delete[] students;
        students = new Student[size];

        for(size_t i {0}; i < size; i++){
            students[i].getStudent(inFile);
        }

    }
};
    struct JobPost{
        char name[MAX_FIRM_NAME];
        int teamSize;
        int leave;
        long long pay;
        void writeToFile(std::ofstream& outFile) const{
            if(!outFile.is_open())
                return;
            outFile.write((const char*) this, sizeof(this));
        }
        void cout() const{
            std::cout<<name<<' '<<teamSize<<' '<<leave<<' '<<pay<<std::endl;
        }
        void readFromFile(std::ifstream& inFile){
            if(!inFile.is_open())
                return;
            inFile.read((char*) this, sizeof(this));
        }
    };
struct System{
    JobPost* jobs;
    int size;


    System(){
        jobs = new JobPost[0];
        size = 0;
    }
    ~System(){
        delete[] jobs;
    }
    void a(const JobPost& job){
        if(size == 1024)
            return;

        JobPost* NewPost = new JobPost[size + 1];
        for(size_t i {0}; i < size; i++){
            NewPost[i] = jobs[i];
        }
        NewPost[size++] = job;
        if(size > 0)
            delete[] jobs;
        jobs = NewPost;
    }
    void i() const{
        for(size_t i {0}; i < size; i++){
            jobs[i].cout();
        }
    }
    bool s(char* name) const{
        if(name == nullptr)
            return;
        for(size_t i {0}; i < size; i++){
            if(strcmp(jobs[i].name, name))
                return true;
        }
        return false;
    }
    int f(long long salary){
        int num = 0;
        for(size_t i {0}; i < size; i++){
            if(jobs[i].pay > salary)
                num++;
        }
        return num;
    }

};

void writeToFile(const char* filename, int n){
    if(filename == nullptr)
        return;
    std::ofstream outFile(filename, std::ios::binary | std::ios::out | std::ios::app);
    if(!outFile.is_open())
        return;

    outFile.write((const char*) n, sizeof(n));
    for(size_t i {0}; i < n; i++){
        JobPost posting;
        std::cin>>posting.name>>posting.teamSize>>posting.leave>>posting.pay;
        posting.writeToFile(outFile);
    }
    outFile.close();

}

void filterOffers(const char* filePath, long long minSalary){
    if(filePath == nullptr)
        return;
    std::ifstream inFile(filePath, std::ios::binary | std::ios::in);
    if(!inFile.is_open())
        return;
    int size;
    inFile.read((char*) size, sizeof(size));
    for(size_t i {0}; i < size; i++){
        JobPost job;
        job.readFromFile(inFile);
        if(job.pay >=  minSalary)
            job.cout();     
    }
        inFile.close();

}
bool existOffer(const char* filePath, const char* name){
    if(filePath == nullptr)
        return;
    std::ifstream inFile(filePath, std::ios::binary | std::ios::in);
    if(!inFile.is_open())
        return;
    int size;
    inFile.read((char*) size, sizeof(size));
    for(size_t i {0}; i < size; i++){
        JobPost job;
        job.readFromFile(inFile);
        if(strcmp(job.name, name)){
            inFile.close();
            return true;
        }       
    }
    inFile.close();
    return false;
}
void perfectOffer(const char* filePath, const char* outFilePath, int maxCoworkers, int minVacancyDays, long long minSalary){
    if(filePath == nullptr)
        return;
    std::ifstream inFile(filePath, std::ios::binary | std::ios::in);
    if(!inFile.is_open())
        return;
    std::ofstream outFile(outFilePath, std::ios::binary | std::ios::out);
    if(!outFile.is_open())
        return;
    int size;
    inFile.read((char*) size, sizeof(size));
    for(size_t i {0}; i < size; i++){
        JobPost job;
        job.readFromFile(inFile);
        if(job.pay >=  minSalary &&
            maxCoworkers >= job.teamSize && 
            minVacancyDays <= job.leave
        ){
            job.writeToFile(outFile);
        }
            
    }
    inFile.close();
    outFile.close();
}


int main(){



    return 0;
}