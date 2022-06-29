#include "mgos.h"
enum indicate
{
  A1 = 26,
  B1 = 27,
  C1 = 19,
  D1 = 22,
  E1 = 21,
  F1 = 33,
  G1 = 32,
  A2 = 13,
  B2 = 23,
  C2 = 4,
  D2 = 2,
  E2 = 15,
  F2 = 12,
  G2 = 14,
  BP1 = 18,
};
void call_back(void *arg)
{
  static bool dir = 0;
  uint16_t *arg_isr = (uint16_t *)arg;
  switch ((*arg_isr) % 10)
  {
  case 0:
    mgos_gpio_write(A2, dir);
    mgos_gpio_write(B2, dir);
    mgos_gpio_write(C2, dir);
    mgos_gpio_write(D2, dir);
    mgos_gpio_write(E2, dir);
    mgos_gpio_write(F2, dir);
    mgos_gpio_write(G2, !dir);
    break;
  case 1:
    mgos_gpio_write(A2, !dir);
    mgos_gpio_write(B2, dir);
    mgos_gpio_write(C2, dir);
    mgos_gpio_write(D2, !dir);
    mgos_gpio_write(E2, !dir);
    mgos_gpio_write(F2, !dir);
    mgos_gpio_write(G2, !dir);
    break;
  case 2:
    mgos_gpio_write(A2, dir);
    mgos_gpio_write(B2, dir);
    mgos_gpio_write(C2, !dir);
    mgos_gpio_write(D2, dir);
    mgos_gpio_write(E2, dir);
    mgos_gpio_write(F2, !dir);
    mgos_gpio_write(G2, dir);
    break;
  case 3:
    mgos_gpio_write(A2, dir);
    mgos_gpio_write(B2, dir);
    mgos_gpio_write(C2, dir);
    mgos_gpio_write(D2, dir);
    mgos_gpio_write(E2, !dir);
    mgos_gpio_write(F2, !dir);
    mgos_gpio_write(G2, dir);
    break;
  case 4:
    mgos_gpio_write(A2, !dir);
    mgos_gpio_write(B2, dir);
    mgos_gpio_write(C2, dir);
    mgos_gpio_write(D2, !dir);
    mgos_gpio_write(E2, !dir);
    mgos_gpio_write(F2, dir);
    mgos_gpio_write(G2, dir);
    break;
  case 5:
    mgos_gpio_write(A2, dir);
    mgos_gpio_write(B2, !dir);
    mgos_gpio_write(C2, dir);
    mgos_gpio_write(D2, dir);
    mgos_gpio_write(E2, !dir);
    mgos_gpio_write(F2, dir);
    mgos_gpio_write(G2, dir);
    break;
  case 6:
    mgos_gpio_write(A2, dir);
    mgos_gpio_write(B2, !dir);
    mgos_gpio_write(C2, dir);
    mgos_gpio_write(D2, dir);
    mgos_gpio_write(E2, dir);
    mgos_gpio_write(F2, dir);
    mgos_gpio_write(G2, dir);
    break;
  case 7:
    mgos_gpio_write(A2, dir);
    mgos_gpio_write(B2, dir);
    mgos_gpio_write(C2, dir);
    mgos_gpio_write(D2, !dir);
    mgos_gpio_write(E2, !dir);
    mgos_gpio_write(F2, !dir);
    mgos_gpio_write(G2, !dir);
    break;
  case 8:
    mgos_gpio_write(A2, dir);
    mgos_gpio_write(B2, dir);
    mgos_gpio_write(C2, dir);
    mgos_gpio_write(D2, dir);
    mgos_gpio_write(E2, dir);
    mgos_gpio_write(F2, dir);
    mgos_gpio_write(G2, dir);
    break;
  case 9:
    mgos_gpio_write(A2, dir);
    mgos_gpio_write(B2, dir);
    mgos_gpio_write(C2, dir);
    mgos_gpio_write(F2, dir);
    mgos_gpio_write(G2, dir);
    mgos_gpio_write(D2, dir);
    mgos_gpio_write(E2, !dir);
    break;
  default:
    mgos_gpio_write(A2, dir);
    mgos_gpio_write(B2, !dir);
    mgos_gpio_write(C2, !dir);
    mgos_gpio_write(D2, !dir);
    mgos_gpio_write(E2, dir);
    mgos_gpio_write(F2, dir);
    mgos_gpio_write(G2, dir);
    break;
  }
  switch ((*arg_isr) / 10)
  {
  case 0:
    mgos_gpio_write(A1, dir);
    mgos_gpio_write(B1, dir);
    mgos_gpio_write(C1, dir);
    mgos_gpio_write(D1, dir);
    mgos_gpio_write(E1, dir);
    mgos_gpio_write(F1, dir);
    mgos_gpio_write(G1, !dir);
    break;
  case 1:
    mgos_gpio_write(A1, !dir);
    mgos_gpio_write(B1, dir);
    mgos_gpio_write(C1, dir);
    mgos_gpio_write(D1, !dir);
    mgos_gpio_write(E1, !dir);
    mgos_gpio_write(F1, !dir);
    mgos_gpio_write(G1, !dir);
    break;
  case 2:
    mgos_gpio_write(A1, dir);
    mgos_gpio_write(B1, dir);
    mgos_gpio_write(C1, !dir);
    mgos_gpio_write(D1, dir);
    mgos_gpio_write(E1, dir);
    mgos_gpio_write(F1, !dir);
    mgos_gpio_write(G1, dir);
    break;
  case 3:
    mgos_gpio_write(A1, dir);
    mgos_gpio_write(B1, dir);
    mgos_gpio_write(C1, dir);
    mgos_gpio_write(D1, dir);
    mgos_gpio_write(E1, !dir);
    mgos_gpio_write(F1, !dir);
    mgos_gpio_write(G1, dir);
    break;
  case 4:
    mgos_gpio_write(A1, !dir);
    mgos_gpio_write(B1, dir);
    mgos_gpio_write(C1, dir);
    mgos_gpio_write(D1, !dir);
    mgos_gpio_write(E1, !dir);
    mgos_gpio_write(F1, dir);
    mgos_gpio_write(G1, dir);
    break;
  case 5:
    mgos_gpio_write(A1, dir);
    mgos_gpio_write(B1, !dir);
    mgos_gpio_write(C1, dir);
    mgos_gpio_write(D1, dir);
    mgos_gpio_write(E1, !dir);
    mgos_gpio_write(F1, dir);
    mgos_gpio_write(G1, dir);
    break;
  case 6:
    mgos_gpio_write(A1, dir);
    mgos_gpio_write(B1, !dir);
    mgos_gpio_write(C1, dir);
    mgos_gpio_write(D1, dir);
    mgos_gpio_write(E1, dir);
    mgos_gpio_write(F1, dir);
    mgos_gpio_write(G1, dir);
    break;
  case 7:
    mgos_gpio_write(A1, dir);
    mgos_gpio_write(B1, dir);
    mgos_gpio_write(C1, dir);
    mgos_gpio_write(D1, !dir);
    mgos_gpio_write(E1, !dir);
    mgos_gpio_write(F1, !dir);
    mgos_gpio_write(G1, !dir);
    break;
  case 8:
    mgos_gpio_write(A1, dir);
    mgos_gpio_write(B1, dir);
    mgos_gpio_write(C1, dir);
    mgos_gpio_write(D1, dir);
    mgos_gpio_write(E1, dir);
    mgos_gpio_write(F1, dir);
    mgos_gpio_write(G1, dir);
    break;
  case 9:
    mgos_gpio_write(A1, dir);
    mgos_gpio_write(B1, dir);
    mgos_gpio_write(C1, dir);
    mgos_gpio_write(F1, dir);
    mgos_gpio_write(G1, dir);
    mgos_gpio_write(D1, dir);
    mgos_gpio_write(E1, !dir);
    break;
  default:
    mgos_gpio_write(A1, dir);
    mgos_gpio_write(B1, !dir);
    mgos_gpio_write(C1, !dir);
    mgos_gpio_write(D1, !dir);
    mgos_gpio_write(E1, dir);
    mgos_gpio_write(F1, dir);
    mgos_gpio_write(G1, dir);
    break;
  }
  mgos_gpio_write(BP1, !dir);
  dir = !dir;
}
void hw_lcd(int s)
{
  static mgos_timer_id id2 = 0;
  static uint16_t arg_ff[3];
  arg_ff[0] = (uint16_t)s;
  if (id2 != 0)
  {
    mgos_clear_timer(id2);
  }
  else
  {
    mgos_gpio_setup_output(A1, 0);
    mgos_gpio_setup_output(B1, 0);
    mgos_gpio_setup_output(C1, 0);
    mgos_gpio_setup_output(D1, 0);
    mgos_gpio_setup_output(E1, 0);
    mgos_gpio_setup_output(F1, 0);
    mgos_gpio_setup_output(G1, 0);
    mgos_gpio_setup_output(BP1, 0);
    mgos_gpio_setup_output(A2, 0);
    mgos_gpio_setup_output(B2, 0);
    mgos_gpio_setup_output(C2, 0);
    mgos_gpio_setup_output(D2, 0);
    mgos_gpio_setup_output(E2, 0);
    mgos_gpio_setup_output(F2, 0);
    mgos_gpio_setup_output(G2, 0);
  }
  id2 = mgos_set_hw_timer(10000, MGOS_TIMER_REPEAT, call_back, (void *)arg_ff);
}