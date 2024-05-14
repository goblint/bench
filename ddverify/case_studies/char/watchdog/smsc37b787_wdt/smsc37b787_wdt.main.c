#include <ddverify/ddverify.h>
#include "smsc37b787_wdt.c"

int main() {
    _ddv_module_init = wb_smsc_wdt_init;
    _ddv_module_exit = wb_smsc_wdt_exit;
    call_ddv();

    return 0;
}
