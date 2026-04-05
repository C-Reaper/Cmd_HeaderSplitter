#ifndef FIXED_H
#define FIXED_H

// Needed for Parse
#include "ConstParser.h"

/*

Fixed Points Numbers:
Bits: 16,32,64

*/

typedef struct Fixed16 {
    short v;
    int dp;
} Fixed16;

typedef struct Fixed32 {
    int v;
    int dp;
} Fixed32;

typedef struct Fixed64 {
    long long v;
    int dp;
} Fixed64;

Fixed16 Fixed16_ByFixed32(Fixed32 in){
    Fixed16 f;
    f.v = in.v;
    f.dp = in.dp;
    return f;
}
Fixed16 Fixed16_ByFixed64(Fixed64 in){
    Fixed16 f;
    f.v = in.v;
    f.dp = in.dp;
    return f;
}
Fixed16 Fixed16_ByDouble(int dp,double d){
    Fixed16 f;
    f.v = (short)(d * (double)(1 << dp) + (d>=0 ? 0.5 : -0.5));
    f.dp = dp;
    return f;
}
double Fixed16_ToDouble(Fixed16 f){
    return (double)(f.v) / (double)(1 << f.dp);
}
Fixed16 Fixed16_ByDp(Fixed16 in,int dp){
    Fixed16 f;
    int D = dp - in.dp;
    f.v = D>0? in.v<<D : in.v>>-D;
    f.dp = dp;
    return f;
}
Fixed16 Fixed16_Add(Fixed16 f1,Fixed16 f2){
    Fixed16 f;
    f.v = f1.v + Fixed16_ByDp(f2,f1.dp).v;
    f.dp = f1.dp;
    return f;
}
Fixed16 Fixed16_Sub(Fixed16 f1,Fixed16 f2){
    Fixed16 f;
    f.v = f1.v - Fixed16_ByDp(f2,f1.dp).v;
    f.dp = f1.dp;
    return f;
}
Fixed16 Fixed16_Mul(Fixed16 f1,Fixed16 f2){
    Fixed16 f;
    f.v = ((int)f1.v * (int)Fixed16_ByDp(f2,f1.dp).v) >> f1.dp;
    f.dp = f1.dp;
    return f;
}
Fixed16 Fixed16_Div(Fixed16 f1,Fixed16 f2){
    Fixed16 f;
    if(f1.v!=0){
        f.v = ((int)f1.v << f1.dp) / (int)Fixed16_ByDp(f2,f1.dp).v;
        f.dp = f1.dp;
    }else{
        f.v = 0;
        f.dp = f1.dp;
    }
    return f;
}

Fixed32 Fixed32_ByFixed16(Fixed16 in){
    Fixed32 f;
    f.v = in.v;
    f.dp = in.dp;
    return f;
}
Fixed32 Fixed32_ByFixed64(Fixed64 in){
    Fixed32 f;
    f.v = in.v;
    f.dp = in.dp;
    return f;
}
Fixed32 Fixed32_ByDouble(int dp,double d){
    Fixed32 f;
    f.v = (int)(d * (double)(1 << dp) + (d>=0 ? 0.5 : -0.5));
    f.dp = dp;
    return f;
}
double Fixed32_ToDouble(Fixed32 f){
    return (double)(f.v) / (double)(1 << f.dp);
}
Fixed32 Fixed32_ByDp(Fixed32 in,int dp){
    Fixed32 f;
    int D = dp - in.dp;
    f.v = D>0? in.v<<D : in.v>>-D;
    f.dp = dp;
    return f;
}
Fixed32 Fixed32_Add(Fixed32 f1,Fixed32 f2){
    Fixed32 f;
    f.v = f1.v + Fixed32_ByDp(f2,f1.dp).v;
    f.dp = f1.dp;
    return f;
}
Fixed32 Fixed32_Sub(Fixed32 f1,Fixed32 f2){
    Fixed32 f;
    f.v = f1.v - Fixed32_ByDp(f2,f1.dp).v;
    f.dp = f1.dp;
    return f;
}
Fixed32 Fixed32_Mul(Fixed32 f1,Fixed32 f2){
    Fixed32 f;
    f.v = ((long long)f1.v * (long long)Fixed32_ByDp(f2,f1.dp).v) >> f1.dp;
    f.dp = f1.dp;
    return f;
}
Fixed32 Fixed32_Div(Fixed32 f1,Fixed32 f2){
    Fixed32 f;
    if(f1.v!=0){
        f.v = ((long long)f1.v << f1.dp) / (long long)Fixed32_ByDp(f2,f1.dp).v;
        f.dp = f1.dp;
    }else{
        f.v = 0;
        f.dp = f1.dp;
    }
    return f;
}

Fixed64 Fixed64_ByFixed16(Fixed16 in){
    Fixed64 f;
    f.v = in.v;
    f.dp = in.dp;
    return f;
}
Fixed64 Fixed64_ByFixed32(Fixed32 in){
    Fixed64 f;
    f.v = in.v;
    f.dp = in.dp;
    return f;
}
Fixed64 Fixed64_ByDouble(int dp,double d){
    Fixed64 f;
    f.v = (long long)(d * (double)(1 << dp) + (d>=0 ? 0.5 : -0.5));
    f.dp = dp;
    return f;
}
double Fixed64_ToDouble(Fixed64 f){
    return (double)(f.v) / (double)(1 << f.dp);
}
Fixed64 Fixed64_ByDp(Fixed64 in,int dp){
    Fixed64 f;
    int D = dp - in.dp;
    f.v = D>0? in.v<<D : in.v>>-D;
    f.dp = dp;
    return f;
}
Fixed64 Fixed64_Add(Fixed64 f1,Fixed64 f2){
    Fixed64 f;
    f.v = f1.v + Fixed64_ByDp(f2,f1.dp).v;
    f.dp = f1.dp;
    return f;
}
Fixed64 Fixed64_Sub(Fixed64 f1,Fixed64 f2){
    Fixed64 f;
    f.v = f1.v - Fixed64_ByDp(f2,f1.dp).v;
    f.dp = f1.dp;
    return f;
}
Fixed64 Fixed64_Mul(Fixed64 f1,Fixed64 f2){
    Fixed64 f;
    f.v = ((long long)f1.v * (long long)Fixed64_ByDp(f2,f1.dp).v) >> f1.dp;
    f.dp = f1.dp;
    return f;
}
Fixed64 Fixed64_Div(Fixed64 f1,Fixed64 f2){
    Fixed64 f;
    if(f1.v!=0){
        f.v = ((long long)f1.v << f1.dp) / (long long)Fixed64_ByDp(f2,f1.dp).v;
        f.dp = f1.dp;
    }else{
        f.v = 0;
        f.dp = f1.dp;
    }
    return f;
}


char* Fixed16_Get(Fixed16 n){
    return (char*)Double_Get(Fixed16_ToDouble(n),n.dp >> 2);
}
Fixed16 Fixed16_Parse(int dp,char* cstr,char AllowSigned){
    return Fixed16_ByDouble(dp,Double_Parse((i8*)cstr,AllowSigned));
}

char* Fixed32_Get(Fixed32 n){
    return (char*)Double_Get(Fixed32_ToDouble(n),n.dp >> 2);
}
Fixed32 Fixed32_Parse(int dp,char* cstr,char AllowSigned){
    return Fixed32_ByDouble(dp,Double_Parse((i8*)cstr,AllowSigned));
}

char* Fixed64_Get(Fixed64 n){
    return (char*)Double_Get(Fixed64_ToDouble(n),n.dp >> 2);
}
Fixed64 Fixed64_Parse(int dp,char* cstr,char AllowSigned){
    return Fixed64_ByDouble(dp,Double_Parse((i8*)cstr,AllowSigned));
}

#endif // !FIXED_H