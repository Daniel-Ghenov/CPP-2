#include "System.h"

int main(){

    System sys(3);
    sys.addFile("Def", 25,3,2023, 17, 6, 0, "rwxr-xr--");
    sys.editFile("Def", "Fmi e super tupo", 25,3,2023, 17, 7, 0, 'u');
    sys.addFile("Abc", 25,3,2023, 17, 6, 0, "rwxr-xr--");
    sys.editFile("Abc", "Obache horata sa qki", 25,3,2023, 17, 7, 0, 'u');
    sys.addInFile("Abc", ", no vse pak e tupo", 25,3,2023, 17, 7, 0, 'u');
    sys.printContent("Def", 'u');
    sys.sort(SortOptions::size);
    sys.print();

    return 0;
}