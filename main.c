#include "monty.h"

int main(int ac, char* av[]) {
    FILE* file;
    char Line[256];
    char* Op_Code;
    char* Value_Str;
    int Value;
    StackNode* stack = NULL;

    if (ac != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        return EXIT_FAILURE;
    }

    file = fopen(av[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Can't open file %s\n", av[1]);
        return EXIT_FAILURE;
    }

    while (fgets(Line, sizeof(Line), file)) {
        Op_Code = strtok(Line, " \n");

        if (Op_Code != NULL) {
            if (strcmp(Op_Code, "push") == 0) {
                Value_Str = strtok(NULL, " \n");
                if (Value_Str != NULL) {
                    Value = atoi(Value_Str);
                    push(&stack, Value);
                } else {
                    fprintf(stderr, "Error: Missing value for push\n");
                    fclose(file);
                    free_stack(stack);
                    return EXIT_FAILURE;
                }
            } else if (strcmp(Op_Code, "pall") == 0) {
                pall(&stack);
            } else {
                fprintf(stderr, "Error: Unknown opcode %s\n", Op_Code);
                fclose(file);
                free_stack(stack);
                return EXIT_FAILURE;
            }
        }
    }

    fclose(file);
    free_stack(stack);
    return EXIT_SUCCESS;
}
