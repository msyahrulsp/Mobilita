#include <stdio.h>
#include "ability.h"

int main(){

    Ability a;

    AB_createAbility(&a, true);
    printf("%d %d", Count(a), Active(a));

    AB_activate(&a);
    printf("%d %d", Count(a), Active(a));

    AB_stackAbility(&a);
    printf("%d %d", Count(a), Active(a));
    
    AB_useAbility(&a);
    printf("%d %d", Count(a), Active(a));

    return 0;
}