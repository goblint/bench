#include <ddverify/ddverify.h>
#include "toshiba.c"

int main() {
    _ddv_module_init = toshiba_init;
    _ddv_module_exit = toshiba_exit;
    call_ddv();

    return 0;
}
