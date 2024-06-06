#include "easylora.h"

void EasyLoRa::LoraE32Ayarlar() {
    digitalWrite(M0, HIGH);
    digitalWrite(M1, HIGH);

    HardwareSerial fixSerial(1);
    LoRa_E32 FixajSerial(TX, RX, &fixSerial, UART_BPS_RATE_9600);

    ResponseStructContainer c;
    c = FixajSerial.getConfiguration();
    Configuration configuration = *(Configuration*)c.data;

    //DEĞİŞEBİLEN AYARLAR
    // Üstte #define kısmında ayarlayınız
    configuration.ADDL = lowByte(Adres);
    configuration.ADDH = highByte(Adres);
    configuration.CHAN = Kanal;

    //SEÇENEKLİ AYARLAR
    configuration.SPED.airDataRate = AIR_DATA_RATE_010_24;  //Veri Gönderim Hızı 2,4 varsayılan
    //configuration.SPED.airDataRate = AIR_DATA_RATE_000_03;  //Veri Gönderim Hızı 0,3 En uzak Mesafe
    //configuration.SPED.airDataRate = AIR_DATA_RATE_101_192; //Veri Gönderim Hızı 19,2 En Hızlı

    configuration.OPTION.transmissionPower = POWER_20;  //Geönderim Gücü max Varsayılan
    //configuration.OPTION.transmissionPower = POWER_10;  //Geönderim Gücü min
    //configuration.OPTION.transmissionPower = POWER_30; // E32 30d modülleri için bunu aktif et

    //GELİŞMİŞ AYARLAR
    configuration.SPED.uartBaudRate = UART_BPS_9600;
    configuration.SPED.uartParity = MODE_00_8N1;
    configuration.OPTION.fec = FEC_0_OFF;
    //configuration.OPTION.fec = FEC_1_ON;
    configuration.OPTION.fixedTransmission = FT_FIXED_TRANSMISSION;
    //configuration.OPTION.fixedTransmission = FT_TRANSPARENT_TRANSMISSION;
    configuration.OPTION.wirelessWakeupTime = WAKE_UP_250;
    configuration.OPTION.ioDriveMode = IO_D_MODE_PUSH_PULLS_PULL_UPS;

    // Ayarları KAYDET ve SAKLA
    ResponseStatus rs = FixajSerial.setConfiguration(configuration, WRITE_CFG_PWR_DWN_SAVE);
    Serial.println(rs.getResponseDescription());
    Serial.println(rs.code);
    c.close();
}
