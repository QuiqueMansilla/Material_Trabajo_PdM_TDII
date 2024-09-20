################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/API/Scr/API_debounce.c \
../Drivers/API/Scr/API_delay.c \
../Drivers/API/Scr/API_uart.c 

OBJS += \
./Drivers/API/Scr/API_debounce.o \
./Drivers/API/Scr/API_delay.o \
./Drivers/API/Scr/API_uart.o 

C_DEPS += \
./Drivers/API/Scr/API_debounce.d \
./Drivers/API/Scr/API_delay.d \
./Drivers/API/Scr/API_uart.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/API/Scr/%.o Drivers/API/Scr/%.su Drivers/API/Scr/%.cyclo: ../Drivers/API/Scr/%.c Drivers/API/Scr/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F413xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/RepositoriosGitHub/PdM_workspace_Quique/Practica5_Uart_F413ZH/Drivers/API/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-API-2f-Scr

clean-Drivers-2f-API-2f-Scr:
	-$(RM) ./Drivers/API/Scr/API_debounce.cyclo ./Drivers/API/Scr/API_debounce.d ./Drivers/API/Scr/API_debounce.o ./Drivers/API/Scr/API_debounce.su ./Drivers/API/Scr/API_delay.cyclo ./Drivers/API/Scr/API_delay.d ./Drivers/API/Scr/API_delay.o ./Drivers/API/Scr/API_delay.su ./Drivers/API/Scr/API_uart.cyclo ./Drivers/API/Scr/API_uart.d ./Drivers/API/Scr/API_uart.o ./Drivers/API/Scr/API_uart.su

.PHONY: clean-Drivers-2f-API-2f-Scr

