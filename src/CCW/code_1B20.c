#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f32 D_8038EC94;

void func_80387F10() {
    jiggySpawn(0x4DU, &D_8038EC94);
}

void func_80387F38(ActorMarker* marker, s32 arg1) {
    func_80387F64(marker_getActor(marker), arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/CCW/code_1B20/func_80387F64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/CCW/code_1B20/func_80388260.s")

void func_80388278(s32 arg0, s32 arg1) {
    func_8025A6EC(COMUSIC_2B_DING_B, 0x6D60);
}

void func_803882A4(ActorMarker* marker, s32 arg1) {
    Actor* actor = marker_getActor(marker);
    
    if (map_get() == MAP_43_CCW_SPRING && actor->state == 1) {
        func_80387F64(actor, 2);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/CCW/code_1B20/func_803882F4.s")

void func_803883F4() {
    Actor* actor = func_80326EEC(0x29D);
    if (actor && actor->state == 1) {
        func_80387F64(actor, 2);
    }
}

s32 func_80388438() {
    Actor* actor = func_80326EEC(0x29D);
    if (actor && actor->state == 2) {
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/CCW/code_1B20/func_80388478.s")

#pragma GLOBAL_ASM("asm/nonmatchings/CCW/code_1B20/func_80388590.s")

#pragma GLOBAL_ASM("asm/nonmatchings/CCW/code_1B20/func_803885F8.s")

