#ifndef EASYLORA_H
#define EASYLORA_H

#include <Arduino.h>
#include <HardwareSerial.h>
#include "LoRa_E32.h"

class EasyLoRa {
public:
    const uint8_t M0 = 4;
    const uint8_t M1 = 6;
    const uint8_t RX = 18;
    const uint8_t TX = 17;
    void LoraE32Ayarlar();

private:
};

#endif
