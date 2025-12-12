#include <ddverify/ddverify.h>
#include "wdt.c"

int main() {
    _ddv_module_init = wdt_init;
    _ddv_module_exit = wdt_exit;
    call_ddv();

    return 0;
}
