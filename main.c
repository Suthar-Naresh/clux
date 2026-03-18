#include "common.h"
#include "chunk.h"
#include "debug.h"

int main(int argc, const char* argv[]) {
    Chunk chunk;

    initChunk(&chunk);
    logger("INFO", "Initialized chunk");

    writeChunk(&chunk, OP_RETURN);
    logger("INFO", "Wrote the return opcode");
    
    disassembleChunk(&chunk, "Testing chunk");
    
    freeChunk(&chunk);
    logger("INFO", "Freeing the chunk...");
    return 0;
}