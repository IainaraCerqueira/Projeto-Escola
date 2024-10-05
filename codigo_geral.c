#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define cls system("clear")
#define tam 100
#define max 3

#define sucesso 1
#define erro_matricula 2
#define erro_sexo 3
#define erro_data 4
#define erro_cpf 5
#define erro_nome 6
#define matricula_inexistente 7

#include "relatorios.h"

int main()
{
    int retorno = 0;
    cadastro listaAlunos[max];
    cadastro listaProfessores[max];
    disciplina listaDisciplinas[max];

    for (int y = 0; y < max; y++)
        listaDisciplinas[y].alunos_disciplina = 0;

    for (int y = 0; y < max; y++)
        listaAlunos[y].disciplinas = 0;
    int sair = 0, achado = 0;

    int menu, menu_alunos = 0, menu_professores = 0, menu_alteracao = 0, menu_disciplinas = 0, menu_disciplina2 = 0, menurelatorio_p = 0, menurelatorio_a = 0;

    int professores_cadastrados = 0, professor_encontrado = 0, disciplinas_cadastradas = 0;

    int alunos_cadastrados = 0, aluno_encontrado = 0;

    int digitos = 0;

    bool retorno1;

    char matricula[tam];

    while (!sair)
    {
        menu_alunos = 0;
        menu_professores = 0;
        menu_disciplinas = 0;
        menu = menuGeral();

        switch (menu)
        {

        case 4:
        {
            listartodos(listaAlunos, alunos_cadastrados, listaProfessores, professores_cadastrados);
        }
        break;

        case 0:
        {
            sair = 1;
            break;
        }

        case 1:
        {
            menu_alunos = -1;
            while (menu_alunos != 5)
            {
                menu_alunos = menuAluno();

                switch (menu_alunos)
                {

                case 1:
                {
                    retorno = 0;
                    while (retorno != sucesso)
                    {
                        retorno = cadastrarAluno(listaAlunos, alunos_cadastrados, listaDisciplinas, disciplinas_cadastradas);
                        if (retorno == sucesso)
                        {
                            printf("\nAluno cadastrado com sucesso!\n\n");
                            alunos_cadastrados++;
                        }
                        else
                        {
                            switch (retorno)
                            {
                            case erro_matricula:
                            {
                                printf("\nErro ao cadastrar aluno. Matrícula inválida.\nA matricula nao deve conter espacos nem letras, e deve ter 11 digitos e não pode ser uma matrícula já existente\n");
                                continue;
                            }
                            case erro_sexo:
                            {
                                printf("\nErro ao cadastrar aluno. Sexo inválido.\n");
                                continue;
                            }
                            case erro_data:
                            {
                                printf("\nErro ao cadastrar aluno. Data inválida.\n");
                                continue;
                            }

                            case erro_cpf:
                            {
                                printf("\nErro ao cadastrar aluno. CPF inválido.\n");
                                continue;
                            }

                            case erro_nome:
                            {
                                printf("\nErro ao cadastrar aluno. Nome inválido.\n");
                                continue;
                            }

                            } // do switch (erros)
                        }     // do else (erros)
                    }
                } // case 1 do switch menu alunos
                break;

                case 2:
                {
                    menurelatorio_a = -1;
                    while (menurelatorio_a != 7)
                    {
                        menurelatorio_a = menuRelatoriosAlu();
                        switch (menurelatorio_a)
                        {
                        case 1:
                        {
                            listarAluno(listaAlunos, alunos_cadastrados);
                        }
                        break;
                        case 2:
                        {
                            listaralusexo(listaAlunos, alunos_cadastrados);
                        }
                        break;
                        case 3:
                        {
                            listasaluidade(listaAlunos, alunos_cadastrados);
                        }
                        break;
                        case 4:
                        {
                            listaralualfabeto(listaAlunos, alunos_cadastrados);
                        }
                        break;
                        case 5:
                        {
                            listaraluniver(listaAlunos, alunos_cadastrados);
                        }
                        break;

                        case 6:
                        {
                            listarAlunoPoucaDisci(listaAlunos, alunos_cadastrados);
                        }
                        break;
                        case 7:
                            break;
                        default:
                        {
                            printf("\nPor favor escolha uma opcao válida!\n");
                        }
                        break;
                        } // fim switch relatorios alunos
                    }
                    break;
                }
                break;

                case 3:
                {
                    if (alunos_cadastrados == 0)
                    {
                        printf("\nSem alunos cadastrados.\n\n");
                        break;
                    }
                    else
                    {
                        retorno = encontrarAluno(listaAlunos, alunos_cadastrados);

                        if (retorno == matricula_inexistente)
                        {
                            printf("\nAluno não encontrado.\n\n");
                            break;
                        }
                        else
                        {
                            aluno_encontrado = retorno;
                            menu_alteracao = menuAlteracao();
                            switch (menu_alteracao)
                            {

                            case 1:
                            {
                                retorno = -1;
                                while (retorno != sucesso)
                                {
                                    retorno = nomefuncaoAluno(listaAlunos, aluno_encontrado);

                                    if (retorno == erro_nome)
                                    {
                                        printf("\nErro ao alterar matrícula. Nome inválido.\n\n");
                                    }
                                    else
                                    {
                                        printf("\nMatrícula alterada.\n\n");
                                    }
                                }
                            }
                            break;

                            case 2:
                            {
                                retorno = -1;
                                while (retorno != sucesso)
                                {
                                    retorno = sexofuncaoAluno(listaAlunos, aluno_encontrado);

                                    if (retorno == erro_nome)
                                    {
                                        printf("\nErro ao alterar matrícula. Sexo inválido.\n\n");
                                    }
                                    else
                                    {
                                        printf("\nMatrícula alterada.\n\n");
                                    }
                                }
                            }
                            break;

                            case 3:
                            {
                                retorno = -1;
                                while (retorno != sucesso)
                                {
                                    retorno = cpffuncaoAluno(listaAlunos, aluno_encontrado);

                                    if (retorno == erro_cpf)
                                    {
                                        printf("\nErro ao alterar matrícula. CPF inválido.\n\n");
                                    }
                                    else
                                    {
                                        printf("\nMatrícula alterada.\n\n");
                                    }
                                }
                            }
                            break;

                            case 4:
                            {
                                retorno = -1;
                                while (retorno != sucesso)
                                {
                                    retorno =
                                        data_nascimentofuncaoAluno(listaAlunos, aluno_encontrado);

                                    if (retorno == erro_data)
                                    {
                                        printf("\nErro ao alterar matrícula. Data inválida.\n\n");
                                    }
                                    else
                                    {
                                        printf("\nMatrícula alterada.\n\n");
                                    }
                                }
                            }
                            break;
                            }
                        }
                    }

                } // do alterar matricula
                break;

                case 4:
                {
                    if (alunos_cadastrados == 0)
                    {
                        printf("\nSem alunos cadastrados.\n\n");
                        break;
                    }
                    else
                    {

                        retorno = excluirAluno(listaAlunos, alunos_cadastrados);

                        if (retorno == matricula_inexistente)
                        {
                            printf("\nAluno não encontrado.\n\n");
                        }
                        else
                        {
                            printf("\nAluno excluído.\n\n");
                            alunos_cadastrados--;
                        }
                    }
                }
                break;
                case 5:
                    break;
                default:
                {
                    printf("\nPor favor escolha uma opcao válida!\n");
                }
                break;
                } // menu alunos

            } // while menu alunos
        }     // case one menu principal
        break;

        case 2:
        {
            menu_professores = -1;
            while (menu_professores != 5)
            {
                menu_professores = menuProfessor();
                switch (menu_professores)
                {
                case 1:
                {
                    retorno = 0;
                    while (retorno != sucesso)
                    {
                        retorno =
                            cadastrarProfessor(listaProfessores, professores_cadastrados);
                        if (retorno == sucesso)
                        {
                            printf("\nProfessor cadastrado com sucesso!\n\n");
                            professores_cadastrados++;
                        }
                        else
                        {
                            switch (retorno)
                            {
                            case erro_matricula:
                            {
                                printf(
                                    "\nErro ao cadastrar professor. Matrícula inválida.\nA matricula nao deve conter espacos nem letras, e deve ter 11 digitos\n\n");
                                continue;
                            }
                            case erro_sexo:
                            {
                                printf("\nErro ao cadastrar professor. Sexo inválido.\n\n");
                                continue;
                            }
                            case erro_data:
                            {
                                printf("\nErro ao cadastrar professor. Data inválida.\n\n");
                                continue;
                            }

                            case erro_cpf:
                            {
                                printf("\nErro ao cadastrar professor. CPF inválido.\n\n");
                                continue;
                            }

                            case erro_nome:
                            {
                                printf("\nErro ao cadastrar professor. Nome inválido.\n\n");
                                continue;
                            }

                            } // do switch (erros)
                        }
                    }
                }
                break;
                case 2:
                {
                    menurelatorio_p = -1;
                    while (menurelatorio_p != 6)
                    {
                        menurelatorio_p = menuRelatoriosProf();
                        switch (menurelatorio_p)
                        {
                        case 1:
                        {
                            listarProfessor(listaProfessores, professores_cadastrados);
                        }
                        break;
                        case 2:
                        {
                            listarprofsexo(listaProfessores, professores_cadastrados);
                        }
                        break;
                        case 3:
                        {
                            listaprofidade(listaProfessores, professores_cadastrados);
                        }
                        break;
                        case 4:
                        {
                            listaprofalfabeto(listaProfessores, professores_cadastrados);
                        }
                        break;
                        case 5:
                        {
                            listarprofniver(listaProfessores, professores_cadastrados);
                        }
                        break;

                        default:
                        {
                            printf("\nPor favor escolha uma opcao válida!\n");
                        }
                        break;
                        } // fim switch relatorios professores
                    }
                    break;
                }
                break;

                case 3:
                {
                    if (professores_cadastrados == 0)
                    {
                        printf("\nSem professores cadastrados.\n\n");
                        break;
                    }
                    else
                    {
                        retorno =
                            encontrarProfessor(listaProfessores, professores_cadastrados);

                        if (retorno == matricula_inexistente)
                        {
                            printf("\nProfessor não encontrado.\n\n");
                            break;
                        }
                        else
                        {
                            professor_encontrado = retorno;
                            menu_alteracao = menuAlteracao();
                            switch (menu_alteracao)
                            {
                            case 1:
                            {
                                retorno = -1;
                                while (retorno != sucesso)
                                {
                                    retorno = matriculafuncaoProfessor(listaProfessores,
                                                                       professores_cadastrados);

                                    if (retorno == erro_matricula)
                                    {
                                        printf(
                                            "\nErro ao alterar matrícula. Matrícula inválida.\n\n");
                                    }
                                    else
                                    {
                                        printf("\nMatrícula alterada.\n\n");
                                    }
                                }
                            }
                            break;

                            case 2:
                            {
                                retorno = -1;
                                while (retorno != sucesso)
                                {
                                    retorno = nomefuncaoProfessor(listaProfessores,
                                                                  professores_cadastrados);

                                    if (retorno == erro_nome)
                                    {
                                        printf("\nErro ao alterar matrícula. Nome inválido.\n\n");
                                    }
                                    else
                                    {
                                        printf("\nMatrícula alterada.\n\n");
                                    }
                                }
                            }
                            break;

                            case 3:
                            {
                                retorno = -1;
                                while (retorno != sucesso)
                                {
                                    retorno = sexofuncaoProfessor(listaProfessores,
                                                                  professores_cadastrados);

                                    if (retorno == erro_nome)
                                    {
                                        printf("\nErro ao alterar matrícula. Sexo inválido.\n\n");
                                    }
                                    else
                                    {
                                        printf("\nMatrícula alterada.\n\n");
                                    }
                                }
                            }
                            break;

                            case 4:
                            {
                                retorno = -1;
                                while (retorno != sucesso)
                                {
                                    retorno = cpffuncaoProfessor(listaProfessores,
                                                                 professores_cadastrados);

                                    if (retorno == erro_cpf)
                                    {
                                        printf("\nErro ao alterar matrícula. CPF inválido.\n\n");
                                    }
                                    else
                                    {
                                        printf("\nMatrícula alterada.\n\n");
                                    }
                                }
                            }
                            break;

                            case 5:
                            {
                                retorno = -1;
                                while (retorno != sucesso)
                                {
                                    retorno = data_nascimentofuncaoProfessor(
                                        listaProfessores, professores_cadastrados);

                                    if (retorno == erro_data)
                                    {
                                        printf("\nErro ao alterar matrícula. Data inválida.\n\n");
                                    }
                                    else
                                    {
                                        printf("\nMatrícula alterada.\n\n");
                                    }
                                }
                            }
                            break;
                            }
                        }
                    }

                } // do alterar matricula
                break;

                case 4:
                {
                    if (professores_cadastrados == 0)
                    {
                        printf("\nSem professores cadastrados.\n\n");
                        break;
                    }
                    else
                    {

                        retorno =
                            excluirProfessor(listaProfessores, professores_cadastrados);

                        if (retorno == matricula_inexistente)
                        {
                            printf("\nProfessor não encontrado.\n\n");
                        }
                        else
                        {
                            printf("\nProfessor excluído.\n\n");
                            professores_cadastrados--;
                        }
                    }
                }
                break;
                default:
                {
                    printf("\nPor favor escolha uma opcao válida!\n");
                }
                break;
                }
            } // do while menu professores
            break;
        } // case 2 do switch menu geral
        break;

        case 3:
            menu_disciplinas = -1;
            while (menu_disciplinas != 6)
            {
                menu_disciplinas = menuDisciplinas();

                switch (menu_disciplinas)
                {
                case 1:
                    menu_disciplina2 = menuDisciplinas2();
                    switch (menu_disciplina2)
                    {
                    case 1:
                        listarDisciplinas2(disciplinas_cadastradas, listaDisciplinas);
                        break;
                    case 2:
                        listarDisciplinas(disciplinas_cadastradas, listaDisciplinas, listaAlunos, alunos_cadastrados);
                        break;
                    case 3:
                        extrapolarDisciplinas(disciplinas_cadastradas, listaDisciplinas);
                    default:
                    {
                        printf("\nPor favor escolha uma opcao válida!\n");
                    }
                    break;
                    } // switch menu disciplinas 2
                    break;
                case 2:
                    retorno = -1;
                    if (disciplinas_cadastradas == max)
                    {
                        printf("\nLimite de disciplinas cadastradas atingido!\n\n");
                    }
                    else
                    {
                        while (retorno != 0)
                        {
                            retorno =
                                inserirDisciplina(disciplinas_cadastradas, listaDisciplinas);
                            if (retorno == 0)
                            {
                                disciplinas_cadastradas++;
                                printf("\nDisciplina cadastrada com sucesso!\n\n");
                            }
                            if (retorno == 1)
                            {
                                printf("\n\nErro, nome de disciplina já existente.\n\n");
                            }
                            if (retorno == 2)
                                printf("\n\nErro, codigo de disciplina ja registrado.\n\n");
                            if (retorno == 4)
                                printf("\n\nErro, codigo de disciplina invalido.\n\n");
                        }
                    }
                    break;

                case 3:
                    if (disciplinas_cadastradas == 0)
                        printf("\nNenhuma disciplina cadastrada para excluir.\n\n");
                    else
                    {
                        excluirDisciplina(&disciplinas_cadastradas, listaDisciplinas);
                        printf("\nDisciplina excluída.\n\n");
                    }
                    break;

                case 4:

                    retorno = matricularAluno(disciplinas_cadastradas, alunos_cadastrados,
                                              listaAlunos, listaDisciplinas);
                    if (retorno == 3)
                        printf("\nDisciplina cheia.\n\n");
                    else if (retorno != -1)
                    {
                        printf("\nAluno matriculado!\n\n");
                        listaDisciplinas[retorno].alunos_disciplina++;
                    }
                    else
                    {
                        printf("\nNão encontramos a disciplina ou aluno :(\n\n");
                    }

                    break;

                case 5:

                    if (disciplinas_cadastradas == 0)
                        printf("\nNenhuma disciplina para alterar.\n");
                    else
                    {
                        menu_disciplina2 =
                            menuAlterar(disciplinas_cadastradas, &achado, listaDisciplinas);

                        alterarDisciplina(menu_disciplina2, achado, listaDisciplinas);
                    }
                    break;
                default:
                {
                    printf("\nPor favor escolha uma opcao válida!\n");
                }
                break;

                } // switch menu disciplinas
            }     // while menu disciplinas
            break;

        } // do switch menu geral
    }
}
