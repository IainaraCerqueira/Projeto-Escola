#ifndef relatorios_h
#endif

#include "funcoes.h"

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define tam 100
#define max 3
#define maxmatri 41
#define extrapolar maxmatri - 40

int menuRelatoriosProf()
{
    int menurelatorio_p;
    printf("\nSelecione um relatorio\n");
    printf("\n1- Listar Professores\n2- Listar Professores por sexo\n3- Listar "
           "Professores por data de nascimento\n4- Listar professores por ordem "
           "alfabetica\n5-Aniversariante do mes\n6-Sair\n");
    scanf("%d", &menurelatorio_p);
    return menurelatorio_p;
}

void listarprofsexo(cadastro listaProfessores[], int professores_cadastrados)
{
    char sexo;
    if (professores_cadastrados == 0)
    {
        printf("Sem professores cadastrados.\n");
    }
    else
    {
        printf("Qual sexo deseja listar?\n");
        scanf(" %c", &sexo);

        if (sexo == 'F' || sexo == 'f')
        {
            for (int i = 0; i < professores_cadastrados; i++)
            {
                if (listaProfessores[i].sexo == 'F')
                {
                    printf("\n");
                    printf("Professor #%i:\n", i + 1);
                    printf("%s\n", listaProfessores[i].nome);
                    printf("Matrícula: %s\n", listaProfessores[i].matricula);
                    printf("Sexo: %c\n", listaProfessores[i].sexo);
                    printf("CPF: %s\n", listaProfessores[i].cpf);
                    printf("Data de nascimento: %02d/%02d/%d\n",
                           listaProfessores[i].data_nascimento.dia,
                           listaProfessores[i].data_nascimento.mes,
                           listaProfessores[i].data_nascimento.ano);
                    printf("\n");
                }
                else
                {
                    printf("Nao ha professores do sexo feminino cadastrados.\n");
                }
            }
        }
        else
        {
            for (int i = 0; i < professores_cadastrados; i++)
            {
                if (listaProfessores[i].sexo == 'M')
                {
                    printf("\n");
                    printf("Professor #%i:\n", i + 1);
                    printf("%s\n", listaProfessores[i].nome);
                    printf("Matrícula: %s\n", listaProfessores[i].matricula);
                    printf("Sexo: %c\n", listaProfessores[i].sexo);
                    printf("CPF: %s\n", listaProfessores[i].cpf);
                    printf("Data de nascimento: %02d/%02d/%d\n",
                           listaProfessores[i].data_nascimento.dia,
                           listaProfessores[i].data_nascimento.mes,
                           listaProfessores[i].data_nascimento.ano);
                    printf("\n");
                }
                else
                {
                    printf("Nao ha professores do sexo masculino cadastrados.\n");
                }
            }
        }
    }
}

void listarprofniver(cadastro listaProfessores[], int professores_cadastrados)
{
    int mes;

    if (professores_cadastrados == 0)
    {
        printf("Sem professores cadastrados.\n");
    }
    else
    {
        printf("Qual mês deseja listar?\n");
        scanf(" %d", &mes);

        for (int i = 0; i < professores_cadastrados; i++)
        {
            if (listaProfessores[i].data_nascimento.mes == mes)
            {
                printf("\n");
                printf("Professor #%i:\n", i + 1);
                printf("%s\n", listaProfessores[i].nome);
                printf("Matrícula: %s\n", listaProfessores[i].matricula);
                printf("Sexo: %c\n", listaProfessores[i].sexo);
                printf("CPF: %s\n", listaProfessores[i].cpf);
                printf("Data de nascimento: %02d/%02d/%d\n",
                       listaProfessores[i].data_nascimento.dia,
                       listaProfessores[i].data_nascimento.mes,
                       listaProfessores[i].data_nascimento.ano);
                printf("\n");
            }
            else
            {
                printf("Não há professores nascidos nesse mês.\n");
            }
        }
    }
}
void listaprofalfabeto(cadastro listaProfessores[], int professores_cadastrados)
{
    int i, j, r;
    cadastro aux[1];
    if (professores_cadastrados == 0)
    {
        printf("Sem professores cadastrados.\n");
    }
    else
    {
        for (i = 0; i < professores_cadastrados; i++)
        {
            for (j = i + 1; j < professores_cadastrados; j++)
            {
                r = strcmp(listaProfessores[i].nome, listaProfessores[j].nome);
                if (r > 0)
                {
                    aux[i] = listaProfessores[i];
                    listaProfessores[i] = listaProfessores[j];
                    listaProfessores[j] = aux[i];
                }
            }
        }
        for (i = 0; i < professores_cadastrados; i++)
        {
            printf("\n");
            printf("Professor #%d:\n", i + 1);
            printf("%s\n", listaProfessores[i].nome);
            printf("Matrícula: %s\n", listaProfessores[i].matricula);
            printf("Sexo: %c\n", listaProfessores[i].sexo);
            printf("CPF: %s\n", listaProfessores[i].cpf);
            printf("Data de nascimento: %02i/%02i/%i\n",
                   listaProfessores[i].data_nascimento.dia,
                   listaProfessores[i].data_nascimento.mes,
                   listaProfessores[i].data_nascimento.ano);
            printf("\n");
        }
    }
}

void listaprofidade(cadastro listaProfessores[], int professores_cadastrados)
{
    cadastro aux[1];
    if (professores_cadastrados == 0)
    {
        printf("Sem professores cadastrados.\n");
    }
    else
    {
        for (int i = 0; i < professores_cadastrados; i++)
        {
            for (int j = i + 1; j < professores_cadastrados; j++)
            {
                if (listaProfessores[i].data_nascimento.ano >
                    listaProfessores[j].data_nascimento.ano)
                {
                    aux[i] = listaProfessores[i];
                    listaProfessores[i] = listaProfessores[j];
                    listaProfessores[j] = aux[i];
                }
                else if ((listaProfessores[i].data_nascimento.ano ==
                          listaProfessores[j].data_nascimento.ano) &&
                         (listaProfessores[i].data_nascimento.mes >
                          listaProfessores[j].data_nascimento.mes))
                {
                    aux[i] = listaProfessores[i];
                    listaProfessores[i] = listaProfessores[j];
                    listaProfessores[j] = aux[i];
                }
                else if ((listaProfessores[i].data_nascimento.ano ==
                          listaProfessores[j].data_nascimento.ano) &&
                         (listaProfessores[i].data_nascimento.mes ==
                          listaProfessores[j].data_nascimento.mes) &&
                         (listaProfessores[i].data_nascimento.dia >
                          listaProfessores[j].data_nascimento.dia))
                {
                    aux[i] = listaProfessores[i];
                    listaProfessores[i] = listaProfessores[j];
                    listaProfessores[j] = aux[i];
                }
            }
        }
    }

    for (int i = 0; i < professores_cadastrados; i++)
    {
        printf("\n");
        printf("Professor #%d:\n", i + 1);
        printf("%s\n", listaProfessores[i].nome);
        printf("Matrícula: %s\n", listaProfessores[i].matricula);
        printf("Sexo: %c\n", listaProfessores[i].sexo);
        printf("CPF: %s\n", listaProfessores[i].cpf);
        printf("Data de nascimento: %02i/%02i/%i\n",
               listaProfessores[i].data_nascimento.dia,
               listaProfessores[i].data_nascimento.mes,
               listaProfessores[i].data_nascimento.ano);
        printf("\n");
    }
}

/// relatorios alunos
int menuRelatoriosAlu()
{
    int menurelatorio_a;
    printf("\nSelecione um relatorio\n");
    printf("\n1- Listar Alunos\n2- Listar Alunos por sexo\n3- Listar Alunos por "
           "data de nascimento\n4- Listar Alunos por ordem "
           "alfabetica\n5- Listar Aniversariantes do mes\n6 -Listar Alunos cadastrados em menos de tres disciplina\n7- Sair\n");
    scanf("%d", &menurelatorio_a);
    return menurelatorio_a;
}

void listaralusexo(cadastro listaAlunos[], int alunos_cadastrados)
{
    char sexo;
    if (alunos_cadastrados == 0)
    {
        printf("Sem alunos cadastrados.\n");
    }
    else
    {
        printf("Qual sexo deseja listar?\n");
        scanf(" %c", &sexo);

        if (sexo == 'F' || sexo == 'f')
        {
            for (int i = 0; i < alunos_cadastrados; i++)
            {
                if (listaAlunos[i].sexo == 'F')
                {
                    printf("\n");
                    printf("Aluno #%i:\n", i + 1);
                    printf("%s\n", listaAlunos[i].nome);
                    printf("Matrícula: %s\n", listaAlunos[i].matricula);
                    printf("Sexo: %c\n", listaAlunos[i].sexo);
                    printf("CPF: %s\n", listaAlunos[i].cpf);
                    printf("Data de nascimento: %02d/%02d/%d\n",
                           listaAlunos[i].data_nascimento.dia,
                           listaAlunos[i].data_nascimento.mes,
                           listaAlunos[i].data_nascimento.ano);
                    printf("\n");
                }
                else
                {
                    printf("Nao ha alunos do sexo feminino cadastrados.\n");
                }
            }
        }
        else
        {
            for (int i = 0; i < alunos_cadastrados; i++)
            {
                if (listaAlunos[i].sexo == 'M')
                {
                    printf("\n");
                    printf("Aluno #%i:\n", i + 1);
                    printf("%s\n", listaAlunos[i].nome);
                    printf("Matrícula: %s\n", listaAlunos[i].matricula);
                    printf("Sexo: %c\n", listaAlunos[i].sexo);
                    printf("CPF: %s\n", listaAlunos[i].cpf);
                    printf("Data de nascimento: %02d/%02d/%d\n",
                           listaAlunos[i].data_nascimento.dia,
                           listaAlunos[i].data_nascimento.mes,
                           listaAlunos[i].data_nascimento.ano);
                    printf("\n");
                }
                else
                {
                    printf("Nao ha alunos do sexo masculino cadastrados.\n");
                }
            }
        }
    }
}

void listaraluniver(cadastro listaAlunos[], int alunos_cadastrados)
{
    int mes;

    if (alunos_cadastrados == 0)
    {
        printf("Sem alunos cadastrados.\n");
    }
    else
    {
        printf("Qual mês deseja listar?\n");
        scanf(" %d", &mes);

        for (int i = 0; i < alunos_cadastrados; i++)
        {
            if (listaAlunos[i].data_nascimento.mes == mes)
            {
                printf("\n");
                printf("Aluno #%i:\n", i + 1);
                printf("%s\n", listaAlunos[i].nome);
                printf("Matrícula: %s\n", listaAlunos[i].matricula);
                printf("Sexo: %c\n", listaAlunos[i].sexo);
                printf("CPF: %s\n", listaAlunos[i].cpf);
                printf("Data de nascimento: %02d/%02d/%d\n",
                       listaAlunos[i].data_nascimento.dia,
                       listaAlunos[i].data_nascimento.mes,
                       listaAlunos[i].data_nascimento.ano);
                printf("\n");
            }
            else
            {
                printf("Não há alunos nascidos nesse mês.\n");
            }
        }
    }
}

void listaralualfabeto(cadastro listaAlunos[], int alunos_cadastrados)
{
    int i, j, r;
    cadastro aux[1];
    if (alunos_cadastrados == 0)
    {
        printf("Sem alunos cadastrados.\n");
    }
    else
    {
        for (i = 0; i < alunos_cadastrados; i++)
        {
            for (j = i + 1; j < alunos_cadastrados; j++)
            {
                r = strcmp(listaAlunos[i].nome, listaAlunos[j].nome);
                if (r > 0)
                {
                    aux[i] = listaAlunos[i];
                    listaAlunos[i] = listaAlunos[j];
                    listaAlunos[j] = aux[i];
                }
            }
        }
        for (i = 0; i < alunos_cadastrados; i++)
        {
            printf("\n");
            printf("Aluno #%d:\n", i + 1);
            printf("%s\n", listaAlunos[i].nome);
            printf("Matrícula: %s\n", listaAlunos[i].matricula);
            printf("Sexo: %c\n", listaAlunos[i].sexo);
            printf("CPF: %s\n", listaAlunos[i].cpf);
            printf("Data de nascimento: %02i/%02i/%i\n",
                   listaAlunos[i].data_nascimento.dia,
                   listaAlunos[i].data_nascimento.mes,
                   listaAlunos[i].data_nascimento.ano);
            printf("\n");
        }
    }
}

void listasaluidade(cadastro listaAlunos[], int alunos_cadastrados)
{
    cadastro aux[1];
    if (alunos_cadastrados == 0)
    {
        printf("Sem alunos cadastrados.\n");
    }
    else
    {
        for (int i = 0; i < alunos_cadastrados; i++)
        {
            for (int j = i + 1; j < alunos_cadastrados; j++)
            {
                if (listaAlunos[i].data_nascimento.ano >
                    listaAlunos[j].data_nascimento.ano)
                {
                    aux[i] = listaAlunos[i];
                    listaAlunos[i] = listaAlunos[j];
                    listaAlunos[j] = aux[i];
                }
                else if ((listaAlunos[i].data_nascimento.ano ==
                          listaAlunos[j].data_nascimento.ano) &&
                         (listaAlunos[i].data_nascimento.mes >
                          listaAlunos[j].data_nascimento.mes))
                {
                    aux[i] = listaAlunos[i];
                    listaAlunos[i] = listaAlunos[j];
                    listaAlunos[j] = aux[i];
                }
                else if ((listaAlunos[i].data_nascimento.ano ==
                          listaAlunos[j].data_nascimento.ano) &&
                         (listaAlunos[i].data_nascimento.mes ==
                          listaAlunos[j].data_nascimento.mes) &&
                         (listaAlunos[i].data_nascimento.dia >
                          listaAlunos[j].data_nascimento.dia))
                {
                    aux[i] = listaAlunos[i];
                    listaAlunos[i] = listaAlunos[j];
                    listaAlunos[j] = aux[i];
                }
            }
        }
    }
    for (int i = 0; i < alunos_cadastrados; i++)
    {
        printf("\n");
        printf("Aluno #%d:\n", i + 1);
        printf("%s\n", listaAlunos[i].nome);
        printf("Matrícula: %s\n", listaAlunos[i].matricula);
        printf("Sexo: %c\n", listaAlunos[i].sexo);
        printf("CPF: %s\n", listaAlunos[i].cpf);
        printf("Data de nascimento: %02i/%02i/%i\n", listaAlunos[i].data_nascimento.dia,
               listaAlunos[i].data_nascimento.mes,
               listaAlunos[i].data_nascimento.ano);
        printf("\n");
    }
}

// relatorios disciplinas

void extrapolarDisciplinas(int disciplinas_cadastradas, disciplina listaDisciplinas[])
{
    int a = 0;
    if (disciplinas_cadastradas == 0)
        printf("\nNenhuma matéria cadastrada para exibir.\n");
    for (int i = 0; i < disciplinas_cadastradas; i++)
    {
        if (listaDisciplinas[i].alunos_disciplina < extrapolar)
        {
            printf("\nA disciplina %s tem mais de 40 vagas disponiveis.\n", listaDisciplinas[i].nome);
            a++;
        }
        if (a == 0)
        {
            printf("\nNenhuma matéria com mais de 40 vagas.\n");
        }
    }
}

void listarAlunoPoucaDisci(cadastro listaAlunos[], int alunos_cadastrados)
{
    if (alunos_cadastrados == 0)
    {
        printf("Sem alunos cadastrados.\n");
    }
    else
    {
        for (int i = 0; i < alunos_cadastrados; i++)
        {
            if (listaAlunos[i].disciplinas < 3)
            {
                printf("\n");
                printf("Aluno #%d:\n", i + 1);
                printf("%s\n", listaAlunos[i].nome);
                printf("Matrícula: %s\n", listaAlunos[i].matricula);
                printf("Sexo: %c\n", listaAlunos[i].sexo);
                printf("CPF: %s\n", listaAlunos[i].cpf);
                printf("Data de nascimento: %02i/%02i/%i\n", listaAlunos[i].data_nascimento.dia,
                       listaAlunos[i].data_nascimento.mes,
                       listaAlunos[i].data_nascimento.ano);
                printf("\nQuantidade de disciplinas cadastradas: %d\n", listaAlunos[i].disciplinas);
            }
        }
    }
}

void listartodos(cadastro listaAlunos[], int alunos_cadastrados, cadastro listaProfessores[], int professores_cadastrados)
{
    int tamanho;
    char nomecomp[tam];
    char *p;
    if ((alunos_cadastrados == 0) && (professores_cadastrados == 0))
    {
        printf("Sem pessoas cadastradas.\n");
    }
    else
    {
        printf("\nBusca por pessoa, digite no minimo tres letras ou pressione 0 para sair\n");
        scanf("\n%99[^\n]", nomecomp);

        tamanho = strlen(nomecomp);
        if (tamanho < 3)
        {
            printf("Digite no minimo tres caracteres!");
        }
        else
        {

            for (int i = 0; i < alunos_cadastrados; i++)
            {
                p = strstr(listaAlunos[i].nome, nomecomp);
                if (p)
                {
                    printf("\n");
                    printf("Aluno #%d:\n", i + 1);
                    printf("%s\n", listaAlunos[i].nome);
                    printf("Matrícula: %s\n", listaAlunos[i].matricula);
                    printf("Sexo: %c\n", listaAlunos[i].sexo);
                    printf("CPF: %s\n", listaAlunos[i].cpf);
                    printf("Data de nascimento: %02i/%02i/%i\n", listaAlunos[i].data_nascimento.dia,
                           listaAlunos[i].data_nascimento.mes,
                           listaAlunos[i].data_nascimento.ano);
                    printf("Quantidade de disciplinas cadastradas: %d\n", listaAlunos[i].disciplinas);
                }
            }
            for (int i = 0; i < professores_cadastrados; i++)
            {
                p = strstr(listaProfessores[i].nome, nomecomp);
                if (p)
                {
                    printf("\n");
                    printf("Professor #%d:\n", i + 1);
                    printf("%s\n", listaProfessores[i].nome);
                    printf("Matrícula: %s\n", listaProfessores[i].matricula);
                    printf("Sexo: %c\n", listaProfessores[i].sexo);
                    printf("CPF: %s\n", listaProfessores[i].cpf);
                    printf("Data de nascimento: %02i/%02i/%i\n",
                           listaProfessores[i].data_nascimento.dia,
                           listaProfessores[i].data_nascimento.mes,
                           listaProfessores[i].data_nascimento.ano);
                    printf("\n");
                }
            }
        }
    }
}
