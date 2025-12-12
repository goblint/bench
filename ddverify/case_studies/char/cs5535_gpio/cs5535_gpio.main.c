#include <ddverify/ddverify.h>
#include "cs5535_gpio.c"

int main() {
    _ddv_module_init = cs5535_gpio_init;
    _ddv_module_exit = cs5535_gpio_cleanup;
    call_ddv();

    return 0;
}
