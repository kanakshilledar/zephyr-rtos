# SPDX-License-Identifier: Apache-2.0

zephyr_library()
<<<<<<< HEAD
=======
zephyr_library_property(ALLOW_EMPTY TRUE)

>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
add_subdirectory_ifdef(CONFIG_WIFI_ESP_AT       esp_at)
add_subdirectory_ifdef(CONFIG_WIFI_ESP32        esp32)
add_subdirectory_ifdef(CONFIG_WIFI_ESWIFI       eswifi)
add_subdirectory_ifdef(CONFIG_WIFI_SIMPLELINK   simplelink)
add_subdirectory_ifdef(CONFIG_WIFI_WINC1500     winc1500)
