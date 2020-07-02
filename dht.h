#ifndef DHT_HPP
#define DHT_HPP

#include "../hal/hal.h"
#include "../tools/data_types/byte_types.h" 

#include "dht_settings.h"

typedef enum DHTType{
    DHT11, DHT22, DHT21
} DHTType;

typedef struct DHTInterface {
    gpio_t signal;
    DHTType sensorType;
} DHTInterface;


// ===== Also requires WeatherSensor interface, have merged this with main libsoilar branch yet ======

// #define SIGFOX_MODE_ON                           true
// #define SIGFOX_MODE_OFF                          false
// #define SIGFOX_RESET_MODE_SYSTEM                 0U
// #define SIGFOX_RESET_MODE_CHIP                   1U
// #define SIGFOX_STATUS_MODE_SYSTEM                0U
// #define SIGFOX_STATUS_MODE_CHIP                  1U
// #define SIGFOX_STATUS_MODE_ALL                   2U

// #define SD_MAX_INSTANCES                         1U

typedef struct WeatherSensor {
    bool (*read)(int16_t*, int16_t*);
    void (*start)(void);
    void (*reset)(void);
} WeatherSensor;


// ==============================================================================================

bool readDHT(int16_t* temp, int16_t* humid);
void startDHT(void);
void resetDHT(void);

void createDHT(WeatherSensor* self, DHTInterface* interface);


////// 

int32_t _pollSignal(uint8_t state, uint32_t timeout);
bool _readPulses(uint16_t* buff, uint8_t size);

#endif /* DHT_HPP */
