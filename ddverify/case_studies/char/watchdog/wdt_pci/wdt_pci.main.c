#include <ddverify/ddverify.h>
#include "wdt_pci.c"

int main() {
    _ddv_module_init = wdtpci_init;
    _ddv_module_exit = wdtpci_cleanup;
    call_ddv();

    return 0;
}
