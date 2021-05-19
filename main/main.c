/* esp_event (event loop library) basic example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/

#include "esp_log.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_event.h"
#include "iot_button.h"

#define BUTTON_BOOT_IO           GPIO_NUM_0
#define BUTTON_BOOT_ACTIVE_LEVEL 0

static const char* TAG = "main";

void button_event_handler(void* event_handler_arg, esp_event_base_t event_base, int32_t event_id, void* event_data)
{
  button_event_data_t* btn_data = (button_event_data_t*) event_data;

  switch (event_id) {
  case BUTTON_PRESS_DOWN:
    //ESP_LOGI(TAG, "Button %d BUTTON_PRESS_DOWN - repeat %d", btn_data->gpio_num, btn_data->repeat);
    break;
  case BUTTON_PRESS_UP:
    //ESP_LOGI(TAG, "Button %d BUTTON_PRESS_UP - repeat %d", btn_data->gpio_num, btn_data->repeat);
    break;
  case BUTTON_PRESS_REPEAT:
    //ESP_LOGI(TAG, "Button %d BUTTON_PRESS_REPEAT - repeat %d", btn_data->gpio_num, btn_data->repeat);
    break;
  case BUTTON_SINGLE_CLICK:
    ESP_LOGI(TAG, "Button %d BUTTON_SINGLE_CLICK - repeat %d", btn_data->gpio_num, btn_data->repeat);
    break;
  case BUTTON_DOUBLE_CLICK:
    ESP_LOGI(TAG, "Button %d BUTTON_DOUBLE_CLICK - repeat %d", btn_data->gpio_num, btn_data->repeat);
    break;
  case BUTTON_LONG_PRESS_START:
    //ESP_LOGI(TAG, "Button %d BUTTON_LONG_PRESS_START - repeat %d", btn_data->gpio_num, btn_data->repeat);
    break;
  case BUTTON_LONG_PRESS_HOLD:
    //ESP_LOGI(TAG, "Button %d BUTTON_LONG_PRESS_HOLD - repeat %d", btn_data->gpio_num, btn_data->repeat);
    break;
  default:
    ESP_LOGW(TAG, "Button %d event %d - repeat %d", btn_data->gpio_num, event_id, btn_data->repeat);
  }
}


/* Example main */
void app_main(void)
{
  ESP_LOGI(TAG, "setting up");

  button_config_t btn_cfg = {
    .type = BUTTON_TYPE_GPIO,
    .gpio_button_config = {
      .gpio_num = BUTTON_BOOT_IO,
      .active_level = BUTTON_BOOT_ACTIVE_LEVEL
    }
  };

  button_handle_t btn_h = iot_button_create(&btn_cfg);

  esp_event_handler_register(BUTTON_EVENTS, ESP_EVENT_ANY_ID, &button_event_handler, NULL);


   
}
