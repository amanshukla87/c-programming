#include <stdio.h>

struct Sensor
{
    int id;
    float temperature;
};

int main(void)
{
    struct Sensor sensor = {1, 28.7f};

    printf("Sensor ID: %d\n", sensor.id);
    printf("Temperature: %.1f C\n", sensor.temperature);

    return 0;
}
