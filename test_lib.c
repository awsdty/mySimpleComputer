#include <stdlib.h>
#include <stdio.h>

#include "mySimpleComputer.h"


int Test(){
    printf("\n\n\t\tTest function mySimpleComputer\n");
    printf("sc_memoryInit()\n");
    sc_memoryInit();
    printf("\n");
    printf("sc_memorySet()\n");
    printf("\taddress = %d, value = %d\n", 25, 5);
    sc_memorySet(25, 5);
    printf("\tMemory[%d] = %d\n", 25, 5);
    printf("sc_memorySet()\n");
    int value;
    sc_memoryGet(25, &value);
    printf("\taddress = %d, value = %d\n", 25, value);
    char file[] = "data.bin";
    printf("sc_memorySave()\n");
    printf("\tSave memory: file = %s\n", file);
    sc_memorySave(file);
    printf("sc_memoryLoad()\n");
    printf("\tLoad memory: file = %s\n", file);
    sc_memoryLoad(file);
    printf("sc_regInit()\n");
    sc_regInit();
    printf("\tRegs:\n\t");
    for(int i = 1; i < COUNT_REG; ++i){
        printf("%d ", Regs[i]);
    }
    printf("\n");
    printf("sc_regSet(REG_0, 1)\n");
    printf("\tRegs:\n\t");
    sc_regSet(REG_0, 1);
    for(int i = 1; i < COUNT_REG; ++i){
        printf("%d ", Regs[i]);
    }
    printf("\n");

    printf("sc_regGet(REG_0, value)\n");
    sc_regGet(REG_0, &value);
    printf("\tvalue = %d\n", value);
    printf("\n");
    printf("sc_commandEndcode()\n");
    int c = 150, o = 60;
    int val;
    printf("\tcommand = %d, operand = %d\n", c, o);
    sc_commandEncode(c, o, &val);
    printf("\tvalue = %d\n", val);
    printf("sc_commandDecode()\n");
    
    val =5000;
    printf("\tvalue = %d\n", val);
    sc_commandDecode(val, &c, &o);
    printf("\tcommand = %d, operand = %d\n", c, o);
    

}






int main(){

    Test();


    return 0;

}















