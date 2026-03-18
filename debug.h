#ifndef clux_debug_h
#define clux_debug_h

#include "chunk.h"

void logger(const char* type, const char* info);
void disassembleChunk(Chunk* chunk, const char* name);
int disassembleInstruction(Chunk* chunk, int offset);

#endif