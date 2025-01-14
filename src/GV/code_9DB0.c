#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_8034E120(void *, f32, f32, f32, s32);

typedef struct {
    s16 unk0;
    s16 unk2;
    Struct6Ds *unk4;
}Struct_GV_9DB0_1;

/* .data */
Struct_GV_9DB0_1 D_80391650[] = {
    {0x190, 1, 0 },
    {0x191, 5, 0 },
    {0x192, 3, 0 },
    {0x193, 4, 0 },
    {0x194, 3, 0 },
    {0x195, 7, 0 },
    {0x196, 0, 0 },
    {0x197, 4, 0 },
    {0x198, 0, 0 },
    {0x199, 2, 0 },
    {0x19A, 6, 0 },
    {0x19B, 1, 0 },
    {0x19C, 6, 0 },
    {0x19D, 5, 0 },
    {0x19E, 2, 0 },
    {0x19F, 7, 0 },
    {0x000, 0, 0 },
};
f32 D_803916D8[3] = {0.0f, 100.0f, 0.0f};

/*.bss */
extern struct {
    Struct_GV_9DB0_1 *tile1_0;
    Struct_GV_9DB0_1 *tile2_4;
    u8 matchCnt_8;//match_count
    u8 state_9;
    //u8 padA[0x2];
    f32 unkC;
    ActorMarker *unk10;
}D_80391AE0;

/* .code */
Struct_GV_9DB0_1 * func_803901A0(s32 arg0){
    int i;
    for(i = 0; D_80391650[i].unk0 != 0; i++){
        if(arg0 == D_80391650[i].unk0)
            return D_80391650 + i;
    }
    return NULL;
}

void func_803901F0(void *arg0){
    FUNC_8030E624(SFX_3F6_UNKNOWN, 1.0f, 30000);
}

void func_80390218(void *arg0){
    FUNC_8030E624(SFX_7F_HEAVYDOOR_SLAM, 0.8f, 32725);
    func_8030E6D4(SFX_7F_HEAVYDOOR_SLAM);
}

void func_80390248(void){
    jiggySpawn(JIGGY_40_GV_MATCHING_GAME, D_803916D8);
}

//matchingGame_setState
void func_80390270(s32 next_state){
    if(next_state == 2){
        item_set(ITEM_6_HOURGLASS, 1);
        if(func_803203FC(2))
            item_set(ITEM_0_HOURGLASS_TIMER, 4499);
        else
            item_set(ITEM_0_HOURGLASS_TIMER, 5999);
    }
    if(D_80391AE0.state_9 == 2){
        item_set(ITEM_6_HOURGLASS, 0);
    }

    if(next_state == 3){
        if(func_803203FC(2)){
            func_803204E4(3, 0);
            func_803204E4(5, 0);
        }
        else{
            func_8028F66C(BS_INTR_F);
        }
    }
    
    if(next_state == 4){
        if(func_803203FC(2)){
            func_803204E4(3, 0);
            func_803204E4(5, 1);
        }
        else{
            func_8025A6EC(COMUSIC_2D_PUZZLE_SOLVED_FANFARE, 0x7fff);
            if(D_80391AE0.unk10){
                func_8035D490(D_80391AE0.unk10);
            }
            func_80324E38(0.5f, 3);
            timed_setCameraToNode(1.5f, 2);
            timedFunc_set_0(1.7f, func_80390248);
            func_80324E88(4.0f);
            func_80324E38(4.0f, 0);

        }
    }//L803903D8
    D_80391AE0.state_9 = next_state;
}

//matchingGame_reset
void func_803903EC(void){
    func_80390270(0);
}

//matchingGame_init
void func_8039040C(void){
    Actor *actor;
    D_80391AE0.state_9 = 0;
    if(map_get() == MAP_13_GV_MEMORY_GAME){
        if( !jiggyscore_isSpawned(JIGGY_40_GV_MATCHING_GAME) //jiggy is collected
            ||  func_803203FC(2)                      //in FF minigame
        ){
            D_80391AE0.matchCnt_8 = 0;
            D_80391AE0.tile1_0 = NULL;
            D_80391AE0.tile2_4 = NULL;
            D_80391AE0.state_9 = 1;
            D_80391AE0.unkC = 0.0f;
            actor = func_80326EEC(0x34f);
            if(actor){
                D_80391AE0.unk10 = actor->marker; 
            }
            else{
                D_80391AE0.unk10 = NULL;
            }
        }
    }
}

void func_803904A8(void){
    f32 sp5C;
    f32 sp50[3];
    s32 sp4C;
    Struct6Ds *sp48;
    Struct_GV_9DB0_1 * sp44;
    f32 sp38[3];
    f32 pad34;

    sp5C = time_getDelta();
    if(!D_80391AE0.state_9)
        return;

    if(D_80391AE0.unk10 && !D_80391AE0.unk10->unk5C){
        D_80391AE0.unk10 = NULL;
    }

    if(D_80391AE0.tile1_0 == NULL || D_80391AE0.tile2_4 == NULL){
        if( player_getActiveHitbox(0) == HITBOX_1_BEAK_BUSTER && func_8028F20C()){
            player_getPosition(sp50);
            sp4C = func_8033F3E8(func_80309744(0), sp50, 0x190, 0x1a0);
            if(sp4C){
                sp48 = func_8034C528(sp4C);
                if(D_80391AE0.state_9 == 1){
                    func_80390270(2);
                }
                if(func_8034DC78(sp48) != 1){
                    sp44 = func_803901A0(sp4C);
                    func_8034E254(sp48, func_803901F0);
                    func_8034E25C(sp48, func_80390218);
                    func_8034E120(sp48, 0.0f, 180.0f, 0.7f, 1);

                    D_80391AE0.tile2_4 = D_80391AE0.tile1_0;
                    D_80391AE0.tile1_0 = sp44;
                    sp44->unk4 = sp48;

                    if(D_80391AE0.unk10){
                        func_8035D4F0(D_80391AE0.unk10, sp4C);
                    }
                }
            }
        }
    }//L80390608

    if(D_80391AE0.tile1_0 && D_80391AE0.tile2_4){
        s32 sp48;
        if( func_8034DC78(D_80391AE0.tile1_0->unk4) == 1 && func_8034DC78(D_80391AE0.tile2_4->unk4) == 1){
            if(0.0f < D_80391AE0.unkC){
                if(0.6 < D_80391AE0.unkC && D_80391AE0.unkC - sp5C <= 0.6){
                    func_8025A6EC(COMUSIC_2C_BUZZER, 0x7fff);
                }//L803906AC
                D_80391AE0.unkC -= sp5C;
                if(D_80391AE0.unkC <= 0.0f){
                    func_8034E254(D_80391AE0.tile1_0->unk4, 0);
                    func_8034E25C(D_80391AE0.tile1_0->unk4, 0);
                    func_8034E120(D_80391AE0.tile1_0->unk4, 180.0f, 0.0f, 0.5f, 2);
                    func_8034E120(D_80391AE0.tile2_4->unk4, 180.0f, 0.0f, 0.5f, 2);
                    player_getPosition(sp38);
                    sp48  = func_8033F3E8(func_80309744(0), sp38, 0x190, 0x1a0);
                    if(sp48 == D_80391AE0.tile1_0->unk0 || sp48 == D_80391AE0.tile2_4->unk0){
                        func_8028F66C(BS_INTR_14);
                    }
                    D_80391AE0.tile1_0 = D_80391AE0.tile2_4 = NULL;
                }
            }//L80390788
            else{
                if(D_80391AE0.tile2_4->unk2 == D_80391AE0.tile1_0->unk2){
                    D_80391AE0.matchCnt_8++;
                    if(D_80391AE0.matchCnt_8 == 8){
                        func_80390270(4); //end game state
                    }
                    else{
                        func_8025A6EC(COMUSIC_2B_DING_B, 0x7fff);
                    }
                    D_80391AE0.tile1_0 = D_80391AE0.tile2_4 = NULL;
                }//L803907E4
                else{
                    D_80391AE0.unkC = 1.0f;
                }
            }//L803907EC
        }//L803907F0
    }//L803907F0
    
    if( D_80391AE0.state_9 == 1
        && func_803203FC(2)
        && func_803203FC(3)
    ){
        func_80390270(2);
    }

    if(D_80391AE0.state_9 == 2){
        if(D_80391AE0.tile1_0 == NULL || D_80391AE0.tile2_4 == NULL){
            if(item_empty(ITEM_6_HOURGLASS)){
                func_80390270(3);
            }
        }
    }
}
