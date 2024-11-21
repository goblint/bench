#include <ddverify/ddverify.h>
#include "generic_nvram.c"

int main() {
    _ddv_module_init = nvram_init;
    _ddv_module_exit = nvram_cleanup;
    call_ddv();

    return 0;
}
