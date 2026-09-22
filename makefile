INCLUDE_STACK= src/stack_for_chess.c
INCLUDE_INPUT=src/input_function.c
INCLUDE= -I "includes"
final:
	@echo "Compiling  the Files..."
# 	@gcc chess.c stack_for_chess.c input_function.c -o chess.exe
	@gcc chess.c $(INCLUDE_STACK) $(INCLUDE_INPUT) $(INCLUDE) -o chess.exe
run:
	@echo "Running The Executable "
	@./chess.exe 
clean:
	@echo "Clearing Up The Executable..."
	@rm chess.exe
	
	@echo "success"
Stack:
	@echo "Compiling stack...."
	@gcc $(INCLUDE_STACK) -o stack.exe
del_stack:
	@echo "Removing stack executable..."
	@rm stack.exe

	
	

