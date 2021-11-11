/*Ivesti  sveiku  skaiciu  seka,  kurios  pabaiga  zymima  skaiciumi  0.
  Isvesti  nariu,  kurie prasideda nelyginiu skaitmenimi, skaiciu.*/
// Matas Samsonas 2021 - 10 - 14
#include <stdio.h>
#include <math.h>
int main()
{
    int number, exponent, amount = 0;
    char buffer;
    printf("The following program reads an input which consists of an array of integers which ends with a zero.\n");//
    printf("And then outputs how many of them begin with an odd number \n");                                        //
    printf("The bounds of this program are (-10^8, 10^9).\n");                                                      //  User interface (Vartotojo sasaja)
    printf("-----------------------------------------------\n");                                                    //
    printf("Input a whole number or an array of them:\n");                                                          //
    while(1)
    {
        if(scanf("%9d", &number)) // Input'as naudojantis scanf
        {
            buffer = getchar();
            if ((buffer == ' ') || (buffer == '\n') || (buffer == 9)) // Patikrinama ar simbolis po perskaityto skaitmens yra space, EOL arba horizontalus tab'as
            {
                if (!number)
                {
                    break;
                }
                printf("Input accepted.\n"); // Gryztamasis rysis, kai input atitinka visus reikalavimus
                exponent = 0;
                while(pow(10, ++exponent) <= abs(number)) // Randa rodykli su kuriuo abs(number) / 10^rodyklis butu skaicius nuo 1 iki 9 + 1
                    ;
                if((int)(abs(number) / pow(10, exponent - 1)) % 2) // Patikrina ar number / 10^rodyklis yra lyginis
                {
                    amount++;
                }
            }
            else
            {
                if((buffer >= '0') && (buffer <= '9'))
                {
                    printf("This integer exceeds the bounds of this program. Try again.\n"); // Gryztamasis rysis, kai ivestas skaicius virsija rezius.
                }
                else
                {
                    printf("This input consists of an alphanumerical set of characters. Try again.\n"); // Gryztamasis rysys, kai input'e yra ir numeriu ir kitu simboliu
                }
                while((buffer != ' ') && (buffer != '\n') && (buffer != 9))
                {
                    buffer = getchar();
                }
            }
        }
        else
        {
            printf("This input began with an alphabetical or special character. Try again.\n"); // Griztamasis rysys, kai input prasideda ne numeriu
            buffer = getchar();
            while((buffer != ' ') && (buffer != '\n') && (buffer != 9))
            {
                buffer = getchar();
            }
        }
    }
    printf("Out of the accepted inputs %d began with an odd number", amount); // Programos pabaiga ir rezultatai
    return 0;
}
