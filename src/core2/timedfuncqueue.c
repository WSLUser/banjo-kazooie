#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_802BAE4C(void);
void func_802BAE20(f32);
void func_80324BA0(u32);

typedef struct timed_function_queue_s{
    f32 time;
    u8  arg_cnt;
    u8  pad5[3];
    union { 
        void (* func0)(void);
        void (* func1)(s32);
        void (* func2)(s32, s32);
        void (* func3)(s32, s32, s32);
        void (* func4)(s32, s32, s32, s32);
        void (* func5)(s32, s32, s32, s32, s32);
        void (* func6)(s32*);
    };
    s32  arg[25];
    
}TimedFunction;

typedef struct tfq_struct_2_s{
    u32 unk0;
    u32 unk4;
    u32 unk8;
    f32 unkC[3];
    f32 unk18;
    f32 unk1C;
}timefuncqueue_Struct2;

typedef struct timed_func_array_s{
    VLA *ptr;
    f32 time;
}TimedFunctionArray;

typedef struct delayed_jiggy_s{
    u32 id;
    f32 pos[3];
} DelayedJiggyInfo;

//void __spawnjiggy(DelayedJiggyInfo *);
TimedFunction* __timedFuncQueue_insert(f32, u32, void(* func)(u32, u32, u32, u32, u32), u32, u32, u32, u32, u32);
void func_8030E760(u32, f32, u32);
void func_8030E9C4(u32, u32, u32, f32 *, f32, f32);

void timedFuncAdd_0(f32 time, void(*funcPtr)(void));
void func_80324EE4(f32 time, void(*funcPtr)(u32), u32 arg0);
void func_80324F20(f32 time, void(*funcPtr)(u32, u32), u32 arg0, u32 arg1);
void func_80324F64(f32 time, void(*funcPtr)(u32, u32, u32), u32 arg0, u32 arg1, u32 arg2);
void func_80325048(f32 time, void(*funcPtr)(u32, u32, u32, u32, u32, u32), u32* argPtr );

void func_802BE720(void);

extern TimedFunctionArray D_80383380;


TimedFunction* __timedFuncQueue_insert(f32 time, u32 cnt, void(* funcPtr)(u32, u32, u32, u32, u32), u32 arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4){
    TimedFunction * startPtr;
    TimedFunction *retVal;
    TimedFunction * iPtr;
    TimedFunction * endPtr;

    startPtr = (TimedFunction * )vla_getBegin(D_80383380.ptr);
    endPtr = (TimedFunction * )vla_getEnd(D_80383380.ptr);
    if(endPtr == startPtr){
        D_80383380.time = 0.0f; 
    }
    else{
        time += D_80383380.time;
    }
    for(iPtr = startPtr; iPtr < endPtr; iPtr++){
        if(iPtr->time > time)
            break;
    }
    retVal = (TimedFunction * )vla_insertNew(&D_80383380, ((s32)iPtr - (s32)startPtr)/(s32)sizeof(TimedFunction));
    retVal->time = time;
    retVal->arg_cnt = cnt;
    retVal->func5 = funcPtr;
    retVal->arg[0] = arg0;
    retVal->arg[1] = arg1;
    retVal->arg[2] = arg2;
    retVal->arg[3] = arg3;
    retVal->arg[4] = arg4;
    return retVal;
}

void __timedFunc_execute(TimedFunction *arg0){
    if(arg0->arg_cnt == 0)
        arg0->func0();
    else if(arg0->arg_cnt == 1)
        arg0->func1(arg0->arg[0]);
    else if(arg0->arg_cnt == 2)
        arg0->func2(arg0->arg[0], arg0->arg[1]);
    else if(arg0->arg_cnt == 3)
        arg0->func3(arg0->arg[0], arg0->arg[1], arg0->arg[2]);
    else if(arg0->arg_cnt == 4)
        arg0->func4(arg0->arg[0], arg0->arg[1], arg0->arg[2], arg0->arg[3]);
    else if(arg0->arg_cnt == 5)
        arg0->func5(arg0->arg[0], arg0->arg[1], arg0->arg[2], arg0->arg[3], arg0->arg[4]);
    else if(arg0->arg_cnt == 6)
        arg0->func6(&arg0->arg[5]);
}

void func_80324A28(u32 soundId, u32 volume){
    func_8025A6EC(soundId, volume);
}

void func_80324A48(u32 arg0){
    func_8025A7DC(arg0);
}

void func_80324A68(u32 arg0, s32 arg1, u32 arg2){
    func_8030E760(arg0, arg1/1000.0f, arg2);
}

void func_80324AA4(timefuncqueue_Struct2 *arg0){
    func_8030E9C4(arg0->unk0, arg0->unk4, arg0->unk8, &arg0->unkC, arg0->unk18, arg0->unk1C);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/timedfuncqueue/func_80324AEC.s")

void func_80324BA0(u32 arg0){
    if(arg0 == 1)
        func_8028F918(1);
    else if(arg0 == 2)
        func_8028F918(3);
    else if(arg0 == 3)
        func_8028F918(2);
    else{ 
        if(arg0 == 0)
            func_8028F918(0);
        else if (arg0 == 4)
            func_802D6114();
    }
}

void __spawnjiggy(DelayedJiggyInfo *jigInfo){
    jiggySpawn(jigInfo->id, &jigInfo->pos);
}

void func_80324C58(void){
    vla_clear(D_80383380.ptr);
}

f32 func_80324C7C(void){
    return D_80383380.time;
}

void func_80324C88(f32 time, u32 arg0, f32 arg1, u32 arg2){
    func_80324F64(time, func_80324A68, arg0, (s32)(arg1*1000.0f), arg2);
}

void func_80324CD8(f32 time){
    timedFuncAdd_0(time, func_802BE720);
}

void func_80324CFC(f32 time, u32 id, u32 volume){
    func_80324F20(time, func_80324A28, id, volume);
}

void func_80324D2C(f32 time, u32 arg0){
    func_80324EE4(time, func_80324A48, arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/timedfuncqueue/func_80324D54.s")
// void func_80324D54(f32 time, u32 arg1, u32 arg2, u32 arg3, f32 * arg4, f32 arg5, f32 arg6){
//     timefuncqueue_Struct2 argStruct;
//     argStruct.unk0 = arg1;
//     //argStruct.unk4 = arg2;
//     argStruct.unk8 = arg3;
//     argStruct.unk18 = arg5;
//     argStruct.unk1C = arg6;
//     argStruct.unkC[0] = arg4[0];
//     argStruct.unkC[1] = arg4[1];
//     argStruct.unkC[2] = arg4[2];
    
//     func_80325048(time, func_80324AA4, (u32) &argStruct);
// }

#pragma GLOBAL_ASM("asm/nonmatchings/core2/timedfuncqueue/func_80324DBC.s")

void func_80324E38(f32 time, u32 arg0){
    func_80324EE4(time, func_80324BA0, arg0);
}

void func_80324E60(f32 time, u32 arg0){
    func_80324EE4(time, func_802BAE20, arg0);
}

void func_80324E88(f32 time){
    timedFuncAdd_0(time, func_802BAE4C);
}

void timedFuncAdd_0(f32 time, void(*funcPtr)(void)){
    __timedFuncQueue_insert(time, 0, funcPtr, 0, 0, 0, 0, 0);
}

void func_80324EE4(f32 time, void(*funcPtr)(u32), u32 arg0){
    __timedFuncQueue_insert(time, 1, funcPtr, arg0, 0, 0, 0, 0);
}

void func_80324F20(f32 time, void(*funcPtr)(u32, u32), u32 arg0, u32 arg1){
    __timedFuncQueue_insert(time, 2, funcPtr, arg0, arg1, 0, 0, 0);
}

void func_80324F64(f32 time, void(*funcPtr)(u32, u32, u32), u32 arg0, u32 arg1, u32 arg2){
    __timedFuncQueue_insert(time, 3, funcPtr, arg0, arg1, arg2, 0, 0);
}

void func_80324FAC(f32 time, void(*funcPtr)(u32, u32, u32, u32), u32 arg0, u32 arg1, u32 arg2, u32 arg3){
    __timedFuncQueue_insert(time, 4, funcPtr, arg0, arg1, arg2, arg3, 0);
}

void func_80324FF8(f32 time, void(*funcPtr)(u32, u32, u32, u32, u32), u32 arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4){
    __timedFuncQueue_insert(time, 5, funcPtr, arg0, arg1, arg2, arg3, arg4);
}

void func_80325048(f32 time, void(*funcPtr)(u32, u32, u32, u32, u32, u32), u32* argPtr ){
    TimedFunction *q = __timedFuncQueue_insert(time, 6, funcPtr, 0, 0, 0, 0, 0);
    func_80254608(&q->arg[5], argPtr, 0x50);
}

//timedJiggySpawn
void func_80325098(f32 time, u32 jiggyId, f32 *position){
    DelayedJiggyInfo jiggyInfo;
    jiggyInfo.id = jiggyId;
    jiggyInfo.pos[0] = position[0];
    jiggyInfo.pos[1] = position[1];
    jiggyInfo.pos[2] = position[2];

    func_80325048(time, __spawnjiggy, &jiggyInfo);
}

//timerFuncQueue_Empty
u32 func_803250DC(void){
    return !vla_size(D_80383380.ptr);
}

//timedFuncQueue_Flush
void func_80325104(void){
    TimedFunction *iPtr;
    TimedFunction iFunc;

    while(vla_size(D_80383380.ptr) > 0){
        iPtr = vla_getBegin(D_80383380.ptr);
        func_80254608(&iFunc, iPtr, sizeof(TimedFunction));
        vla_remove(D_80383380.ptr, 0);
        __timedFunc_execute(&iFunc);
    }
}

//timedFuncQueue_Free
void func_8032517C(void){
    vla_free(D_80383380.ptr);
}

//timedFuncQueue_Init
void func_803251A0(void){
    D_80383380.ptr = vla_new(0x70, 0x10);
    D_80383380.time = 0.0f;
}

//timedFuncQueue_update
void func_803251D4(void){
    TimedFunction *iPtr;
    TimedFunction iFunc;

    if(vla_size(D_80383380.ptr) == 0)
        return;

    D_80383380.time += func_8033DD9C();

    while(vla_size(D_80383380.ptr) > 0){
        iPtr = vla_getBegin(D_80383380.ptr);
        if(D_80383380.time < iPtr->time)
            break;
        func_80254608(&iFunc, iPtr, sizeof(TimedFunction));
        vla_remove(D_80383380.ptr, 0);
        __timedFunc_execute(&iFunc);
    }
}

void func_80325288(void){
    D_80383380.ptr = vla_802ED9E0(D_80383380.ptr);
}

void func_803252B0(u32 arg0){
    mapSpecificFlags_set(arg0, 1);
}

void func_803252D0(f32 time, u32 arg0){
    func_80324EE4(time, func_803252B0, arg0);
}