/*
 * Copyright (c) 2024 Ayush Singh <ayush@beagleboard.org>
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once

#include <Arduino.h>
#include <api/HardwareSPI.h>
#include <zephyr/drivers/spi.h>

#define SPR0 0
#define SPR1 1
#define CPHA 2
#define CPOL 3
#define MSTR 4
#define DORD 5
#define SPE 6
#define SPIE 7

namespace arduino {
class ZephyrSPI : public HardwareSPI {
public:
  ZephyrSPI(const struct device *spi);

  virtual uint8_t transfer(uint8_t data);
  virtual uint16_t transfer16(uint16_t data);
  virtual void transfer(void *buf, size_t count);

  // Transaction Functions
  virtual void usingInterrupt(int interruptNumber);
  virtual void notUsingInterrupt(int interruptNumber);
  virtual void beginTransaction(SPISettings settings);
  virtual void endTransaction(void);

  // SPI Configuration methods
  virtual void attachInterrupt();
  virtual void detachInterrupt();

  virtual void begin();
  virtual void end();

private:
  const struct device *spi_dev;
	struct spi_config config;
};

} // namespace arduino

extern arduino::ZephyrSPI SPI;
/* Serial Peripheral Control Register */
extern uint8_t SPCR;

using arduino::SPI_MODE0;
using arduino::SPI_MODE1;
using arduino::SPI_MODE2;
using arduino::SPI_MODE3;
using arduino::SPISettings;
