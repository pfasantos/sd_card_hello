#include <stdio.h>
#include <string.h>

#include "sd_driver.h"
#include "main.h"
#include "esp_log.h"
#include "esp_err.h"

static const char* TAG = "MAIN_APP";

void app_main(void)
{   
    esp_err_t ret = sdcard_init();
    if (ret != ESP_OK) {
        ESP_LOGE(TAG, "Falha ao inicializar o SD Card.");
        return;
    }

    FILE* file = fopen(MOUNT_POINT "/arquivo.txt", "w");
    if (!file){
        ESP_LOGE(TAG, "Erro ao abrir o arquivo.");
        return;
    }

    char* text = "Hello, world!";
    if (file){
        fwrite(text, sizeof(char), strlen(text), file);
    }
    fclose(file);
    ESP_LOGI(TAG, "Arquivo fechado.");
}