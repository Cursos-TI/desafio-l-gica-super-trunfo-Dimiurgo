#include <stdio.h>
#include <stdbool.h>

int main() {
    // Variáveis para a primeira carta
    char estado1;
    char codigo1[4];
    char cidade1[50];
    unsigned long int populacao1;
    float area1;
    float pib1;
    int pontosTuristicos1;
    float densidadePopulacional1; // Nova variável para densidade populacional
    float pibPerCapita1; // Nova variável para PIB per capita

    // Variáveis para a segunda carta
    char estado2;
    char codigo2[4];
    char cidade2[50];
    unsigned long int populacao2;
    float area2;
    float pib2;
    int pontosTuristicos2;
    float densidadePopulacional2; // Nova variável para densidade populacional
    float pibPerCapita2; // Nova variável para PIB per capita

    // Variáveis para escolha do menu
    int opcao1, opcao2;
    
    // Variáveis para armazenar valores dos atributos selecionados para comparação
    float valor1_carta1, valor1_carta2; // Primeiro atributo
    float valor2_carta1, valor2_carta2; // Segundo atributo
    float soma_carta1, soma_carta2;     // Soma dos atributos
    bool atributo1_inverso = false;     // Flag para atributos onde menor valor vence
    bool atributo2_inverso = false;    
    char nome_atributo1[30], nome_atributo2[30]; // Nomes dos atributos

    // Leitura dos dados da primeira carta
    printf("\n=== Cadastro da Primeira Carta ===\n");
    printf("Digite o estado (A-H): ");
    scanf(" %c", &estado1);
    printf("Digite o código da carta (ex: A01): ");
    scanf("%s", codigo1);
    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]s", cidade1);
    printf("Digite a população: ");
    scanf("%lu", &populacao1);
    printf("Digite a área em km²: ");
    scanf("%f", &area1);
    printf("Digite o PIB (em bilhões): ");
    scanf("%f", &pib1);
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &pontosTuristicos1);

    // Cálculo da densidade populacional e PIB per capita para a primeira carta
    densidadePopulacional1 = populacao1 / area1;
    pibPerCapita1 = (pib1 * 1000000000.0) / populacao1;

    // Leitura dos dados da segunda carta
    printf("\n=== Cadastro da Segunda Carta ===\n");
    printf("Digite o estado (A-H): ");
    scanf(" %c", &estado2);
    printf("Digite o código da carta (ex: A01): ");
    scanf("%s", codigo2);
    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]s", cidade2);
    printf("Digite a população: ");
    scanf("%lu", &populacao2);
    printf("Digite a área em km²: ");
    scanf("%f", &area2);
    printf("Digite o PIB (em bilhões): ");
    scanf("%f", &pib2);
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &pontosTuristicos2);

    // Cálculo da densidade populacional e PIB per capita para a segunda carta
    densidadePopulacional2 = populacao2 / area2;
    pibPerCapita2 = (pib2 * 1000000000.0) / populacao2;

    // Exibição dos dados da primeira carta
    printf("\nCarta 1:\n");
    printf("Estado: %c\n", estado1);
    printf("Código: %s\n", codigo1);
    printf("Nome da Cidade: %s\n", cidade1);
    printf("População: %lu\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %.2f bilhões de reais\n", pib1);
    printf("Número de Pontos Turísticos: %d\n", pontosTuristicos1);
    printf("Densidade Populacional: %.2f hab/km²\n", densidadePopulacional1);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita1);

    // Exibição dos dados da segunda carta
    printf("\nCarta 2:\n");
    printf("Estado: %c\n", estado2);
    printf("Código: %s\n", codigo2);
    printf("Nome da Cidade: %s\n", cidade2);
    printf("População: %lu\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("Número de Pontos Turísticos: %d\n", pontosTuristicos2);
    printf("Densidade Populacional: %.2f hab/km²\n", densidadePopulacional2);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita2);

    printf("\n\n======= MENU DE COMPARAÇÃO - PRIMEIRO ATRIBUTO =======\n");
    printf("Escolha o primeiro atributo para comparar as cartas:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Populacional\n");
    printf("6 - PIB per Capita\n");
    printf("Digite sua opção (1-6): ");
    scanf("%d", &opcao1);
    
    // Validação da primeira opção
    while (opcao1 < 1 || opcao1 > 6) {
        printf("Opção inválida! Por favor, escolha um número de 1 a 6: ");
        scanf("%d", &opcao1);
    }
    
    // Armazenar valores do primeiro atributo selecionado
    switch(opcao1) {
        case 1: // População
            valor1_carta1 = (float)populacao1;
            valor1_carta2 = (float)populacao2;
            strcpy(nome_atributo1, "População");
            break;
        case 2: // Área
            valor1_carta1 = area1;
            valor1_carta2 = area2;
            strcpy(nome_atributo1, "Área");
            break;
        case 3: // PIB
            valor1_carta1 = pib1;
            valor1_carta2 = pib2;
            strcpy(nome_atributo1, "PIB");
            break;
        case 4: // Pontos Turísticos
            valor1_carta1 = (float)pontosTuristicos1;
            valor1_carta2 = (float)pontosTuristicos2;
            strcpy(nome_atributo1, "Pontos Turísticos");
            break;
        case 5: // Densidade Populacional - menor valor vence
            valor1_carta1 = densidadePopulacional1;
            valor1_carta2 = densidadePopulacional2;
            atributo1_inverso = true;
            strcpy(nome_atributo1, "Densidade Populacional");
            break;
        case 6: // PIB per Capita
            valor1_carta1 = pibPerCapita1;
            valor1_carta2 = pibPerCapita2;
            strcpy(nome_atributo1, "PIB per Capita");
            break;
    }
    
    printf("\n\n======= MENU DE COMPARAÇÃO - SEGUNDO ATRIBUTO =======\n");
    printf("Escolha o segundo atributo para comparar as cartas:\n");
    
    
    for (int i = 1; i <= 6; i++) {
        if (i != opcao1) { // Exclui o atributo já escolhido
            switch(i) {
                case 1:
                    printf("%d - População\n", i);
                    break;
                case 2:
                    printf("%d - Área\n", i);
                    break;
                case 3:
                    printf("%d - PIB\n", i);
                    break;
                case 4:
                    printf("%d - Pontos Turísticos\n", i);
                    break;
                case 5:
                    printf("%d - Densidade Populacional\n", i);
                    break;
                case 6:
                    printf("%d - PIB per Capita\n", i);
                    break;
            }
        }
    }
    
    printf("Digite sua opção (1-6, exceto %d): ", opcao1);
    scanf("%d", &opcao2);
    
    // Validação da segunda opção
    while (opcao2 < 1 || opcao2 > 6 || opcao2 == opcao1) {
        printf("Opção inválida ou igual à primeira escolha! Por favor, escolha um número diferente de %d: ", opcao1);
        scanf("%d", &opcao2);
    }
    
    // Armazenar valores do segundo atributo selecionado
    switch(opcao2) {
        case 1: // População
            valor2_carta1 = (float)populacao1;
            valor2_carta2 = (float)populacao2;
            strcpy(nome_atributo2, "População");
            break;
        case 2: // Área
            valor2_carta1 = area1;
            valor2_carta2 = area2;
            strcpy(nome_atributo2, "Área");
            break;
        case 3: // PIB
            valor2_carta1 = pib1;
            valor2_carta2 = pib2;
            strcpy(nome_atributo2, "PIB");
            break;
        case 4: // Pontos Turísticos
            valor2_carta1 = (float)pontosTuristicos1;
            valor2_carta2 = (float)pontosTuristicos2;
            strcpy(nome_atributo2, "Pontos Turísticos");
            break;
        case 5: // Densidade Populacional - menor valor vence
            valor2_carta1 = densidadePopulacional1;
            valor2_carta2 = densidadePopulacional2;
            atributo2_inverso = true;
            strcpy(nome_atributo2, "Densidade Populacional");
            break;
        case 6: // PIB per Capita
            valor2_carta1 = pibPerCapita1;
            valor2_carta2 = pibPerCapita2;
            strcpy(nome_atributo2, "PIB per Capita");
            break;
    }
    
    // Comparação e cálculo da soma de atributos
    float pontos_carta1_atributo1 = atributo1_inverso ? 
        (valor1_carta1 < valor1_carta2 ? valor1_carta1 : 0) : 
        (valor1_carta1 > valor1_carta2 ? valor1_carta1 : 0);
        
    float pontos_carta2_atributo1 = atributo1_inverso ? 
        (valor1_carta2 < valor1_carta1 ? valor1_carta2 : 0) : 
        (valor1_carta2 > valor1_carta1 ? valor1_carta2 : 0);
        
    float pontos_carta1_atributo2 = atributo2_inverso ? 
        (valor2_carta1 < valor2_carta2 ? valor2_carta1 : 0) : 
        (valor2_carta1 > valor2_carta2 ? valor2_carta1 : 0);
        
    float pontos_carta2_atributo2 = atributo2_inverso ? 
        (valor2_carta2 < valor2_carta1 ? valor2_carta2 : 0) : 
        (valor2_carta2 > valor2_carta1 ? valor2_carta2 : 0);
        
    // Soma dos valores para determinar o vencedor
    soma_carta1 = valor1_carta1 + valor2_carta1;
    soma_carta2 = valor1_carta2 + valor2_carta2;
    
    // Resultados das comparações individuais
    int resultado_atributo1 = atributo1_inverso ? 
        (valor1_carta1 < valor1_carta2 ? 1 : (valor1_carta1 > valor1_carta2 ? 2 : 0)) : 
        (valor1_carta1 > valor1_carta2 ? 1 : (valor1_carta1 < valor1_carta2 ? 2 : 0));
        
    int resultado_atributo2 = atributo2_inverso ? 
        (valor2_carta1 < valor2_carta2 ? 1 : (valor2_carta1 > valor2_carta2 ? 2 : 0)) : 
        (valor2_carta1 > valor2_carta2 ? 1 : (valor2_carta1 < valor2_carta2 ? 2 : 0));
    
    // Exibição dos resultados
    printf("\n\n======= RESULTADO DA COMPARAÇÃO =======\n");
    printf("Atributos escolhidos: %s e %s\n\n", nome_atributo1, nome_atributo2);
    
    // Mostrar comparação do primeiro atributo
    printf("ATRIBUTO 1: %s\n", nome_atributo1);
    printf("Carta 1 - %s: ", cidade1);
    
    if (opcao1 == 1) {
        printf("%lu habitantes\n", populacao1);
        printf("Carta 2 - %s: %lu habitantes\n", cidade2, populacao2);
    } else if (opcao1 == 2) {
        printf("%.2f km²\n", area1);
        printf("Carta 2 - %s: %.2f km²\n", cidade2, area2);
    } else if (opcao1 == 3) {
        printf("%.2f bilhões\n", pib1);
        printf("Carta 2 - %s: %.2f bilhões\n", cidade2, pib2);
    } else if (opcao1 == 4) {
        printf("%d pontos\n", pontosTuristicos1);
        printf("Carta 2 - %s: %d pontos\n", cidade2, pontosTuristicos2);
    } else if (opcao1 == 5) {
        printf("%.2f hab/km²\n", densidadePopulacional1);
        printf("Carta 2 - %s: %.2f hab/km²\n", cidade2, densidadePopulacional2);
    } else if (opcao1 == 6) {
        printf("%.2f reais\n", pibPerCapita1);
        printf("Carta 2 - %s: %.2f reais\n", cidade2, pibPerCapita2);
    }
    
    // Resultado do primeiro atributo
    if (resultado_atributo1 == 1) {
        printf("Vencedor no atributo %s: Carta 1 (%s)%s\n", nome_atributo1, cidade1, atributo1_inverso ? " (menor valor vence)" : "");
    } else if (resultado_atributo1 == 2) {
        printf("Vencedor no atributo %s: Carta 2 (%s)%s\n", nome_atributo1, cidade2, atributo1_inverso ? " (menor valor vence)" : "");
    } else {
        printf("Empate no atributo %s!\n", nome_atributo1);
    }
    
    // Mostrar comparação do segundo atributo
    printf("\nATRIBUTO 2: %s\n", nome_atributo2);
    printf("Carta 1 - %s: ", cidade1);
    
    if (opcao2 == 1) {
        printf("%lu habitantes\n", populacao1);
        printf("Carta 2 - %s: %lu habitantes\n", cidade2, populacao2);
    } else if (opcao2 == 2) {
        printf("%.2f km²\n", area1);
        printf("Carta 2 - %s: %.2f km²\n", cidade2, area2);
    } else if (opcao2 == 3) {
        printf("%.2f bilhões\n", pib1);
        printf("Carta 2 - %s: %.2f bilhões\n", cidade2, pib2);
    } else if (opcao2 == 4) {
        printf("%d pontos\n", pontosTuristicos1);
        printf("Carta 2 - %s: %d pontos\n", cidade2, pontosTuristicos2);
    } else if (opcao2 == 5) {
        printf("%.2f hab/km²\n", densidadePopulacional1);
        printf("Carta 2 - %s: %.2f hab/km²\n", cidade2, densidadePopulacional2);
    } else if (opcao2 == 6) {
        printf("%.2f reais\n", pibPerCapita1);
        printf("Carta 2 - %s: %.2f reais\n", cidade2, pibPerCapita2);
    }
    
    // Resultado do segundo atributo
    if (resultado_atributo2 == 1) {
        printf("Vencedor no atributo %s: Carta 1 (%s)%s\n", nome_atributo2, cidade1, atributo2_inverso ? " (menor valor vence)" : "");
    } else if (resultado_atributo2 == 2) {
        printf("Vencedor no atributo %s: Carta 2 (%s)%s\n", nome_atributo2, cidade2, atributo2_inverso ? " (menor valor vence)" : "");
    } else {
        printf("Empate no atributo %s!\n", nome_atributo2);
    }
    
    // Exibir soma e resultado final
    printf("\n======= SOMA DOS ATRIBUTOS =======\n");
    printf("Carta 1 - %s: %.2f\n", cidade1, soma_carta1);
    printf("Carta 2 - %s: %.2f\n", cidade2, soma_carta2);
    
    // Determina vencedor geral baseado na soma
    if (soma_carta1 > soma_carta2) {
        printf("\n===== RESULTADO FINAL =====\n");
        printf("Vencedor: Carta 1 (%s) com soma de atributos = %.2f\n", cidade1, soma_carta1);
    } else if (soma_carta2 > soma_carta1) {
        printf("\n===== RESULTADO FINAL =====\n");
        printf("Vencedor: Carta 2 (%s) com soma de atributos = %.2f\n", cidade2, soma_carta2);
    } else {
        printf("\n===== RESULTADO FINAL =====\n");
        printf("EMPATE! Ambas as cartas somam %.2f\n", soma_carta1);
    }
    
    return 0;
}