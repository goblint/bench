#include <ddverify/ddverify.h>
#include "floppy.c"

int main() {
    _ddv_module_init = floppy_init;
    _ddv_module_exit = cleanup_module;
    call_ddv();

    return 0;
}
