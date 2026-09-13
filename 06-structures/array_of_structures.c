#include <stdio.h>

struct Sensor
{
    int id;
    float temperature;
};

int main(void)
{
    struct Sensor sensors[3] = {
        {1, 28.7f},
        {2, 30.2f},
        {3, 27.9f}
    };

    for (int i = 0; i < 3; i++)
    {
        printf("Sensor %d: %.1f C\n", sensors[i].id, sensors[i].temperature);
    }

    return 0;
}
