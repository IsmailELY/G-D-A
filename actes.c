#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"structure.h"
#include <time.h>
#include <unistd.h>



int index_acte()
{
    int index;
    FILE* fichier=fopen("Index", "r");
    if(fichier==NULL)
    {
      index=1;
    }
    else
    {
      fscanf(fichier,"%d",&index);
      index+=1;
    }
    fichier=fopen("Index", "w+");
    fprintf(fichier,"%d",index);
    fclose(fichier);
    return index;
}


void acte_generator(data *element,data*head)
{
    char nv_info[20*20];
    int index=index_acte();
    unsigned long longueur;
    data *element_mere=(data*)malloc(sizeof(data));
    data *element_pere=(data*)malloc(sizeof(data));


      system("cls");
      printf("\n\n______________________________Veuillez inserer les donnees du pere :_________________________________\n");
      sleep(2);
      element_pere->human=search_pers(head);
      system("cls");
      printf("\n\n____________________________Veuillez inserer les donnees de la mere :________________________________\n");
      sleep(2);
      element_mere->human=search_pers(head);
      system("cls");


      FILE* fichier = fopen("acte.html", "w+");

      if (element_pere==NULL || element_pere->human->ID==0)
      {
        element_pere=(data*)malloc(sizeof(data));
        element_pere->human->NAME[0]='\0';
        element_pere->human->Fst_NAME[0]='\0';
      }

      if (element_mere==NULL || element_mere->human->ID==0)
      {
        element_mere=(data*)malloc(sizeof(data));
        element_mere->human->NAME[0]='\0';
        element_mere->human->Fst_NAME[0]='\0';
      }

      char sexe[6];
      if (element->human->sexe==m)
      {
      	sexe[0]='H';
      	sexe[1]='o';
      	sexe[2]='m';
      	sexe[3]='m';
      	sexe[4]='e';
      	sexe[5]='\0';
      }
      else if (element->human->sexe==f)
      {
      	sexe[0]='F';
      	sexe[1]='e';
      	sexe[2]='m';
      	sexe[3]='m';
      	sexe[4]='e';
      	sexe[5]='\0';
      }

      fputs("<!DOCTYPE html>\n<html>\n<head>\n<meta charset=""UTF-8"" />\n<title>Acte de Naissance</title>\n<style>\ntable{border-collapse:\n collapse;\nmargin : 20px auto auto auto; }\ntd, th {border: 3px solid black;}\nbody { text-align: center;\n padding: 0;\n margin: 0; }\n</style>\n<BODY><table>\n",fichier);
      printf("enter votre Etat :\n");
      scanf("%s",nv_info);
      fprintf(fichier, "<caption>1-ÉTAT : %s      ",nv_info);
      printf("c est le service d'etat civil de quelle ville ?\n");
      scanf("%s",nv_info);

      fprintf(fichier, "2-SERVICE DE L’ÉTAT CIVIL DE : %s </caption>\n",nv_info);
      fputs("<thead> <!-- En-tête du tableau --> \n <tr>\n",fichier);
      fprintf(fichier, "<th colspan=""4"">3 EXTRAIT DE L’ACTE DE NAISSANCE N° : %d </th>\n",index);
      fputs("</tr>\n</thead>\n<tfoot> <!-- Pied de tableau -->\n<tr>\n<th>11</th>",fichier);
      fputs("</tr>\n</tfoot>\n<tbody> <!-- Corps du tableau -->\n<tr>\n<td>4</td>\n",fichier);
      printf("si vous voulez entrer autres enonciations de l'acte veuillez l'entrer :\n");
      scanf("%s",nv_info);
      fprintf(fichier,"<td colspan=""3"">DATE ET LIEU DE NAISSANCE: %d/%d/%d</td> \n </tr> \n<tr> \n     <td>5</td> \n     <td colspan=""3"">NOM: %s</td> \n </tr> \n<tr> \n<td>6</td> \n     <td colspan=""3"">PRENOM: %s</td> \n </tr> \n<tr> \n     <td>7</td> \n     <td>SEXE: %s</td> \n     <td>8-PERE</td> \n<td>9-MERE</td> \n </tr> \n<tr> \n     <td>5</td> \n     <td>NOM</td> \n     <td>%s</td> \n     <td>%s</td> \n </tr> \n<tr> \n     <td>6</td> \n     <td>PRENOM</td> \n     <td>%s</td> \n     <td>%s</td> \n </tr> \n<tr> \n 	<td>10</td> \n 	<td colspan=""3"">AUTRES ÉNONCIATIONS DE L’ACTE:%s</td>\n",element->human->birth[0],element->human->birth[1],element->human->birth[2],element->human->NAME,element->human->Fst_NAME,sexe,element_pere->human->NAME,element_mere->human->NAME,element_pere->human->Fst_NAME,element_mere->human->Fst_NAME,nv_info);
      fputs("</tr>\n</tbody>\n</table>\n</html>",fichier);
      printf("entrer le nom sous le quel l'acte sera enregistrer :\n");
      scanf("%s",nv_info);
      longueur=strlen(nv_info);
      nv_info[longueur]='.';
      nv_info[longueur+1]='h';
      nv_info[longueur+2]='t';
      nv_info[longueur+3]='m';
      nv_info[longueur+4]='l';
      nv_info[longueur+5]='\0';

      rename("acte.html",nv_info);
      fclose(fichier);
    }
