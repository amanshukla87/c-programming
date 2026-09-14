#include <stdio.h>

enum SensorStatus
{
    SENSOR_OK,
    SENSOR_WARNING,
    SENSOR_ERROR
};

int main(void)
{
    enum SensorStatus status = SENSOR_OK;

    if (status == SENSOR_OK)
    {
        printf("Sensor status: OK\n");
    }
    else if (status == SENSOR_WARNING)
    {
        printf("Sensor status: WARNING\n");
    }
    else
    {
        printf("Sensor status: ERROR\n");
    }

    return 0;
}
