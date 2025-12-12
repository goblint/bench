#include <ddverify/ddverify.h>
#include "nbd.c"

int main() {
    _ddv_module_init = nbd_init;
    _ddv_module_exit = nbd_cleanup;
    call_ddv();

    return 0;
}
