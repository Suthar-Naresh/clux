#include "common.h"
#include "chunk.h"
#include "debug.h"

int main(int argc, const char* argv[]) {
    Chunk chunk;

    initChunk(&chunk);

    // [OP_CONSTANT, 6.9, OP_RETURN] it is 3byte of program
    // like 
    // PUSH 6.9
    // RET

    int constant = addConstant(&chunk, 6.9);
    writeChunk(&chunk, OP_CONSTANT);
    writeChunk(&chunk, constant);
    writeChunk(&chunk, OP_RETURN);
    
    disassembleChunk(&chunk, "Testing chunk");
    
    freeChunk(&chunk);
    return 0;
}