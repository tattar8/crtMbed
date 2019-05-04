#ifndef CHARS_H
#define CHARS_H

#include <stdint.h>

//these are defines since we use them to initialize a static framebuffer later on
#define FB_WIDTH 50
#define FB_HEIGHT 290

uint8_t* asciiLookup(uint8_t val);

extern uint8_t frameBuffer[FB_WIDTH][FB_HEIGHT];

void writeLetterToFb(uint8_t letter,uint8_t rowStart, uint8_t colStart);
void writeStringToFb(char* stringIn, uint8_t rowStart, uint8_t colStart);

#endif