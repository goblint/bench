#include <ddverify/ddverify.h>
#include "ib700wdt.c"

int main() {
    _ddv_module_init = ibwdt_init;
    _ddv_module_exit = ibwdt_exit;
    call_ddv();

    return 0;
}
