#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern void func_803114D0(void );
extern void func_803184C8(gczoombox_t *, f32, s32, s32, f32, s32, s32);
extern int func_803114B0(void);
extern void gczoombox_open(gczoombox_t *);
extern void gczoombox_minimize(gczoombox_t *);
extern void gczoombox_close(gczoombox_t *);
extern bool func_803188B4(gczoombox_t *);

extern s8 D_8036C4D0[];
extern f32 D_80378534;

/* .bss */
struct {
    char output[0x100];
    u8 *unk100;
    struct13s *string_list[2]; //string ptr
    char *string[2]; //current_string
    u8 string_count[2];   //zoombox string_count
    s8 string_cmd[2]; //current_cmd
    u8 string_index[2]; //current_string_index
    struct15s unk11A[2];
    gczoombox_t *zoombox[2];
    s16 unk124[2];
    u32 unk128_31:8;
    u32 state:8;
    u32 unk128_15:8;
    u32 active_zoombox:1; //active_zoombox_index
    u32 unk128_6:1;
    u32 unk128_5:1;
    u32 unk128_4:1;
    u32 unk128_3:1;
    u32 pad128_2:2;
    u32 unk128_0:1;
    u32 unk12C_31:2;
    u32 unk12C_29:2;
    u32 unk12C_27:2;
    u32 unk12C_25:2;
    s32 unk12C_23:8;
    u32 unk12C_15:4;
    u32 unk12C_11:4;
    u32 pad12C_7:8;
    s16 unk130;
    s8  unk132;
    u8  pad133[0x1];
    ActorMarker *caller;
    s32  unk138;
    void (* unk13C)(ActorMarker *, s32, s32);
    void (* unk140)(ActorMarker *, s32, s32);
    s32  (* unk144)(ActorMarker *, s32, s32);
    struct14s unk148[4];
} D_80382E20;
char D_80382FF8[0x18];

/* .code */
int func_8030EDC0(ActorMarker *caller, s32 arg1){
    return (arg1 == -1)? 0: caller->unk5C == arg1;
}

void gcdialog_init(void) {

    s8 temp_t9;
    u32 temp_t2;
    u8 temp_a1;
    u8 temp_t0;
    u8 temp_t3;
    u8 temp_t5;
    u8 temp_t6;
    u8 temp_t7;
    u8 temp_t8;
    s32 i;
    struct14s *i_ptr;

    D_80382E20.unk100 = 0;
    
    for( i = 0; i < 2; i++){
        D_80382E20.string_list[i] = NULL;
        D_80382E20.string_count[i] = 0;
        D_80382E20.zoombox[i] = NULL;
        D_80382E20.string_index[i] = NULL;
        D_80382E20.string_cmd[i] = -1;
        D_80382E20.string[i] = 0;
        D_80382E20.unk11A[i].unk0_7 = 0;
        D_80382E20.unk11A[i].unk0_5 = 0;
    }

    for(i = 0; i < 4; i++){
        D_80382E20.unk148[i].unk0 =  -1;
        D_80382E20.unk148[i].unk2 = 0;
        D_80382E20.unk148[i].unk10 = NULL;
        D_80382E20.unk148[i].unk14 = 0;
        D_80382E20.unk148[i].unk18 = NULL;
        D_80382E20.unk148[i].unk1C = NULL;
        D_80382E20.unk148[i].unk20 = 0;
        D_80382E20.unk148[i].unk4[0] = D_80382E20.unk148[i].unk4[1] = D_80382E20.unk148[i].unk4[2] = 0;
    }

    D_80382E20.state = 0;
    D_80382E20.unk128_31 =  D_80382E20.unk128_5 = FALSE;
    D_80382E20.unk12C_31 = D_80382E20.unk12C_29 = D_80382E20.unk12C_27 = D_80382E20.unk12C_25 = 0;
    D_80382E20.unk128_15 = D_80382E20.active_zoombox = FALSE;
    D_80382E20.unk128_6 = TRUE; 
    D_80382E20.unk12C_23 = -1;
    D_80382E20.unk12C_15 = D_80382E20.unk12C_11 = 0;
    D_80382E20.unk130 = (s16) -1;
    D_80382E20.caller = NULL;
    D_80382E20.unk13C = NULL;
    D_80382E20.unk140 = NULL;
    D_80382E20.unk144 = 0;
    D_80382E20.unk132 = 0xC;
    D_80382E20.unk128_3 = TRUE;
}

static void _gcdialog_freeZoomboxes(void){
    s32 i;
    for(i =0; i < 2; i++){
        gczoombox_free(D_80382E20.zoombox[i]);
        D_80382E20.zoombox[i] = NULL;
    }
}

void func_8030F078(void){
    s32 i;
    s32 j;
    for(i = 0; i <2; i++){
        for(j =0; j < D_80382E20.string_count[i]; j++){
            D_80382E20.string_list[i][j].str = NULL;
        }
        D_80382E20.string_count[i] = 0;
        free(D_80382E20.string_list[i]);
        D_80382E20.string_list[i] = NULL;
    }
    if(D_80382E20.unk130 != -1){
        func_8031B6D8(D_80382E20.unk130);
    }
    D_80382E20.unk100 = NULL;
}

void func_8030F130(void){
   func_8030F078();
   if(D_80382E20.zoombox[1] != NULL && !D_80382E20.unk11A[1].unk0_7){
       func_80347A14(1);
   }
   if(!D_80382E20.unk11A[0].unk0_7 && !D_80382E20.unk11A[1].unk0_7){
       _gcdialog_freeZoomboxes();
   }
   D_80382E20.unk130 = -1;
   D_80382E20.unk128_15 = 0;
   D_80382E20.unk128_31 = 0;
   D_80382E20.caller = NULL;
   D_80382E20.unk13C = NULL;
   D_80382E20.unk140 = NULL;
   D_80382E20.unk144 = NULL;
}

void func_8030F1D0(void){
    if(func_803114B0()){
        func_8025A55C(-1, 300, 2);
    }
    func_803114D0();
    func_8030F130();
    D_80382E20.state = 0;
}

void func_8030F218(char *next_state, char *arg1, char *arg2, bool arg3, bool arg4) {
    s32 var_v0;
    s32 i;
    s32 j;

    var_v0 = 0;\
    for(i = 0; arg1[i] != '\0'; i++){
        if (arg1[i] == ((arg3) ? 0xE : '~')) {
            if (arg4) {
                next_state[var_v0++] = 0xFD;
                next_state[var_v0++] = 0x68;
            }

            for(j = 0 ; arg2[j] != '\0'; j++){
                next_state[var_v0++] = arg2[j];
                if (arg4 && !arg3 && arg2[j] == ' ') {
                    next_state[var_v0++] = 0xFD;
                    next_state[var_v0++] = 0x68;
                }
            }
            if (arg4) {
                next_state[var_v0++] = 0xFD;
                next_state[var_v0++] = 0x6C;
            }
        } else {
            next_state[var_v0++] = arg1[i];
        }
    }
    next_state[var_v0] = '\0';
}

void func_8030F338(void){
    if(D_80382E20.unk13C != NULL){
        if(D_80382E20.caller == NULL){
            D_80382E20.unk13C(D_80382E20.caller, D_80382E20.unk130, D_80382E20.unk12C_23);
        }else{
            if(func_8030EDC0(D_80382E20.caller, D_80382E20.unk138)){
                D_80382E20.unk13C(D_80382E20.caller, D_80382E20.unk130, D_80382E20.unk12C_23);
            }
        }
    }
    if(D_80382E20.unk128_31 & 0x8){
            if((!func_802E4A08() && !func_803203FC(UNKFLAGS1_1F_IN_CHARACTER_PARADE)) || !D_80382E20.unk128_3){
                func_8028F918(0);
            }
    }//L8030F3E8
    func_8025A55C(-1, 0x12c, 2);
    func_8030F130();
}

void gcdialog_draw(Gfx **gfx, Mtx **mtx, Vtx **vtx){
    s32 i;
    for(i = 0; i<2; i++){
        gczoombox_draw(D_80382E20.zoombox[i], gfx, mtx, vtx);
    }
}

void gcdialog_setState(s32 next_state){
    s32 i;
    s32 j;
    s32 v0 = 6;

    if(v0);
    if(D_80382E20.state != v0 ||  next_state != v0){
        switch(next_state){
            case 1:
                for(i = 0; i < 2; i++){
                    if(D_80382E20.zoombox[i] != NULL && D_80382E20.unk11A[i].unk0_7 == 0)
                        gczoombox_open(D_80382E20.zoombox[i]);
                }
                break;

            case 5:
                for(i =0; i < 2; i++){
                    if(D_80382E20.zoombox[i] != NULL && D_80382E20.unk11A[i].unk0_7 == 0){
                        gczoombox_minimize(D_80382E20.zoombox[i]);
                        gczoombox_close(D_80382E20.zoombox[i]);
                    }
                }
                break;

            case 6:
                for(i  = 0; i< 2; i++){//L8030F59C
                    for(j = D_80382E20.string_index[i]; D_80382E20.string_list[i][j].cmd < -4 || D_80382E20.string_list[i][j].cmd >= 0; j++){
                        if(D_80382E20.string_list[i][j].cmd == -7 && D_80382E20.unk140){
                            if(D_80382E20.caller == NULL){
                                D_80382E20.unk140(D_80382E20.caller, D_80382E20.unk130, *D_80382E20.string_list[i][j].str);
                            }else{
                                if(func_8030EDC0(D_80382E20.caller, D_80382E20.unk138)){
                                    D_80382E20.unk140(D_80382E20.caller, D_80382E20.unk130, *D_80382E20.string_list[i][j].str);
                                }
                            }
                        }
                    }
                }
                D_80382E20.unk12C_25 = 0;
                for(i=0; i< 2; i++){
                    D_80382E20.unk11A[i].unk0_7 = 0;
                    if(D_80382E20.zoombox[i] != NULL){
                        D_80382E20.unk12C_25 += (u8)func_803188B4(D_80382E20.zoombox[i]);
                    }
                }
                break;

            case 7:
                func_8030F338();
                next_state = 0;
                break;
            case 8:
                func_8030F338();
                for(i=0; i<2; i++){
                    if(D_80382E20.unk11A[i].unk0_7 == 0){
                        gczoombox_free(D_80382E20.zoombox[i]);
                        D_80382E20.zoombox[i] = NULL;
                    }
                }
                break;
            default:
                break;
        }
        D_80382E20.state = next_state;
    }
    
}

void func_8030F754(enum talk_pic_e portrait_id, s32 arg1){
    s32 temp_a0;
    s32 temp_v0;

    switch(arg1){
        case 1: //L8030F790
            D_80382E20.unk12C_31++;
            break;
        
        case 3: //L8030F7BC
            gcdialog_setState(2);
            break;

        case 4: //L8030F7CC
            if(D_80382E20.state == 6){
                D_80382E20.unk12C_25--;
                if(D_80382E20.unk12C_25 == 0){
                    temp_a0 = ((D_80382E20.unk11A[0].unk0_7) ? 1 : 0);
                    temp_v0 = ((D_80382E20.unk11A[1].unk0_7) ? 1 : 0);
                    gcdialog_setState((temp_v0 + temp_a0) ? 8 : 5);
                }//L8030F980
                break;
            }

            temp_v0 = ((D_80382E20.unk11A[0].unk0_7) ? 1 : 0) + ((D_80382E20.unk11A[1].unk0_7) ? 1 : 0);
            if(temp_v0 > (s32)D_80382E20.unk12C_29){
                D_80382E20.unk12C_29++;
                if(D_80382E20.unk128_15 == D_80382E20.unk12C_29 + D_80382E20.unk12C_27){
                    gcdialog_setState(8);
                }
            }
            break;

        case 6: //L8030F8FC
            D_80382E20.unk12C_27++;
            if(D_80382E20.unk12C_27 == D_80382E20.unk128_15){
                gcdialog_setState(7);
            }//L8030F964

            if(D_80382E20.unk128_15 == D_80382E20.unk12C_29 + D_80382E20.unk12C_27){
                gcdialog_setState(8);
            }
            break;
    }//L8030F984
}

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_87E30/gcdialog_update.s")
#else
void gcdialog_update(void) {
    s32 spA8;
    s32 i;
    s32 sp90[6];
    bool temp_v1_2;
    s32 sp84[2];
    s32 sp80;
    s32 sp7C;
    char *sp4C[8];
    s32 var_v0_6;
    s32 var_a3;
    s32 var_v0_2;

    sp80 = -1;
    if (D_80382E20.unk128_31 & 0x80) {
        func_8024E5A8(0, sp90);
        func_8024E640(0, sp84);
    } else {
        func_8024E55C(0, sp90);
        func_8024E60C(0, sp84);
    }
    switch (D_80382E20.state) {                          /* switch 1 */
        case 1:                                     /* switch 1 */
            var_a3 = 0;\
            for(i = 0; i < 2; i++){
                if(D_80382E20.zoombox[i] == NULL){
                    var_a3++;
                }
            };
            if (var_a3 == 2) {
                gcdialog_setState(7);
            } else if (D_80382E20.unk128_15 == D_80382E20.unk12C_31) {
                D_80382E20.unk12C_31 = 0;
                gcdialog_setState(2);
            }
            break;

        case 2:                                     /* switch 1 */
            if ((D_80382E20.zoombox[D_80382E20.active_zoombox] == NULL) || func_80318BEC(D_80382E20.zoombox[D_80382E20.active_zoombox]) || (D_80382E20.unk11A[D_80382E20.active_zoombox].unk0_5 != 0)) {
                D_80382E20.active_zoombox ^= 1;
            } else {
                D_80382E20.string_cmd[D_80382E20.active_zoombox] = D_80382E20.string_list[D_80382E20.active_zoombox][D_80382E20.string_index[D_80382E20.active_zoombox]].cmd;
                D_80382E20.string[D_80382E20.active_zoombox] = D_80382E20.string_list[D_80382E20.active_zoombox][D_80382E20.string_index[D_80382E20.active_zoombox]].str;
                switch (D_80382E20.string_cmd[D_80382E20.active_zoombox]) {            /* switch 2 */
                    case -2:                                /* switch 2 */
                        if (D_80382E20.string_index[D_80382E20.active_zoombox] == 0) {
                            D_80382E20.unk12C_29++;
                        }
                        gczoombox_minimize(D_80382E20.zoombox[D_80382E20.active_zoombox]);
                        D_80382E20.unk11A[D_80382E20.active_zoombox].unk0_7 = 1;
                        D_80382E20.unk11A[D_80382E20.active_zoombox].unk0_5 = 1;
                        D_80382E20.active_zoombox ^= 1;
                        D_80382E20.unk128_6 = TRUE;
                        break;

                    case -1:                                /* switch 2 */
                        D_80382E20.unk11A[D_80382E20.active_zoombox].unk0_7 = 2;
                        gcdialog_setState(4);
                        break;

                    case -4:                        /* switch 2 */
                        gczoombox_minimize(D_80382E20.zoombox[D_80382E20.active_zoombox]);
                        gczoombox_close(D_80382E20.zoombox[D_80382E20.active_zoombox]);
                        D_80382E20.unk11A[D_80382E20.active_zoombox].unk0_7 = 0;
                        D_80382E20.unk11A[D_80382E20.active_zoombox].unk0_5 = 1;
                        D_80382E20.active_zoombox ^= 1;
                        D_80382E20.unk128_6 = TRUE;
                        break;

                        case -7:                        /* switch 2 */
                        if (D_80382E20.unk140 != NULL) {
                            if (D_80382E20.caller == NULL) {
                                D_80382E20.unk140(D_80382E20.caller, D_80382E20.unk130, *D_80382E20.string[D_80382E20.active_zoombox]);
                            } else if (func_8030EDC0(D_80382E20.caller, D_80382E20.unk138)) {
                                D_80382E20.unk140(D_80382E20.caller, D_80382E20.unk130, *D_80382E20.string[D_80382E20.active_zoombox]);
                            }
                        }
                        D_80382E20.string_index[D_80382E20.active_zoombox]++;
                        break;

                    case -9:                        /* switch 2 */
                    case -8:                        /* switch 2 */
                        do {
                            D_80382E20.string_index[D_80382E20.active_zoombox]++;
                            D_80382E20.string_cmd[D_80382E20.active_zoombox] = D_80382E20.string_list[D_80382E20.active_zoombox][D_80382E20.string_index[D_80382E20.active_zoombox]].cmd;
                        } while (D_80382E20.string_cmd[D_80382E20.active_zoombox] == -8 || D_80382E20.string_cmd[D_80382E20.active_zoombox] == -9);
                        break;

                    case -6:                        /* switch 2 */
                        for(var_v0_2 = D_80382E20.string_index[D_80382E20.active_zoombox]; 
                            D_80382E20.string_list[D_80382E20.active_zoombox][var_v0_2].cmd < -4;
                            var_v0_2++){
                        }
                        
                        if (D_80382E20.string_list[D_80382E20.active_zoombox][var_v0_2].cmd >= 0) {
                            func_803189C4(D_80382E20.zoombox[D_80382E20.active_zoombox], D_80382E20.string_list[D_80382E20.active_zoombox][var_v0_2].cmd + 0xC);
                        }
                        if (D_80382E20.string_index[D_80382E20.active_zoombox]) {
                            gczoombox_minimize(D_80382E20.zoombox[D_80382E20.active_zoombox]);
                        }
                        if ((D_80382E20.string_index[D_80382E20.active_zoombox] == 0) && (D_80382E20.unk11A[D_80382E20.active_zoombox].unk0_7 == 2)) {
                            gczoombox_minimize(D_80382E20.zoombox[D_80382E20.active_zoombox]);
                        }
                        D_80382E20.unk11A[D_80382E20.active_zoombox].unk0_7 = 0;
                        D_80382E20.string_index[D_80382E20.active_zoombox]++;
                        D_80382E20.active_zoombox ^= 1;
                        D_80382E20.unk128_6 = TRUE;
                        break;
                        
                    case -5:                        /* switch 2 */
                        gczoombox_minimize(D_80382E20.zoombox[D_80382E20.active_zoombox]);
                        D_80382E20.unk11A[D_80382E20.active_zoombox].unk0_7 = 0;
                        D_80382E20.string_index[D_80382E20.active_zoombox]++;
                        D_80382E20.active_zoombox ^= 1;
                        D_80382E20.unk128_6 = TRUE;
                        break;

                    case -3:                        /* switch 2 */
                        D_80382E20.unk11A[D_80382E20.active_zoombox].unk0_7 = 0;
                        gcdialog_setState(4);
                        break;

                    default:                                /* switch 2 */
                        if (!func_80316ED4(D_80382E20.string_list[D_80382E20.active_zoombox][D_80382E20.string_index[D_80382E20.active_zoombox]].str)) {
                            D_80382E20.string_index[D_80382E20.active_zoombox]++;
                        } else {
                            if(D_80382E20.string_list[D_80382E20.active_zoombox][D_80382E20.string_index[D_80382E20.active_zoombox] + 1].cmd == -8){
                                if (D_80382E20.unk144 != NULL) {
                                    sp7C = 1;
                                    
                                    if (D_80382E20.caller == NULL) {
                                        sp80 = D_80382E20.unk144(D_80382E20.caller, D_80382E20.unk130, D_80382E20.string_index[D_80382E20.active_zoombox]);
                                    }
                                    else if (func_8030EDC0(D_80382E20.caller, D_80382E20.unk138)) {
                                        sp80 = D_80382E20.unk144(D_80382E20.caller, D_80382E20.unk130, D_80382E20.string_index[D_80382E20.active_zoombox]);
                                    }

                                    if (sp80 < 0) {
                                        sp80 = -1 - sp80;
                                        sp7C = 0;
                                    }
                                    if((sp80 >= 0) && ((D_80382E20.string_list[D_80382E20.active_zoombox][D_80382E20.string_index[D_80382E20.active_zoombox] + sp80 + 1].cmd == -8))) {
                                            strlen(D_80382E20.string_list[D_80382E20.active_zoombox][D_80382E20.string_index[D_80382E20.active_zoombox] + sp80 + 1].str);
                                            strlen(D_80382E20.string_list[D_80382E20.active_zoombox][D_80382E20.string_index[D_80382E20.active_zoombox]].str);
                                            func_8030F218(D_80382E20.output, D_80382E20.string_list[D_80382E20.active_zoombox][D_80382E20.string_index[D_80382E20.active_zoombox]].str, D_80382E20.string_list[D_80382E20.active_zoombox][D_80382E20.string_index[D_80382E20.active_zoombox] + sp80 + 1].str, func_8031B604(D_80382E20.string_list[D_80382E20.active_zoombox][D_80382E20.string_index[D_80382E20.active_zoombox]].str), sp7C);
                                    }
                                    else{
                                        sp80 = -1;
                                    }
                                }
                            } else if(D_80382E20.string_list[D_80382E20.active_zoombox][D_80382E20.string_index[D_80382E20.active_zoombox] + 1].cmd == -9){
                                    if (D_80382E20.unk144 != NULL) {
                                        D_80382FF8[0] = '\0';
                                        if (D_80382E20.caller == 0) {
                                            sp80 = D_80382E20.unk144(D_80382E20.caller, D_80382E20.unk130, D_80382E20.string_index[D_80382E20.active_zoombox]);
                                        }
                                        else if (func_8030EDC0(D_80382E20.caller, D_80382E20.unk138)) {
                                            sp80 = D_80382E20.unk144(D_80382E20.caller, D_80382E20.unk130, D_80382E20.string_index[D_80382E20.active_zoombox]);
                                        }
                                        strIToA(D_80382FF8, sp80);
                                        strlen(D_80382FF8);
                                        strlen(D_80382E20.string_list[D_80382E20.active_zoombox][D_80382E20.string_index[D_80382E20.active_zoombox]].str);
                                        func_8030F218(D_80382E20.output, D_80382E20.string_list[D_80382E20.active_zoombox][D_80382E20.string_index[D_80382E20.active_zoombox]].str, &D_80382FF8, func_8031B604(D_80382E20.string_list[D_80382E20.active_zoombox][D_80382E20.string_index[D_80382E20.active_zoombox]].str), 0);
                                    }
                            }
                            if (func_803189C4(D_80382E20.zoombox[D_80382E20.active_zoombox], D_80382E20.string_cmd[D_80382E20.active_zoombox] + 0xC)) {
                                gczoombox_minimize(D_80382E20.zoombox[D_80382E20.active_zoombox]);
                                D_80382E20.unk128_6 = TRUE;
                            }
                            if (D_80382E20.unk128_6) {
                                gczoombox_maximize(D_80382E20.zoombox[D_80382E20.active_zoombox]);
                                D_80382E20.unk128_6 = FALSE;
                            }
                            if (sp80 == -1) {
                                for(spA8 = D_80382E20.string_index[D_80382E20.active_zoombox]; 
                                    ((D_80382E20.string_list[D_80382E20.active_zoombox][spA8].cmd == D_80382E20.string_cmd[D_80382E20.active_zoombox]) && ((spA8 * 0) < 8));
                                    spA8++
                                ){
                                    sp4C[spA8 - D_80382E20.string_index[D_80382E20.active_zoombox]] = D_80382E20.string_list[D_80382E20.active_zoombox][spA8].str;
                                }
                                func_80318284(D_80382E20.zoombox[D_80382E20.active_zoombox], spA8 - D_80382E20.string_index[D_80382E20.active_zoombox], sp4C);
                                D_80382E20.string_index[D_80382E20.active_zoombox] = spA8;
                            } else {
                                func_803183A4(D_80382E20.zoombox[D_80382E20.active_zoombox], D_80382E20.output);
                                D_80382E20.string_index[D_80382E20.active_zoombox]++;
                            }
                            gcdialog_setState(3);
                        }
                        break;
                }
            }
            break;
        case 3:                                         /* switch 1 */
            temp_v1_2 = D_80382E20.unk128_31 & 0x80;
            if (D_80382E20.unk128_0 && (sp90[FACE_BUTTON(BUTTON_B)] == 1)) {
                gcdialog_setState(6);
            }
            else{
                if (!temp_v1_2) {
                    var_v0_6 = (temp_v1_2) ? func_8024E5E8(0, 4) : func_8024E5E8(0, 3);
                    if ((var_v0_6 ^ 1) == 0) {
                        gcdialog_setState(6);
                    }
                }
            }
            break;

        case 4:                                         /* switch 1 */
            if (sp90[FACE_BUTTON(BUTTON_A)] == 1) {
                D_80382E20.unk12C_23 = 1;
            } else if (sp90[FACE_BUTTON(BUTTON_B)] == 1) {
                D_80382E20.unk12C_23 = 0;
            }
            if (D_80382E20.unk12C_23 != -1) {
            //     var_a0 = 5;
                gcdialog_setState((D_80382E20.unk11A[D_80382E20.active_zoombox].unk0_7) ? 8 : 5);
            }
            break;

        case 7:                                         /* switch 1 */
        case 8:                                         /* switch 1 */
            gcdialog_setState(0);
            break;
    }

    for(i = 0; i < 2; i++){
        gczoombox_update(D_80382E20.zoombox[i]);
    }
}
#endif

//parses text asset into seperate strings
void func_80310574(s32 text_id){
    s32 i;
    s32 j;
    u8 *txt;
    s32 _v0;
    char ch;
    s32 len;

    txt = D_80382E20.unk100 = func_8031B66C(text_id);
    
    for(i = 0; i < 2; i++){
        D_80382E20.string_count[i] = *(txt++);
        D_80382E20.string_list[i] = (struct13s *) malloc(D_80382E20.string_count[i]*sizeof(struct13s));
        for(j = 0; j < D_80382E20.string_count[i]; j++){//L803105F0
            ch = *(txt++);
            if(ch > 0 && ch < 0x20){
                _v0 = -ch;
            }
            else{
                _v0 = (ch >= 0x80)? ch - 0x80 : ch;
            }
            
            D_80382E20.string_list[i][j].cmd = _v0;
            len = *(txt);
            txt++;
            D_80382E20.string_list[i][j].str = txt;
            txt += len;
            
        }
        //L80310664
    }
}

s32 func_8031068C(s32 next_state){
    return (next_state) ? 0 : 0xA0;
}

int func_803106A4(s32 next_state){
    return (next_state) ? 1 : 0;
}

void func_803106BC(s32 text_id, s32 arg1, ActorMarker *marker, void(*callback)(ActorMarker *, s32, s32), void(*arg4)(ActorMarker *, s32, s32), s32 arg5){
    s32 i;
    s32 j;

    s32 temp_a2;

    func_80310574(text_id);
    D_80382E20.unk12C_29 = 0;
    D_80382E20.unk12C_31 = (D_80382E20.unk12C_25 = D_80382E20.unk12C_29);
    D_80382E20.unk12C_27 = D_80382E20.unk12C_31;
    D_80382E20.unk128_15 = D_80382E20.unk12C_27;
    for(j = 0; j < 2; j++){//L80310774
        i = 0;
        temp_a2 = D_80382E20.string_list[j][0].cmd;
        while(D_80382E20.string_list[j][i].cmd < -4 && i < D_80382E20.string_count[j]){
            i++; 
        };
        D_80382E20.string_cmd[j] = temp_a2;
        //L803107C4
        D_80382E20.string[j] = D_80382E20.string_list[j]->str;
        D_80382E20.string_index[j] = 0;
        D_80382E20.unk124[j] = func_8031068C(j);
        D_80382E20.unk11A[j].unk0_5 = 0;
        if(D_80382E20.string_list[j][i].cmd >= 0){
            if(!D_80382E20.unk11A[j].unk0_7){
                D_80382E20.zoombox[j] =  gczoombox_new(D_80382E20.unk124[j], D_80382E20.string_list[j][i].cmd + 0xC, 0, func_803106A4(j), func_8030F754);
                if( j == 1 ){
                    func_80347A14(0);
                }
            } else{//L80310860
                 D_80382E20.unk12C_31++; 
            } //L80310880
            D_80382E20.unk128_15++;
        }else{//L80310890
            if(D_80382E20.string_list[j][i].cmd < -2){
                if(D_80382E20.unk11A[j].unk0_7){
                    gczoombox_close(D_80382E20.zoombox[j]);
                    D_80382E20.unk128_15++;
                }else{
                    D_80382E20.zoombox[j] = NULL;
                }
                D_80382E20.unk11A[j].unk0_7 = 0;
            }else{//L803108D8
                if(D_80382E20.unk11A[j].unk0_7){
                    D_80382E20.unk128_15++;
                    D_80382E20.unk12C_31++;
                }
            }
        }//L80310910
    }
    D_80382E20.unk130 = text_id;
    D_80382E20.unk128_31 = arg1;
    if(D_80382E20.string_cmd[0] < 0){
        D_80382E20.active_zoombox = 0;
    }else{//L80310950
        D_80382E20.active_zoombox = 1;
    }//L8031095C
    D_80382E20.unk128_6 = 1;
    D_80382E20.unk12C_23 = ((func_802E4A08() || func_803203FC(UNKFLAGS1_1F_IN_CHARACTER_PARADE)) && D_80382E20.unk128_3) ? 1 : -1;
    D_80382E20.caller = marker;
    D_80382E20.unk13C = callback;
    D_80382E20.unk140 = arg4;
    D_80382E20.unk144 = arg5;
    D_80382E20.unk138 = (marker != NULL )? ((marker->unk5C)? marker->unk5C : -1) : 0;
    gcdialog_setState(((func_802E4A08() || func_803203FC(UNKFLAGS1_1F_IN_CHARACTER_PARADE)) && D_80382E20.unk128_3) ? 6 : 1);
    //L803109EC
}

void func_80310A5C(s32 next_state, s32 arg1, s32 arg2, s32 arg3, s32 arg4){
    s32 i;
    f32 tmpf;
    for(i = 0, tmpf = D_80378534; i< 2; i++){
        if(D_80382E20.zoombox[i]){
            func_803184C8(D_80382E20.zoombox[i], arg2, next_state, arg1, tmpf, arg3, arg4);
        }
    }
}

void func_80310B1C(s32 text_id, s32 arg1, ActorMarker *marker, void(*callback)(ActorMarker *, s32, s32), void(*arg4)(ActorMarker *, s32, s32), s32 arg5){
    func_803106BC(text_id, arg1, marker, callback, arg4, arg5);
    if(map_get() == MAP_90_GL_BATTLEMENTS && 0x10ec < text_id){
        func_80310A5C( 3, 4, 0x1e, arg1 & 2, arg1 & 0x80);
    }
    else{
        func_80310A5C( 5, 2, 0xF, arg1 & 2, arg1 & 0x80);
    }
}

void func_80310BB4(s32 next_state, s32 arg1, s32 arg2){
    func_80310A5C(arg1, arg2, next_state, D_80382E20.unk128_31 & 2, D_80382E20.unk128_31 & 0x80);
}

void func_80310BFC(void){
    s32 ch;
    if(D_80382E20.unk128_4){
        D_80382E20.unk132++;
        ch = D_8036C4D0[D_80382E20.unk132];
        if(D_80382E20.zoombox[0] != NULL){
            D_80382E20.unk124[0] -= ch;
            func_80318B7C(D_80382E20.zoombox[0], D_80382E20.unk124[0]);
        }//L80310C60
        
        if(D_80382E20.zoombox[1] != NULL){
            D_80382E20.unk124[1] += ch;
            func_80318B7C(D_80382E20.zoombox[1], D_80382E20.unk124[1]);
        }//L80310C84
        if(D_80382E20.unk132 == 0xC){
            D_80382E20.unk128_5 = 0;
        }
    }else{//L80310CA4
        D_80382E20.unk132--;
        ch = D_8036C4D0[D_80382E20.unk132];
        if(D_80382E20.zoombox[0] != NULL){
            D_80382E20.unk124[0] += ch;
            func_80318B7C(D_80382E20.zoombox[0], D_80382E20.unk124[0]);
        }
        if(D_80382E20.zoombox[1] != NULL){
            D_80382E20.unk124[1] -= ch;
            func_80318B7C(D_80382E20.zoombox[1], D_80382E20.unk124[1]);
        }
        if(D_80382E20.unk132 == 0){
            D_80382E20.unk128_5 = 0;
        }
    }
}

void func_80310D2C(void){
    struct14s * sp24;
    
    if(D_80382E20.unk128_5)
        func_80310BFC();

    if(getGameMode() == GAME_MODE_3_NORMAL || func_802E4A08()){
        if(D_80382E20.unk128_5)
            return;

        if(!func_803114B0() && (s32)(D_80382E20.unk12C_15) > 0){
            
            sp24 = D_80382E20.unk148 + D_80382E20.unk12C_11;
            func_80310B1C(sp24->unk0,sp24->unk2, sp24->unk10, sp24->unk18, sp24->unk1C, sp24->unk20);
            
            D_80382E20.unk138 = sp24->unk14;
            func_8025A55C(8000, 300, 2);
            if((sp24->unk2 & 0x8) && !((func_802E4A08() || func_803203FC(UNKFLAGS1_1F_IN_CHARACTER_PARADE)) && D_80382E20.unk128_3)){//L80310E6C
                    func_8028F918(0);
                    if( 0.0f == sp24->unk4_x
                        && 0.0f == sp24->unk4_y
                        && 0.0f == sp24->unk4_z
                    ){
                        func_8028F918((D_80382E20.string_cmd[1] < 0)? 1 : 3);
                    }
                    else{//L80310F00
                        func_8028F94C((D_80382E20.string_cmd[1] < 0)? 1 : 3, sp24->unk4);
                    }
            } //L80310F28
            
            D_80382E20.unk12C_11++;
            if(!((s32) D_80382E20.unk12C_11 < 4)){
                D_80382E20.unk12C_11 = D_80382E20.unk12C_11 - 4;
            }
            D_80382E20.unk12C_15--;
            
        }else{//L80310F88
            gcdialog_update();
        }//L80310F98
        if( ( D_80382E20.state != 0 && D_80382E20.state != 5 && D_80382E20.state != 7)
            || ((!D_80382E20.state && (D_80382E20.unk11A[0].unk0_7  || D_80382E20.unk11A[1].unk0_7)))
            || D_80382E20.unk12C_15
        ){
                //L80310FF0
            if(func_802FADD4(0)){
                if(item_getCount(ITEM_6_HOURGLASS) != 0)
                    func_802FACA4(0x28);
                else
                    func_802FAD64(ITEM_0_HOURGLASS_TIMER);
            }
            else {
                if(func_802FADD4(3)){
                    if(item_getCount(ITEM_3_PROPELLOR_TIMER) != 0){
                        func_802FACA4(0x28);
                    }
                    else{
                        func_802FAD64(ITEM_3_PROPELLOR_TIMER);
                    }
                }
            }
            //L80311068
            if(func_802FBE04())
                func_802FACA4(0x2A);

            if(func_802FC390()){
                func_802FACA4(0x29);
            }
        } 
        else{//L803110A0
            if(func_802FAD9C(0x28))
                func_802FAD64(0x28);
            
            if(func_802FAD9C(0x2A))
                func_802FAD64(0x2A);
            
            if(func_802FAD9C(0x29))
                func_802FAD64(0x29);
            
        }
    }
}

int func_803110F8(s32 next_state, s32 arg1, s32 arg2, s32 arg3, void (*arg4)(ActorMarker *, enum asset_e, s32)){
    func_8025A55C(15000, 300, 2);
    func_80311174(next_state + 0xe57, 0x84, NULL, NULL, NULL, NULL, arg4);
    func_80310A5C(arg2, arg3, arg1, 0, 0);
    return 1;
}

int func_80311174(s32 text_id, s32 arg1, f32 *pos, ActorMarker *marker, void(*callback)(ActorMarker *, enum asset_e, s32), void(*arg5)(ActorMarker *, enum asset_e, s32), s32 arg6){
    f32 pad;
    s32 temp_v1;

    if(func_803203FC(1) || func_802D686C())
        return 0;

    if(!func_803114B0()){
        func_80310B1C(text_id, arg1, marker, callback, arg5, arg6);
        if(arg1 & 8){
            if(!(func_802E4A08() || func_803203FC(UNKFLAGS1_1F_IN_CHARACTER_PARADE)) || !D_80382E20.unk128_3){//L80311214
                if(pos != NULL){
                    func_8028F94C(((D_80382E20.string_cmd[1] < 0)? 1 : 3), pos);
                }else{//L8031126C
                    func_8028F918(((D_80382E20.string_cmd[1] < 0)? 1 : 3));
                }
            }
        }//L8031128C
        func_8025A55C(0x1f40, 0x12c, 2);
        return 1;
    }else{//L803112A0
        if(arg1 & 0x20){ 
            if(!(D_80382E20.unk128_31 & 0x80)){
                func_803114D0();
            }
            else{
                D_80382E20.unk12C_15 = 0;
                D_80382E20.unk12C_11 = 0;
            }
        }//L803112E8
        if(arg1 & 0x04 || arg1 & 0x20){
            
            //L80311300
            temp_v1 = D_80382E20.unk12C_11 + D_80382E20.unk12C_15;
            temp_v1 = (temp_v1 < 4)?temp_v1 : temp_v1 - 4;
            //L80311328
            D_80382E20.unk148[temp_v1].unk0 = text_id;
            D_80382E20.unk148[temp_v1].unk2 = arg1;
            if(pos){
                D_80382E20.unk148[temp_v1].unk4[0] = pos[0];
                D_80382E20.unk148[temp_v1].unk4[1] = pos[1];
                D_80382E20.unk148[temp_v1].unk4[2] = pos[2];
            }
            else{
                D_80382E20.unk148[temp_v1].unk4[2] = 0.0f;
                D_80382E20.unk148[temp_v1].unk4[1] = 0.0f;
                D_80382E20.unk148[temp_v1].unk4[0] = 0.0f;
            }
            D_80382E20.unk148[temp_v1].unk10 = marker;
            D_80382E20.unk148[temp_v1].unk14 = (marker != NULL )? ((marker->unk5C)? marker->unk5C : -1) : 0;
            D_80382E20.unk148[temp_v1].unk18 = callback;
            D_80382E20.unk148[temp_v1].unk1C = arg5;
            D_80382E20.unk148[temp_v1].unk20 = arg6;
            D_80382E20.unk12C_15++;
            if(arg1 & 0x08){
                if(!( func_802E4A08() ||  func_803203FC(0x1f, &D_80382E20)) || !D_80382E20.unk128_3){//L8031141C
                    if(!func_8028EC04()){
                        if(pos != NULL){
                            func_8028F94C(2, pos);
                        }
                        else{//L80311444
                            func_8028F918(2);
                        }
                    }
                    else{//L80311454
                        func_8028F918(func_8028EC04());
                    }
                }
            }
            return 1;
        }
    }
    return 0;
}

bool func_80311480(s32 text_id, s32 arg1, f32 *pos, ActorMarker *marker, void(*callback)(ActorMarker *, enum asset_e, s32), void(*arg5)(ActorMarker *, enum asset_e, s32)){
    return func_80311174(text_id, arg1, pos, marker, callback, arg5, 0);
}

int func_803114B0(void){
    return (D_80382E20.unk130 + 1) != 0;
}

int func_803114C4(void){
    return D_80382E20.unk130;
}

void func_803114D0(void){
    s32 i;

    if(func_803114B0()){
        gcdialog_setState(6);
    }else{
        if(D_80382E20.state != 6){
            D_80382E20.unk12C_25 = 0;
            for(i = 0; i< 2; i++){
                D_80382E20.unk11A[i].unk0_7 = 0;
                if(D_80382E20.zoombox[i]){
                    D_80382E20.unk12C_25 += (u8)func_803188B4(D_80382E20.zoombox[i]);
                }
            }
            if(D_80382E20.unk12C_25 != 0){
                D_80382E20.state = 6;
            }
        }
    }//L80311594
    D_80382E20.unk12C_15 = 0;
    D_80382E20.unk12C_11 = 0;

}

int func_803115C4(s32 next_state){
    if(func_803114C4() != next_state){
        return 0;
    }else{
        gcdialog_setState(6);
        return 1;
    }
}

void func_80311604(void){
    if(func_803114B0()){
        D_80382E20.unk128_5 = 1;
        D_80382E20.unk128_4 = 0;
        D_80382E20.unk132++;
    }
}

void func_80311650(void){
    if(func_803114B0()){
        D_80382E20.unk128_5 = 1;
        D_80382E20.unk128_4 = 1;
        D_80382E20.unk132--;
    }
}

void gcdialog_defrag(void){
    s32 i;
    
    for(i = 0; i< 2; i++){
        func_80318C0C(D_80382E20.zoombox[i]);
        if(D_80382E20.string_list[i]){
            D_80382E20.string_list[i] = (struct13s *)defrag(D_80382E20.string_list[i]);
        }
        if(D_80382E20.zoombox[i] != NULL){
            D_80382E20.zoombox[i] = (gczoombox_t *)defrag(D_80382E20.zoombox[i]);
        }
    }
}

void func_80311714(int next_state){
    D_80382E20.unk128_3 = next_state;
}
