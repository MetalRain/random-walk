#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

int const AREA_W = 10;
int const AREA_H = 10;
int const AREA_LENGTH = AREA_W * AREA_H;
int const WALK_LENGTH = 26;

int main(){
    char walk[26] = {};
    char amount[4] = {-1, 1, -AREA_W, AREA_W};
    int rand_start = 0;
    int offset = 0;
    int new_offset = 0;
    int direction = 0;
    int r = 0;
    int w = 0;
    int v = 1;
    int i = 0;
    char current = '.';
    bool ok = 0;

    srand((unsigned) time(NULL));

    // Starting position
    offset = (rand() % AREA_LENGTH);
    walk[0] = offset;

    do {
        // Find valid random direction
        ok = 0;
        rand_start = rand();
        for (r = rand_start; r < (rand_start + 4); r++){
            direction = r % 4;
            if (
                ((offset % AREA_W) == 0 && direction == 0)
                || ((offset % AREA_W) == (AREA_W - 1) && direction == 1)
                || ((offset / AREA_W) == 0 && direction == 2)
                || ((offset / AREA_W) == (AREA_H - 1) && direction == 3)
            ) {
                // Invalid
                continue;
            } else {
                // Valid
                ok = 1;
                break;
            }
        }

        if (ok == 1){
            // Check if already used
            new_offset = offset + amount[direction];
            for (w = 0; w < v; w++){
                if (walk[w] == new_offset) {
                    ok = 0;
                    break;
                }
            }
        }
        
        if (ok == 1) {
            // Store position and continue
            offset = new_offset;
            walk[v] = offset;
            v++;
        } else {
            // Backtrack
            v = v > 1 ? v - 1 : 1;
            offset = walk[v-1];
        }
        
    } while (v < WALK_LENGTH);

    // Print result
    for(i = 0; i < AREA_LENGTH; i++){
        current = '.';
        for (v = 0; v < WALK_LENGTH; v++){
            if (walk[v] == i){
                current = 65 + v;
            }
        }
        printf("%c ", current);
        if (i % AREA_W == (AREA_W - 1)){
            printf("\n");
        }
    }
}
