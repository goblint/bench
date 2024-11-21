#include <ddverify/ddverify.h>
#include "i8xx_tco.c"

int main() {
    _ddv_module_init = watchdog_init;
    _ddv_module_exit = watchdog_cleanup;
    call_ddv();

    return 0;
}
