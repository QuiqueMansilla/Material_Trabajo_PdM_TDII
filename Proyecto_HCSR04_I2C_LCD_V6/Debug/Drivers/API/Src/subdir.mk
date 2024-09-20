################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/API/Src/API_GPIO.c \
../Drivers/API/Src/API_HCSR04.c \
../Drivers/API/Src/API_I2C_LCD.c \
../Drivers/API/Src/API_ReadShowData.c \
../Drivers/API/Src/API_delay.c \
../Drivers/API/Src/API_uart.c 

OBJS += \
./Drivers/API/Src/API_GPIO.o \
./Drivers/API/Src/API_HCSR04.o \
./Drivers/API/Src/API_I2C_LCD.o \
./Drivers/API/Src/API_ReadShowData.o \
./Drivers/API/Src/API_delay.o \
./Drivers/API/Src/API_uart.o 

C_DEPS += \
./Drivers/API/Src/API_GPIO.d \
./Drivers/API/Src/API_HCSR04.d \
./Drivers/API/Src/API_I2C_LCD.d \
./Drivers/API/Src/API_ReadShowData.d \
./Drivers/API/Src/API_delay.d \
./Drivers/API/Src/API_uart.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/API/Src/%.o Drivers/API/Src/%.su Drivers/API/Src/%.cyclo: ../Drivers/API/Src/%.c Drivers/API/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F413xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/RepositoriosGitHub/PdM_workspace_Quique/Proyecto_HCSR04_I2C_LCD_V6/Drivers/API/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-API-2f-Src

clean-Drivers-2f-API-2f-Src:
	-$(RM) ./Drivers/API/Src/API_GPIO.cyclo ./Drivers/API/Src/API_GPIO.d ./Drivers/API/Src/API_GPIO.o ./Drivers/API/Src/API_GPIO.su ./Drivers/API/Src/API_HCSR04.cyclo ./Drivers/API/Src/API_HCSR04.d ./Drivers/API/Src/API_HCSR04.o ./Drivers/API/Src/API_HCSR04.su ./Drivers/API/Src/API_I2C_LCD.cyclo ./Drivers/API/Src/API_I2C_LCD.d ./Drivers/API/Src/API_I2C_LCD.o ./Drivers/API/Src/API_I2C_LCD.su ./Drivers/API/Src/API_ReadShowData.cyclo ./Drivers/API/Src/API_ReadShowData.d ./Drivers/API/Src/API_ReadShowData.o ./Drivers/API/Src/API_ReadShowData.su ./Drivers/API/Src/API_delay.cyclo ./Drivers/API/Src/API_delay.d ./Drivers/API/Src/API_delay.o ./Drivers/API/Src/API_delay.su ./Drivers/API/Src/API_uart.cyclo ./Drivers/API/Src/API_uart.d ./Drivers/API/Src/API_uart.o ./Drivers/API/Src/API_uart.su

.PHONY: clean-Drivers-2f-API-2f-Src

