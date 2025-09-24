#include <stdio.h>
#include <string.h>

// Desafio Super Trunfo - Países
// Tema 2 - Comparação das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de comparação de cartas de cidades. 
// Siga os comentários para implementar cada parte do desafio.

int main() {
   // Variáveis da Carta 1
    char Estado1[50];  
    char CodigoDaCarta1[4];
    char NomeDaCidade1[50];
    unsigned long int Populacao1;
    int PontosTuristicos1;
    float AreaEmKm1;
    float DensiPop1;
    float PIB1;
    float PIBPC1;
    float SuperPoder1;

    // Variáveis da Carta 2
    char Estado2[50]; 
    char CodigoDaCarta2[4];
    char NomeDaCidade2[50];
    unsigned long int Populacao2;
    int PontosTuristicos2;
    float AreaEmKm2;
    float DensiPop2;
    float PIB2;
    float PIBPC2;
    float SuperPoder2;

    // Entrada da Carta 1
    printf("Digite o Estado da Carta 1 (A-H): ");
    scanf("%s", Estado1);
    
    printf("Digite o Código da Carta 1 (ex: A01): ");
    scanf("%s", CodigoDaCarta1);

    getchar(); // consome o \n que sobrou
    printf("Digite o Nome da Cidade da Carta 1: ");
    fgets(NomeDaCidade1, 50, stdin);
    NomeDaCidade1[strcspn(NomeDaCidade1, "\n")] = '\0'; // remove o \n do final

    printf("Digite a População da Cidade da Carta 1: ");
    scanf("%lu", &Populacao1);

    printf("Digite a Área da Cidade da Carta 1 (Km²): ");
    scanf("%f", &AreaEmKm1);

    DensiPop1 = (float) Populacao1 / AreaEmKm1;

    printf("Digite o PIB da Carta 1: ");
    scanf("%f", &PIB1);

    PIBPC1 = (float) PIB1 / Populacao1;

    printf("Digite o Número de Pontos Turisticos da Cidade da Carta 1: ");
    scanf("%d", &PontosTuristicos1);

    // Entrada da Carta 2
    printf("Digite o Estado da Carta 2 (A-H): ");
    scanf("%s", &Estado2);
    
    printf("Digite o Código da Carta 2 (ex: B02): ");
    scanf("%s", CodigoDaCarta2);

    getchar(); // consome o \n
    printf("Digite o Nome da Cidade da Carta 2: ");
    fgets(NomeDaCidade2, 50, stdin);
    NomeDaCidade2[strcspn(NomeDaCidade2, "\n")] = '\0'; // remove o \n do final

    printf("Digite a População da Cidade da Carta 2: ");
    scanf("%lu", &Populacao2);

    printf("Digite a Área da Cidade da Carta 2 (Km²): ");
    scanf("%f", &AreaEmKm2);

    DensiPop2 = (float) Populacao2 / AreaEmKm2;

    printf("Digite o PIB da Carta 2: ");
    scanf("%f", &PIB2);

    PIBPC2 = (float) PIB2 / Populacao2;

    printf("Digite o Número de Pontos Turísticos da Cidade da Carta 2: ");
    scanf("%d", &PontosTuristicos2);

    //Cálculo do Super Poder
    float inversoDensiPop1 = (DensiPop1 == 0.0) ? 0.0 : (1.0f / DensiPop1);
    float inversoDensiPop2 = (DensiPop2 == 0.0) ? 0.0 : (1.0f / DensiPop2);

    SuperPoder1 = (float)Populacao1 + AreaEmKm1 + PIB1 + PontosTuristicos1 + PIBPC1 + inversoDensiPop1;
    SuperPoder2 = (float)Populacao2 + AreaEmKm2 + PIB2 + PontosTuristicos2 + PIBPC2 + inversoDensiPop2;

    //Menu de Comparação
    int opcao;
    printf("\n=== MENU DE COMPARAÇÃO ===\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - PIB per Capita\n");
    printf("5 - Pontos Turísticos\n");
    printf("6 - Densidade Demográfica\n");
    printf("7 - Super Poder\n");
    printf("Escolha o atributo (1-7): ");
    scanf("%d", &opcao);

    printf("\n--- Comparação de Cartas ---\n");
    switch(opcao) {
        case 1: // População
            printf("Atributo: População\n");
            printf("%s: %lu habitantes\n", NomeDaCidade1, Populacao1);
            printf("%s: %lu habitantes\n", NomeDaCidade2, Populacao2);

            if (Populacao1 > Populacao2)
                printf("Vencedor: %s\n", NomeDaCidade1);
            else if (Populacao2 > Populacao1)
                printf("Vencedor: %s\n", NomeDaCidade2);
            else
                printf("Empate!\n");
            break;

        case 2: // Área
            printf("Atributo: Área (Km²)\n");
            printf("%s: %.2f km²\n", NomeDaCidade1, AreaEmKm1);
            printf("%s: %.2f km²\n", NomeDaCidade2, AreaEmKm2);

            if (AreaEmKm1 > AreaEmKm2)
                printf("Vencedor: %s\n", NomeDaCidade1);
            else if (AreaEmKm2 > AreaEmKm1)
                printf("Vencedor: %s\n", NomeDaCidade2);
            else
                printf("Empate!\n");
            break;

        case 3: // PIB
            printf("Atributo: PIB\n");
            printf("%s: %.2f\n", NomeDaCidade1, PIB1);
            printf("%s: %.2f\n", NomeDaCidade2, PIB2);

            if (PIB1 > PIB2)
                printf("Vencedor: %s\n", NomeDaCidade1);
            else if (PIB2 > PIB1)
                printf("Vencedor: %s\n", NomeDaCidade2);
            else
                printf("Empate!\n");
            break;

        case 4: // PIB per Capita
            printf("Atributo: PIB per Capita\n");
            printf("%s: %.2f\n", NomeDaCidade1, PIBPC1);
            printf("%s: %.2f\n", NomeDaCidade2, PIBPC2);

            if (PIBPC1 > PIBPC2)
                printf("Vencedor: %s\n", NomeDaCidade1);
            else if (PIBPC2 > PIBPC1)
                printf("Vencedor: %s\n", NomeDaCidade2);
            else
                printf("Empate!\n");
            break;

        case 5: // Pontos Turísticos
            printf("Atributo: Pontos Turísticos\n");
            printf("%s: %d pontos\n", NomeDaCidade1, PontosTuristicos1);
            printf("%s: %d pontos\n", NomeDaCidade2, PontosTuristicos2);

            if (PontosTuristicos1 > PontosTuristicos2)
                printf("Vencedor: %s\n", NomeDaCidade1);
            else if (PontosTuristicos2 > PontosTuristicos1)
                printf("Vencedor: %s\n", NomeDaCidade2);
            else
                printf("Empate!\n");
            break;

        case 6: // Densidade Demográfica (regra invertida)
            printf("Atributo: Densidade Demográfica\n");
            printf("%s: %.2f hab/km²\n", NomeDaCidade1, DensiPop1);
            printf("%s: %.2f hab/km²\n", NomeDaCidade2, DensiPop2);

            if (DensiPop1 < DensiPop2) // aqui vence o MENOR
                printf("Vencedor: %s\n", NomeDaCidade1);
            else if (DensiPop2 < DensiPop1)
                printf("Vencedor: %s\n", NomeDaCidade2);
            else
                printf("Empate!\n");
            break;

        case 7: // Super Poder
            printf("Atributo: Super Poder\n");
            printf("%s: %.2f pontos\n", NomeDaCidade1, SuperPoder1);
            printf("%s: %.2f pontos\n", NomeDaCidade2, SuperPoder2);

            if (SuperPoder1 > SuperPoder2)
                printf("Vencedor: %s\n", NomeDaCidade1);
            else if (SuperPoder2 > SuperPoder1)
                printf("Vencedor: %s\n", NomeDaCidade2);
            else
                printf("Empate!\n");
            break;

        default:
            printf("Opção inválida!\n");
    }

    return 0;
}