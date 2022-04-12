#include <ddverify/ddverify.h>
#include "cpqarray.c"

int main() {
    _ddv_module_init = cpqarray_init;
    _ddv_module_exit = cpqarray_exit;
    call_ddv();

    return 0;
}
