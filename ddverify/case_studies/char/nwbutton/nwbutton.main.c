#include <ddverify/ddverify.h>
#include "nwbutton.c"

int main() {
    _ddv_module_init = nwbutton_init;
    _ddv_module_exit = nwbutton_exit;
    call_ddv();

    return 0;
}
