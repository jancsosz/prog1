#define MAX_TITKOS 4096
#define OLVASAS_BUFFER 256
#define KULCS_MERET 4
#define _GNU_SOURCE

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

double
atlagos_szohossz (const char *titkos, int titkos_meret)
{
    int sz = 0;
    for (int i = 0; i < titkos_meret; ++i)
        if (titkos[i] == ' ')
            ++sz;

    return (double) titkos_meret / sz;
}

int
tiszta_lehet (const char *titkos, int titkos_meret)
{
    // a tiszta szoveg valszeg tartalmazza a gyakori magyar szavakat
    // illetve az átlagos szóhossz vizsgálatával csökkentjük a
    // potenciális töréseket

    double szohossz = atlagos_szohossz (titkos, titkos_meret);

    return szohossz > 6.0 && szohossz < 9.0
           && strcasestr (titkos, "hogy") && strcasestr (titkos, "nem")
           && strcasestr (titkos, "az") && strcasestr (titkos, "ha");

}

void
exor (const char kulcs[], int kulcs_meret, char titkos[], int titkos_meret, char *buffer)
{

    int kulcs_index = 0;

    for (int i = 0; i < titkos_meret; ++i)
    {

        buffer[i] = titkos[i] ^ kulcs[kulcs_index];
        kulcs_index = (kulcs_index + 1) % kulcs_meret;

    }

}

void
exor_tores (const char kulcs[], int kulcs_meret, char titkos[],
            int titkos_meret)
{

    char *buffer;

    if ((buffer = (char *)malloc(sizeof(char)*titkos_meret)) == NULL)
    {
        printf("Memoria (buffer) faliora\n");
        exit(-1);
    }

    exor (kulcs, kulcs_meret, titkos, titkos_meret, buffer);

    if(tiszta_lehet (buffer, titkos_meret))
    {
      printf("Kulcs: [%c%c%c%c]\nTiszta szoveg: [%s]\n",
			 kulcs[0],kulcs[1],kulcs[2],kulcs[3], buffer);      
    }
    
    free(buffer);

}

int
main (void)
{
    char titkos[MAX_TITKOS];
    char *p = titkos;
    int olvasott_bajtok;

    // titkos fajt berantasa
    while ((olvasott_bajtok =
                read (0, (void *) p,
                      (p - titkos + OLVASAS_BUFFER <
                       MAX_TITKOS) ? OLVASAS_BUFFER : titkos + MAX_TITKOS - p)))
        p += olvasott_bajtok;

    // maradek hely nullazasa a titkos bufferben
    for (int i = 0; i < MAX_TITKOS - (p - titkos); ++i)
        titkos[p - titkos + i] = '\0';

    //tobbi szal aktivalasa
    #pragma omp parallel for
    // osszes kulcs eloallitasa
    for (int ii = 'a'; ii <= 'z'; ++ii)
        for (int ji = 'a'; ji <= 'z'; ++ji)
            for (int ki = 'a'; ki <= 'z'; ++ki)
                for (int li = 'a'; li <= 'z'; ++li)         
                                {

                                    char *kulcs;

                                    if ((kulcs = (char *)malloc(sizeof(char)*KULCS_MERET)) == NULL)
                                    {
                                        printf("Memoria (kulcs) faliora\n");
                                        exit(-1);
                                    }

                                    kulcs[0] = ii;
                                    kulcs[1] = ji;
                                    kulcs[2] = ki;
                                    kulcs[3] = li;                                 
                                    exor_tores (kulcs, KULCS_MERET, titkos, p - titkos);

                                    free(kulcs);
                                }

    return 0;
}
