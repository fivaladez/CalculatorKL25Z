################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/2_HIL/Buttons_driver.c" \
"../Sources/2_HIL/LCD_driver.c" \
"../Sources/2_HIL/Leds_driver.c" \

C_SRCS += \
../Sources/2_HIL/Buttons_driver.c \
../Sources/2_HIL/LCD_driver.c \
../Sources/2_HIL/Leds_driver.c \

OBJS += \
./Sources/2_HIL/Buttons_driver.o \
./Sources/2_HIL/LCD_driver.o \
./Sources/2_HIL/Leds_driver.o \

C_DEPS += \
./Sources/2_HIL/Buttons_driver.d \
./Sources/2_HIL/LCD_driver.d \
./Sources/2_HIL/Leds_driver.d \

OBJS_QUOTED += \
"./Sources/2_HIL/Buttons_driver.o" \
"./Sources/2_HIL/LCD_driver.o" \
"./Sources/2_HIL/Leds_driver.o" \

C_DEPS_QUOTED += \
"./Sources/2_HIL/Buttons_driver.d" \
"./Sources/2_HIL/LCD_driver.d" \
"./Sources/2_HIL/Leds_driver.d" \

OBJS_OS_FORMAT += \
./Sources/2_HIL/Buttons_driver.o \
./Sources/2_HIL/LCD_driver.o \
./Sources/2_HIL/Leds_driver.o \


# Each subdirectory must supply rules for building sources it contributes
Sources/2_HIL/Buttons_driver.o: ../Sources/2_HIL/Buttons_driver.c
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/2_HIL/Buttons_driver.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/2_HIL/Buttons_driver.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/2_HIL/LCD_driver.o: ../Sources/2_HIL/LCD_driver.c
	@echo 'Building file: $<'
	@echo 'Executing target #7 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/2_HIL/LCD_driver.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/2_HIL/LCD_driver.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/2_HIL/Leds_driver.o: ../Sources/2_HIL/Leds_driver.c
	@echo 'Building file: $<'
	@echo 'Executing target #8 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/2_HIL/Leds_driver.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/2_HIL/Leds_driver.o"
	@echo 'Finished building: $<'
	@echo ' '


