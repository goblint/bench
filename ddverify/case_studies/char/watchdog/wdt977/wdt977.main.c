#include <ddverify/ddverify.h>
#include "wdt977.c"

int main() {
    _ddv_module_init = wd977_init;
    _ddv_module_exit = wd977_exit;
    call_ddv();

    return 0;
}
