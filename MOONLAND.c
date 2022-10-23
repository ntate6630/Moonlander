/* Moonlander game converted from the Usbourne book - Computer Space Games */<
/* Originaly written in BASIC                                              */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#define ASCII_ESC 27

main()
{
     int t = 0, height = 500, velocity = 50, newVelocity = 0;
     int i = 0, fuel = 120, burn = 0, decent = 1, flag = 1;
     char n[10];

     printf("%c[2J", ASCII_ESC);        /* Clear screen */
     printf("%c[H", ASCII_ESC);         /* Move cursor to top left */
     do{
          printf("\n\tTime = %d\t", t);
          printf("Height = %d\t", height);
          printf("Velocity = %d\t", velocity);
          printf("Fuel = %d\n\n", fuel);

          for(i = 2; i < height / 6; ++i)
               printf(" ");             /* Calculate position on the screen */

          printf("*\n");                 /* Draw lander at new position */

          if(fuel != 0)
          {
               do{
                    i = 0;
                    printf("\tInput burn?  0 to 30  ");
                    scanf("%s", n);

                    while(n[i] != '\0')
                    {
                         flag = isdigit(n[i]);
                         /*  printf("%s", n);  */
                         if(!flag)
                              break;
                         i++;
                    }
                    if(flag)
                    {
                         burn = atoi(n);
                         /*  printf("%d\n", burn);  */
                         break;
                    }
                    else if(!flag || burn < 0 || burn > 30)
                    {
                         printf("\tInput error!\n");
                         flag = 1;
                         continue;      /* Retry if input is not valid */
                    }<
               }while(flag);

               if(burn < 0)
                    burn = 0;
               if(burn > 30)
                    burn = 30;
          }
          if(burn > fuel)
               burn = fuel;

          newVelocity = velocity - burn + 5;
          fuel = fuel - burn;
          if((newVelocity + velocity) / 2 >= height)
               decent = 0;

          height = height - (newVelocity + velocity) / 2;
          t++;
          velocity = newVelocity;
     }while(decent == 1);

     newVelocity = velocity + (5 - burn) * height / velocity;
     if(newVelocity > 5)
          printf("You crashed - No survivors!\n");
     if(newVelocity > 1 && newVelocity <= 5)
          printf("You landed with some damage!\n");
     if(newVelocity <= 1)
          printf("Good landing!");
}
