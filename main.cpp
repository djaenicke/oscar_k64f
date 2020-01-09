#include "mbed.h"
#include "io_abstraction.h"
#include "battery_monitor.h"
#include "motor_controls.h"
#include "serial_ctrl.h"

static Serial debug_out(USBTX, USBRX, 115200);
static DigitalOut init_complete_led(LED_BLUE);

static Thread motor_controls_thread(osPriorityRealtime);

// main() runs in its own thread in the OS
int main() {
  /* Initialization code */
  init_complete_led.write(0);

  InitMotorControls();
  Bluetooth_Serial_Init();

  /* Start the threads */
  motor_controls_thread.start(RunMotorControls);

  while (true) {
    
  }
}

