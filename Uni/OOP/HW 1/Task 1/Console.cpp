#include"Console.h"

void tableInterface(){
    Table table;
    char input[MAXFILE_NAME];
    std::cin>>input;

    std::ifstream inFile(input, std::ios::in);
    if(!inFile.is_open())
        return;
    table.readFromFile(inFile);
    inFile.close();

    while(1){
        char input1 [MAX_VALUE_LEN];
        char input2 [MAX_VALUE_LEN];
        char input3 [MAX_VALUE_LEN]; 

        std::cin>>input;

        if(strcmp(input, "print") == 0){
            table.print();
        }
        else if(strcmp(input, "changeName") == 0){

            std::cin>>input1>>input2;
            table.changeColName(input1, input2);
        }
        else if(strcmp(input, "changeRow") == 0){

            int index;
            std::cin>>index>>input1>>input2;
            table.changeValue(index, input1, input2);
        }
        else if(strcmp(input, "addRow") == 0){

            Row row;
            for(size_t i {0}; i < table.getRowCount(); i++){
                std::cin>>input1;
                row.addValue(input1);         
            }
            table.addRow(row);
        }
        else if(strcmp(input, "selectWhere") == 0){

            std::cin>>input1>>input2;
            table.selectRows(input1, input2);
        }
        else if(strcmp(input, "changeByIdx") == 0){
            std::cin>>input1>>input2>>input3;
            table.changeValue(input1, input2, input3);
        }
        else if(strcmp(input, "save") == 0){
            std::cin>>input1;
            std::ofstream outFile(input1, std::ios::out);
            if(!outFile.is_open())
                continue;
            table.saveToFile(outFile);
            outFile.close();
        }
        else if(strcmp(input, "quit") == 0){
            break;
        }
        else{
            continue;
        }
        std::cout<<"Operation successfully executed"<<std::endl;
    }

}