#include <stdio.h>
#include "sense.h"
#include <unistd.h>
#include "letters.h"

#define PINK 0xF80F
#define BLACK 0x0000

pi_framebuffer_t *fb = NULL;
sense_fb_bitmap_t *bm = NULL;


int open_display(void);

void show_big_letter(void (*)(int (*)[8]));

void show_small_letter(void (*)(int (*)[5]));

int main(void) {
        open_display();
        show_big_letter(make_heart);
        show_small_letter(make_B);
        show_small_letter(make_E);
        show_small_letter(make_M);
        show_small_letter(make_Y);
        show_small_letter(make_B);
        show_small_letter(make_F);
        show_big_letter(make_question);
        return 1;
}

int open_display() {
        fb = getFrameBuffer();
        bm = fb->bitmap;
        return 1;
}

void show_big_letter(void (*letter)(int (*)[8])) {
        int text[8][8]; (*letter)(text);
        for (int row = 0; row<8; row++) {
                for (int show = 0; show<8; show++) {
                        if (text[row][show]) {
                                bm->pixel[row][show]=PINK;
                        }
                }
        }
        sleep(5);
        clearFrameBuffer(fb, BLACK);
}


void show_small_letter(void (*letter)(int (*)[5])) {
        int text[5][5]; (*letter)(text);
        for (int row = 0; row<5; row++) {
                for (int show = 0; show<5; show++) {
                        if (text[row][show]) {
                                bm->pixel[row+2][show]=PINK;
                        }
                }
        }
        sleep(3);
        clearFrameBuffer(fb, BLACK);
}
