#include <ddverify/ddverify.h>
#include "cm206.c"

int main() {
    _ddv_module_init = __cm206_init;
    _ddv_module_exit = cm206_exit;
    call_ddv();

    return 0;
}
