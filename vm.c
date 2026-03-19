#include <stdio.h>
#include "common.h"
#include "vm.h"
#include "debug.h"

VM vm;

static void resetStack() {
    vm.tos = vm.stack; // As tos is pointer, and it points past the top element just like ip
                       // Or tos points to the next available free location on the stack
}

void initVM() {
    resetStack();
}

void freeVM(){}

Value push(Value value) {
    *vm.tos = value;
    vm.tos++;
}

Value pop() {
    vm.tos--;
    return *vm.tos;
}

static InterpretResult run() {
    #define READ_BYTE() (*vm.ip++)
    #define READ_CONSTANT() (vm.chunk->constants.values[READ_BYTE()])
    
    for(;;) {
        #ifdef DEBUG_TRACE_EXECUTION
        disassembleInstruction(vm.chunk, (int)(vm.ip - vm.chunk->code));
        #endif

        uint8_t instruction;
        switch(instruction = READ_BYTE()) {
            case OP_CONSTANT: {
                Value constant = READ_CONSTANT();
                printValue(constant);
                printf("\n");
                break;
            }
            case OP_RETURN: {
                return INTERPRET_OK;
            }
        }
    }

    #undef READ_BYTE
    #undef READ_CONSTANT
}

InterpretResult interpret(Chunk* chunk) {
    vm.chunk = chunk;
    vm.ip = vm.chunk->code;
    return run(); // This will actually execute the instruction
}