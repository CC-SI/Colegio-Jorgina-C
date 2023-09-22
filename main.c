#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

char aluno[] = {"Teste"};
int ra = 123456789;
char alunoPass[] = "senhateste";
char ocorrencias[2][100] = {"Quebrou o nariz do amiguinho.","Se desculpou com o amiguinho"};

char user[100];
int userID;

char teacher[] = {"Prof Teste"};
int rs = 987654321;
char teacherPass[] = "senhateste";

#define OPTIONS_LENGTH 2

int CheckPassword(char password[])
{
    char input[10];
    printf("Senha: ");
    scanf("%s", &input);

    if(strcmp(password,input) == 0)
        return 1;

    return 0;
}

int Login ()
{
    int id;
    int result;

    system("cls");
    printf("RA/RS: ");
    scanf("%i", &id);

    userID = id;
    if(id == ra)
    {
        result = CheckPassword(alunoPass);
        strcpy(user, aluno);
        return result != 0 ? 2 : 1;
    }
    else
    if(id == rs)
        result = CheckPassword(teacherPass);
    else
    {
        result = 0;
        userID = 0;
    }
    printf("%i", result);
}

int AreaAluno()
{
    char options[4][30] = {"Ocorrencias", "Boletim", "Cronograma", "Sair"};
    int i;
    int selection;
    int area = 2;

    system("cls");
    AreaAlunoHeader();
    printf("Entre com a opção desejada.\n");

    for(i = 0; i < 4; i++)
    {
        printf("%i. %s\n", i +1, options[i]);
    }

    scanf("%i", &selection);

    switch(selection)
    {
        case 1:
            Ocorrencias();
            break;
        case 4:
            area = 0;
            break;
    }

    return area;
}

void AreaAlunoHeader()
{
    printf("Aluno: %s RA: %i.\n\n", user, userID);
}

void Ocorrencias()
{
    int i;

    system("cls");
    AreaAlunoHeader();

    for(i = 0; i < 2; i++)
    {
        printf("%i. %s\n", i + 1, ocorrencias[i]);
    }

    system("pause");
}

int Menu()
{
    char options[OPTIONS_LENGTH][10] = {"Logar", "Sair"};

    int i;
    int selection;

    system("cls");
    printf("Entre com a opção desejada.\n");

    for(i = 0; i < OPTIONS_LENGTH; i++)
    {
        printf("%i. %s\n", i +1, options[i]);
    }

    scanf("%i", &selection);

    if(selection != 1)
        selection = -1;

    return selection;
}

void Navigate()
{
    int currentArea = 0, navigate;
    int count = 0;
    //0 = Menu;
    //1 = Login;
    //2 = Area Aluno
    //3 = Area Professor

    printf("Area atual: %i\n", currentArea);

    while(count < 10)
    {
        switch(currentArea)
        {
            case 0:
                navigate = Menu();
                break;
            case 1:
                navigate = Login();
                break;
            case 2:
                navigate = AreaAluno();
                break;
            default:
                return;
        }

        if(navigate == currentArea)
            count++;
        else
        {
            count = 0;
            currentArea = navigate;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    Navigate();

    system("pause");
}