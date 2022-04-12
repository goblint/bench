#include <ddverify/ddverify.h>
#include "sc1200wdt.c"

int main() {
    _ddv_module_init = sc1200wdt_init;
    _ddv_module_exit = sc1200wdt_exit;
    call_ddv();

    return 0;
}
