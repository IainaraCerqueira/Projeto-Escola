#ifndef funcoes_aluno_h
#endif

#include "structs.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define tam 100
#define max 3

#define sucesso 1
#define erro_matricula 2
#define erro_sexo 3
#define erro_data 4
#define erro_cpf 5
#define erro_nome 6
#define matricula_inexistente 7

int menuGeral()
{
    int menu;
    printf("Bem Vindo ao Projeto Escola!\n\n######----MENU----######\n\n1- Aluno\n2- Professor\n3- Disciplina\n4- Busca Geral\n0- Sair\n");
    scanf("%d", &menu);
    return menu;
}

/////menu aluno

int menuAluno()
{
    int menu_alunos;
    printf("######----MENU ALUNO----######\n\n");
    printf("1- Cadastrar aluno\n2- Relatórios\n3- Atualizar cadastro\n4- Excluir cadastro\n5- Sair\n");
    scanf(" %d", &menu_alunos);
    return menu_alunos;
}

int encontrarAluno(cadastro listaAlunos[], int alunos_cadastrados)
{
    int i, j, achou = 0, aluno_encontrado = 0;
    char matricula[tam];

    printf("\nInsira matrícula: ");
    scanf(" %[^\n]s", matricula);

    for (i = 0; i < alunos_cadastrados; i++)
    {
        if (strcmp(matricula, listaAlunos[i].matricula) == 0)
        {
            achou = 1;
            return i;
        }
    }

    if (achou == 0)
    {
        return matricula_inexistente;
    }
}

int matriculafuncaoAluno(cadastro listaAlunos[max], int alunos_cadastrados)
{
    int digitos = 0, retorno = 0, achou = 0;
    char matricula[tam];

    printf("\nInsira matrícula: ");
    scanf(" %99[^\n]", &matricula[0]);

    for (int i = 0; i < alunos_cadastrados; i++)
    {
        if (strcmp(matricula, listaAlunos[i].matricula) == 0)
        {
            achou = 1;
        }
    }

    if (achou == 1)
    {
        return erro_matricula;
    }
    for (int i = 0; matricula[i] != '\0'; i++)
    {
        if (matricula[i] < '0' || matricula[i] > '9')
        {
            return erro_matricula;
        }
    }

    for (int i = 0; matricula[i] != '\0'; i++)
    {
        digitos++;
    }

    if (digitos < 11)
    {
        return erro_matricula;
    }

    strcpy(listaAlunos[alunos_cadastrados].matricula, matricula);

    return sucesso;
}
int nomefuncaoAluno(cadastro listaAlunos[max], int alunos_cadastrados)
{
    int retorno = -1;
    printf("\nNome: ");
    scanf(" %[^\n]s", listaAlunos[alunos_cadastrados].nome);

    for (int i = 0; listaAlunos[alunos_cadastrados].nome[i] != '\0'; i++)
    {
        if ((listaAlunos[alunos_cadastrados].nome[i] >= '0') &&
            (listaAlunos[alunos_cadastrados].nome[i] <= '9'))
        {
            return erro_nome;
        }
    }

    return sucesso;
}

int data_nascimentofuncaoAluno(cadastro listaAlunos[max], int alunos_cadastrados)
{
    printf("\nData de nascimento: \n");

    printf("\nInsira o dia: ");
    scanf(" %d", &listaAlunos[alunos_cadastrados].data_nascimento.dia);

    if ((listaAlunos[alunos_cadastrados].data_nascimento.dia < 1) ||
        (listaAlunos[alunos_cadastrados].data_nascimento.dia > 31))
    {
        return erro_data;
    }

    printf("\nInsira o mês: ");
    scanf(" %d", &listaAlunos[alunos_cadastrados].data_nascimento.mes);

    if ((listaAlunos[alunos_cadastrados].data_nascimento.mes < 1) ||
        (listaAlunos[alunos_cadastrados].data_nascimento.mes > 12))
    {
        return erro_data;
    }

    printf("\nInsira o ano: ");
    scanf(" %d", &listaAlunos[alunos_cadastrados].data_nascimento.ano);

    if ((listaAlunos[alunos_cadastrados].data_nascimento.ano < 1924) || (listaAlunos[alunos_cadastrados].data_nascimento.ano > 2007))
    {
        return erro_data;
    }
    return sucesso;
}

int sexofuncaoAluno(cadastro listaAlunos[max], int alunos_cadastrados)
{

    printf("\nSexo: ");
    scanf(" %c", &listaAlunos[alunos_cadastrados].sexo);

    if (listaAlunos[alunos_cadastrados].sexo > 90)
    {
        listaAlunos[alunos_cadastrados].sexo -= 32;
    }

    if ((listaAlunos[alunos_cadastrados].sexo != 'M') &&
        (listaAlunos[alunos_cadastrados].sexo != 'F'))
    {
        return erro_sexo;
    }

    return sucesso;
}

int cpffuncaoAluno(cadastro listaAlunos[max], int alunos_cadastrados)
{
    int digitos = 0;

    printf("\nCPF: ");
    scanf(" %99[^\n]", listaAlunos[alunos_cadastrados].cpf);

    for (int i = 0; listaAlunos[alunos_cadastrados].cpf[i] != '\0'; i++)
    {
        digitos++;
    }

    if (digitos < 11)
    {
        return erro_cpf;
    }

    return sucesso;
}

int cadastrarAluno(cadastro listaAlunos[], int alunos_cadastrados, disciplina listaDisciplinas[], int disciplinas_cadastradas)
{
    int digitos = 0, retorno = 0;

    if (alunos_cadastrados > max)
    {
        printf("\nLista lotada!\n\n");
    }
    else
    {

        printf("\n\nCadastro (novo aluno):\n");
        retorno = matriculafuncaoAluno(listaAlunos, alunos_cadastrados);
        if (retorno == erro_matricula)
        {
            return erro_matricula;
        }

        retorno = nomefuncaoAluno(listaAlunos, alunos_cadastrados);
        if (retorno == erro_nome)
        {
            return erro_nome;
        }

        retorno = data_nascimentofuncaoAluno(listaAlunos, alunos_cadastrados);
        if (retorno == erro_data)
        {
            return erro_data;
        }

        retorno = sexofuncaoAluno(listaAlunos, alunos_cadastrados);
        if (retorno == erro_sexo)
        {
            return erro_sexo;
        }

        retorno = cpffuncaoAluno(listaAlunos, alunos_cadastrados);
        if (retorno == erro_cpf)
        {
            return erro_cpf;
        }
    }
    return sucesso;
}

void listarAluno(cadastro listaAlunos[], int alunos_cadastrados)
{ ////// listar ALUNOS
    char digit;

    if (alunos_cadastrados == 0)
    {
        printf("\nSem professores cadastrados.\n\n");
    }
    else
    {
        for (int i = 0; i < alunos_cadastrados; i++)
        {
            printf("\n");
            printf("Aluno #%i:\n", i + 1);
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
    printf("Digite alguma coisa para continuar:\n");
    scanf(" %c", &digit);
}

int menuAlteracao()
{
    int menu_alteracao;

    printf("\nInsira o que deve ser alterado:\n");
    printf("1-  Nome\n2- Sexo\n3- CPF\n4- Data de nascimento\n\n");
    scanf(" %d", &menu_alteracao);

    return menu_alteracao;
}

int excluirAluno(cadastro listaAlunos[max], int alunos_cadastrados)
{
    int retorno = 0, aluno_encontrado = 0;

    retorno = encontrarAluno(listaAlunos, alunos_cadastrados);

    if (retorno == matricula_inexistente)
    {
        return matricula_inexistente;
    }
    else
    {
        aluno_encontrado = retorno;

        for (int i = aluno_encontrado; i < alunos_cadastrados; i++)
        {

            for (int j = i; j < alunos_cadastrados - 1; j++)
            {

                strcpy(listaAlunos[j + 1].matricula, listaAlunos[j].matricula);

                strcpy(listaAlunos[j + 1].matricula, listaAlunos[j].matricula);

                listaAlunos[j].sexo = listaAlunos[j + 1].sexo;

                listaAlunos[j].data_nascimento.dia =
                    listaAlunos[j + 1].data_nascimento.dia;

                listaAlunos[j].data_nascimento.mes =
                    listaAlunos[j + 1].data_nascimento.mes;

                listaAlunos[j].data_nascimento.ano =
                    listaAlunos[j + 1].data_nascimento.ano;

                strcpy(listaAlunos[j + 1].matricula, listaAlunos[j].matricula);
            }
        }
        return sucesso;
    }
}
///////// menu professor

int menuProfessor()
{
    int menu_professores;
    printf("######----MENU PROFESSOR----######\n\n");
    printf("1- Cadastrar professor\n2- Relatórios\n3- Atualizar cadastro\n4- Excluir professor\n5- Sair\n\n");
    scanf(" %d", &menu_professores);
    return menu_professores;
}

int encontrarProfessor(cadastro listaProfessores[], int professores_cadastrados)
{
    int i, j, achou = 0;
    char matricula[tam];

    printf("\nInsira matrícula: ");
    scanf(" %99[^\n]", matricula);

    for (i = 0; i < professores_cadastrados; i++)
    {
        if (strcmp(matricula, listaProfessores[i].matricula) == 0)
        {
            achou = 1;
            return i;
        }
    }

    if (achou == 0)
    {
        return matricula_inexistente;
    }
}

int matriculafuncaoProfessor(cadastro listaProfessores[], int professores_cadastrados)
{
    int digitos = 0, achou = 0;
    char matricula[tam];

    printf("\nInsira matrícula: ");
    scanf(" %99[^\n]", matricula);

    for (int i = 0; i < professores_cadastrados; i++)
    {
        if (strcmp(matricula, listaProfessores[i].matricula) == 0)
        {
            achou = 1;
        }
    }

    if (achou == 1)
    {
        return erro_matricula;
    }
    for (int i = 0; matricula[i] != '\0'; i++)
    {
        if (matricula[i] < '0' || matricula[i] > '9')
        {
            return erro_matricula;
        }
    }

    for (int i = 0; matricula[i] != '\0'; i++)
    {
        digitos++;
    }

    if (digitos < 11)
    {
        return erro_matricula;
    }

    strcpy(listaProfessores[professores_cadastrados].matricula, matricula);

    return sucesso;
}

int nomefuncaoProfessor(cadastro listaProfessores[max], int professores_cadastrados)
{

    printf("\nNome: ");
    scanf(" %99[^\n]", listaProfessores[professores_cadastrados].nome);

    for (int i = 0; listaProfessores[professores_cadastrados].nome[i] != '\0';
         i++)
    {
        if (listaProfessores[professores_cadastrados].nome[i] >= '0' &&
            listaProfessores[professores_cadastrados].nome[i] <= '9')
        {
            return erro_nome;
        }
    }
    return sucesso;
}

int data_nascimentofuncaoProfessor(cadastro listaProfessores[], int professores_cadastrados)
{

    printf("\nData de nascimento: \n");

    printf("\nInsira o dia: ");
    scanf(" %d", &listaProfessores[professores_cadastrados].data_nascimento.dia);

    if (listaProfessores[professores_cadastrados].data_nascimento.dia < 1 || listaProfessores[professores_cadastrados].data_nascimento.dia > 31)
    {
        return erro_data;
    }

    printf("\nInsira o mês: ");
    scanf(" %d", &listaProfessores[professores_cadastrados].data_nascimento.mes);

    if (listaProfessores[professores_cadastrados].data_nascimento.mes < 1 || listaProfessores[professores_cadastrados].data_nascimento.mes > 12)
    {
        return erro_data;
    }

    printf("\nInsira o ano: ");
    scanf(" %d", &listaProfessores[professores_cadastrados].data_nascimento.ano);

    if (listaProfessores[professores_cadastrados].data_nascimento.ano < 1924 || listaProfessores[professores_cadastrados].data_nascimento.ano > 2007)
    {
        return erro_data;
    }
    return sucesso;
}

int sexofuncaoProfessor(cadastro listaProfessores[], int professores_cadastrados)
{
    int digitos = 0, retorno = 0;

    printf("\nSexo: ");
    scanf(" %c", &listaProfessores[professores_cadastrados].sexo);

    if (listaProfessores[professores_cadastrados].sexo > 90)
    {
        listaProfessores[professores_cadastrados].sexo -= 32;
    }

    if (listaProfessores[professores_cadastrados].sexo != 'M' &&
        listaProfessores[professores_cadastrados].sexo != 'F')
    {
        return erro_sexo;
    }

    return sucesso;
}

int cpffuncaoProfessor(cadastro listaProfessores[], int professores_cadastrados)
{
    int digitos = 0;

    printf("\nCPF: ");
    scanf(" %99[^\n]", listaProfessores[professores_cadastrados].cpf);

    for (int i = 0; listaProfessores[professores_cadastrados].cpf[i] != '\0';
         i++)
    {
        digitos++;
    }

    if (digitos < 11)
    {
        return erro_cpf;
    }

    return sucesso;
}

int cadastrarProfessor(cadastro listaProfessores[], int professores_cadastrados)
{
    int digitos = 0, retorno = 0;

    if (professores_cadastrados > max)
    {
        printf("\nLista lotada!\n\n");
    }
    else
    {

        printf("\n\nCadastro (novo professor):\n");
        retorno =
            matriculafuncaoProfessor(listaProfessores, professores_cadastrados);
        if (retorno == erro_matricula)
        {
            return erro_matricula;
        }

        retorno = nomefuncaoProfessor(listaProfessores, professores_cadastrados);
        if (retorno == erro_nome)
        {
            return erro_nome;
        }

        retorno = data_nascimentofuncaoProfessor(listaProfessores, professores_cadastrados);
        if (retorno == erro_data)
        {
            return erro_data;
        }

        retorno = sexofuncaoProfessor(listaProfessores, professores_cadastrados);
        if (retorno == erro_sexo)
        {
            return erro_sexo;
        }

        retorno = cpffuncaoProfessor(listaProfessores, professores_cadastrados);
        if (retorno == erro_cpf)
        {
            return erro_cpf;
        }
    }

    return sucesso;
}

void listarProfessor(cadastro listaProfessores[], int professores_cadastrados)
{ ////listar PROFESSOR
    char digit;

    if (professores_cadastrados == 0)
    {
        printf("\nSem professores cadastrados.\n\n");
    }
    else
    {
        for (int i = 0; i < professores_cadastrados; i++)
        {
            printf("\n");
            printf("Professor #%i:\n", i + 1);
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
    printf("Digite alguma coisa para continuar:\n");
    scanf(" %c", &digit);
}

int excluirProfessor(cadastro listaProfessores[], int professores_cadastrados)
{
    int retorno = 0, professor_encontrado = 0;

    retorno = encontrarProfessor(listaProfessores, professores_cadastrados);

    if (retorno == matricula_inexistente)
    {
        return matricula_inexistente;
    }
    else
    {
        professor_encontrado = retorno;

        for (int i = professor_encontrado; i < professores_cadastrados; i++)
        {

            for (int j = i; j < professores_cadastrados - 1; j++)
            {

                strcpy(listaProfessores[j + 1].matricula,
                       listaProfessores[j].matricula);

                strcpy(listaProfessores[j + 1].nome, listaProfessores[j].nome);

                listaProfessores[j].sexo = listaProfessores[j + 1].sexo;

                listaProfessores[j].data_nascimento.dia =
                    listaProfessores[j + 1].data_nascimento.dia;

                listaProfessores[j].data_nascimento.mes =
                    listaProfessores[j + 1].data_nascimento.mes;

                listaProfessores[j].data_nascimento.ano =
                    listaProfessores[j + 1].data_nascimento.ano;

                strcpy(listaProfessores[j + 1].cpf, listaProfessores[j].cpf);
            }
        }
        return sucesso;
    }
}

//// menu disciplina

int menuDisciplinas()
{
    int menu_disciplina;
    printf("######----MENU DISCIPLINAS----######\n\n");
    printf("1 - Relatorios\n2 - Inserir disciplina\n3 - Excluir "
           "disciplina\n4 - Matricular Aluno\n5 - Atualizar cadastro de "
           "disciplina\n6 - Voltar\n\n");

    scanf(" %d", &menu_disciplina);

    return menu_disciplina;
}

int menuDisciplinas2()
{
    int menu_disciplina;
    printf("######----MENU DISCIPLINAS----######\n\n");
    printf("1 - Listar apenas informações da disciplina\n2 - Listar disciplinas "
           "com alunos\n3 - Listar disciplinas que extrapolam 40 vagas\n4 - Voltar\n");

    scanf(" %d", &menu_disciplina);
    return menu_disciplina;
}

void listarDisciplinas(int disciplinas_cadastradas,
                       disciplina listaDisciplinas[], cadastro listaAlunos[], int alunos_cadastrados)
{
    int retorno = -1;
    if (disciplinas_cadastradas == 0)
    {
        printf("\nSem disciplinas cadastradas.\n\n");
    }
    else
    {
        for (int i = 0; i < disciplinas_cadastradas; i++)
        {
            printf("\n%s ", listaDisciplinas[i].nome);
            printf("(%s)\n", listaDisciplinas[i].code);
            printf("Professor: %s\n", listaDisciplinas[i].prof);
            printf("Semestre: %dº\n", listaDisciplinas[i].semestre);
            if (listaDisciplinas[i].alunos_disciplina == 0)
            {
                printf("\nSem alunos matriculados.\n\n");
            }
            else
            {
                for (int y = 0; y < alunos_cadastrados; y++)
                {
                    for (int j = 0; j < listaDisciplinas[i].alunos_disciplina; j++)
                    {
                        retorno = strcmp(listaAlunos[y].matricula, listaDisciplinas[i].listaAlunosCode[j]);
                        if (retorno == 0)
                        {
                            printf("\nAluno: \n");
                            printf("%s", listaAlunos[y].nome);
                            printf(" - %s\n\n", listaDisciplinas[i].listaAlunosCode[j]);
                        }
                    }
                }
            }
        }
    }
}

void listarDisciplinas2(int disciplinas_cadastradas,
                        disciplina listaDisciplinas[])
{
    if (disciplinas_cadastradas == 0)
    {
        printf("\nSem disciplinas cadastradas.\n\n");
    }
    else
    {
        for (int i = 0; i < disciplinas_cadastradas; i++)
        {
            printf("\n%s ", listaDisciplinas[i].nome);
            printf("(%s)\n", listaDisciplinas[i].code);
            printf("Professor: %s\n", listaDisciplinas[i].prof);
            printf("Semestre: %dº\n", listaDisciplinas[i].semestre);
            if (listaDisciplinas[i].alunos_disciplina == 0)
            {
                printf("\nSem alunos matriculados.\n\n");
            }
        }
    }
}

int inserirDisciplina(int disciplinas_cadastradas,
                      disciplina listaDisciplinas[])
{
    char nome[tam], code[tam], prof[tam];
    int compNome, semestre, achou = 0, compCode, digitos;
    printf("\nInsira o nome da disciplina: ");
    scanf(" %[^\n]s", &nome[0]);
    printf("\nInsira o codigo da disciplina: ");
    scanf(" %s", code);
    for (int i = 0; listaDisciplinas[disciplinas_cadastradas].code[i] != '\0'; i++)
    {
        if (code[i] < '0' || code[i] > '9' || code[i] == ' ')
        {
            return 4;
        }
    }

    for (int i = 0; code[i] != '\0'; i++)
    {
        digitos++;
    }

    if (digitos < 11)
    {
        return 4;
    }
    printf("\nInsira o semestre: ");
    scanf(" %d", &semestre);
    printf("\nInsira o professor que lecionara a materia: ");
    scanf(" %[^\n]s", &prof[0]);

    if (disciplinas_cadastradas > 0)
    {
        for (int i = 0; i < disciplinas_cadastradas; i++)
        {
            compNome = strcmp(nome, listaDisciplinas[i].nome);
            compCode = strcmp(code, listaDisciplinas[i].code);
            if (compNome == 0)
            {
                achou = 1;
                break;
            }
            if (compCode == 0)
            {
                achou = 2;
                break;
            }
        }

        if (achou == 1)
        {
            return 1;
        }
        else if (achou == 2)
            return 2;
        else
        {
            strcpy(listaDisciplinas[disciplinas_cadastradas].nome, nome);
            strcpy(listaDisciplinas[disciplinas_cadastradas].code, code);
            strcpy(listaDisciplinas[disciplinas_cadastradas].prof, prof);
            listaDisciplinas[disciplinas_cadastradas].semestre = semestre;
            return 0;
        }
    }

    else
    {

        strcpy(listaDisciplinas[disciplinas_cadastradas].nome, nome);
        strcpy(listaDisciplinas[disciplinas_cadastradas].code, code);
        strcpy(listaDisciplinas[disciplinas_cadastradas].prof, prof);
        listaDisciplinas[disciplinas_cadastradas].semestre = semestre;

        return 0;
    }
}

void excluirDisciplina(int *disciplinas_cadastradas,
                       disciplina listaDisciplinas[])
{
    char code[tam];
    int retorno;

    printf("\nInsira o código da matéria que deseja excluir: ");
    scanf(" %s", code);

    for (int i = 0; i < *disciplinas_cadastradas; i++)
    {
        retorno = strcmp(listaDisciplinas[i].code, code);
        if (retorno == 0)
        {
            if (i == *disciplinas_cadastradas - 1)
                (*disciplinas_cadastradas)--;
            else
            {
                strcpy(listaDisciplinas[i].nome,
                       listaDisciplinas[*disciplinas_cadastradas - 1].nome);
                strcpy(listaDisciplinas[i].code,
                       listaDisciplinas[*disciplinas_cadastradas - 1].code);
                strcpy(listaDisciplinas[i].prof,
                       listaDisciplinas[*disciplinas_cadastradas - 1].prof);
                for (int j = 0; j < listaDisciplinas[i].alunos_disciplina; j++)
                {
                    strcpy(listaDisciplinas[i].listaAlunosCode[j],
                           listaDisciplinas[listaDisciplinas[i].alunos_disciplina - 1].listaAlunosCode[j]);
                }
                listaDisciplinas[i].semestre =
                    listaDisciplinas[*disciplinas_cadastradas - 1].semestre;
                (*disciplinas_cadastradas)--;
            }
        }
        else if (retorno != 0 && i == *disciplinas_cadastradas - 1)
            printf("Nenhuma materia com esse codigo esta registrada.\n\n");
    }
}

int matricularAluno(int alunos_cadastrados, int disciplinas_cadastradas, cadastro listaAlunos[], disciplina listaDisciplinas[])
{
    int comp, disciplina_encontrada = 0, alunos_disciplina = 0,
              aluno_encontrado = 0, me;
    char matricula[tam], disciplina[tam];
    bool achou = false;
    printf("Insira a matricula do aluno: ");
    scanf(" %s", matricula);

    for (int i = 0; i < max; i++)
    {
        comp = strcmp(listaAlunos[i].matricula, matricula);
        if (comp == 0)
        {
            achou = true;
            aluno_encontrado = i;
            break;
        }
    }

    if (achou == false)
    {
        return -1;
    }
    else
    {

        printf("Insira o codigo da disciplina: ");
        scanf(" %s", disciplina);
        for (int i = 0; i < disciplinas_cadastradas; i++)
        {
            comp = strcmp(listaDisciplinas[i].code, disciplina);
            if (comp == 0)
            {
                me = i;
                if (listaDisciplinas[me].alunos_disciplina == maxmatri - 1)
                    return 3;
            }
        }

        achou = false;

        for (int i = 0; i < max; i++)
        {
            comp = strcmp(listaDisciplinas[i].code, disciplina);
            if (comp == 0)
            {
                achou = true;
                disciplina_encontrada = i;
                break;
            }
        }

        if (achou == true)
        {
            strcpy(listaDisciplinas[disciplina_encontrada]
                       .listaAlunosCode[alunos_disciplina],
                   listaAlunos[aluno_encontrado].matricula);
            listaAlunos[aluno_encontrado].disciplinas++;
            return disciplina_encontrada;
        }
        else
        {
            return -1;
        }
    }
}

int menuAlterar(int disciplinas_cadastradas, int *i,
                disciplina listaDisciplinas[])
{
    int menu_disciplina, achou = 0, comp;
    char code[tam];
    printf("\nDigite o codigo da materia que deseja alterar: ");
    scanf(" %s", code);
    while (achou != 1)
    {
        for (*i = 0; *i < disciplinas_cadastradas; (*i)++)
        {
            comp = strcmp(listaDisciplinas[*i].code, code);
            if (comp == 0)
            {
                achou = 1;
            }
            else
                printf("\nNao existe disciplina com esse codigo.\n");
            break;
        }
    }

    printf("######----ALTERAR DISCIPLINAS----######\n\n");
    printf("O que deseja alterar:\n");
    printf("1 - Nome\n2 - Codigo\n3 - Professor\n4 - Semestre\n5 - Voltar\n\n");

    scanf(" %d", &menu_disciplina);
    return menu_disciplina;
}

void alterarDisciplina(int menu_disciplina2, int i,
                       disciplina listaDisciplinas[])
{
    char nome[tam], code[tam], prof[tam];
    int semestre;
    switch (menu_disciplina2)
    {
    case 1:
        printf("\nDigite o novo nome da materia: ");
        scanf(" %[^\n]s", &nome[0]);
        strcpy(listaDisciplinas[i].nome, nome);
        break;
    case 2:
        printf("\nDigite o novo codigo da materia: ");
        scanf(" %s", code);
        strcpy(listaDisciplinas[i].code, code);
        break;
    case 3:
        printf("\nDigite o novo nome da materia: ");
        scanf(" %[^\n]s", &prof[0]);
        strcpy(listaDisciplinas[i].prof, prof);
        break;
    case 4:
        printf("\nDigite o novo nome da materia: ");
        scanf(" %d", &semestre);
        listaDisciplinas[i].semestre = semestre;
        break;
    default:
        break;
    }
}