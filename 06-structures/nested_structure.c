#include <stdio.h>

struct Date
{
    int day;
    int month;
    int year;
};

struct Sensor
{
    int id;
    float temperature;
    struct Date last_updated;
};

int main(void)
{
    struct Sensor sensor = {
        1,
        28.7f,
        {13, 9, 2026}
    };

    printf("Sensor ID: %d\n", sensor.id);
    printf("Temperature: %.1f C\n", sensor.temperature);
    printf("Last updated: %02d/%02d/%d\n",
           sensor.last_updated.day,
           sensor.last_updated.month,
           sensor.last_updated.year);

    return 0;
}
