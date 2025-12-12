#include <ddverify/ddverify.h>
#include "sbc60xxwdt.c"

int main() {
    _ddv_module_init = sbc60xxwdt_init;
    _ddv_module_exit = sbc60xxwdt_unload;
    call_ddv();

    return 0;
}
