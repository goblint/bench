#include <ddverify/ddverify.h>
#include "pcwd.c"

int main() {
    _ddv_module_init = pcwd_init_module;
    _ddv_module_exit = pcwd_cleanup_module;
    call_ddv();

    return 0;
}
