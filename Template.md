
  

![](logoEST.png)


# Segurança Informática</span> <br>
##  Projeto </span> <br>

### nome aluno1 ; numero aluno1  <br>
### nome aluno2 ; numero aluno 2 <br>

<br>




## 1 Introdução


## 2 Vulnerabilidades Condiçoes de Corrida - Introdução
Uma condição de corrida surge quando um programa depende da sequência e(ou) momento de execução de processos ou threads. Condições de corrida critica
ocorrem quando processos ou threads dependem da mesma informação de estado. As operações efetuadas sobre informação de estado partilhada devem ser
realizadas em secções criticas que devem ser executadas de forma exclusiva. Falhas a esta regra (de execução mutuamente exclusiva) podem permitir a
corrupção do estado partilhado.
Condições de corrida podem ser de difícil reprodução uma vez que o resultado final é não-determinista e depende do momento de execução nos vários processos
ou threads. Problemas desta natureza podem não ser notados quando se executam os programas em modo de debug ou quando se adiciona logging.

Em outros palavras, é a situação onde o tempo que os eventos ocorrem podem influenciar sua execução.
Softwares básicos como o sistema operacional, servidores diversos como banco de dados e HTTP também encontram condições de corrida.

**Como occorrem**
Se for algo exclusivo em memória ou que é garantido que apenas uma aplicação pode acessar só pode ocorrer uma condição de corrida se existir mais de uma thread, caso contrário não há concorrência, então o tempo é regido de forma linear pela aplicação.

Já recursos compartilhados entre várias aplicações estão sempre suscetíveis à condição de corrida.

Algumas condições de corrida, ou tentativas de solucionar condições de corrida podem provocar um deadlock que é a interdependência entre duas operações que são paralelas. Uma impede a outra de ser executada que por sua vez impede a primeira de ser executada.

<div style="page-break-after: always"></div>

## 3 Vulnerabilidades Condições de Corrida - Setup
Para o setup inicial precisamos de desativar a proteção contra ataques deste género. Foi através do seguinte comando que foi possivel fazê-lo

```sh
   $  sudo sysctl -w fs.protected_symlinks=0
```
Em computação, um symlink é um tipo especial de arquivo que contém uma referência a outro arquivo ou diretório na forma de um caminho absoluto ou relativo e que afeta a resolução do nome de caminho (pathname). Os symlinks já estiveram presentes em 1978 em sistemas operacionais de mini-computadores da DEC e do RDOS da Data General.



<div style="page-break-after: always"></div>

## 4 Vulnerabilidades Condições de Corrida - Programa Vulnerável

```c
/* vulp.c */
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define DELAY 5000

int main(){
  char* fn = "./XYZ";
  char buffer[60];
  FILE *fp;
  long i;
  /* get user input */
  scanf("%50s", buffer);
  if(access(fn, W_OK) == 0){
    for(i=0;i<DELAY;i++){
      int a = i ^ 2;
    }
    fp = fopen(fn, "a+");
    fwrite(buffer,sizeof(char),strlen(buffer), fp);
    fwrite("\n",sizeof(char),1, fp);
    fclose(fp);
  }else printf("No permission \n");
}
```


SetUID Program

```sh
   $ ls
   $ gcc vulp.c -o vulp
   $ sudo chown root vulp
   $ sudo chmod 4755 vulp
   $ ls -l vulp.c
```

![Permissões do programa vulp](checkOwnership.png "Permissões do programa vulp")
*Permissões do programa vulp* 



<div style="page-break-after: always"></div>

## 5 Escolher o objetivo

Criar utilizador com permissões de root
```sh
   $ sudo adduser teste
   $ cut -d: -f1 /etc/passwd # List all users (teste appear)
   $ sudo chown teste vulp # SETUID to teste
   $ sudo chmod 4755 vulp
   $ ls -l vulp #OUTPUT: -rwsr-xr-x 1 teste seed 7628 Jan 8 07:36 vulp
```

<div style="page-break-after: always"></div>


## 5 String de formato 2.1

Hexadecimal
bfb9dfcf.b75392ef.b740be6e.b752ba88.b779fe60.b740bc45.bfb9d544.bfb9d0d4.0d696911.b740bc45.78383025.3830252e.30252e78.252e7838.2e783830.78383025.3830252e.30252e78.252e7838.2e783830.

Este valores representam os conteúdos de memória lidos pelo programa, que não deveriam ser acedidos fora do mesmo.


**2.2**


<div style="page-break-after: always"></div>


##  Referências
 
  1. [The Linux Command Line](https://linuxcommand.org/)
  2. [How to Write a Setuid Program](http://nob.cs.ucdavis.edu/~bishop/secprog/1987-sproglogin.pdf)
  3. [fork](https://www.csl.mtu.edu/cs4411.ck/www/NOTES/process/fork/create.html)
  1. [The Linux Command Line](https://linuxcommand.org/)
  2. [How to Write a Setuid Program](http://nob.cs.ucdavis.edu/~bishop/secprog/1987-sproglogin.pdf)
  3. [fork](https://www.csl.mtu.edu/cs4411.ck/www/NOTES/process/fork/create.html)

  <div style="page-break-after: always"></div>


   