################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/1_App/main.c" \
"../Sources/1_App/sa_mtb.c" \

C_SRCS += \
../Sources/1_App/main.c \
../Sources/1_App/sa_mtb.c \

OBJS += \
./Sources/1_App/main.o \
./Sources/1_App/sa_mtb.o \

C_DEPS += \
./Sources/1_App/main.d \
./Sources/1_App/sa_mtb.d \

OBJS_QUOTED += \
"./Sources/1_App/main.o" \
"./Sources/1_App/sa_mtb.o" \

C_DEPS_QUOTED += \
"./Sources/1_App/main.d" \
"./Sources/1_App/sa_mtb.d" \

OBJS_OS_FORMAT += \
./Sources/1_App/main.o \
./Sources/1_App/sa_mtb.o \


# Each subdirectory must supply rules for building sources it contributes
Sources/1_App/main.o: ../Sources/1_App/main.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/1_App/main.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/1_App/main.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/1_App/sa_mtb.o: ../Sources/1_App/sa_mtb.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/1_App/sa_mtb.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/1_App/sa_mtb.o"
	@echo 'Finished building: $<'
	@echo ' '


