/**
 * Helper functions for processing double values.
 *
 * @author Oliver Krauss @date 21 Aug 2019
 */
#include <stdio.h>
#include <assert.h>
#include <stdint.h>

typedef union
{
    double value;
    struct
    {
        uint32_t lsw;
        uint32_t msw;
    } parts;
    uint64_t word;
} ieee_double_shape_type;

double read_double(const char* text){
    printf("Recompile worked");
    ieee_double_shape_type ew_u;
    const int check = sscanf(text,"%x,%x",&ew_u.parts.msw,&ew_u.parts.lsw);
    assert(check==2);
    return ew_u.value;
}

void print_double(const double x){
    ieee_double_shape_type ew_u;
    ew_u.value = x;
    printf("%g 0x%08x,%08x",x,ew_u.parts.msw,ew_u.parts.lsw);
}

double tweak_double(const double x, const int epsilon){
    ieee_double_shape_type ew_u;
    ew_u.value = x;
    long unsigned int temp = ew_u.parts.lsw + epsilon;
    if(temp > 0xffffffff) {
        fprintf(stderr,"tweak_double(%g,%d) overflowed lsw 0x%lx\n",x,epsilon,temp);}
    ew_u.parts.lsw = temp;
    return ew_u.value;
}