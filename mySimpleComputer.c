#include <stdlib.h>
#include <stdio.h>

#include "mySimpleComputer.h"

int array[SIZE];
int Regs[COUNT_REG];
char Regs2;

int sc_memoryInit(){
    int i;
    for(i = 0; i < SIZE; ++i){
        array[i] = 0;
    }
    return 0;
}

int sc_memorySet(int address, int value){
    if(address < 0 || address >= SIZE){
        printf("Error: memory segmentation failed\n");
        Regs[REG_M] = 1;
       
        return 1;
    }
    array[address] = value;
    return 0;
}

int sc_memoryGet (int address, int * value){
    if(address < 0 || address >= SIZE){
        printf("Error: memory segmentation failed\n");
        Regs[REG_M] = 1;
        
        return 1;
    }
    *value = array[address];
    return 0;
}

int sc_memorySave(char * filename){
    FILE *file = fopen(filename, "wb");
    fwrite(array, sizeof(int), SIZE, file);
    fclose(file);
    return 0;
}

int sc_memoryLoad(char *filename){
    FILE *file = fopen(filename, "wb");
    if(!file){
        printf("File %s not found\n", filename);
        return 1;
    }
    fread(array, sizeof(int), SIZE, file);
    fclose(file);
    return 0;

}
//
int sc_regInit(){
    int i;
    for(i = 0; i < COUNT_REG; ++i){
        Regs[i] = 0;
        
    }
    
    return 0;
}
int sc_regSet(int reg, int value){
    if(reg < 1 || reg > COUNT_REG){
        printf("Error: invalid register\n");
        return 1;
    }
    if(value != 0 && value != 1){
        printf("Error: invalid value\n");
        return 1;
    }
    
    Regs[reg] = value;
    return 0;
}   
int sc_regGet(int reg, int *value){
    if(reg < 1 || reg >= COUNT_REG){
        printf("Error: invalid register\n");
        return 1;
    }
    *value = Regs[reg];
    
    return 0;
}   

int sc_commandEncode(int command, int operand, int * value){

    if(command > 0x7F || command < 0){
        printf("Error: command out of range(0, 127)\n");
        return 1;
    }
    if(operand > 0x7F || operand < 0){
        printf("Error: operand out of range(0, 127)\n");
        return 1;
    }
    *value = (operand & 0x7F) | ((command & 0x7F)<<7);
    return 0;
    

}
int sc_commandDecode(int value, int * command, int * operand){
    if(value < 0 || value > 0x4000){
        printf("Error: invalid value\n");
        return 1;
    }
    int d1 = value >> 7;
    *command = d1;
    d1 = d1 << 7;
    *operand = value - d1;
    return 0;

}
