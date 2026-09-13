#include <stdio.h>

struct Sensor
{
    int id;
    float temperature;
};

int main(void)
{
    struct Sensor sensor = {1, 28.7f};
    struct Sensor *ptr = &sensor;

    printf("Sensor ID: %d\n", ptr->id);
    printf("Temperature: %.1f C\n", ptr->temperature);

    ptr->temperature = 30.5f;

    printf("Updated temperature: %.1f C\n", ptr->temperature);

    return 0;
}
