#include <stdio.h>

typedef struct
{
    int id;
    float temperature;
} Sensor;

int main(void)
{
    Sensor sensor = {1, 28.7f};

    printf("Sensor ID: %d\n", sensor.id);
    printf("Temperature: %.1f C\n", sensor.temperature);

    return 0;
}
