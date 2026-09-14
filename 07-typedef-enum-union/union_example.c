#include <stdio.h>

union SensorValue
{
    int count;
    float temperature;
};

int main(void)
{
    union SensorValue value;

    value.temperature = 28.7f;

    printf("Temperature: %.1f C\n", value.temperature);

    value.count = 10;

    printf("Count: %d\n", value.count);

    return 0;
}
