#include <nuttx/config.h>

#include <arch/chip/pin.h>
#include <stdio.h>

#include "neopixel.h"

int main(int argc, FAR char *argv[])
{

/* Adjust the pin number and number of pixels
 * according to your environment.
 */
#define PIN_NO   (PIN_PWM0)
#define N_PIXELS (12)

  neopixel_client_t *client = NULL;
  neopixel_color_t   color = {255, 255, 255};

  client = neopixel_inizialize(PIN_NO, N_PIXELS);

  neopixel_setall(client, &color);

  neopixel_show(client);

  sleep(5);

  neopixel_clear(client);
  neopixel_show(client);

  neopixel_finalize(client);

  return 0;
}
