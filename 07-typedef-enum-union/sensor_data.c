#include <stdio.h>
#include <string.h>

typedef enum
{
    SENSOR_TEMPERATURE,
    SENSOR_PRESSURE,
    SENSOR_STATUS
} SensorType;

typedef union
{
    float temperature;
    float pressure;
    int status;
} SensorValue;

typedef struct
{
    SensorType type;
    SensorValue value;
} SensorData;

void print_sensor_data(const SensorData *data)
{
    switch (data->type)
    {
        case SENSOR_TEMPERATURE:
            printf("Temperature: %.2f C\n", data->value.temperature);
            break;

        case SENSOR_PRESSURE:
            printf("Pressure: %.2f kPa\n", data->value.pressure);
            break;

        case SENSOR_STATUS:
            printf("Status: %d\n", data->value.status);
            break;
    }
}

int main(void)
{
    SensorData data;

    data.type = SENSOR_TEMPERATURE;
    data.value.temperature = 32.5f;
    print_sensor_data(&data);

    data.type = SENSOR_PRESSURE;
    data.value.pressure = 101.3f;
    print_sensor_data(&data);

    data.type = SENSOR_STATUS;
    data.value.status = 1;
    print_sensor_data(&data);

    printf("Size of SensorValue union: %zu bytes\n", sizeof(SensorValue));

    return 0;
}
