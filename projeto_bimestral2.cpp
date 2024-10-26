#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main (void){

//RA e senha
vector <string> ra_login {"2022216048", "2022114186"}; //RA = Paulo e Vitor
vector <string> senha {"batatinha123", "1505"}; //Senha = Paulo e Vitor

string login_verificar;

string senha_verificar;

//Informações de cadastro
string nome;
vector <string> nomes;

string endereco;
vector <string> enderecos;

string cpf;
vector <string> cpfs;

string data;
vector <string> datas;

//Cargos
string efetivado = "Funcionario Efetivado";
string temporario = "Funcionario Temporario";
string estagiario = "Funcionario Estagiario";
vector <string> funci;
int efet {0}, estag {0}, temp {0};   
int consulta {};
char necessidade, resposta {}, tipo_funcionario {}, sair_edit;
int tam {};   

//Salários
double salario_efet {2700};
double salario_estag {800};
double salario_temp {1350};

//Contas de salário
double soma_sal_efet {0};
double soma_sal_temp {0};
double soma_sal_estag {0};

///////////////////////////////////////////////////////////////////////////////////
// LOGIN

    do {
        cout << "\nPor favor digite o login: ";
        cin >> login_verificar;
        if (login_verificar != ra_login.at(0) && login_verificar != ra_login.at(1))
        {
            system("CLS");
            cout << "!!!LOGIN INCORRETO!!!" << endl;
        }
    } while (login_verificar != ra_login.at(0) && login_verificar != ra_login.at(1));

    do {
        cout << "Digite a senha: ";
        cin >> senha_verificar;
        if (senha_verificar != senha.at(0) && senha_verificar != senha.at(1))
        {
            system ("CLS");
            cout << "!!!SENHA INCORRETA!!!" << endl;
        }
    }while (senha_verificar != senha.at(0) && senha_verificar != senha.at(1));

    system("CLS");

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
                do 
                {
                    tam++;
                    cout << "         === Cadastro de novo funcionario ===          " << endl;
                                
                    cout << "Para comecar o cadastro, primeiramente digite o nome do funcionario: ";
                    cin.ignore();
                    getline (cin, nome);
                    nomes.push_back(nome);

                    cout << "Informe o endereco do funcionario: ";
                    getline (cin, endereco);
                    enderecos.push_back(endereco);
                

                    cout << "Informe o CPF: ";
                    getline (cin, cpf);
                    cpfs.push_back(cpf);

                    cout << "Informe a data de admissao: ";
                    getline (cin, data);
                    datas.push_back(data);

                    cout << "O funcionario eh: " << endl;
                    cout << "1- Funcionario Efetivado" << endl;
                    cout << "2- Funcionario Temporario" << endl;
                    cout << "3- Funcionario Estagiario" << endl;
                    cin >> tipo_funcionario;

                    if (tipo_funcionario != '1' && tipo_funcionario != '2' && tipo_funcionario != '3')
                    {
                        do 
                        {   
                            cout << "Digite um valor valido" << endl;
                            cout << "\nO funcionario eh:" << endl;
                            cout << "1- Funcionario Efetivado" << endl;
                            cout << "2- Funcionario Temporario" << endl;
                            cout << "3- Funcionario Estagiario" << endl;
                            cin >> tipo_funcionario;
                            system("CLS");
                        }while (tipo_funcionario != '1' && tipo_funcionario != '2' && tipo_funcionario != '3');
                    }

                    switch (tipo_funcionario)
                    {
                        case '1':
                            funci.push_back(efetivado);
                            efet++;
                            soma_sal_efet += salario_efet;
                        break;
                        case '2':
                            funci.push_back(temporario);
                            temp++;
                            soma_sal_temp += salario_temp;
                        break;
                        case '3':
                            funci.push_back(estagiario);
                            estag++;
                            soma_sal_estag += salario_estag;
                        break;
                        
                    }
                        system ("CLS");
                    cout << "Deseja cadastrar um novo funcionario ?" << endl;
                    cout << "Digite 1 para sim" << endl;
                    cout << "Digite 2 para nao" << endl;
                    cin >> resposta;
                    
                    system("CLS");
                    if (resposta > '2' || resposta < '1')
                    {
                        do 
                        {   
                            system("CLS");
                            cout << "!!!DIGITE UM NUMERO VALIDO!!!" << endl;
                            cout << "\nDeseja cadastrar um novo funcionario ?" << endl;
                            cout << "Digite 1 para sim" << endl;
                            cout << "Digite 2 para nao" << endl;
                            cin >> resposta;
                        }while (resposta != '1' && resposta != '2');
                    }
                    system("CLS");

                }while (resposta != '2');

        do
        {
            cout << "\nDigite o numero correspondente a sua necessidade: " << endl;
            cout << "1 - Consulta de funcionario" << endl;
            cout << "2 - Relatorio" << endl;
            cout << "3 - Editar cadastro" << endl;
            cout << "\n=================================================================" << endl;
            cin >> necessidade;
        } while (necessidade != '1' && necessidade != '2' && necessidade != '3');

        switch (necessidade)
        {
            
            // Consulta de funcionario
            case '1':
                system("CLS");
                
                /////////////////////////////////////////////////////////////////

                cout << "Digite o numero referente ao funcionario que voce deseja consultar: " << endl;
                for (int i = 0; i < tam; i++)
                {
                    cout << i << "- " << nomes.at(i) << endl;
                }
                
                cin >> consulta;

                if (consulta > tam - 1)
                {
                    do
                    {   
                        system("CLS");
                        cout << "!!!DIGITE UM NUMERO VALIDO!!!" << endl;
                        
                        for (int i = 0; i < tam; i++)
                        {
                            cout << i << "- " << nomes.at(i) << endl;
                        }
                        cout << "\nDigite o numero referente ao funcionario que voce deseja consultar: ";
                        cin >> consulta;
                    }while (consulta > tam - 1);
                }
                system ("CLS");
                for (int i = 0; i < 1; i++)
                {
                        cout << "Nome: " << nomes.at(consulta) << endl;
                        cout << "Endereco: " << enderecos.at(consulta) << endl;
                        cout << "CPF: " << cpfs.at(consulta) << endl;
                        cout << "Data de admicao: " << datas.at(consulta) << endl;
                        cout << "Cargo do Funcionario: " << funci.at(consulta) << endl;

                }
                break;
                /////////////////////////////////////////////////////////////

                /////////////////////////////////////////////////////////////////////////////////////////////////////////
                // Folha de pagamento

            case '2':
                system("CLS");
                cout << "Salario efetivado: " << salario_efet << endl;
                cout << "Salario temporario: " << salario_temp << endl;
                cout << "Salario estagiario: " << salario_estag << endl;
                cout << "\nSoma salarios efetivados: " << soma_sal_efet << endl;
                cout << "Soma salarios temporarios: " << soma_sal_temp << endl;
                cout << "Soma salarios estagiarios: " << soma_sal_estag << endl;
                cout << "\nSoma de todos os salarios: " << soma_sal_efet + soma_sal_estag + soma_sal_temp << endl;
                cout << "\nNumero de funcionarios Efetivados: " << efet << endl;
                cout << "Numero de funcionarios Temporarios: " << temp << endl;
                cout << "Numero de funcionarios Estagiarios: " << estag << endl;
                if (efet == 0)
                {
                    cout << "Media salarial de funcionarios efetivados: 0" << endl;
                }else 
                {
                    cout << "Media salarial de funcionarios efetivados: " << soma_sal_efet / efet << endl;
                }
                if (temp == 0)
                {
                    cout << "Media salarial de funcionarios temporarios: 0" << endl;
                }else
                {
                    cout << "Media salarial de funcionarios temporarios: " << soma_sal_temp / temp << endl;
                }
                if (estag == 0)
                {
                    cout << "Media salarial de funcionarios estagiarios: 0" << endl;
                }else
                {
                    cout << "Media salarial de funcionarios estagiarios: " << soma_sal_estag / estag << endl;
                }
            break;

            case '3':

                char consult_edit;
                
                cout << "Digite o numero referente ao funcionario que voce deseja consultar: " << endl;
                for (int i = 0; i < tam; i++)
                {
                    cout << i << "- " << nomes.at(i) << endl;
                }
                
                cin >> consulta;

                if (consulta > tam - 1)
                {
                    do
                    {   
                        system("CLS");
                        cout << "!!!DIGITE UM NUMERO VALIDO!!!" << endl;
                        
                        for (int i = 0; i < tam; i++)
                        {
                            cout << i << "- " << nomes.at(i) << endl;
                        }
                        cout << "\nDigite o numero referente ao funcionario que voce deseja consultar: ";
                        cin >> consulta;
                    }while (consulta > tam - 1);
                }
                system ("CLS");
                for (int i = 0; i < 1; i++)
                {
                        cout << "Nome: " << nomes.at(consulta) << endl;
                        cout << "Endereco: " << enderecos.at(consulta) << endl;
                        cout << "CPF: " << cpfs.at(consulta) << endl;
                        cout << "Data de admissao: " << datas.at(consulta) << endl;
                        cout << "Cargo do Funcionario: " << funci.at(consulta) << endl;
                }
                do
                {
                    cout << "Qual dado voce deseja alterar ?" << endl;
                    cout << "1 - Nome " << endl;
                    cout << "2 - Endereco " << endl;
                    cout << "3 - CPF " << endl;
                    cout << "4 - Data de admissao " << endl;
                    cin >> consult_edit;
                    
                    
                    switch (consult_edit)
                    {
                        case '1':
                            
                            cout << "Digite o nome: ";
                            cin.ignore();
                            getline(cin, nome);
                            nomes.at(consulta) = nome;

                            system ("CLS");
                            for (int i = 0; i < 1; i++)
                                {
                                    cout << "Nome: " << nomes.at(consulta) << endl;
                                    cout << "Endereco: " << enderecos.at(consulta) << endl;
                                    cout << "CPF: " << cpfs.at(consulta) << endl;
                                    cout << "Data de admissao: " << datas.at(consulta) << endl;
                                    cout << "Cargo do Funcionario: " << funci.at(consulta) << endl;

                                    cout << "\nDeseja editar mais alguma coisa neste funcionario?" << endl;
                                    cout << "1 - Sim" << endl;
                                    cout << "2 - Nao" << endl;
                                    cin >> sair_edit;

                                }
                        break;

                        case '2':
                             cout << "Digite o endereco: ";
                             cin.ignore();
                             getline(cin, endereco);
                             enderecos.at(consulta) = endereco;

                            system ("CLS");
                            for (int i = 0; i < 1; i++)
                                {
                                    cout << "Nome: " << nomes.at(consulta) << endl;
                                    cout << "Endereco: " << enderecos.at(consulta) << endl;
                                    cout << "CPF: " << cpfs.at(consulta) << endl;
                                    cout << "Data de admissao: " << datas.at(consulta) << endl;
                                    cout << "Cargo do Funcionario: " << funci.at(consulta) << endl;

                                    cout << "\nDeseja editar mais alguma coisa neste funcionario?" << endl;
                                    cout << "1 - Sim" << endl;
                                    cout << "2 - Nao" << endl;
                                    cin >> sair_edit;
                                }
                        break;

                        case '3':
                            cout << "Digite o CPF: ";
                            cin.ignore();
                            getline(cin, cpf);
                            cpfs.at(consulta) = cpf;

                            system ("CLS");
                            for (int i = 0; i < 1; i++)
                                {
                                    cout << "Nome: " << nomes.at(consulta) << endl;
                                    cout << "Endereco: " << enderecos.at(consulta) << endl;
                                    cout << "CPF: " << cpfs.at(consulta) << endl;
                                    cout << "Data de admissao: " << datas.at(consulta) << endl;
                                    cout << "Cargo do Funcionario: " << funci.at(consulta) << endl;

                                    cout << "\nDeseja editar mais alguma coisa neste funcionario?" << endl;
                                    cout << "1 - Sim" << endl;
                                    cout << "2 - Nao" << endl;
                                    cin >> sair_edit;
                                }
                        break;

                        case '4':
                            cout << "Digite a data de admissao: ";
                            cin.ignore();
                            getline(cin, data);
                            datas.at(consulta) = data;

                            system ("CLS");
                            for (int i = 0; i < 1; i++)
                                {
                                    cout << "Nome: " << nomes.at(consulta) << endl;
                                    cout << "Endereco: " << enderecos.at(consulta) << endl;
                                    cout << "CPF: " << cpfs.at(consulta) << endl;
                                    cout << "Data de admissao: " << datas.at(consulta) << endl;
                                    cout << "Cargo do Funcionario: " << funci.at(consulta) << endl;

                                    cout << "\nDeseja editar mais alguma coisa neste funcionario?" << endl;
                                    cout << "1 - Sim" << endl;
                                    cout << "2 - Nao" << endl;
                                    cin >> sair_edit;
                                }

                    }
                }while (sair_edit != '2');
                
                    break;
                
        }

        
        
        
        

}






















































































































































































































































































// Te amamos Belle <3
// Ass: Paulo e Vitor