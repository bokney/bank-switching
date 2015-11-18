
//  main.c
//  bank switching
//  [16/11/2015]

#include <gb/gb.h>
#include <gb/hardware.h>

#define MASTER_TIME 256 // delay between loops

extern const unsigned char tileData1, tileData2, tileData3;
extern const unsigned char mapData1, mapData2, mapData3;

UINT8 step; // current loop / which bank to access

void main(void) NONBANKED {
    wait_vbl_done();
    step = 0;
    
    for (;;) { // loop
        
        wait_vbl_done();
        
        DISPLAY_OFF;
        HIDE_SPRITES;
        HIDE_BKG;
        
        SWITCH_ROM_MBC1(step + 1);
        
        switch(step) {
            case 0: {
                set_bkg_data(0, 0, &tileData1);
                set_bkg_tiles(4, 4, 7, 7, &mapData1);
                break; }
            case 1: {
                set_bkg_data(0, 0, &tileData2);
                set_bkg_tiles(4, 4, 7, 7, &mapData2);
                break; }
            case 2: {
                set_bkg_data(0, 0, &tileData3);
                set_bkg_tiles(4, 4, 7, 7, &mapData3);
                break; }
        }
        
        step++; if (step == 3) step = 0;
        
        DISPLAY_ON;
        SHOW_SPRITES;
        SHOW_BKG;
        
        delay(MASTER_TIME);
    }
    
}
