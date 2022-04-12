#include <ddverify/ddverify.h>
#include "genrtc.c"

int main() {
    _ddv_module_init = rtc_generic_init;
    _ddv_module_exit = rtc_generic_exit;
    call_ddv();

    return 0;
}
