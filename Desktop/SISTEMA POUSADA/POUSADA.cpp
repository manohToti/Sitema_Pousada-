#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pousada
{
	char nome[25];
	int nrodias;
	float vlr_cta;
	} diaria [5];
	
	int main(){
		int cont=0, i=0;
		float totalganho=0;
		
		FILE *ptarq;
		
		ptarq = fopen("ctrl_diarias.bin", "wb");
		
		if (ptarq == NULL)
		printf ("O arquivo nao foi aberto.");
		
		for (i=0; i<5; i++)
		{
			fflush (stdin);
			system ("cls");
			printf ("\n \n\ CADASTRO DE CONTROLE DAS DIARIAS\n");
			printf ("\nRegistro %d", i+1);
			printf ("\n\ Nome Proprio .: ");
			gets (diaria[i].nome);
			fflush (stdin);
			
			do
			{
				printf ("\n Numero de dias: ");
				scanf  ("%d", & diaria[i].nrodias );
				
				if(diaria[i].nrodias<=0) 
					printf("O valor informado %d nao e valido!", diaria[i].nrodias);
			}	while	(diaria[i].nrodias<=0);
			
			if (diaria[i].nrodias >= 10)
				diaria[i].vlr_cta = diaria[i].nrodias * 8;
				else 
					diaria[i].vlr_cta = diaria[i].nrodias * 15;
					
		totalganho += diaria[i].vlr_cta;
				
		}
		
		printf ("\n\n Total ganho pela pousada: R$ %.2f", 1, ptarq);
			
			for (i=0; i<15; i++)
			{
				fwrite (&diaria[i], sizeof(struct pousada), 1, ptarq);
				
			}
		
		printf ("\n\n\n\n F I M D A G R A V A Ç A O D E D A D O S");
		printf ("\n\n");
		
		fclose (ptarq);
		system ("pause");
		
		system ("cls");
		printf ("\n\n A P R E S E N T A N D O   R E G I S T R O S");
		
		ptarq = fopen ("crtl_diarias.bin", "rb");
		
		if (ptarq == NULL)
		printf ("O arquivo nao foi aberto.");
		
		for (i=0; i<5; i++)
		{
			fseek (ptarq, i*sizeof(struct pousada), SEEK_SET);
			fread (&diaria, sizeof(struct pousada), 1, ptarq);
			
			printf ("\n\n Nome . . . . . . . . . .: %s", diaria[i].nome);
			printf ("\n Numero de dias : %d", diaria[i].nrodias);
			printf ("\nValor da conta :R$ %.2f", diaria[i].vlr_cta);
			
			printf ("\n\n");
			system ("pause");
			
		}
		
		printf ("\n\n");
		system ("pause");
		fclose (ptarq);
		return (0);
	
	
	}
