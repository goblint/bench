#include <ddverify/ddverify.h>
#include "mixcomwd.c"

int main() {
    _ddv_module_init = mixcomwd_init;
    _ddv_module_exit = mixcomwd_exit;
    call_ddv();

    return 0;
}
