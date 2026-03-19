#include "common.h"
#include "chunk.h"
#include "debug.h"
#include "vm.h"

int main(int argc, const char* argv[]) {
    initVM();

    Chunk chunk;

    initChunk(&chunk);

    // -((1.2 + 3.4) / 5.6)
    // INFIX-to-POSTFIX: ((1.2 3.4 +) 5.6 /) -
    // push 1.2; push 3.4; add; push 5.6; div; negate
    int constant = addConstant(&chunk, 1.2);
    writeChunk(&chunk, OP_CONSTANT, 34);
    writeChunk(&chunk, constant, 34); // PUSH 1.2
    
    constant = addConstant(&chunk, 3.4);
    writeChunk(&chunk, OP_CONSTANT, 34);
    writeChunk(&chunk, constant, 34); // PUSH 3.4
    
    writeChunk(&chunk, OP_ADD, 34); // ADD
    
    constant = addConstant(&chunk, 5.6);
    writeChunk(&chunk, OP_CONSTANT, 34);
    writeChunk(&chunk, constant, 34); // PUSH 5.6

    writeChunk(&chunk, OP_DIV, 34); // DIV

    writeChunk(&chunk, OP_NEGATE, 34);
    
    writeChunk(&chunk, OP_RETURN, 34);
    
    disassembleChunk(&chunk, "Testing chunk");
    interpret(&chunk);
    
    freeVM();
    freeChunk(&chunk);
    return 0;
}