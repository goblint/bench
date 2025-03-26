#include <ddverify/ddverify.h>
#include "pcwd_pci.c"

int main() {
    _ddv_module_init = pcipcwd_init_module;
    _ddv_module_exit = pcipcwd_cleanup_module;
    call_ddv();

    return 0;
}
