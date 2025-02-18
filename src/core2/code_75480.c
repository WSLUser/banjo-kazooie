#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* .data */
extern s32 D_803698B4;

/* .bss */
struct8s *D_80381570[4];

/* .code */
f32 func_802FC410(struct8s * arg0) {
    f32 var_f2;
    s32 var_v0;

    var_f2 = 0.0f;
    for(var_v0 = 0; var_v0 < D_803698B4; var_v0++){
        if (arg0 == D_80381570[var_v0]) {
            return var_f2;
        }
        var_f2 += 35.0f;
    }
    return 0.0f;
}

void func_802FC468(void){
    s32 i = 0;

    D_803698B4--;
    while(i < D_803698B4){
        D_80381570[i] = D_80381570[i + 1];
        i++;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_75480/func_802FC4AC.s")

void func_802FC580(s32 arg0, struct8s * arg1){
    func_802FC4AC(arg1);
} 

void func_802FC5A4(s32 arg0, struct8s *arg1){
    func_802FC468();
}

void func_802FC5C8(s32 arg0, struct8s *arg1){
    arg1->unk18 = 0;
    arg1->unk1C = 0.0f;
}

void func_802FC5DC(s32 arg0, struct8s *arg1){
    s32 sp1C;
    struct8s *var_v0 = D_80381570[0];

    if(D_803698B4 != 0){
        arg1->unkC = func_802FC410(arg1) + var_v0->unk1C;
    }
}

void func_802FC630(s32 ag0, struct8s* arg1){
    D_803698B4 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_75480/func_802FC644.s")
