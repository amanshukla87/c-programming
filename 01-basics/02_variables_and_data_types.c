#include <stdio.h>

int main(void)
{
    int sensor_value = 25;
    float voltage = 3.3f;
    char status = 'A';

    printf("Sensor value: %d\n", sensor_value);
    printf("Voltage: %.1f V\n", voltage);
    printf("Status: %c\n", status);

    return 0;
}
