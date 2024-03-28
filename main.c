#include "monty.h"

int main(int argc, char* argv[]) {
    FILE* file;
    char line[256];
    char* opcode;
    char* value_str;
    int value;
    StackNode* stack = NULL;

    if (argc != 2) {
        fprintf(stderr, "USAGE: monty file\n");
        return EXIT_FAILURE;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    while (fgets(line, sizeof(line), file)) {
        opcode = strtok(line, " \n");

        if (opcode != NULL) {
            if (strcmp(opcode, "push") == 0) {
                value_str = strtok(NULL, " \n");
                if (value_str != NULL) {
                    value = atoi(value_str);
                    push(&stack, value);
                } else {
                    fprintf(stderr, "Error: Missing value for push\n");
                    fclose(file);
                    free_stack(stack);
                    return EXIT_FAILURE;
                }
            } else if (strcmp(opcode, "pall") == 0) {
                pall(&stack);
            } else {
                fprintf(stderr, "Error: Unknown opcode %s\n", opcode);
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
