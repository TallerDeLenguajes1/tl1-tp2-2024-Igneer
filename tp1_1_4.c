#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define M = 5

struct compu
{
    int velocidad; //Entre 1 y 3 GHz
    int anio; //Entre 2015 y 2023
    int cantidad; //Entre 1 y 8
    char *tipo_cpu; //valores del arreglo tipos
};

void MostrarPCs(struct compu PCs[], int tam);
void PCvieja(struct compu PCs[], int tam);
void PCveloz(struct compu PCs[], int tam);

//EJERCICIO 4

//Funcion RAND() -> a = rand()%11+20 numeros entre 20 y 30, el modulo generar numeros de 0 a 10 y al sumarle hacemos que solo puedan ser numeros entre 20 y 30

int main()
{
    srand(time(NULL));
    char tipos[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};
    //b)
    struct compu PCs[5];

    for(int i = 0; i < 5; i++)
    {
        do
        {
            printf("Ingrese la velocidad de la PC %d(entre 1 y 3GHz):", (i+1));
            scanf("%d", &PCs[i].velocidad);
        }while(PCs[i].velocidad <=0 || PCs[i].velocidad > 3);

        do
        {
            printf("Ingrese el anio de la PC %d (entre 2015 y 2024):", (i+1));
            scanf("%d", &PCs[i].anio);
        }while(PCs[i].anio < 2015  || PCs[i].anio > 2024);

        do
        {
            printf("Ingrese la cantidad de nucleos de la PC %d (entre 1 y 8):", (i+1));
            scanf("%d", &PCs[i].cantidad);
        }while(PCs[i].cantidad < 1 || PCs[i].cantidad > 8);


        int j = rand() % 6; //indice para agarrar de forma aleatoria un tipo de procesador
        PCs[i].tipo_cpu = &tipos[j][0];        

        printf("\n");
    }
    

    MostrarPCs(PCs, 5);
    PCvieja(PCs, 5);
    PCveloz(PCs, 5);

    return 1;
}

void MostrarPCs(struct compu PCs[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        printf("-------------------PC %d-------------------\n", (i+1));
        printf("Velocidad: %d GHz\n", PCs[i].velocidad);
        printf("Anio: %d\n", PCs[i].anio);
        printf("Nucleos del procesador: %d nucleos\n", PCs[i].cantidad);
        printf("Marca del procesador: ");
        puts(PCs->tipo_cpu);
        printf("-------------------------------------------\n\n");
    }
}

void PCvieja(struct compu PCs[], int tam)
{
    int menor = PCs[0].anio;
    int j = 0;
    for (int i = 0; i < tam; i++)
    {
        if (PCs[i].anio < menor)
        {
            menor = PCs[i].anio;
            j = i;
        }
    }
        printf("---------------PC mas vieja----------------\n", (j+1));
        printf("Velocidad: %d GHz\n", PCs[j].velocidad);
        printf("Anio: %d\n", PCs[j].anio);
        printf("Nucleos del procesador: %d nucleos\n", PCs[j].cantidad);
        printf("Marca del procesador: ");
        puts(PCs[j].tipo_cpu);
        printf("-------------------------------------------\n");
}

void PCveloz(struct compu PCs[], int tam)
{
    int veloz = 0;
    int j = 0;
    for (int i = 0; i < tam; i++)
    {
        if (PCs[i].velocidad > veloz)
        {
            veloz = PCs[i].velocidad;
            j = i;
        }
    }
        printf("---------------PC mas veloz----------------\n", (j+1));
        printf("Velocidad: %d GHz\n", PCs[j].velocidad);
        printf("Anio: %d\n", PCs[j].anio);
        printf("Nucleos del procesador: %d nucleos\n", PCs[j].cantidad);
        printf("Marca del procesador: ");
        puts(PCs[j].tipo_cpu);
        printf("-------------------------------------------\n");
}