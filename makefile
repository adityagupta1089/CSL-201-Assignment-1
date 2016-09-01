# Output Name
OUTPUT_NAME := "RoomBookingSystem"
# All targets
all: 
	@echo '==================================================='
	@echo '**Author: Aditya Gupta [2015CSB1003]**'
	@echo '>>Loading default data files...'
	cp -R default\ data/. data/.
	@echo '>>Invoking GCC C++ Linker...'
	g++ -o $(OUTPUT_NAME) ./src/*.cpp ./src/*.h
	@echo 'Finished Building.'
	@echo '>>You can run the program using `./'$(OUTPUT_NAME)'` \n>>and you clean using `make clean`'
	@echo '==================================================='
# Other targets
clean:
	@echo '==================================================='
	@echo '>>Cleaning Files...'
	rm -rf $(OUTPUT_NAME)
	@echo '>>Cleaning Data...'
	rm -rf data/*
	@echo '>>Done.'
	@echo '==================================================='
