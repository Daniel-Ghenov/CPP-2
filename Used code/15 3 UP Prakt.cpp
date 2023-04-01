#include <iostream>
#include <fstream>

const int relationMaxSize = 25;
const int lineMaxSize = 1024;
const int userMaxSize = 20;
const int systemMaxSize = 100;
const int loginInputSize = 10;

int difference(char* filename){
    std::ifstream inFile(filename);
    if(!inFile.is_open()){
        return -1;
    }
    int sum, product;
    inFile>>sum>>product;
    
    return sum - product;
}

void writeABC(char* filename){
    int a,b,c;
    std::cin>>a>>b>>c;

    std::ofstream outFile(filename);
    if(!outFile.is_open()){
        return;
    }

    outFile<< a + b + c<<" "<< a*b*c;
    outFile.close();
}
int lengthOfFile(char* filename){
    std::ifstream inFile(filename);
    if(!inFile.is_open()){
        return -1;
    }
    inFile.seekg(0 , inFile.end);
    int len = inFile.tellg();
    inFile.close();
    return len;
}
int myGcd(int a, int b){

    while(b > 0){
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}
struct Rational {
    int nom;
    int denom;
};
void toNorm(Rational& rat){
    int gcd = myGcd(rat.nom, rat.denom);
    rat.nom /= gcd;
    rat.denom /= gcd;
}
void sum(const Rational& rat1, const Rational& rat2, char* filename){
    std::ofstream outFile(filename);
    if(!outFile.is_open()){
        return;
    }
    Rational sum;
    sum.nom = (rat1.nom * rat2.denom) + (rat2.nom * rat1.denom);
    sum.denom = rat1.denom * rat2.denom;
    toNorm(sum);
    outFile << sum.nom<<"/"<<sum.denom;
}
void prod(const Rational& rat1, const Rational& rat2, char* filename){
    std::ofstream outFile(filename);
    if(!outFile.is_open()){
        return;
    }
    Rational prod;
    prod.nom = rat1.nom * rat2.nom;
    prod.denom = rat1.denom * rat2.denom;
    toNorm(prod);
    outFile << prod.nom<<"/"<<prod.denom;
}
struct Pair{
    int a, b;
};
struct Relation{
    Pair pairs[relationMaxSize];
    int currSize;
};
Pair createPair(){
    int a, b;

    std::cin>>a>>b;
    Pair pair;
    pair.a = a;
    pair.b = b;
    return pair;
}
void initPair(Pair& pair, int a, int b){
    pair.a = a;
    pair.b = b;
}
void initRelation(Relation& relation){
    int pairCount;
    std::cin>>pairCount;
    for(size_t i {0}; i < pairCount; i++){
        relation.pairs[i] = createPair();
    }
    relation.currSize = pairCount;
}
void addPairToRelation(Relation& relation, const Pair& pair){
    if(relation.currSize >= 25 || relation.currSize < 0){
        return;
    }
    relation.pairs[relation.currSize++] = pair;
}
void readRelFromFile(char* filename, Relation& relation){
    std::ifstream iFile(filename);
    if(!iFile.is_open()){
        return;
    }
    char* line = new char[lineMaxSize];
    iFile.ignore();
    int counter = 0;

    iFile.getline(line, lineMaxSize, '(');
    while(!iFile.eof()){
        iFile.getline(line, lineMaxSize, '(');

        relation.pairs[counter].a = line[0] - '0';
        relation.pairs[counter++].b = line[4] - '0';
    }
    relation.currSize = counter;
    iFile.close();
}
void writeRelationToFile(const Relation& relation, char* filename){
    std::ofstream outFile(filename);
    if(!outFile.is_open()){
        return;
    }
    int size = relation.currSize;
    for(size_t i{0}; i < size; i++){
        outFile<<"("<<relation.pairs[i].a<<" , "<<relation.pairs[i].b<<") ";
    }
    outFile.close();
}

struct User{
    char username[userMaxSize];
    char email[userMaxSize];
    char password[userMaxSize];
};
struct System{
    User users[systemMaxSize];
    int currSysSize;
} 
void readUserFromFile(User& user, char* filename){
    
    std::ifstream iFile(filename);
    if(!iFile.is_open()){
        return;
    }
    char line[userMaxSize];

    iFile<<user.username<<user.email<<user.password;
    iFile.close();
}
void readUserFromFileStream(User& user, std::ifstream& iFile){
    iFile<<user.username<<user.email<<user.password;

}
void writeUserToFile(const User& user, char* filename){
    std::ofstream outFile(filename, ios::app);
    if(!outFile.is_open()){
        return;
    }
    outFile<<user.username<<" "<<user.email<<" "<<user.password<<std::endl;
    outFile.close();
}
void writeSystemToFile(const System& system, char* filename){
    int size = system.currSysSize;

    for(size_t i {0}; i < size; i++){
        writeUserToFile(system.users[i], filename);
    }

}
void readSystemFromFile(System& system, char* filename){
    std::ifstream iFile(filename);

    if(!iFile.is_open())
        return;
    
    int counter = 0;
    while(iFile.eof()){
        readUserFromFileStream(system.users[counter++], iFile);
        iFile.ignore();
    }
    iFile.close();
}
void login(System& system){
    char input[]
}

int main(){
    // char filename[] = "result.txt";
    // writeABC(filename);
    // std::cout<<difference(filename);

    // Rational rat1 {1,2};
    // Rational rat2 {3,4};
    // char filename1[] = "add.txt";
    // char filename2[] = "mult.txt";
    // sum(rat1, rat2, filename1);
    // prod(rat1, rat2, filename2);

    // Relation rel;
    // initRelation(rel);
    // char filename[] = "relation.txt";
    // writeRelationToFile(rel, filename);
    
    // Relation rel;
    // char filename[] = "relation.txt";
    // readRelFromFile(filename, rel);
    // addPairToRelation(rel, createPair());
    // writeRelationToFile(rel, filename);
    







    return 0;
}