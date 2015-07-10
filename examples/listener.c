#include <stdio.h>
#include "freertps/freertps.h"
#include <signal.h>
#include "led.h"
#include "delay.h"

static bool g_done = false;
void sigint_handler(int signum)
{
  g_done = true;
}

void chatter_cb(const void *msg)
{
  //printf("chatter_cb\n");
  uint32_t str_len = *((uint32_t *)msg);
  //printf("str len = %d\n", str_len - 1);
  char buf[128] = {0};
  for (int i = 0; i < str_len && i < sizeof(buf)-1; i++)
    buf[i] = ((uint8_t *)msg)[4+i];
  printf("I heard: [%s]\n", buf);
}

int main(int argc, char **argv)
{
  printf("hello, world!\r\n");
  int i = 0;
  while (1)
  {
    led_toggle();
    delay_ms(100);
    printf("hello %d\r\n", i);
    i++;
  }
  /*
  frudp_init();
  freertps_create_subscription("chatter", 
                               "simple_msgs::dds_::String_",
                               chatter_cb);
  signal(SIGINT, sigint_handler);
  while (!g_done)
  {
    if (!frudp_listen(1000))
      break;
    frudp_discovery_tick();
  }
  frudp_fini();
  return 0;
  */
}

