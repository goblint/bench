#include <ddverify/ddverify.h>
#include "w83877f_wdt.c"

int main() {
    _ddv_module_init = w83877f_wdt_init;
    _ddv_module_exit = w83877f_wdt_unload;
    call_ddv();

    return 0;
}
