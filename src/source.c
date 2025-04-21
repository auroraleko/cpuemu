#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct {
    int val;
    int loc;
} Byte; Byte bus[64];
char operation[10];
char *operation_pointer = &operation;

int _LOAD() {
    int i, input;
    printf("ADDRESS TO LOAD FROM: ");scanf("%d", &input);
    i=0;
    while (i<64) {
        if (bus[i].loc == input) {
            return bus[i].val;
        } else {
            i++;
        }
    }
}

void _STORE() {
    int i, input_v, input_l;
    printf("ADDRESS TO STORE IN: ");scanf("%d", &input_l);
    printf("VALUE: ");scanf("%d", &input_v);
    i=0;
    while (i<64) {
        if (bus[i].loc == input_l) {
            bus[i].val = input_v;break;
        } else {
            i++;
        }
    }
}

int _MATH_OP(int x, int y) {
    printf("NUMBERS TO %s (1): ", operation);scanf("%d", &x);
    printf("NUMBERS TO %s (2):", operation);scanf("%d", &y);
    if (operation == "ADD") {
        return x + y;
    } else if (operation == "SUBTRACT") {
        return x - y;
    } else if (operation == "DIVIDE") {
        return x / y;
    } else if (operation == "MULTIPLY") {
        return x * y;
    }
}

void _MATH(int x, int y) {
    int operation_choice;
    printf("ARITHMETIC OPERATION:\n1) +\n2) -\n3) /\n4) *\n> : ");scanf("%d", &operation_choice);
    switch (operation_choice) {
    case 1:
        *operation_pointer = "ADD";
        break;
    case 2:
        *operation_pointer = "SUBTRACT";
        break;
    case 3:
        *operation_pointer = "DIVIDE";
        break;
    case 4:
        *operation_pointer = "MULTIPLY";
        break;
    default:
        break;
    }
    _MATH_OP();
}

int main() {
    int input;
    printf("1) LOAD\n2) STORE\n3) MATH\n4) CLOCK\n5) QUIT\n> : ");scanf("%d", &input);
    while (1) {
        switch (input) {
        case 1:
            _LOAD();
            break;
        case 2:
            _STORE();
            break;
        case 3:
            _MATH();
            break;
        case 4:
            system("clear && timedatectl");printf("\n");
            break;
        case 5:
            exit(0);
            break;
        default:
            continue;
        }
    }
    return 0;
}
