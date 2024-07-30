# MCU name
# MCU = RP2040
# # Bootloader selection
# BOOTLOADER = rp2040
# SERIAL_DRIVER = vendor
MCU = atmega32u4
BOOTLOADER = caterina

OLED_ENABLE = yes
RGBLIGHT_ENABLE = no
EXTRAKEY_ENABLE = yes
LTO_ENABLE = yes
COMBO_ENABLE = yes
KEY_OVERRIDE_ENABLE = yes

# Disable unsupported hardware, maybe it reduces firmware size?
AUDIO_SUPPORTED = no
BACKLIGHT_SUPPORTED = no
CONSOLE_ENABLE = no
MOUSEKEY_ENABLE = no
VIA_ENABLE = no
ENCODER_MAP_ENABLE = yes
