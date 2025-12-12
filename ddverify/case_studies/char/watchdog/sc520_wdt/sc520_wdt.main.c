#include <ddverify/ddverify.h>
#include "sc520_wdt.c"

int main() {
    _ddv_module_init = sc520_wdt_init;
    _ddv_module_exit = sc520_wdt_unload;
    call_ddv();

    return 0;
}
