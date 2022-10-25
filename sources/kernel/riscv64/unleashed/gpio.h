#pragma once

#define GPIO_BASE 0x10060000

enum gpio_registers
{
    GPIO_IPUNT_VAL = 0,
    GPIO_INPUT_ENABLE = 4,
    GPIO_OUTPUT_ENABLE = 8,
    GPIO_OUTPUT_VAL = 12,
    GPIO_INTERNAL_PU_ENABLE = 16, // internal pull up
    GPIO_PIN_DRIVE_STENGTH = 20,
    GPIO_RISE_INT_ENABLE = 24,
    GPIO_RISE_INT_PENDING = 28,
    GPIO_FALL_INT_ENABLE = 32,
    GPIO_FALL_INT_PENDING = 36,
    GPIO_HIGH_INT_ENABLE = 40,
    GPIO_HIGH_INT_PENDING = 44,
    GPIO_LOW_INT_ENABLE = 48,
    GPIO_LOW_INT_PENDING = 52,
    GPIO_IO_FUNC_ENABLE = 56,
    GPIO_IO_FUNC_SELECT = 60,
    GPIO_OUTPUT_XOR = 64,
};
