#include <stdio.h>
#include <string.h>

struct aluno {
    char nome[150];
    int idade, mensal;
    float peso, altura, imc;
};

int main() {
    int cont = 0, menu;
    struct aluno alunos[5];

    printf("--------- Cadastro ---------\n");
    do {
        printf("\nCadastro %dº aluno", cont + 1);
        printf("\nNome completo: ");
        fgets(alunos[cont].nome, sizeof(alunos[cont].nome), stdin);
        alunos[cont].nome[strcspn(alunos[cont].nome, "\n")] = 0;

        printf("Idade: ");
        scanf("%d", &alunos[cont].idade);
        getchar();

        printf("Peso: ");
        scanf("%f", &alunos[cont].peso);
        getchar();

        printf("Altura: ");
        scanf("%f", &alunos[cont].altura);
        getchar();

        printf("Plano mensal (1 – Mensal, 2 – Trimestral, 3 – Anual)");
        printf("\nPlano escolhido: ");
        scanf("%d", &alunos[cont].mensal);
        getchar();

        alunos[cont].imc = alunos[cont].peso / (alunos[cont].altura * alunos[cont].altura);
        cont++;
    } while (cont < 5);

    printf("\n------ Menu principal ------\n");
    printf("1. Listar todos os alunos e seus dados\n");
    printf("2. Pesquisar aluno pelo nome e mostrar detalhes\n");
    printf("3. Mostrar a média de idade dos alunos cadastrados\n");
    printf("4. Alterar o plano de um aluno\n");
    printf("5. Sair do programa\n");

    do {
        printf("\nDigite sua opção: ");
        scanf("%d", &menu);
        getchar();
        if (menu < 1 || menu > 5) {
            printf("Opção inválida, tente novamente.\n");
        }
    } while (menu > 1 && menu < 5);

    switch (menu) {
        case 1:
            printf("------ Lista de Alunos e dados ------\n");
            for (cont = 0; cont < 5; cont++) {
                printf("\n------ Ficha %dº aluno ------", cont + 1);
                printf("\nNome: %s", alunos[cont].nome);
                printf("\nIdade: %d", alunos[cont].idade);
                printf("\nPeso: %.1f", alunos[cont].peso);
                printf("\nAltura: %.2f", alunos[cont].altura);
                printf("\nIMC: %.2f - ", alunos[cont].imc);

                if (alunos[cont].imc < 18.5) {
                    printf("Abaixo do peso.\n");
                } else if (alunos[cont].imc <= 24.9) {
                    printf("Peso normal.\n");
                } else if (alunos[cont].imc <= 29.9) {
                    printf("Acima do peso.\n");
                } else {
                    printf("Obesidade.\n");
                }
            }
            break;

        case 2: {
            char nom_dig[150];
            int encontrado = 0;
            printf("\n------ Pesquisar aluno por nome ------");
            printf("\nDigite o nome para mostrar os dados: ");
            fgets(nom_dig, sizeof(nom_dig), stdin);
            nom_dig[strcspn(nom_dig, "\n")] = 0;

            for (cont = 0; cont < 5; cont++) {
                if (strcmp(nom_dig, alunos[cont].nome) == 0) {
                    encontrado = 1;
                    printf("\nSegue os dados do aluno digitado:");
                    printf("\n------ Ficha do aluno ------");
                    printf("\nNome: %s", alunos[cont].nome);
                    printf("\nIdade: %d", alunos[cont].idade);
                    printf("\nPeso: %.1f", alunos[cont].peso);
                    printf("\nAltura: %.2f", alunos[cont].altura);
                    printf("\nIMC: %.2f - ", alunos[cont].imc);

                    if (alunos[cont].imc < 18.5) {
                        printf("Abaixo do peso.\n");
                    } else if (alunos[cont].imc <= 24.9) {
                        printf("Peso normal.\n");
                    } else if (alunos[cont].imc <= 29.9) {
                        printf("Acima do peso.\n");
                    } else {
                        printf("Obesidade.\n");
                    }
                    break;
                }
            }
            if (!encontrado) {
                printf("\nAluno não encontrado.\n");
            }
            break;
        }

        case 3: {
            int soma = 0;
            for (cont = 0; cont < 5; cont++) {
                soma += alunos[cont].idade;
            }
            float media = soma / 5.0;
            printf("------ Média de idade dos alunos ------");
            printf("\nA média de idade é: %.1f anos\n", media);
            break;
        }

        case 4: {
            char nom_dig[150];
            int encontrado = 0;
            printf("------ Alteração de plano de aluno ------");
            printf("\nDigite o nome do aluno que quer alterar o plano: ");
            fgets(nom_dig, sizeof(nom_dig), stdin);
            nom_dig[strcspn(nom_dig, "\n")] = 0;

            for (cont = 0; cont < 5; cont++) {
                if (strcmp(nom_dig, alunos[cont].nome) == 0) {
                    encontrado = 1;
                    printf("Plano atual: %d\n", alunos[cont].mensal);
                    printf("Digite o novo plano (1 – Mensal, 2 – Trimestral, 3 – Anual): ");
                    scanf("%d", &alunos[cont].mensal);
                    getchar();
                    printf("Plano alterado com sucesso!\n");
                    break;
                }
            }
            if (!encontrado) {
                printf("Aluno não encontrado.\n");
            }
            break;
        }

        case 5:
            printf("----- Opção selecionada foi 'Saída' ------");
            printf("\nFim do código.\n");
            break;
    }

    return 0;
}