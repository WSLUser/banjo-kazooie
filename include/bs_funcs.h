#ifndef __BS_FUNCS__
#define __BS_FUNCS__

//interrupt
void func_802B5350(void);
void func_80296608(void);
void func_80296590(void); //bsow

//bsidle
void bsidle_init(void); 
void bsidle_update(void);
void bsidle_end(void);
//bswalkslow
void func_802B7260(void);
void func_802B735C(void);
//bswalk
void func_802B74F8(void);
void func_802B7614(void);
//bswalkfast
void func_802B77B8(void);
void func_802B796C(void);
void func_802B7B88(void);
//bsjump
void func_802B112C(void);
void func_802B1354(void);
void func_802B1614(void);
//bspunch
void func_802AB28C(void);
void func_802AB2FC(void);
void func_802AB58C(void);
//bscrouch
void func_802AD7EC(void);
void func_802AD970(void);
void func_802ADCCC(void);
//bsbtrotjump
void func_802A9328(void);
void func_802A9478(void);
void func_802A9864(void);
//bsskid
void func_802B6760(void);
void func_802B6850(void);
void func_802B69F0(void);
//0xd
void func_802B63F8(void);
void func_802B64D0(void);
void func_802B6500(void);
//bsow
void func_802B1FD8(void);
void func_802B209C(void);
void func_802B2184(void);
//bsbuster
void func_8029FC64(void);
void func_8029FD8C(void);
void func_802A0278(void);
//bsflap
void func_802A2690(void);
void func_802A2A1C(void);
void func_802A2D10(void);
//bsbpeck
void func_802A651C(void);
void func_802A66F0(void);
void func_802A6928(void);
//bsbflip
void func_802A2E6C(void);
void func_802A2F48(void);
void func_802A330C(void);
//bsbbarge
void bsbarge_init(void);
void bsbarge_update(void);
void bsbarge_end(void);
//bsbtrot_enter
void func_802A8E3C(void);
void func_802A8EA4(void);
void func_802A8F34(void);
//bsbtrot_idle
void func_802A8F60(void);
void func_802A8FB0(void);
void func_802A9010(void);
//bsbtrot_walk
void func_802A90F8(void);
void func_802A914C(void);
void func_802A9300(void);
//bsbtrot_exit
void func_802A988C(void);
void func_802A98C8(void);
void func_802A9904(void);
//bsfly_knockback
void func_802A4D90(void);
void func_802A4EC8(void);
void func_802A4F44(void);
//BS_WONDERWING_ENTER
void func_802AA630(void);
void func_802AA6DC(void);
void func_802AA728(void);
//BS_WONDERWING_IDLE
void func_802AA754(void);
void func_802AA798(void);
void func_802AA7FC(void);
//BS_WONDERWING_WALK,
void func_802AA81C(void);
void func_802AA87C(void);
void func_802AA95C(void);
void func_80296608(void);
//BS_WONDERWING_JUMP
void func_802AA97C(void);
void func_802AAAC4(void);
void func_802AAC1C(void);
//BS_WONDERWING_EXIT
void func_802AAC44(void);
void func_802AACF0(void);
void func_802AAD2C(void);
//BS_EGG_HEAD
void func_802A23E0(void);
void func_802A2468(void);
void func_802A2650(void);
//BS_EGG_ASS
void func_802A2170(void);
void func_802A21F8(void);
void func_802A23AC(void);
//BS_CREEP(void);
void func_802B6FC8(void);
void func_802B70C4(void);
//BS_LANDING(void);
void func_802B5278(void);
void func_802B52B0(void);
//BS_BSHOCK_CHARGE(void);
void func_802A69B0(void);
void func_802A6B40(void);
void func_802A6DF4(void);
//BS_BSHOCK_JUMP(void);
void func_802A6E60(void);
void func_802A6FC8(void);
void func_802A70D4(void);
//BS_FLY_ENTER(void);
void func_802A3820(void);
void func_802A38DC(void);
void func_802A3994(void);
void func_802A505C(void);
//BS_FLY(void);
void func_802A39BC(void);
void func_802A3AA8(void);
void func_802A3F70(void);
//BS_LONGLEG_ENTER(void);
void func_802A55C0(void);
void func_802A5684(void);
void func_802A5718(void);
//BS_LONGLEG_IDLE(void);
void func_802A5744(void);
void func_802A5798(void);
void func_802A587C(void);
//BS_LONGLEG_WALK(void);
void func_802A589C(void);
void func_802A592C(void);
void func_802A5A90(void);
//BS_LONGLEG_JUMP(void);
void func_802A5D20(void);
void func_802A5E70(void);
void func_802A611C(void);
//BS_LONGLEG_EXIT(void);
void func_802A5BB4(void);
void func_802A5C34(void);
void func_802A5CF4(void);
//BS_BOMB(void);
void func_802A3F9C(void);
void func_802A411C(void);
void func_802A4404(void);
//BS_DIVE_IDLE(void);
void func_802A762C(void);
void func_802A7674(void);
void func_802A7718(void);
//BS_DIVE_B(void);
void func_802A7738(void);
void func_802A7838(void);
void func_802A7A2C(void);
//BS_SWIM_IDLE,  
void func_802B5774(void);
void func_802B5950(void);
void func_802B5AF8(void);
//BS_SWIM(void);
void func_802B5B18(void);
void func_802B5C40(void);
void func_802B5E10(void);
//BS_FALL(void);
void func_802B1660(void);
void func_802B1750(void);
void func_802B1920(void);
//BS_DIVE_ENTER
void func_802A7DAC(void);
void func_802A7E2C(void);
void func_802A7F4C(void);
//BS_ROLL(void);
void func_802B6A4C(void);
void func_802B6B70(void);
void func_802B6CD4(void);
//BS_SLIDE
void func_802B4250(void);
void func_802B43C0(void);
void func_802B452C(void);
//0x33(void);
void func_802B9ACC(void);
void func_802B9B14(void);
void func_802B9AAC(void);
void func_802B9D00(void);
//BS_JIG_NOTEDOOR(void);
void func_802B0F88(void);
void func_802B1090(void);
void func_802B0EF0(void);
//BS_ANT_IDLE
void func_8029E618(void);
void func_8029E6B0(void);
void func_8029E73C(void);
//BS_ANT_WALK
void func_8029E764(void);
void func_8029E7D4(void);
void func_8029E8A0(void);
//BS_ANT_JUMP
void func_8029E8C8(void);
void func_8029EA04(void);
void func_8029EB94(void);
//BS_DIVE_A
void func_802A7A54(void);
void func_802A7AB0(void);
void func_802A7BA8(void);
//BS_CARRY_IDLE(void);
void func_802AAF24(void);
void func_802AAFD0(void);
void func_802AB018(void);
void func_802AB1A4(void);
//BS_CARRY_WALK(void);
void func_802AB038(void);
void func_802AB0DC(void);
void func_802AB164(void);
//0x3C (void);
void func_802B6130(void);
void func_802B61E0(void);
void func_802B6218(void);
void func_802B6220(void);
//BS_FALL_TUMBLING(void);
void func_802B1DD0(void);
void func_802B1E80(void);
void func_802B1F6C(void);
//BS_ANT_FALL(void);
void func_8029EBBC(void);
void func_8029EC5C(void);
void func_8029ED3C(void);
//BS_ANT_OW
void func_8029EFA8(void);
void func_8029EFC8(void);
void func_8029EFE8(void);
    //0x3F
void func_802B1BF4(void);
void func_802B1CF8(void);
void func_802B1DA4(void);
    //0x40
void func_802B2BF0(void);
void func_802B2C58(void);
void func_802B2D50(void);
    //BS_DIE
void func_802ADEA0(void);
void func_802AE058(void);
void func_802AE30C(void);
    //BS_DINGPOT
void func_802A5120(void);
void func_802A5190(void);
void func_802A51C0(void);
    //BS_ANT_DIE
void func_8029F068(void);
void func_8029F218(void);
void func_8029F348(void);
//BS_JIG_JIGGY
void func_802B0A78(void);
void func_802B0BE4(void);
void func_802B0D1C(void);
void func_802B0EBC(void);
//BS_BTROT_SLIDE
void func_802A9924(void);
void func_802A9A34(void);
void func_802A9B78(void);
//0x46
void func_802A2098(void);
void func_802A2130(void);
void func_802A2054(void);
//BS_PUMPKIN_IDLE
void func_802B2384(void);
void func_802B242C(void);
void func_802B24AC(void);
//BS_PUMPKIN_WALK
void func_802B24D4(void);
void func_802B2580(void);
void func_802B2610(void);
//BS_PUMPKIN_JUMP
void func_802B2638(void);
void func_802B2750(void);
void func_802B2990(void);
//BS_PUMPKIN_FALL
void func_802B29C0(void);
void func_802B2A5C(void);
void func_802B2BD0(void);
//BS_LANDING_IN_WATER
void func_802A846C(void);
void func_802A85EC(void);
void func_802A872C(void);
//BS_PUMPKIN_OW
void func_802B2FDC(void);
void func_802B2FFC(void);
void func_802B301C(void);
//BS_PUMPKIN_DIE
void func_802B309C(void);
void func_802B3240(void);
void func_802B3448(void);
//BS_CLIMB_IDLE
void func_802AB830(void);
void func_802AB8DC(void);
void func_802ABA10(void);
void func_802ABD60(void);
//BS_CLIMB_MOVE
void func_802ABA30(void);
void func_802ABAA4(void);
void func_802ABCAC(void);
//BS_CLIMB_EXIT
void func_802B1928(void);
void func_802B1A54(void);
void func_802B1BCC(void);
//0x52
void func_802B5FD0(void);
void func_802B6064(void);
void func_802B60D0(void);
void func_802B60D8(void);
    //0x53
void func_802B6270(void);
void func_802B6314(void);
void func_802B63C8(void);
void func_80296590(void);
    //0x55
void func_802A6144(void);
void func_802A624C(void);
void func_802A6368(void);
void func_802B5350(void);
    //0x56
void func_802B3868(void);
void func_802B3954(void);
void func_802B3A20(void);
void func_80296590(void);
    //0x57
void func_802A4430(void);
void func_802A4548(void);
void func_802A4664(void);
void func_802A505C(void);
    //0x58
void func_802A4748(void);
void func_802A48B4(void);
void func_802A4A40(void);
void func_80296590(void);
    //0x59
void func_802A4CD0(void);
void func_802A4CF0(void);
void func_802A4D10(void);
void func_802A505C(void);
    //0x54
void func_802A7F6C(void);
void func_802A8098(void);
void func_802A82D4(void);
void func_80296590(void);
    //0x5B
void func_802B6540(void);
void func_802B65E0(void);
void func_802B66AC(void);
void func_802B66F8(void);
    //0x5E
void func_802AC0D4(void);
void func_802AC178(void);
void func_802AC224(void);
void func_802B5350(void);
    //0x5F
void func_802AC24C(void);
void func_802AC2BC(void);
void func_802AC380(void);
void func_802B5350(void);
    //0x60
void func_802AC3A8(void);
void func_802AC4DC(void);
void func_802AC6D0(void);
void func_802B5350(void);
    //0x61
void func_802AC6F8(void);
void func_802AC78C(void);
void func_802AC8CC(void);
void func_802B5350(void);
    //0x62
void func_802A6394(void);
void func_802A63F0(void);
void func_802A6450(void);
void func_80296608(void);
    //0x63
void func_802ACB38(void);
void func_802ACB58(void);
void func_802ACB78(void);
void func_80296590(void);
    //0x64
void func_802ACBF8(void);
void func_802ACDA0(void);
void func_802ACEFC(void);
void func_80296590(void);
    //0x67
void func_802B8284(void);
void func_802B8330(void);
void func_802B83BC(void);
void func_802B5350(void);
    //0x68
void func_802B83E4(void);
void func_802B8454(void);
void func_802B84F0(void);
void func_802B5350(void);
    //0x69
void func_802B8518(void);
void func_802B8654(void);
void func_802B8888(void);
void func_802B5350(void);
    //0x6A
void func_802B88B0(void);
void func_802B894C(void);
void func_802B8AB4(void);
void func_802B5350(void);
    //0x6B
void func_802A1F6C(void);
void func_802A1FC8(void);
void func_802A2014(void);
void func_80296608(void); 
//0x0000006C
void func_802B8C84(void);
void func_802B8CA4(void);
void func_802B8CC4(void);
void func_80296590(void);
//0x0000006D
void func_802B8D44(void);
void func_802B8F04(void);
void func_802B9010(void);
void func_80296590(void);
//0x0000006E
void func_802ACFCC(void);
void func_802AD024(void);
void func_802AD168(void);
void func_802B5350(void);
//0x0000006F
void func_802AD18C(void);
void func_802AD1D4(void);
void func_802AD288(void);
void func_802B5350(void);
//0x00000070
void func_802AD328(void);
void func_802AD3AC(void);
void func_802AD530(void);
void func_802B5350(void);
//0x00000071
void func_802A9C38(void);
void func_802A9D08(void);
void func_802AA068(void);
void func_80296608(void);
//0x00000072
void func_802B45F0(void);
void func_802B4708(void);
void func_802B4844(void);
void func_80296590(void);
//0x00000073
void func_802B3CEC(void);
void func_802B3D1C(void);
void func_802B3D6C(void);
void func_80296608(void);
//0x00000074
void func_802B3E2C(void);
void func_802B3E64(void);
void func_802B3EF4(void);
void func_80296608(void);
//0x00000075
void func_802B3D8C(void);
void func_802B3DBC(void);
void func_802B3E0C(void);
void func_80296608(void);
//0x00000076
void func_802A4F74(void);
void func_802A4FC8(void);
void func_802A503C(void);
void func_80296608(void);
//0x00000077
void func_802B5E8C(void);
void func_802B5EFC(void);
void func_802B5F38(void);
void func_80296608(void);
//0x00000078
void func_802A83C0(void);
void func_802A8410(void);
void func_802A844C(void);
void func_80296608(void);
//0x00000079
void func_802AA088(void);
void func_802AA0E8(void);
void func_802AA134(void);
void func_80296608(void);
//0x0000007A
void func_802B7BB8(void);
void func_802B7C30(void);
void func_80296608(void);
//0x0000007B
void func_802AA15C(void);
void func_802AA27C(void);
void func_802AA338(void);
void func_80296590(void);
//0x0000007C
void func_802B3FA4(void);
void func_802B4004(void);
void func_802B4038(void);
void func_802B4080(void);
//0x0000007D
void func_802B91A4(void);
void func_802B9214(void);
void func_802B92DC(void);
void func_802B98C0(void);
//0x0000007E
void func_802B9304(void);
void func_802B9440(void);
void func_802B9578(void);
void func_802B98C0(void);
//0x0000007F
void func_802A7BD0(void);
void func_802A7CA8(void);
void func_802A7D74(void);
void func_80296590(void);
//0x00000080
void func_802B978C(void);
void func_802B9830(void);
void func_802B9880(void);
void func_80296590(void);
//0x00000081
void func_802B90D0(void);
void func_802B9130(void);
void func_802B917C(void);
void func_802B98C0(void);
//0x00000082
void func_802B95A0(void);
void func_802B963C(void);
void func_802B976C(void);
void func_802B98C0(void);
//0x00000085
void func_802A1080(void);
void func_802A10D4(void);
void func_802A117C(void);
void func_802B5350(void);
//0x00000086
void func_802A11A4(void);
void func_802A1214(void);
void func_802A12D4(void);
void func_802B5350(void);
//0x00000087
void func_802A12FC(void);
void func_802A1438(void);
void func_802A163C(void);
void func_802B5350(void);
//0x00000088
void func_802A1664(void);
void func_802A170C(void);
void func_802A18C8(void);
void func_802B5350(void);
//0x00000089
void func_802A1B68(void);
void func_802A1B88(void);
void func_802A1BA8(void);
void func_802B5350(void);
//0x0000008A
void bsbeemain_die_init(void);
void func_802A1DD8(void);
void func_802A1F2C(void);
void func_80296590(void);
//0x0000008B
void func_802A0590(void);
void func_802A0630(void);
void func_802A0704(void);
void func_802B5350(void);
//0x0000008C
void bsbeefly_enter(void);
void bsbeefly_update(void);
void bsbeefly_end(void);
void func_802B5350(void);
//0x0000008D
void func_802AD56C(void);
void func_802AD5C0(void);
void func_802AD614(void);
void func_802B5350(void);
//0x0000008E
void func_8029F398(void);
void func_8029F3F4(void);
void func_8029F440(void);
void func_802B5350(void);
//0x0000008F
void func_802B34A0(void);
void func_802B34F8(void);
void func_802B353C(void);
void func_802B5350(void);
//0x00000091
void func_802A4D30(void);
void func_802A4D50(void);
void func_802A4D70(void);
void func_802A505C(void);
//0x00000092
void func_8029F468(void);
void func_8029F490(void);
void func_8029F4B0(void);
void func_802AE490(void);
//0x00000093
void func_802B3564(void);
void func_802B3584(void);
void func_802B35A4(void);
void func_802AE490(void);
//0x00000094
void func_802AD654(void);
void func_802AD674(void);
void func_802AD69C(void);
void func_802AE490(void);
//0x00000095
void func_802B9060(void);
void func_802B9088(void);
void func_802B90A8(void);
void func_802AE490(void);
//0x00000096
void func_802B5F58(void);
void func_802B5F80(void);
void func_802B5FA0(void);
void func_802AE490(void);
//0x00000097
void func_802A874C(void);
void func_802A8774(void);
void func_802A8794(void);
void func_802AE490(void);
//0x00000098
void func_802B7D4C(void);
void func_802B7DC0(void);
void func_802B7DE0(void);
void func_802AE490(void);
//0x00000099
void func_802A50B0(void);
void func_802A50D8(void);
void func_802A50F8(void);
void func_802AE490(void);
//0x0000009A
void func_802AA378(void);
void func_802AA3A8(void);
void func_802AA3D0(void);
void func_802AE490(void);
//0x0000009B
void func_802A6478(void);
void func_802A64A0(void);
void func_802A64E0(void);
void func_802AE490(void);
//0x0000009C
void func_802B990C(void);
void func_802B9934(void);
void func_802B9954(void);
void func_802AE490(void);
//0x0000009D
void func_802A0478(void);
void func_802A04A0(void);
void func_802A04C0(void);
void func_802AE490(void);
//0x0000009E
void func_802ABCCC(void);
void func_802ABD0C(void);
void func_802ABD40(void);
void func_802ABD60(void);
//0x0000009F
void func_8029F008(void);
void func_8029F028(void);
void func_8029F048(void);
void func_80296590(void);
//0x000000A0
void func_802B303C(void);
void func_802B305C(void);
void func_802B307C(void);
void func_80296590(void);
//0x000000A1
void func_802ACB98(void);
void func_802ACBB8(void);
void func_802ACBD8(void);
void func_80296590(void);
//0x000000A2
void func_802B8CE4(void);
void func_802B8D04(void);
void func_802B8D24(void);
void func_80296590(void);
//0x000000A3
void func_802A1BC8(void);
void func_802A1BE8(void);
void func_802A1C08(void);
void func_80296590(void);
//0x000000A4
void func_802AAD4C(void);
void func_802AAD6C(void);
void func_802AAD94(void);
void func_80296608(void);
//0x000000A5
void func_802AADBC(void);
void func_802AAE08(void);
void func_802AAE4C(void);
void func_80296608(void);

#endif