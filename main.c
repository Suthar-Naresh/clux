#include "common.h"
#include "chunk.h"
#include "debug.h"
#include "vm.h"

int main(int argc, const char* argv[]) {
    initVM();

    Chunk chunk;

    initChunk(&chunk);

    // [OP_CONSTANT, 6.9, OP_NEGATE, OP_RETURN] it is 4byte of program
    // like 
    // PUSH 6.9
    // NEGATE
    // RET

    int constant = addConstant(&chunk, 6.9);
    writeChunk(&chunk, OP_CONSTANT, 34);
    writeChunk(&chunk, constant, 34);
    writeChunk(&chunk, OP_NEGATE, 34);
    writeChunk(&chunk, OP_RETURN, 34); // more like "return -6.9"
    
    disassembleChunk(&chunk, "Testing chunk");
    interpret(&chunk);
    
    freeVM();
    freeChunk(&chunk);
    return 0;
}