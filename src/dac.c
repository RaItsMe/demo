#include <driver/dac.h>
void dac_ch1_enable(void)
{
  dac_output_enable(DAC_CHANNEL_1);
}
void dac_ch1_voltage(int x)
{
  dac_output_voltage(DAC_CHANNEL_1, (uint8_t)x);
}