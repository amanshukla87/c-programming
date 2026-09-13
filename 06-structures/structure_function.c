#include <stdio.h>

struct Sensor
{
    int id;
    float temperature;
};

void print_sensor(struct Sensor sensor)
{
    printf("Sensor ID: %d\n", sensor.id);
    printf("Temperature: %.1f C\n", sensor.temperature);
}

int main(void)
{
    struct Sensor sensor = {1, 28.7f};

    print_sensor(sensor);

    return 0;
}
