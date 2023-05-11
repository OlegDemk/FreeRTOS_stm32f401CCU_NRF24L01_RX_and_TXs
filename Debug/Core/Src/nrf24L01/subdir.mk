################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/nrf24L01/nrf24L01.c 

OBJS += \
./Core/Src/nrf24L01/nrf24L01.o 

C_DEPS += \
./Core/Src/nrf24L01/nrf24L01.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/nrf24L01/%.o Core/Src/nrf24L01/%.su: ../Core/Src/nrf24L01/%.c Core/Src/nrf24L01/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xC -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-nrf24L01

clean-Core-2f-Src-2f-nrf24L01:
	-$(RM) ./Core/Src/nrf24L01/nrf24L01.d ./Core/Src/nrf24L01/nrf24L01.o ./Core/Src/nrf24L01/nrf24L01.su

.PHONY: clean-Core-2f-Src-2f-nrf24L01

