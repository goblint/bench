#include <ddverify/ddverify.h>
#include "aztcd.c"

int main() {
    _ddv_module_init = aztcd_init;
    _ddv_module_exit = aztcd_exit;
    call_ddv();

    return 0;
}
