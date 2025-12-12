#include <ddverify/ddverify.h>
#include "ds1286.c"

int main() {
    _ddv_module_init = ds1286_init;
    _ddv_module_exit = ds1286_exit;
    call_ddv();

    return 0;
}
