#include <stdio.h>

int main() {

float n;
int i, contn = 0;

for (i=0; i <6; i++){

    scanf("%f",&n );
    if (n > 0.0)
    {
       contn++;
    }
}
printf("%d valores positivos\n", contn);

    return 0;
}
