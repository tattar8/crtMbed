#include "chars.h"
#include <string.h>
#include "mbed.h"

extern Serial pc;

uint8_t frameBuffer[FB_WIDTH][FB_HEIGHT];

uint8_t char_w = 3;
uint8_t char_h = 5;

uint8_t a_u[15] = {0,1,0,1,0,1,1,1,1,1,0,1,1,0,1};
uint8_t b_u[15] = {1,1,0,1,0,1,1,1,0,1,0,1,1,1,0};
uint8_t c_u[15] = {1,1,1,1,0,0,1,0,0,1,0,0,1,1,1};
uint8_t d_u[15] = {1,1,0,1,0,1,1,0,1,1,0,1,1,1,0};
uint8_t e_u[15] = {1,1,1,1,0,0,1,1,1,1,0,0,1,1,1};
uint8_t f_u[15] = {1,1,1,1,0,0,1,1,1,1,0,0,1,0,0};
uint8_t g_u[15] = {1,1,1,1,0,0,1,0,1,1,0,1,1,1,1};
uint8_t h_u[15] = {1,0,1,1,0,1,1,1,1,1,0,1,1,0,1};
uint8_t i_u[15] = {1,1,1,0,1,0,0,1,0,0,1,0,1,1,1};
uint8_t j_u[15] = {0,0,1,0,0,1,0,0,1,0,0,1,1,1,1};
uint8_t k_u[15] = {1,0,1,1,1,0,1,0,0,1,1,0,1,0,1};
uint8_t l_u[15] = {1,0,0,1,0,0,1,0,0,1,0,0,1,1,1};
uint8_t m_u[15] = {1,0,1,1,1,1,1,0,1,1,0,1,1,0,1};
uint8_t n_u[15] = {1,0,1,1,1,1,1,1,1,1,1,1,1,0,1};
uint8_t o_u[15] = {1,1,1,1,0,1,1,0,1,1,0,1,1,1,1};
uint8_t p_u[15] = {1,1,1,1,0,1,1,1,1,1,0,0,1,0,0};
uint8_t q_u[15] = {1,1,1,1,0,1,1,0,1,1,1,1,0,0,1};
uint8_t r_u[15] = {1,1,1,1,0,1,1,1,1,1,1,0,1,0,1};
uint8_t s_u[15] = {1,1,1,1,0,0,1,1,1,0,0,1,1,1,1};
uint8_t t_u[15] = {1,1,1,0,1,0,0,1,0,0,1,0,0,1,0};
uint8_t u_u[15] = {1,0,1,1,0,1,1,0,1,1,0,1,1,1,1};
uint8_t v_u[15] = {1,0,1,1,0,1,1,0,1,1,0,1,0,1,0};
uint8_t w_u[15] = {1,0,1,1,0,1,1,0,1,1,1,1,1,0,1};
uint8_t x_u[15] = {1,0,1,0,1,0,0,1,0,0,1,0,1,0,1};
uint8_t y_u[15] = {1,0,1,1,0,1,0,1,0,0,1,0,0,1,0};
uint8_t z_u[15] = {1,1,1,0,0,1,0,1,0,1,0,0,1,1,1};
uint8_t space_c[15] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
uint8_t a_l[15] = {1,1,0,0,0,1,1,1,1,1,0,1,1,1,1};
uint8_t b_l[15] = {1,0,0,1,0,0,1,1,1,1,0,1,1,1,1};
uint8_t c_l[15] = {0,0,0,0,0,0,1,1,1,1,0,0,1,1,1};
uint8_t d_l[15] = {0,0,1,0,0,1,1,1,1,1,0,1,1,1,1};
uint8_t e_l[15] = {0,1,0,1,0,1,1,1,1,1,0,0,0,1,1};
uint8_t f_l[15] = {0,0,1,0,1,0,1,1,1,0,1,0,0,1,0};
uint8_t g_l[15] = {1,1,1,1,0,1,1,1,1,0,0,1,1,1,1};
uint8_t h_l[15] = {1,0,0,1,0,0,1,1,1,1,0,1,1,0,1};
uint8_t i_l[15] = {0,1,0,0,0,0,0,1,0,0,1,0,0,1,0};
uint8_t j_l[15] = {0,0,1,0,0,0,0,0,1,0,0,1,1,1,1};
uint8_t k_l[15] = {1,0,0,1,0,0,1,0,1,1,1,0,1,0,1};
uint8_t l_l[15] = {0,1,0,0,1,0,0,1,0,0,1,0,0,1,0};
uint8_t m_l[15] = {0,0,0,0,0,0,1,0,1,1,1,1,1,0,1};
uint8_t n_l[15] = {0,0,0,0,0,0,0,0,0,1,1,1,1,0,1};
uint8_t o_l[15] = {0,0,0,0,0,0,1,1,1,1,0,1,1,1,1};
uint8_t p_l[15] = {0,0,0,1,1,1,1,0,1,1,1,1,1,0,0};
uint8_t q_l[15] = {0,0,0,1,1,1,1,0,1,1,1,1,0,0,1};
uint8_t r_l[15] = {0,0,0,0,0,0,0,0,1,0,1,0,0,1,0};
uint8_t s_l[15] = {0,0,0,0,0,0,0,1,1,0,1,0,0,0,1};
uint8_t t_l[15] = {0,1,0,1,1,1,0,1,0,0,1,0,0,1,0};
uint8_t u_l[15] = {0,0,0,0,0,0,0,0,0,1,0,1,1,1,1};
uint8_t v_l[15] = {0,0,0,0,0,0,0,0,0,1,0,1,0,1,0};
uint8_t w_l[15] = {0,0,0,0,0,0,0,1,0,1,1,1,1,1,1};
uint8_t x_l[15] = {0,0,0,0,0,0,1,0,1,0,1,0,1,0,1};
uint8_t y_l[15] = {0,0,0,1,0,1,1,1,1,0,0,1,1,1,1};
uint8_t z_l[15] = {0,0,0,0,0,0,1,1,1,0,1,0,1,1,1};


uint8_t* asciiLookup(uint8_t val){
    switch(val){
        case 65: return a_u;
        case 66: return b_u;
        case 67: return c_u;
        case 68: return d_u;
        case 69: return e_u;
        case 70: return f_u;
        case 71: return g_u;
        case 72: return h_u;
        case 73: return i_u;
        case 74: return j_u;
        case 75: return k_u;
        case 76: return l_u;
        case 77: return m_u;
        case 78: return n_u;
        case 79: return o_u;
        case 80: return p_u;
        case 81: return q_u;
        case 82: return r_u;
        case 83: return s_u;
        case 84: return t_u;
        case 85: return u_u;
        case 86: return v_u;
        case 87: return w_u;
        case 88: return x_u;
        case 89: return y_u;
        case 90: return z_u;
        case 32: return space_c;
        default: return 0;
    }
}

void writeLetterToFb(uint8_t letter,uint8_t rowStart, uint8_t colStart){
    uint8_t* letterBm = asciiLookup(letter);

    pc.printf("Printing letter %d at %d,%d \r\n", letter, colStart, rowStart);

    for (int iterCol = 0; iterCol <char_w; iterCol++){
        for (int iterRow = 0; iterRow < char_h; iterRow++){
            frameBuffer[colStart + iterCol][rowStart + iterRow] = letterBm[iterRow * char_w + iterCol];
        }
    }
}

void writeStringToFb(char* stringIn, uint8_t rowStart, uint8_t colStart){
    //determine the total width of the string.  The extra 1 is to account for gaps between chars
    int stringWidth = (char_w + 1) * strlen(stringIn);

    int nCharsInRow = FB_WIDTH / (char_w + 1);

    int colCnt = 0;
    for (int lcv = 0; lcv < strlen(stringIn); lcv++){
        if (colCnt >= nCharsInRow - 1){
            colCnt = 0;
            rowStart += char_h + 1;
        }

        writeLetterToFb((uint8_t) stringIn[lcv], rowStart, colStart + colCnt * (char_w + 1));
        colCnt++;
    }
}