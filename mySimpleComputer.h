#define SIZE 100
#define COUNT_REG 6
#define REG_P 0x1
#define REG_0 0x2
#define REG_M 0x3
#define REG_T 0x4
#define REG_E 0x5

extern int array[SIZE];
extern int Regs[COUNT_REG];
extern char Regs2;

int sc_memoryInit();
int sc_memorySet(int address, int value);
int sc_memoryGet (int address, int * value);
int sc_memorySave(char * filename);
int sc_memoryLoad(char *filename);

int sc_regInit();
int sc_regSet(int reg, int value);
int sc_regGet(int reg, int *value);

int sc_commandEncode(int command, int operand, int * value);
int sc_commandDecode(int value, int * command, int * operand);

void print_memory();
void print_reg_flags();
