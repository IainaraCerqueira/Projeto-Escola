#ifndef structs_h
#endif

#include <stdio.h>

#define tam 100
#define max 3
#define maxmatri 41
#define extrapolar maxmatri - 40

typedef struct
{
    int dia;
    int mes;
    int ano;
} data;

typedef struct
{
    char matricula[tam];
    char nome[tam];
    char sexo;
    data data_nascimento;
    char cpf[tam];
    int disciplinas;
} cadastro;

typedef struct
{
    char listaAlunos[maxmatri][tam];
    char listaAlunosCode[maxmatri][tam];
    char nome[tam];
    int alunos_disciplina;
    char code[tam];
    char prof[tam];
    int semestre;
} disciplina;
