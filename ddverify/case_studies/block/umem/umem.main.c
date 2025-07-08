#include <ddverify/ddverify.h>
#include "umem.c"

int main() {
    _ddv_module_init = mm_init;
    _ddv_module_exit = mm_cleanup;
    call_ddv();

    return 0;
}
