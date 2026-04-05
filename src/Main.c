#if defined __linux__
#include "/home/codeleaded/System/Static/Library/HSplitter.h"
#elif defined _WINE
#include "/home/codeleaded/System/Static/Library/HSplitter.h"
#elif defined _WIN32
#include "F:/home/codeleaded/System/Static/Library/HSplitter.h"
#endif

int main(int argc,const char *argv[]){
    HSplitter hs = HSplitter_New();
    
    HSplitter_Load_H(&hs,"./code/Fixed.h");
    HSplitter_Save_H(&hs,0U,"./code/Fixed2.h");
    
    //HSplitter_Load_H(&hs,"./code/Test.h");
    //HSplitter_Save_CH(&hs,"./inc","./lib");

    HSplitter_Print(&hs);
    HSplitter_Free(&hs);
    return 0;
}