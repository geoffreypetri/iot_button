# IOT Button

IOT Button component from Espressif's [esp-iot-solution](https://github.com/espressif/esp-iot-solution/tree/master/components/button) with events loop !

Example code for simplicity.

1. Create the button instance (here connected on GPIO0).
```c
button_config_t btn_cfg = {
  .type = BUTTON_TYPE_GPIO,
  .gpio_button_config = {
    .gpio_num = BUTTON_BOOT_IO,
    .active_level = BUTTON_BOOT_ACTIVE_LEVEL
  }
};
button_handle_t btn_h = iot_button_create(&btn_cfg);
```

2. Then register the event handler function (here `button_event_handler`, handling any event from `BUTTON_EVENTS` base).
```c
esp_event_handler_register(BUTTON_EVENTS, ESP_EVENT_ANY_ID, &button_event_handler, NULL);
```
