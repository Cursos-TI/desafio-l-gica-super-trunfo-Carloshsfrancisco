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

    // Menu de atributos
    int opcao1, opcao2;
    printf("\n=== MENU DE ATRIBUTOS ===\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - PIB per Capita\n");
    printf("5 - Pontos Turísticos\n");
    printf("6 - Densidade Demográfica\n");
    printf("7 - Super Poder\n");
    printf("Escolha o PRIMEIRO atributo (1-7): ");
    scanf("%d", &opcao1);

    // Menu dinâmico (o escolhido antes desaparece)
    printf("\n=== SEGUNDO ATRIBUTO ===\n");
    for (int i = 1; i <= 7; i++) {
        if (i == opcao1) continue;
        switch (i) {
            case 1: printf("1 - População\n"); break;
            case 2: printf("2 - Área\n"); break;
            case 3: printf("3 - PIB\n"); break;
            case 4: printf("4 - PIB per Capita\n"); break;
            case 5: printf("5 - Pontos Turísticos\n"); break;
            case 6: printf("6 - Densidade Demográfica\n"); break;
            case 7: printf("7 - Super Poder\n"); break;
        }
    }
    printf("Escolha o SEGUNDO atributo: ");
    scanf("%d", &opcao2);

    // Função auxiliar para pegar valores
    float valor1, valor2;
    char nomeAtributo[50];
    int i;
    float soma1 = 0, soma2 = 0;

    for (i = 1; i <= 2; i++) {
        int opcao = (i == 1) ? opcao1 : opcao2;
        switch(opcao) {
            case 1:
                valor1 = (float)Populacao1;
                valor2 = (float)Populacao2;
                strcpy(nomeAtributo, "População");
                break;
            case 2:
                valor1 = AreaEmKm1;
                valor2 = AreaEmKm2;
                strcpy(nomeAtributo, "Área");
                break;
            case 3:
                valor1 = PIB1;
                valor2 = PIB2;
                strcpy(nomeAtributo, "PIB");
                break;
            case 4:
                valor1 = PIBPC1;
                valor2 = PIBPC2;
                strcpy(nomeAtributo, "PIB per Capita");
                break;
            case 5:
                valor1 = (float)PontosTuristicos1;
                valor2 = (float)PontosTuristicos2;
                strcpy(nomeAtributo, "Pontos Turísticos");
                break;
            case 6:
                valor1 = DensiPop1;
                valor2 = DensiPop2;
                strcpy(nomeAtributo, "Densidade Demográfica");
                break;
            case 7:
                valor1 = SuperPoder1;
                valor2 = SuperPoder2;
                strcpy(nomeAtributo, "Super Poder");
                break;
            default:
                printf("Opção inválida!\n");
                return 0;
        }

        printf("\n--- Comparação %d ---\n", i);
        printf("Atributo: %s\n", nomeAtributo);
        printf("%s: %.2f\n", NomeDaCidade1, valor1);
        printf("%s: %.2f\n", NomeDaCidade2, valor2);

        // Regra normal (maior vence), exceção para densidade
        if (opcao == 6) {
            soma1 += (valor1 < valor2) ? valor1 : 0;
            soma2 += (valor2 < valor1) ? valor2 : 0;
        } else {
            soma1 += (valor1 > valor2) ? valor1 : 0;
            soma2 += (valor2 > valor1) ? valor2 : 0;
        }
    }

    // Exibe resultado final
    printf("\n=== RESULTADO FINAL ===\n");
    printf("Soma dos atributos:\n");
    printf("%s: %.2f\n", NomeDaCidade1, soma1);
    printf("%s: %.2f\n", NomeDaCidade2, soma2);

    if (soma1 > soma2)
        printf("Vencedor: %s\n", NomeDaCidade1);
    else if (soma2 > soma1)
        printf("Vencedor: %s\n", NomeDaCidade2);
    else
        printf("Empate!\n");

    return 0;
}