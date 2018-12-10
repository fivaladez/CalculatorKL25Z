################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/3_HAL/ADC_driver.c" \
"../Sources/3_HAL/GPIO_driver.c" \
"../Sources/3_HAL/PIT_driver.c" \
"../Sources/3_HAL/PWM_driver.c" \
"../Sources/3_HAL/UART_driver.c" \

C_SRCS += \
../Sources/3_HAL/ADC_driver.c \
../Sources/3_HAL/GPIO_driver.c \
../Sources/3_HAL/PIT_driver.c \
../Sources/3_HAL/PWM_driver.c \
../Sources/3_HAL/UART_driver.c \

OBJS += \
./Sources/3_HAL/ADC_driver.o \
./Sources/3_HAL/GPIO_driver.o \
./Sources/3_HAL/PIT_driver.o \
./Sources/3_HAL/PWM_driver.o \
./Sources/3_HAL/UART_driver.o \

C_DEPS += \
./Sources/3_HAL/ADC_driver.d \
./Sources/3_HAL/GPIO_driver.d \
./Sources/3_HAL/PIT_driver.d \
./Sources/3_HAL/PWM_driver.d \
./Sources/3_HAL/UART_driver.d \

OBJS_QUOTED += \
"./Sources/3_HAL/ADC_driver.o" \
"./Sources/3_HAL/GPIO_driver.o" \
"./Sources/3_HAL/PIT_driver.o" \
"./Sources/3_HAL/PWM_driver.o" \
"./Sources/3_HAL/UART_driver.o" \

C_DEPS_QUOTED += \
"./Sources/3_HAL/ADC_driver.d" \
"./Sources/3_HAL/GPIO_driver.d" \
"./Sources/3_HAL/PIT_driver.d" \
"./Sources/3_HAL/PWM_driver.d" \
"./Sources/3_HAL/UART_driver.d" \

OBJS_OS_FORMAT += \
./Sources/3_HAL/ADC_driver.o \
./Sources/3_HAL/GPIO_driver.o \
./Sources/3_HAL/PIT_driver.o \
./Sources/3_HAL/PWM_driver.o \
./Sources/3_HAL/UART_driver.o \


# Each subdirectory must supply rules for building sources it contributes
Sources/3_HAL/ADC_driver.o: ../Sources/3_HAL/ADC_driver.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/3_HAL/ADC_driver.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/3_HAL/ADC_driver.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/3_HAL/GPIO_driver.o: ../Sources/3_HAL/GPIO_driver.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/3_HAL/GPIO_driver.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/3_HAL/GPIO_driver.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/3_HAL/PIT_driver.o: ../Sources/3_HAL/PIT_driver.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/3_HAL/PIT_driver.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/3_HAL/PIT_driver.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/3_HAL/PWM_driver.o: ../Sources/3_HAL/PWM_driver.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/3_HAL/PWM_driver.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/3_HAL/PWM_driver.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/3_HAL/UART_driver.o: ../Sources/3_HAL/UART_driver.c
	@echo 'Building file: $<'
	@echo 'Executing target #5 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/3_HAL/UART_driver.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/3_HAL/UART_driver.o"
	@echo 'Finished building: $<'
	@echo ' '


