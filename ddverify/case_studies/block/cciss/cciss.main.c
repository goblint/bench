#include <ddverify/ddverify.h>
#include "cciss.c"

int main() {
    _ddv_module_init = cciss_init;
    _ddv_module_exit = cciss_cleanup;
    call_ddv();

    return 0;
}
