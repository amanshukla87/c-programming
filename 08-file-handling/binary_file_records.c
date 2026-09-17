#include <stdio.h>

struct SensorRecord {
    int id;
    float temperature;
    float voltage;
};

int main(void)
{
    struct SensorRecord records[] = {
        {1, 28.5f, 3.30f},
        {2, 31.2f, 3.28f},
        {3, 29.7f, 3.31f}
    };
    struct SensorRecord record;
    const char *filename = "sensor_records.dat";
    FILE *file;
    size_t count = sizeof(records) / sizeof(records[0]);

    /* Write structures to a binary file. */
    file = fopen(filename, "wb");
    if (file == NULL) {
        perror("Unable to open file for writing");
        return 1;
    }

    if (fwrite(records, sizeof(struct SensorRecord), count, file) != count) {
        perror("Error while writing records");
        fclose(file);
        return 1;
    }
    fclose(file);

    /* Read the structures back from the binary file. */
    file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Unable to open file for reading");
        return 1;
    }

    printf("Sensor records read from binary file:\n");
    printf("ID\tTemperature\tVoltage\n");
    printf("--------------------------------\n");

    while (fread(&record, sizeof(struct SensorRecord), 1, file) == 1) {
        printf("%d\t%.1f C\t\t%.2f V\n",
               record.id, record.temperature, record.voltage);
    }

    if (ferror(file)) {
        perror("Error while reading records");
        fclose(file);
        return 1;
    }

    fclose(file);
    return 0;
}
