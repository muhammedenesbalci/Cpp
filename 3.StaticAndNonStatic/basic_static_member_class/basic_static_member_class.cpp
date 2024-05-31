#include "basic_static_member_class.h" 

int GfG::static_member_initialized = 10; // Ortak değişkenin bildirimi
int GfG::static_member_not_initialized; //bu hjata vermez çünkü 0 dır defaultu

// Consturctor
GfG::GfG(){
        // Do nothing
    }