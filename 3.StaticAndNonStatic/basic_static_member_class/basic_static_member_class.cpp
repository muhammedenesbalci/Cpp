#include "basic_static_member_class.h" 

int GfG::static_member_initialized = 10; // Ortak değişkenin bildirimi
int GfG::static_member_not_initialized;

// Consturctor
GfG::GfG(){
        // Do nothing
    }