#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "gc/gctransition.h"

void animctrl_setAnimTimer(AnimCtrl*, f32);
void func_8025AC20(s32, s32, s32, f32, char*, s32);
f32 func_80257618(void);
void func_8024CE60(f32, f32);


/* .data */
struct9s D_8036C150[0x16]= {
    {0x1,  2, 0, 0.1f, 0, 0, 0.0f},
    {0x2,  3, 1, 0.1f, 0, 0, 0.0f},
    {0x3,  4, 0, 0.5f, ASSET_7CF_MODEL_TRANSITION_UNKNOWN, 0, 25.0f},
    {0x4,  5, 1, 0.5f, ASSET_7CF_MODEL_TRANSITION_UNKNOWN, 0, 25.0f},
    {0x5,  4, 0, 2.5f, ASSET_7D0_MODEL_TRANSITION_JIGGY, 0,   3.5f},
    {0x6,  5, 1, 0.9f, ASSET_7D0_MODEL_TRANSITION_JIGGY, 0, 3.5f},
    {0x7,  0, 0, 0.0f, 0, 0, 0.0f},
    {0x8,  7, 0, 1.1f, 0, 0, 0.0f},
    {0x9,  8, 6, 0.7f, 0, 0, 0.0f},
    {0xA,  5, 1, 3.5f, ASSET_7D4_MODEL_TRANSITION_WITCH, 0, 3.7f},
    {0xB,  4, 0, 0.3f, ASSET_7CF_MODEL_TRANSITION_UNKNOWN, 0, 25.0f},
    {0xC,  5, 1, 0.3f, ASSET_7CF_MODEL_TRANSITION_UNKNOWN, 0, 25.0f},
    {0xD,  2, 0, 0.6f, 0, 0, 0.0f},
    {0xE,  4, 0, 1.0f, ASSET_7CF_MODEL_TRANSITION_UNKNOWN, 0, 25.0f},
    {0xF,  5, 1, 1.0f, ASSET_7CF_MODEL_TRANSITION_UNKNOWN, 0, 25.0f},
    {0x10, 4, 0, 2.5f, ASSET_467_MODEL_TRANSITION_FALLING_JIGGIES, ASSET_1F5_ANIM_TRANSITION_FALLING_JIGGIES, 0.269645989f},
    {0x11, 5, 1, 2.0f, ASSET_467_MODEL_TRANSITION_FALLING_JIGGIES, ASSET_1F5_ANIM_TRANSITION_FALLING_JIGGIES, 0.269645989f},
    {0x12, 4, 0, 1.2f, ASSET_7CF_MODEL_TRANSITION_UNKNOWN, 0, 25.0f},
    {0x13, 5, 1, 1.2f, ASSET_7CF_MODEL_TRANSITION_UNKNOWN, 0, 25.0f},
    {0x14, 5, 1, 2.2f, ASSET_7CF_MODEL_TRANSITION_UNKNOWN, 0, 25.0f},
    {0x15, 4, 0, 2.2f, ASSET_7CF_MODEL_TRANSITION_UNKNOWN, 0, 25.0f},
    0
};

struct9s D_8036C308[0xC] = {
    {0xA,  5, 1, 3.5f, ASSET_7D4_MODEL_TRANSITION_WITCH, 0, 3.7f},
    {0x10, 4, 0, 2.5f, ASSET_467_MODEL_TRANSITION_FALLING_JIGGIES, ASSET_1F5_ANIM_TRANSITION_FALLING_JIGGIES, 0.269645989f},
    {0x11, 5, 1, 2.0f, ASSET_467_MODEL_TRANSITION_FALLING_JIGGIES, ASSET_1F5_ANIM_TRANSITION_FALLING_JIGGIES, 0.269645989f},
    {0x6,  5, 1, 0.9f, ASSET_7D0_MODEL_TRANSITION_JIGGY, 0, 3.5f},
    {0x5,  4, 0, 2.5f, ASSET_7D0_MODEL_TRANSITION_JIGGY, 0, 3.5f},
    {0x9,  8, 6, 0.7f, 0, 0, 0.0f},
    {0x8,  7, 0, 0.7f, 0, 0, 0.0f},
    {0xE,  4, 0, 1.0f, ASSET_7CF_MODEL_TRANSITION_UNKNOWN, 0, 25.0f},
    {0xF,  5, 1, 1.0f, ASSET_7CF_MODEL_TRANSITION_UNKNOWN, 0, 25.0f},
    {0x7,  0, 0, 0.0f, 0, 0, 0.0f},
    {0x8,  7, 0, 1.1f, 0, 0, 0.0f},
    {0x9,  8, 6, 1.5f, 0, 0, 0.0f}
};

struct10s D_8036C3F8[0x18] = {
    {MAP_20_CS_END_NOT_100,                 0x12, 0x13},
    {MAP_1F_CS_START_RAREWARE,              0x15, 0x09},
    {MAP_1E_CS_START_NINTENDO,              0x08, 0x13},
    {MAP_7D_CS_SPIRAL_MOUNTAIN_1,           0x0B, 0x0C},
    {MAP_7E_CS_SPIRAL_MOUNTAIN_2,           0x0B, 0x0C},
    {MAP_85_CS_SPIRAL_MOUNTAIN_3,           0x12, 0x0C},
    {MAP_86_CS_SPIRAL_MOUNTAIN_4,           0x0B, 0x0C},
    {MAP_87_CS_SPIRAL_MOUNTAIN_5,           0x12, 0x13},
    {MAP_88_CS_SPIRAL_MOUNTAIN_6,           0x12, 0x13},
    {MAP_94_CS_INTRO_SPIRAL_7,              0x12, 0x13},
    {MAP_95_CS_END_ALL_100,                 0x12, 0x13},
    {MAP_98_CS_END_SPIRAL_MOUNTAIN_1,       0x12, 0x0A},
    {MAP_99_CS_END_SPIRAL_MOUNTAIN_2,       0x12, 0x0A},
    {MAP_7B_CS_INTRO_GL_DINGPOT_1,          0x0B, 0x0C},
    {MAP_81_CS_INTRO_GL_DINGPOT_2,          0x0B, 0x0C},
    {MAP_82_CS_ENTERING_GL_MACHINE_ROOM,    0x12, 0x0A},
    {MAP_83_CS_GAME_OVER_MACHINE_ROOM,      0x12, 0x13},
    {MAP_84_CS_UNUSED_MACHINE_ROOM,         0x12, 0x0C},
    {MAP_7C_CS_INTRO_BANJOS_HOUSE_1,        0x0B, 0x0C},
    {MAP_89_CS_INTRO_BANJOS_HOUSE_2,        0x0B, 0x0A},
    {MAP_8A_CS_INTRO_BANJOS_HOUSE_3,        0x01, 0x02},
    {MAP_96_CS_END_BEACH_1,                 0x12, 0x13},
    {MAP_97_CS_END_BEACH_2,                 0x08, 0x14},
    {0,                                     0x05, 0x06}
};
f32 D_8036C440 = 63.6026115f;
f32 D_8036C444 = 500.0f;


/* .bss */
struct{
    s32 unk0; //times drawn?
    struct9s *unk4;
    u8 unk8; //state
    u8 pad9[3]; //not needed
    void * unkC; //asset_ptr
    f32 rotation;
    f32 timer;
    AnimCtrl *animctrl;
    s32 unk1C; //times update called?
} D_80382430;

/* .code */
struct9s *_gctranstion_8030B400(s32 arg0){
    struct9s * i;
    for(i = D_8036C150; i->uid != 0; i++){
        if(i->uid == arg0)
            return i;
    }
    return NULL;
}

struct10s *_gctranstion_8030B44C(s32 map_indx){
    struct10s * i;
    for(i = D_8036C3F8; i->map_indx != 0; i++){
        if(i->map_indx == map_indx)
            return i;
    }
    return i;
}

void _gctranstion_changeState(s32 state, struct9s *arg1){
    if(D_80382430.unkC != NULL){
        func_8033BD20(&D_80382430.unkC);
    }

    if(D_80382430.animctrl != NULL){
        animctrl_free(D_80382430.animctrl);
        D_80382430.animctrl = NULL;
    }
    
    D_80382430.unk0 = 0;
    D_80382430.unk4 = arg1;
    D_80382430.unk8 = state;
    D_80382430.timer = 0.0f;
    if(state == 1)
        D_80382430.unkC = assetcache_get(0x7D2);
    else if(state == 6)
        D_80382430.unkC = assetcache_get(0x7D3);
    else if(arg1 != NULL && arg1->unk8 != 0)
        D_80382430.unkC = assetcache_get(arg1->unk8);

    if(arg1 != NULL && arg1->unkC != NULL){
        D_80382430.animctrl = animctrl_new(0);
        animctrl_reset(D_80382430.animctrl);
        animctrl_setIndex(D_80382430.animctrl, arg1->unkC);
        animctrl_setDuration(D_80382430.animctrl, arg1->unk4);
        animctrl_setPlaybackType(D_80382430.animctrl,  ANIMCTRL_ONCE);
        if(state == 5){
            animctrl_setDirection(D_80382430.animctrl, 0);
            func_8028F7C8(1); //player_noControl(true)
            func_80335110(0); //objects_update(false)
        }
        else{
            osViBlack(1);
            animctrl_setAnimTimer(D_80382430.animctrl, 0.25f); //set animation timer
        }
        func_802875AC(D_80382430.animctrl, "gctransition.c", 0x125); 
    }

    if(state == 4){
        if(func_802D4608()==0){
            func_8025A70C(COMUSIC_4E_IN_TRANSITION);
            func_8025AC20(COMUSIC_4E_IN_TRANSITION, 0, 1000, 0.4f, "gctransition.c", 0x12d);
            func_8025AABC(COMUSIC_4E_IN_TRANSITION);
        }
    }//L8030B67C
    else if(state == 5){
        if(D_80382430.unk4->uid == 0xA){
            func_8030E704(SFX_EB_GRUNTY_LAUGH_2);
        }
        else{
            if(func_802D4608() == 0){
                func_8025A70C(COMUSIC_4F_OUT_TRANSITION);
                func_8025AC20(COMUSIC_4F_OUT_TRANSITION, 0, 1000, 0.2f, "gctransition.c", 0x13a);
                func_8025AABC(COMUSIC_4F_OUT_TRANSITION);
            }
        }
    }
    else if(state == 0){
        func_80335128(1);
        func_80335110(1);
        if(func_8028F070())
            func_8028F7C8(0);
    }
    D_80382430.unk1C = 0;
}  

void gctransition_8030B740(void){
    if(D_80382430.unkC != NULL)
        D_80382430.unkC = defrag_asset(D_80382430.unkC);
}

void gctransition_draw(Gfx **gdl, Mtx **mptr, Vtx **vptr){
    f32 sp74[3];
    f32 sp68[3];
    f32 sp64;
    f32 sp58[3];
    f32 tmp;

    D_80382430.unk0++;
    if(D_80382430.unk8 == 0)
        return;

    func_8024E258();
    if(D_80382430.animctrl != NULL){
        sp74[0] = 0.0f;
        sp74[1] = 0.0f;
        sp74[2] = 350.0f;
    }else{
        sp74[0] = 0.0f;
        sp74[1] = 0.0f;
        sp74[2] = 300.0f;
    }

    sp68[0] = 0.0f;
    sp68[1] = 0.0f;
    sp68[2] = 0.0f;
    func_8024CE60(D_8036C440, D_8036C444);
    func_8024CD88(sp74); //camera_setPosition
    func_8024CE18(sp68); //camera_setRotation
    func_8024CFD4(); //camera_updateNormal
    func_8024C904(gdl, mptr);

    sp58[0] = 0.0f;
    sp58[1] = 0.0f;
    sp58[2] = 0.0f;
    if(D_80382430.animctrl != NULL){
        gDPSetTextureFilter((*gdl)++, G_TF_POINT);
        gDPSetColorDither((*gdl)++, G_CD_DISABLE);
        func_8028781C(D_80382430.animctrl, sp58, 1);
        set_model_render_mode(1);
    }
    if(D_80382430.unk8 == 1 || D_80382430.unk8 == 6){
        func_803391A4(gdl, mptr, sp58, sp68, 1.0f, 0, D_80382430.unkC);
        if(D_80382430.animctrl != NULL){
            gDPSetTextureFilter((*gdl)++, G_TF_BILERP);
            gDPSetColorDither((*gdl)++, G_CD_MAGICSQ);
        }
    }
    else{
        sp64 = D_80382430.timer/(D_80382430.unk4->unk4);
        if(D_80382430.unk8 == 4){

            if(D_80382430.unk4->uid == 0x10){
                tmp = D_80382430.unk4->unk10;
                
            }
            else{
                sp68[2] = D_80382430.rotation - 90.0f*sp64;
                tmp = sp64*D_80382430.unk4->unk10 + 0.1;
            }
            func_803391A4(gdl, mptr, sp58, sp68, tmp, 0, D_80382430.unkC);
        }
        else if(D_80382430.unk8 == 5){//L8030B9EC
            switch (D_80382430.unk4->uid)
            {
            default:
                sp68[2] = D_80382430.rotation - 90.0f*sp64;
                tmp = (1.0f - sp64)*D_80382430.unk4->unk10 + 0.1;
                break;
            case 0x11:
                tmp = D_80382430.unk4->unk10;
                break;
            case 0xA:
                sp68[2] = 0.0f;
                tmp = (1.0f - func_80257618())*D_80382430.unk4->unk10 + 0.1;
                break;
            }
            if(!(D_80382430.unk1C < 3) || D_80382430.unk4->uid != 0x11){
                func_803391A4(gdl, mptr, sp58, sp68, tmp, 0, D_80382430.unkC);
            }
            else{
                func_80338390();
            }

        }
        else if(D_80382430.unk8 == 2){//L8030BAF4
            gcbound_reset();
            gcbound_alpha((1.0f - sp64)*255.0f + 0.5);
            gcbound_color(0,0,0);
            gcbound_draw(gdl);
        }
        else if(D_80382430.unk8 == 3){//L8030BB6C
            gcbound_reset();
            gcbound_alpha(sp64*255.0f + 0.5);
            gcbound_color(0,0,0);
            gcbound_draw(gdl);
        }
        else if(D_80382430.unk8 == 7){//L8030BBD8
            sp64 = (sp64 <= 0.5)? 1.0 : 1.0 - (sp64-0.5)/0.5;
            gcbound_reset();
            gcbound_alpha(sp64*255.0f + 0.5);
            gcbound_color(0xff,0xff,0xff);
            gcbound_draw(gdl);
        }
        else if(D_80382430.unk8 == 8){//L8030BC8C
            
            gcbound_reset();
            gcbound_alpha(sp64*255.0f + 0.5);
            gcbound_color(0xff,0xff,0xff);
            gcbound_draw(gdl);
        }//L8030BD00
        else{
            
        }
        if(D_80382430.animctrl != NULL){
            gDPSetTextureFilter((*gdl)++, G_TF_BILERP);
        }
        func_8024E2FC();
        func_8024C904(gdl, mptr);
    }
}

void gctransition_8030BD4C(void){
    struct10s *tmp_10s;
    struct9s *tmp_a1;
    tmp_10s = _gctranstion_8030B44C(map_get());
    tmp_a1 = _gctranstion_8030B400(tmp_10s->unk1);
   _gctranstion_changeState(tmp_a1->unk1, tmp_a1);
}

f32 gctransition_8030BD88(void){
    return 300.0f;
}

int gctransition_8030BD98(void){
    return D_80382430.unk8 == 0;
}

int gctransition_8030BDAC(void){
    return D_80382430.unk8 != 0;
}

int gctransition_8030BDC0(void){
    return ( D_80382430.unk8 == 0x3)
    || (( D_80382430.unk8 == 1) && (D_80382430.unk0 < 2))
    || ( D_80382430.unk8 == 5)
    || ( D_80382430.unk8 == 8)
    || (( D_80382430.unk8 == 6) && (D_80382430.unk0 < 2));
}

void gctransition_8030BE3C(void){
    _gctranstion_changeState(0, NULL);
}

void gctransition_8030BE60(void){
    struct9s *tmp_a1;
    tmp_a1 = _gctranstion_8030B400(_gctranstion_8030B44C(map_get())->unk2);
   func_8030C180();
   _gctranstion_changeState(tmp_a1->unk1, tmp_a1);
}

void gctransition_8030BEA4(s32 arg0){
    _gctranstion_changeState(D_8036C308[arg0].unk1, &D_8036C308[arg0]);
}

void gctransition_reset(void){
    D_80382430.unk4 = NULL;
    D_80382430.unk8 = 0;
    D_80382430.unkC = NULL;
    D_80382430.rotation = 0.0f;
    _gctranstion_changeState(0,0);
}

void gctransition_update(void){
    f32 sp24;
    f32 tmp;
    

    sp24 = time_getDelta();
    if(D_80382430.unk4 == NULL)
        return;
    
    if(D_80382430.animctrl != NULL){
        animctrl_update(D_80382430.animctrl);
        if(D_80382430.unk8 == 4){
            switch(D_80382430.unk1C){
                case 0:
                    break;
                case 1:
                    func_8028F7C8(1);
                    func_80335110(0);
                    break;
                case 2:
                    func_80335128(0);
                    break;
                case 3:
                    func_802FEF48(D_80382430.unkC); //framebuffer to model texture list
                    break;
                case 4:
                    osViBlack(0);
                    break;
                default:
                   D_80382430.timer += sp24;
                   break;
            }
        }
        else{//L8030BFEC
            switch(D_80382430.unk1C){
                default:
                    D_80382430.timer += sp24;
                    break;
                case 0:
                case 1:
                    break;
                case 2:
                    func_80335128(0); 
                    func_802FEF48(D_80382430.unkC); //framebuffer to model texture list
                    break;
                
            }
            
        }
    }
    else{//L8030C034
        D_80382430.timer += sp24;
    }
    if(D_80382430.unk4->unk4 < D_80382430.timer
        || (D_80382430.animctrl!= NULL && animctrl_isStopped(D_80382430.animctrl))
    ){
        D_80382430.timer = D_80382430.unk4->unk4;
        if(D_80382430.unk8 == 4 || D_80382430.unk8 == 5){
            D_80382430.rotation -= 90.0f;
            if (D_80382430.rotation < -360.0f)
                D_80382430.rotation += 360.0f;
            if (360.0f < D_80382430.rotation)
                D_80382430.rotation -= 360.0f;
        }//L8030C104
        _gctranstion_changeState(D_80382430.unk4->unk2, 0);
        if(D_80382430.unk8 == 4)
            func_8030C180();

        if(D_80382430.animctrl != NULL)
            func_80334ECC();
    }
    D_80382430.unk1C++;
}
