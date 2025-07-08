#include <ddverify/ddverify.h>
#include "w83977f_wdt.c"

int main() {
    _ddv_module_init = w83977f_wdt_init;
    _ddv_module_exit = w83977f_wdt_exit;
    call_ddv();

    return 0;
}
