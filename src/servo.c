#include "mgos.h"
void cb_duty(void *arg)
{
    static uint16_t i = 0;
    uint16_t *arg_isr = (uint16_t *)arg;
    i += 10;
    if (i == arg_isr[0])
    {
        mgos_gpio_write(arg_isr[2], 0);
    }
    else if (i >= arg_isr[1])
    {
        mgos_gpio_write(arg_isr[2], 1);
        i = 0;
    }
}

void hw_timer(int duty_us, int period_us, int pin)
{
    static mgos_timer_id id1 = 0;
    static uint16_t arg_f[3];
    arg_f[0] = (uint16_t)duty_us;
    arg_f[1] = (uint16_t)period_us;
    arg_f[2] = (uint16_t)pin;
    if (id1 != 0)
    {
        mgos_clear_timer(id1);
    }
    mgos_gpio_setup_output(pin, 1);
    id1 = mgos_set_hw_timer(10, MGOS_TIMER_REPEAT, cb_duty, (void *)arg_f);
}

int deg_to_us(int deg, int min, int max, int rangeDeg)
{
    int temp = (((max - min) * deg / rangeDeg) + min);
    int l = temp % 10;
    temp = temp / 10;
    if (l >= 5)
    {
        temp = temp * 10 + 10;
    }
    else
    {
        temp = temp * 10;
    }
    return temp;
}
