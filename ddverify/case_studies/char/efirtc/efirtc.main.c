#include <ddverify/ddverify.h>
#include "efirtc.c"

int main() {
    _ddv_module_init = efi_rtc_init;
    _ddv_module_exit = efi_rtc_exit;
    call_ddv();

    return 0;
}
