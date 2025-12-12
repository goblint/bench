#include <ddverify/ddverify.h>
#include "cdu31a.c"

int main() {
    _ddv_module_init = cdu31a_init;
    _ddv_module_exit = cdu31a_exit;
    call_ddv();

    return 0;
}
