/*
 * Copyright (c) 2022 Dhruva Gole
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include "Arduino.h"

int main(void) {
  setup();

  for (;;) {
    loop();
    if (arduino::serialEventRun) arduino::serialEventRun();
    k_yield();
  }

  return 0;
}
